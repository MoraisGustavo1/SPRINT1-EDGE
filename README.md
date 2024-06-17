# SPRINT1-EDGE
Descrição do Projeto
Este projeto consiste em um sistema de alerta de condições climáticas para corridas de Fórmula E.  Utilizando um sensor de temperatura e umidade DHT22 e um display LCD, o sistema alerta sobre condições climáticas adversas que podem impactar a segurança e o desempenho durante as corridas. LEDs de três cores (verde, azul e vermelho) são utilizados para fornecer alertas visuais e sonoros com base nas leituras do sensor.

## Componentes Utilizados
- Arduino Uno ou similar
- Sensor de temperatura e umidade DHT22
- Display LCD 16x2
- LEDs (verde, azul e vermelho)
- Resistores
- Jumpers e protoboard

## Bibliotecas Utilizadas
- LiquidCrystal
- DHT22
- DHT sensor library

## Funcionamento do Código
## Setup
- No setup, os pinos dos LEDs são configurados como saídas, o sensor DHT22 e o display LCD são inicializados e uma animação de texto é exibida no LCD.

## Loop Principal
- O loop principal alterna entre a medição de temperatura e umidade a cada 3 segundos, exibindo os valores no LCD e acionando os LEDs conforme as condições medidas.
  
## Como Utilizar
- Para dar vida ao projeto, inicie posicionando os componentes na protoboard. A montagem é livre mas caso queira seguir nossa configuração aqui está: ![image](https://github.com/MoraisGustavo1/SPRINT1-EDGE/assets/148806879/7868e2d0-bd72-4549-aeee-8df20e50b4a4)

- Carregue o código no Arduino usando a IDE do Arduino ou em algum simulador como o Wokwi.
- Abra o monitor serial para ver as leituras de temperatura e umidade.
- Observe os alertas no display LCD e os LEDs indicativos de condição climática.

## Links
- Simulação Wokwi: https://wokwi.com/projects/400618792890097665
- Vídeo Explicativo: https://www.youtube.com/watch?v=NZ84CJy3vLs

# Integrantes
- Gustavo Morais RM554972
- Leonardo Novaes RM554807
- Miguel Carmo RM557622
- Estevam Melo RM555124
- Carolina Ferraz RM86833
