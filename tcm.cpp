#include "TCM.h"
void  TCM::begin(int serialPort_){
	serialPort=serialPort_;
	switch(serialPort){
		case 0:
			Serial.begin(115200); break;
		case 1:
			Serial1.begin(115200); break;	
		case 2:
			Serial2.begin(115200); break;	
		case 3:
			Serial3.begin(115200); break;	
		default: break;
	}
}

boolean TCM::readData(){
	boolean read=false;
	int index=0;
	unsigned long initialTime=millis();
        
	while (millis()-initialTime<5){
		switch(serialPort){
			case 0:if(Serial.available()>0)
				dataTCM[index++]=Serial.read();
				break;
			case 1:if(Serial1.available()>0)
				dataTCM[index++]=Serial1.read();
				break;
			case 2:if(Serial2.available()>0)
				dataTCM[index++]=Serial2.read();
				break;
			case 3:if(Serial3.available()>0)
				dataTCM[index++]=Serial3.read();
				break;
		}	
	
	}
	index=0;
	if(index>0)  
	read=true;	
    //TCM set to send info in next order yaw,pitch,roll,temp
	 yaw=bytesToFloat(&dataTCM[5]);
	 pitch=bytesToFloat(&dataTCM[10]);
	 roll=bytesToFloat(&dataTCM[15]);
	 temp=bytesToFloat(&dataTCM[20]);
	 return read;
}
boolean TCM::requestData(){
	for(int i=0;i<5;i++)
switch(serialPort){
case 0: Serial.write(comando[i]);break;
case 1: Serial1.write(comando[i]);break;
case 2: Serial2.write(comando[i]);break;
case 3: Serial3.write(comando[i]);break;	
}
    return readData();
}
	

float TCM::bytesToFloat(unsigned char *data)
{
 float output;
  for(int i=0;i<4;i++)
    *((unsigned char*)(&output) +  (3-i) ) = *(data + i );
    return output;
}