programme 1
#include <Wire.h>
#include <rgb_lcd.h>
#include <DHT.h>
#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float temp;
float hum;
rgb_lcd lcd;

void setup() 
{
    Serial.begin(9600);
    dht.begin();
    
    lcd.begin(16, 2);
}

void loop() 
{   
    breath(REG_RED);
    breath(REG_GREEN);
    breath(REG_BLUE);
    
    hum = dht.readHumidity();
    temp = dht.readTemperature();
    
  
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(hum);
  lcd.print("%");
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C");
}


void breath(unsigned char color)
{

    for(int i=0; i<255; i++)
    {
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
    for(int i=254; i>=0; i--)
    {
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
}
Login - Tinkercad
Cahier des charges
