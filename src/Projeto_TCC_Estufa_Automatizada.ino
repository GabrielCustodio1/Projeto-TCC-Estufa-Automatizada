#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Pin definitions
const int sensorsolopino = A0;    // Pino do sensor de umidade do solo
const int relebombapino = 2;      // Pino de controle da bomba de água
const int relelampadapino = 3;    // Pino de controle da lâmpada
const int releVentoinhaPino = 4; // Pino de controle da ventoinha
const int sensorsoloenergia = 6;  // Pino de controle de energia do sensor
const int dht11Pin = 7;           // Pino do sensor DHT11 (temperatura e umidade)

// Limites de umidade do solo
const int umidademinimasolo = 450;  // Solo úmido
const int umidademaximasolo = 850;  // Solo seco

// Limites ideais para cultivo de morangos
const float temperaturaMinima = 16.0;
const float temperaturaMaxima = 29.0;
const float umidadeMinima = 53.0;
const float umidadeMaxima = 78.0;

// Controle de tempo
const unsigned long lampadacrecimenoliga = 16 * 60 * 60 * 1000UL; // 16 horas de luz
const unsigned long lampadacrescimentodesliga = 8 * 60 * 60 * 1000UL; // 8 horas de descanso
unsigned long controlatempolampada = 0;
const unsigned long tempoleiturasolo = 2 * 1000UL; // Tempo de leitura do sensor de solo
const unsigned long intervalosensorsolo = 30 * 60 * 1000UL; // Intervalo de leitura do sensor de solo (30 minutos)
unsigned long controlatemposensor = 0;
const unsigned long duracaobombaagua = 7 * 1000UL; // Tempo em que a bomba fica ligada (5 segundos)
unsigned long controlatempobomba = 0;
const unsigned long intervaloleituradht11 = 2 * 1000UL; // Intervalo de leitura do DHT11
unsigned long controlatempodht11 = 0;

// Inicia o display LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);
// Inicializa o sensor DHT11
DHT dht11(dht11Pin, DHT11);

void setup() {
    Serial.begin(9600); // Inicializa a comunicação serial
    pinMode(sensorsolopino, INPUT);  // Pino do sensor de solo como entrada
    pinMode(relebombapino, OUTPUT);  // Pino da bomba como saída
    pinMode(relelampadapino, OUTPUT); // Pino da lâmpada como saída
    pinMode(releVentoinhaPino, OUTPUT); // Pino da ventoinha como saída
    pinMode(sensorsoloenergia, OUTPUT);  // Pino de controle do sensor como saída
    dht11.begin(); // Inicializa o sensor DHT11

    // Configura display LCD
    lcd.init();
    lcd.backlight();  // Liga o retroiluminado do LCD
    lcd.setCursor(0, 0);
    lcd.print("ESTUFA G.M - 2024");

    // Liga a lâmpada inicialmente
    digitalWrite(relelampadapino, HIGH);
    controlatempolampada = millis();

    // Ventoinha desligada inicialmente
    digitalWrite(releVentoinhaPino, HIGH);

    digitalWrite(relebombapino, LOW);
}

void loop() {
    unsigned long tempodosistema = millis();  // Obtém o tempo atual do sistema
    int valorsensorsolo = 0;
    float umidade = 0;
    float temperatura = 0;

    // Leitura do sensor de umidade do solo a cada 30 minutos
    if (tempodosistema - controlatemposensor >= intervalosensorsolo) {
        digitalWrite(sensorsoloenergia, HIGH); // Liga o sensor
        delay(tempoleiturasolo); // Espera o sensor estabilizar
        valorsensorsolo = analogRead(sensorsolopino); // Lê o valor do sensor
        digitalWrite(sensorsoloenergia, LOW); // Desliga o sensor
        controlatemposensor = tempodosistema;

        // Atualiza o LCD com a leitura do sensor de solo
        lcd.clear(); // Limpa o LCD antes de atualizar
        lcd.setCursor(0, 0);
        lcd.print("Umidade do Solo:");
        lcd.setCursor(0, 1);
        lcd.print(valorsensorsolo); // Exibe o valor da umidade do solo

        bool needsWatering = valorsensorsolo > umidademaximasolo;  // Verifica se precisa de água

        // Se o solo estiver muito seco, liga a bomba por 5 segundos
        if (needsWatering && (tempodosistema - controlatempobomba >= duracaobombaagua)) {
            digitalWrite(relebombapino, HIGH);  // Liga a bomba
            controlatempobomba = tempodosistema; // Marca o tempo de ativação da bomba
        }
    }

    // Desliga a bomba após 5 segundos de funcionamento
    if (tempodosistema - controlatempobomba >= duracaobombaagua) {
        digitalWrite(relebombapino, LOW);  // Desliga a bomba
    }

    // Leitura do sensor DHT11 a cada 2 segundos
    if (tempodosistema - controlatempodht11 >= intervaloleituradht11) {
        umidade = dht11.readHumidity();  // Lê a umidade do ar
        temperatura = dht11.readTemperature();  // Lê a temperatura do ar

        // Controle da ventoinha
        if (temperatura > temperaturaMaxima) {
            digitalWrite(releVentoinhaPino, LOW); // Liga a ventoinha
        } else if (temperatura <= 27.0) {
            digitalWrite(releVentoinhaPino, HIGH); // Desliga a ventoinha
        }

        // Atualiza o LCD com a leitura do DHT11
        lcd.setCursor(0, 2);
        lcd.print("Temp: ");
        lcd.print(temperatura);
        lcd.print((char)223); // Símbolo de grau Celsius
        lcd.print("C");

        lcd.setCursor(0, 3);
        lcd.print("Hum: ");
        lcd.print(umidade);
        lcd.print("%");

        controlatempodht11 = tempodosistema;
    }

    // Controle da lâmpada
    if (tempodosistema - controlatempolampada >= lampadacrecimenoliga && digitalRead(relelampadapino) == HIGH) {
        digitalWrite(relelampadapino, LOW); // Desliga a lâmpada
        controlatempolampada = tempodosistema;
    } else if (tempodosistema - controlatempolampada >= lampadacrescimentodesliga && digitalRead(relelampadapino) == LOW) {
        digitalWrite(relelampadapino, HIGH); // Liga a lâmpada
        controlatempolampada = tempodosistema;
    }
}
