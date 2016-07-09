#include <tcm.h>
TCM tcm;
void setup() {
  // put your setup code here, to run once:
tcm.begin(0);
}

void loop() {

tcm.requestData();
Serial.println();
Serial.print(tcm.yaw);Serial.print(" ");
Serial.print(tcm.pitch);Serial.print(" ");
Serial.print(tcm.roll);Serial.print(" ");
Serial.println(tcm.temp);
delay(10);
}
