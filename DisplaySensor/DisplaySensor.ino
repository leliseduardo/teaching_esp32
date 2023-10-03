/* 

    Autor: Eduardo Lelis e Liniker - PET Mecatrônica/BSI
    
    Sensor DHT11 e Display OLED - Exemplo de termometro utilizando o sensor DHT11 e o Display OLED

    Referências: https://blog.eletrogate.com/guia-completo-do-display-oled-parte-2-como-programar-3/
                 https://esp32io.com/tutorials/esp32-oled
                 https://www.blogdarobotica.com/2020/10/29/medindo-temperatura-e-umidade-usando-o-sensor-dht11/
                 

*/


                                                                    // Inclusão de bibliotecas
#include <Wire.h>                       
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>                                                    // Inclui a biblioteca DHT Sensor Library
#define DHTPIN 5                                                    // Pino digital 5 conectado ao DHT22
#define DHTTYPE DHT22                                               // DHT 22

DHT dht(DHTPIN, DHTTYPE);                                           // Inicializando o objeto dht do tipo DHT passando como parâmetro o pino (DHTPIN) e o tipo do sensor (DHTTYPE)

                                                                    // Configurações do oled
#define SCREEN_WIDTH 128                                            // OLED width,  in pixels
#define SCREEN_HEIGHT 64                                            // OLED height, in pixels

                                                                    
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);      // Criação de um objeto oled e conexão com a porta I2C

void setup() {
  Serial.begin(115200);                                             // Inicializa a comunicação serial
  dht.begin();                                                      // Inicializa o sensor DHT11

                                                                    // Inicializando oled oled e comunicação I2C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  delay(2000);                                                      // Espera 2 segundos para inicializar o oled
  oled.setCursor(0, 0);
}

void loop() {
  delay(2000);                                                      // Intervalo de dois segundos entre as medições

  float h = dht.readHumidity();                                     // Lê o valor da umidade e armazena na variável h do tipo float (aceita números com casas decimais)
  float t = dht.readTemperature();                                  // Lê o valor da temperatura e armazena na variável t do tipo float (aceita números com casas decimais)

  if (isnan(h) || isnan(t)) {                                       // Verifica se a umidade ou temperatura são ou não um número
    return;                                                         //Caso não seja um número retorna
  }

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);
  oled.println("Curso de ESP32");
  oled.setCursor(0, 20);
  oled.print("Temperatura: ");      
  oled.println(t);
  oled.setCursor(0, 30);
  oled.print("Umidade: ");      
  oled.println(h);
  oled.display();

  delay(500);
}
