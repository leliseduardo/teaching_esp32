/*
      
      Autor: Eduardo Lelis e Liniker - PET Mecatrônica/BSI
    
      Display OLED - Exemplo de código para utilizar o display OLED.

      Referências: https://blog.eletrogate.com/guia-completo-do-display-oled-parte-2-como-programar-3/
                   https://esp32io.com/tutorials/esp32-oled
  
      SCL: Pino 22
      SDA: Pino 21
 
 */

                                                                    // Inclusão de bibliotecas
#include <Wire.h>                       
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

                                                                    // Configurações do display
#define SCREEN_WIDTH 128                                            // OLED width,  in pixels
#define SCREEN_HEIGHT 64                                            // OLED height, in pixels

                                                                    // Criação de um objeto display e conexão com a porta I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

                                                                    // Inicializando display oled e comunicação I2C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  delay(2000);                                                      // Espera 2 segundos para inicializar o display
  oled.setCursor(0, 0);
}

void loop() {                                                       // Escrita no display
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);
  oled.println("Curso de ESP32");
  oled.setCursor(0,28); 
  oled.println("Hello World!");   
  oled.display();
  oled.startscrollleft(0x00, 0x0f); 
  delay(7000);
  oled.stopscroll();
  delay(1000);
}
