#include "DHT.h"

#define pinoA2 A2 //define qual pino do Arduino será usado.

#define DHTTYPE DHT11 //define qual tipo de DHT será usado (11, 21 ou 22)

//Inicia o sensor DHT
DHT dht(pinoA2, DHTTYPE); 

void setup(){
  Serial.begin(9600); //Inicializa a Serial
  delay(2000); //Intervalo de 2 segundos antes de começar
  Serial.println(F("Sistema inicializado!"));
  dht.begin();
}

void loop(){
  delay(2000);

  //Definição das variáveis de humidade e temperatura.
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Se necessário, inclua essa variável (lê temperatura em Fahrenheit)
  //float f = dht.readTemperature(true);

  //Verifica se houve erros e tenta novamente.
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Houve um erro na leitura do sensor!"));
    return;
  }

  /* Inclua se quiser adicionar Fahrenheit, remova o de cima
   if (isnan(h) || isnan(t)) || isnan(f) {
    Serial.println(F("Houve um erro na leitura do sensor!"));
    return;
  }
  */

  //Imprime o texto na Serial
  Serial.print("Umidade: "); 
  Serial.print(h);
  Serial.print("%"); 

  Serial.print(" | Temperatura: ");
  Serial.print(t);
  Serial.println("°C \n");
  delay(2000); //Intervalo de 2 segundos
}
