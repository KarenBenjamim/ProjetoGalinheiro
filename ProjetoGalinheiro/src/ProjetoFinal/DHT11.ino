void DHT(){
  delay(delayMS); // atraso entre as medições
  sensors_event_t event; // inicializa o evento da Temperatura
  
  dht.temperature().getEvent(&event); // faz a leitura da Temperatura
  
  temp = event.temperature;
  
   if (isnan(event.temperature)) // se algum erro na leitura
  {
  Serial.println("Erro na leitura da Temperatura!");
  }
  
  else // senão
  {

  Serial.print("Temperatura: "); // imprime a Temperatura
  Serial.print(event.temperature);
  Serial.println(" *C");
  }
  
  dht.humidity().getEvent(&event); // faz a leitura de umidade]
  
  umi=event.relative_humidity;
  
  if (isnan(event.relative_humidity)) // se algum erro na leitura
  {
    Serial.println("Erro na leitura da Umidade!");
  }
  
  else // senão
  {
    Serial.print("Umidade: "); // imprime a Umidade
    Serial.print(event.relative_humidity);
    Serial.println(" %");
  }  
  
  if (event.temperature < 30.00 ) // se a tensão LDR maior do que limiar
  {
    digitalWrite(ledHDT, HIGH); // liga LED com 5V
  }
  else // senão a tensão LDR < limiar
  {
    digitalWrite(ledHDT, LOW); // desliga LED com 0V
  }
  delay(500); // atraso de 500 milisegundos 
}
