#include <ESP8266WiFi.h>
#include <ThingESP.h>


ThingESP8266 thing("MaximusVid", "LaKi", "123123123");

#define relay 0

unsigned long previousMillis = 0;
const long INTERVAL = 6000;  

void setup()
{
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  thing.SetWiFi("David", "dv290701");

  thing.initDevice();

}

String HandleResponse(String query)
{

  if (query == "nyalakan lampu otomatis") {
    digitalWrite(relay,LOW);
    return "sudah saya hidupkan lampunya -Lampu LaKi";
  }

  else if (query == "matikan lampu otomatis") {
    digitalWrite(relay, HIGH);
    return "sudah saya matikan lampunya -Lampu LaKi";
  }

  else if (query == "cek status lampu")
    return digitalRead(relay ) ? "lampu mati" : "lampu menyala";

  else if (query == "LaKi")
    return "KENAPA WOI !!!";

  else if (query == "command bot")
    return "nyalakan lampu otomatis | matikan lampu otomatis | cek status lampu | bot LaKi | terimakasih | ";
    
  else if (query == "terimakasih")
    return "sama-sama, terimakasih telah menggunakan fitur LaKi (Lampu Kita)";
  else return "command not available ( belum bisa disuruh yg kaya gitu )";

}

void loop()
{  
  thing.Handle();

}
