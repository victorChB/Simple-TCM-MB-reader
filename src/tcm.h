

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define sizeTCMstring 26  //00 1A 05 04 18 p p p p 05 y y y y 19 r r r r 07 t t t t CRC CRC
class TCM {
  public:
	void begin(int serialPort_);
	boolean requestData();
	float yaw,pitch,roll,temp;
 private:
  char serialPort;
  boolean readData();
  float bytesToFloat(unsigned char *data);

  unsigned char comando[5]={0,5,4,0xBF,0x71};
  unsigned char dataTCM[sizeTCMstring];
};