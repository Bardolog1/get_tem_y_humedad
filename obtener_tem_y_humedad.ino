#include <DHT.h>   
#include <DHT_U.h>
#include <SoftwareSerial.h>


int SENSOR = 2;    
float temp, temp_f, hume;

DHT dht(SENSOR, DHT11);  
SoftwareSerial bt(10, 11);
        
void setup(){
  Serial.begin(9600);   
  Serial.println("Listo");
  bt.begin(38400);
  dht.begin();     
}

void loop(){
  if( bt.available())      //lee bt y envia a monitor
  Serial.write(bt.read());

  if(Serial.available())   // lee monitor y envia a bt
  bt.write(Serial.read());
  
  temp=dht.readTemperature();  
  temp_f=dht.readTemperature(true);  
  hume = dht.readHumidity();   
  Serial.println("Temperatura °C: "+String(temp)+" Temperatura °F: "+String(temp_f)+" Humedad: "+String(hume));  // escritura en monitor serial de los valores
  delay(5000);
}
