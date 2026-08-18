# Estufa Automatizada com Arduino

Projeto de automação de uma estufa desenvolvido com foco no monitoramento e controle automático de variáveis ambientais importantes para o cultivo.

A proposta do sistema é utilizar sensores e atuadores para acompanhar as condições internas da estufa e acionar dispositivos automaticamente sempre que necessário.

> Projeto desenvolvido como Trabalho de Conclusão de Curso (TCC), com foco em automação, sistemas embarcados e aplicação prática em ambiente agrícola.

## Sumário

- [Sobre o projeto](#sobre-o-projeto)
- [Problema e solução](#problema-e-solução)
- [Objetivos](#objetivos)
- [Funcionamento do sistema](#funcionamento-do-sistema)
- [Arquitetura do projeto](#arquitetura-do-projeto)
- [Componentes utilizados](#componentes-utilizados)
- [Tecnologias utilizadas](#tecnologias-utilizadas)
- [Como executar](#como-executar)
- [Estrutura do repositório](#estrutura-do-repositório)
- [Resultados esperados](#resultados-esperados)
- [Limitações](#limitações)
- [Melhorias futuras](#melhorias-futuras)
- [Documentação acadêmica](#documentação-acadêmica)
- [Autor](#autor)
- [Licença](#licença)

## Sobre o projeto

O cultivo em estufas exige controle constante de variáveis como temperatura, umidade e ventilação. Quando esse processo depende apenas de intervenção manual, podem ocorrer atrasos, falhas de monitoramento e dificuldade para manter condições ideais por longos períodos.

Este projeto propõe uma solução automatizada utilizando Arduino, sensores e atuadores para monitorar o ambiente da estufa e tomar decisões de controle com base em regras previamente definidas.

O sistema foi desenvolvido como aplicação prática de conceitos de automação, eletrônica e programação embarcada.

## Problema e solução

### Problema

Ambientes de cultivo protegidos precisam manter condições adequadas para favorecer o desenvolvimento das plantas. O monitoramento manual dessas variáveis pode ser insuficiente, especialmente quando há necessidade de resposta rápida a mudanças ambientais.

### Solução

A proposta do projeto é automatizar o ambiente da estufa por meio de:

- Coleta de dados por sensores.
- Processamento das leituras por um microcontrolador.
- Acionamento automático de dispositivos.
- Controle das condições internas da estufa.
- Redução da dependência de intervenção manual.
- Maior consistência no ambiente de cultivo.

## Objetivos

- Desenvolver uma estufa automatizada de baixo custo.
- Monitorar variáveis ambientais relevantes.
- Automatizar o acionamento de dispositivos.
- Aplicar conceitos de Arduino e eletrônica embarcada.
- Construir um protótipo funcional.
- Integrar sensores, lógica de controle e atuadores.
- Documentar o desenvolvimento técnico e acadêmico do projeto.

## Funcionamento do sistema

O sistema opera a partir de um ciclo contínuo de leitura, decisão e ação:

1. Os sensores coletam dados do ambiente.
2. O Arduino processa as informações recebidas.
3. O programa compara os valores com limites previamente definidos.
4. Quando necessário, os atuadores são acionados.
5. O ambiente é ajustado automaticamente.
6. O sistema continua monitorando as variáveis em tempo real.

Fluxo simplificado:

```text
Sensores
   |
   v
Leitura de dados
   |
   v
Processamento no Arduino
   |
   v
Comparação com limites definidos
   |
   +-----------------------------+
   |                             |
   v                             v
Condição normal             Condição fora do ideal
   |                             |
   |                        Acionamento de atuadores
   |                             |
   +------------- Retorno ao monitoramento -----------+
```

## Arquitetura do projeto

A arquitetura geral do sistema pode ser descrita em três camadas:

### 1. Entrada

Responsável por captar informações do ambiente:

- Temperatura.
- Umidade.
- Luminosidade.
- Umidade do solo.
- Outras variáveis, conforme o protótipo.

### 2. Controle

Responsável por processar os dados e executar a lógica de decisão:

- Arduino.
- Regras programadas no firmware.
- Definição de limites e condições de acionamento.

### 3. Saída

Responsável por atuar no ambiente:

- Ventiladores.
- Bombas d’água.
- Relés.
- Iluminação.
- Alarmes ou indicadores.

> Ajuste essa lista de acordo com os sensores e atuadores realmente utilizados no seu projeto.

## Componentes utilizados

A lista abaixo é uma sugestão baseada no tipo de projeto. Atualize-a conforme os componentes reais presentes no TCC e no código:

- Arduino Uno, Mega ou compatível.
- Sensor de temperatura e umidade.
- Sensor de umidade do solo.
- Sensor de luminosidade, se aplicável.
- Módulo relé.
- Ventilador ou cooler.
- Bomba d’água.
- Fonte de alimentação.
- Protoboard.
- Cabos jumper.
- LEDs indicadores.
- Estrutura da estufa protótipo.

## Tecnologias utilizadas

- Arduino IDE.
- Linguagem C/C++ para Arduino.
- Sensores ambientais.
- Atuadores elétricos.
- Lógica de controle automático.
- Sistemas embarcados.
- Git e GitHub.

## Como executar

### Pré-requisitos

- Arduino IDE instalada.
- Placa Arduino compatível.
- Circuito montado com os sensores e atuadores.
- Bibliotecas necessárias instaladas.
- Código-fonte do projeto.

### Clonar o repositório

```bash
git clone https://github.com/GabrielCustodio1/Projeto-TCC-Estufa-Automatizada.git
cd Projeto-TCC-Estufa-Automatizada
```

### Executar o projeto

1. Abra o arquivo `Projeto_TCC_Estufa_Automatizada.ino` na Arduino IDE.
2. Verifique se todas as bibliotecas necessárias estão instaladas.
3. Conecte a placa Arduino ao computador.
4. Selecione a placa correta na Arduino IDE.
5. Selecione a porta serial correspondente.
6. Compile o código.
7. Faça o upload para a placa.
8. Monitore o funcionamento do sistema.
9. Utilize o Monitor Serial, caso o código envie leituras ou mensagens de status.

## Estrutura do repositório

```text
Projeto-TCC-Estufa-Automatizada/
├── Leia-me.TXT
├── Projeto_TCC_Estufa_Automatizada.ino
└── TCC_Gabriel_Custodio_Matheus_Rosa.pdf
```

### `Leia-me.TXT`

Arquivo com informações introdutórias ou instruções de uso do projeto.

### `Projeto_TCC_Estufa_Automatizada.ino`

Código principal do sistema embarcado responsável por monitorar os sensores e controlar os atuadores.

### `TCC_Gabriel_Custodio_Matheus_Rosa.pdf`

Documento acadêmico com descrição detalhada do problema, fundamentação teórica, metodologia, implementação e resultados do projeto.

## Resultados esperados

Com a execução correta do projeto, espera-se que o sistema:

- Monitore o ambiente em tempo real.
- Detecte condições fora do intervalo desejado.
- Acione automaticamente os dispositivos configurados.
- Reduza a necessidade de intervenção manual.
- Contribua para maior estabilidade das condições da estufa.

Exemplos de resultados que podem ser documentados no README:

- Leituras médias obtidas.
- Tempo de resposta do sistema.
- Faixas de temperatura e umidade controladas.
- Eficiência do acionamento automático.
- Testes realizados no protótipo.

> Os resultados reais devem ser extraídos do TCC e adicionados aqui de forma objetiva.

## Limitações

Este projeto representa um protótipo acadêmico e pode apresentar limitações como:

- Dependência de sensores de baixo custo.
- Precisão limitada nas medições.
- Ausência de conectividade remota.
- Dependência de alimentação estável.
- Controle baseado em limiares simples.
- Escalabilidade limitada para aplicações maiores.
- Necessidade de calibração dos sensores.
- Resistência limitada a ambientes agressivos, dependendo da montagem.

## Melhorias futuras

- Adicionar conectividade Wi-Fi ou Bluetooth.
- Criar dashboard para monitoramento remoto.
- Registrar dados em banco ou nuvem.
- Adicionar alertas em tempo real.
- Implementar controle por aplicativo.
- Melhorar a precisão com sensores mais robustos.
- Integrar múltiplas zonas de controle.
- Adicionar histórico de leituras.
- Criar uma interface local com display LCD ou OLED.
- Implementar controle preditivo ou regras mais avançadas.

## Documentação acadêmica

Este repositório inclui o documento final do TCC em PDF, que pode ser utilizado para consultar:

- Fundamentação teórica.
- Requisitos do projeto.
- Componentes utilizados.
- Metodologia de desenvolvimento.
- Arquitetura do sistema.
- Resultados e conclusões acadêmicas.

Se desejar, o arquivo PDF pode ser movido para uma pasta específica, como:

```text
docs/
```

Exemplo:

```text
Projeto-TCC-Estufa-Automatizada/
├── README.md
├── src/
│   └── Projeto_TCC_Estufa_Automatizada.ino
└── docs/
    └── TCC_Gabriel_Custodio_Matheus_Rosa.pdf
```

## Demonstração

Adicione fotos do protótipo, do circuito e da estrutura da estufa:

```markdown

```

Também vale incluir:

- Foto do circuito montado.
- Foto da estufa em funcionamento.
- Diagrama de blocos.
- Vídeo de demonstração do sistema.

## Autor

Desenvolvido por **Gabriel Custódio** e **Matheus Rosa**.

- GitHub: [GabrielCustodio1](https://github.com/GabrielCustodio1)
- Repositório: [Projeto-TCC-Estufa-Automatizada](https://github.com/GabrielCustodio1/Projeto-TCC-Estufa-Automatizada)

## Licença

Este projeto foi desenvolvido para fins acadêmicos e educacionais.

Caso o código, o documento ou a estrutura do projeto sejam reutilizados, recomenda-se manter os créditos aos autores e verificar a licença que será adotada para o repositório.
