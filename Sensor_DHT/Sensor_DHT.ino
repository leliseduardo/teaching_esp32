/* 

    Autor: Eduardo Lelis e Liniker - PET Mecatrônica/BSI
    
    Sensor DHT11 - Exemplo de código para utilizar este sensor com o ESP32.

    Referência: https://www.blogdarobotica.com/2020/10/29/medindo-temperatura-e-umidade-usando-o-sensor-dht11/

*/


#include <DHT.h>                                  // Inclui a biblioteca DHT Sensor Library
#define DHTPIN 5                                  // Pino digital 5 conectado ao DHT22
#define DHTTYPE DHT22                             // DHT 22

DHT dht(DHTPIN, DHTTYPE);                         // Inicializando o objeto dht do tipo DHT passando como parâmetro o pino (DHTPIN) e o tipo do sensor (DHTTYPE)

void setup() {
  Serial.begin(115200);                           // Inicializa a comunicação serial
  dht.begin();                                    // Inicializa o sensor DHT22
}

void loop() {
  delay(2000);                                    // Intervalo de dois segundos entre as medições

  float h = dht.readHumidity();                   // Lê o valor da umidade e armazena na variável h do tipo float (aceita números com casas decimais)
  float t = dht.readTemperature();                // Lê o valor da temperatura e armazena na variável t do tipo float (aceita números com casas decimais)

  if (isnan(h) || isnan(t)) {                     // Verifica se a umidade ou temperatura são ou não um número
    return;                                       //Caso não seja um número retorna
  }

  Serial.print("Umidade: ");                      // Imprime no monitor serial a mensagem "Umidade: "
  Serial.print(h);                                // Imprime na serial o valor da umidade
  Serial.println("%");                            // Imprime na serial o caractere "%" e salta para a próxima linha
  Serial.print("Temperatura: ");                  // Imprime no monitor serial a mensagem "Temperatura: "
  Serial.print(t);                                // Imprime na serial o valor da temperatura
  Serial.println("°C ");                          // Imprime no monitor serial "ºC" e salta para a próxima linha
}
