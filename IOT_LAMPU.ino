#include "CTBot.h"
CTBot robot;
int relay=0;

void setup() {
  Serial.begin(115200);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  robot.wifiConnect("David", "dv290701");
  robot.setTelegramToken("2055046520:AAFgX9bGC2JEuDuSem4AL0nnYhINN4Taz0o");
  if(robot.testConnection())
  Serial.println("Terhubung!");
  else
  Serial.println("Error!");

}

void loop() {
  TBMessage pesan;

  if(robot.getNewMessage(pesan)){
    Serial.print("Ada pesan Masuk : ");
    Serial.println(pesan.text);
    if(pesan.text.equalsIgnoreCase("RELAY ON")){
      digitalWrite(relay,LOW);
      robot.sendMessage(pesan.sender.id,"Relay Menyala");
    }
    else if(pesan.text.equalsIgnoreCase("RELAY OFF")){
      digitalWrite(relay,HIGH);
      robot.sendMessage(pesan.sender.id,"Relay Padam");
    }
    else{
      String balas;
      balas="Maaf, perintahnya salah. Coba kirim RELAY ON atau RELAY OFF.";
      robot.sendMessage(pesan.sender.id,balas);
    }
  }

}
