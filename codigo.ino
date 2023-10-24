#include <dht.h> //inlcui a biblioteca dht

const int pinoDHT11 = A2; //pino analógios utilizado pelo DHT11

dht DHT; //variável do tipo DHT

void setup(){
  Serial.begin(9600); //inicializa a serial
  delay(2000); //intervalo de 2 segundos antes de iniciar
}

void loop(){
  DHT.read11(pinoDHT11); //lé as informações do sensor
  Serial.print("Umidade: "); //imprime o texto na serial
  Serial.print(DHT.humidity); //imprime na serial o valor de umidade medido
  Serial.print("%"); //escreve o texto em seguida
  Serial.print(" / Temperatura: "); //imprime o texto na serial
  Serial.print(DHT.temperature, 0); //imprime na serial o valor de umidade medido e remove a parte decimal
  Serial.println("*C"); //imprime o texto na serial
  delay(2000); //intervalo de 2 segundos (não diminuir esse valor)
}
