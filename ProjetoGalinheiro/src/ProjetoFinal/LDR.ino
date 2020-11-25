void LDR() 
{
  Leitura = analogRead(portaLDR); // leitura da tensão no pino analogico A0
  VoltageLDR = Leitura * (5.0/1024); // calculo da tensão no LDR
  Serial.print("Leitura sensor LDR = "); // imprime no monitor serial
  Serial.println(VoltageLDR); // imprime a tensão do LDR
  
  if (VoltageLDR > 15) // se a tensão LDR maior do que limiar
    digitalWrite(ledLDR, HIGH); // liga LED com 5V
  else // senão a tensão LDR < limiar
    digitalWrite(ledLDR, LOW); // desliga LED com 0V
  delay(500);
 }
