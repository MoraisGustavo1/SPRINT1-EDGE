// Bibliotecas necessárias para o sensor DHT e o display LCD
#include <DHT.h>
#include <LiquidCrystal.h>

// Instancia o sensor DHT na porta 13, especificando o modelo DHT22
DHT dht(13, DHT22);

// Define as portas dos LEDs
#define LED_AZUL 9
#define LED_VERDE 8
#define LED_VERMELHO 7

// Define as portas do display LCD
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

// Variável para contar o tempo em milissegundos
long tempo = 0;

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  // Inicializa o sensor DHT
  dht.begin();

  // Inicializa o display LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);

  // Inicializa a comunicação serial
  Serial.begin(9600);

  // Exibe uma animação de texto no display
  animateText("     DEVIN", 0);
}

void loop() {
  // Chama a função para medir e exibir a temperatura, depois espera 3 segundos
  temp();
  delay(3000);

  // Chama a função para medir e exibir a umidade, depois espera 3 segundos
  umidade();
  delay(3000);
}

// Funções para ligar os LEDs e desligar os demais
void ligarAzul() {
  digitalWrite(LED_AZUL, HIGH);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, LOW);
}

void ligarVerde() {
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_VERMELHO, LOW);
}

void ligarVermelho() {
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
}

// Função para medir e exibir a temperatura
void temp() {
  // Variáveis para armazenar a soma e a média da temperatura
  float tempSoma = 0;
  float temperatura = dht.readTemperature(); // Lê a temperatura do sensor

  // Verifica se 1 segundo se passou desde a última medição
  if (millis() >= tempo + 1000) {
    for (int i = 0; i < 5; i++) { // Realiza 5 medições
      tempSoma += temperatura; // Soma a temperatura lida
      delay(1000); // Espera 1 segundo entre as medições
    }
  }

  float tempMedia = tempSoma / 5; // Calcula a média das temperaturas medidas
  Serial.print("Temperatura = ");
  Serial.println(tempMedia); // Exibe a temperatura média no monitor serial

  // Condicionais para verificar a faixa da temperatura
  if (tempMedia >= 15 && tempMedia <= 30) {
    // Temperatura dentro da faixa ideal
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp OK!");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(tempMedia);
    lcd.print("C");
    ligarVerde();
  } else if (tempMedia > 30) {
    // Temperatura alta
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp Alta!");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cuidado com");
    lcd.setCursor(0, 1);
    lcd.print("Superaquecimento");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp = ");
    lcd.print(tempMedia);
    lcd.print("C");
    delay(2000);

    ligarVermelho();
  } else {
    // Temperatura baixa
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp Baixa!");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cuidado com");
    lcd.setCursor(0, 1);
    lcd.print("Mudanca de clima");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp = ");
    lcd.print(tempMedia);
    lcd.print("C");
    delay(2000);

    ligarAzul();
  }
}

// Função para medir e exibir a umidade
void umidade() {
  // Variáveis para armazenar a soma e a média da umidade
  float umidadeSoma = 0;
  float umidade = dht.readHumidity(); // Lê a umidade do sensor

  // Verifica se 1 segundo se passou desde a última medição
  if (millis() >= tempo + 1000) {
    for (int i = 0; i < 5; i++) { // Realiza 5 medições
      umidadeSoma += umidade; // Soma a umidade lida
      delay(1000); // Espera 1 segundo entre as medições
    }
  }

  float umiMedia = umidadeSoma / 5; // Calcula a média das umidades medidas
  Serial.print("Umidade = ");
  Serial.println(umiMedia); // Exibe a umidade média no monitor serial

  // Condicionais para verificar a faixa da umidade
  if (umiMedia >= 40 && umiMedia <= 70) {
    // Umidade dentro da faixa ideal
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade OK!");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade = ");
    lcd.print(umiMedia);
    lcd.print("%");
    delay(2000);

    ligarVerde();
  } else if (umiMedia > 70) {
    // Umidade alta
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade alta!");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cuidado");
    lcd.setCursor(0, 1);
    lcd.print("com chuvas!");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade = ");
    lcd.print(umiMedia);
    lcd.print("%");
    delay(2000);

    ligarVermelho();
  } else {
    // Umidade baixa
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade baixa!");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cuidado");
    lcd.setCursor(0, 1);
    lcd.print("clima arido");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umidade = ");
    lcd.print(umiMedia);
    lcd.print("%");
    delay(2000);

    ligarAzul();
  }
}

// Função para animar o texto no display LCD
void animateText(String text, int row) {
  for (int i = 0; i < text.length(); i++) {
    lcd.setCursor(i, row); // Define a posição do cursor no LCD
    lcd.print(text[i]); // Imprime um caractere por vez
    delay(300); // Espera 300 milissegundos
  }
  delay(1500); // Espera 1,5 segundos antes de limpar o display
  lcd.clear(); // Limpa o display
}
