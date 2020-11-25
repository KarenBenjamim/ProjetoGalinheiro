 void LCD(){  

  lcd.setCursor(0, 0);
    if (isnan(temp)){
     lcd.println("Erro na leitura da Temperatura!");
    }
    else 
    {  
      lcd.print("Temp: "); // imprime a Temperatura
      lcd.print(temp);
      lcd.println(" *C  ");
    }
  lcd.setCursor(1, 1);
  if (isnan(umi)){
    lcd.println("Erro na leitura da Umidade!");
  }
  else
  {
    lcd.print("Umi: "); // imprime a Umidade
    lcd.print(umi);
    lcd.println(" %   ");
  }
  
 }
