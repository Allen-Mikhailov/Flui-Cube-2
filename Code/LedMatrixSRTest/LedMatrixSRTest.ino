#include "ShiftRegister.h"

ShiftRegister reg(16);



int rows[] = {7, 2, 8, 4, 15, 9, 14, 11};
int columns[] = {3, 13, 12, 6, 10, 5, 1, 0};

int frame = 0;
char values[16];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  while (!Serial)
    delay(10);
  Serial.println("Starting up");
  
  reg.SER_PIN = 19;
  reg.OE_PIN = 4;
  reg.RCLK_PIN = 23;
  reg.SRCLK_PIN = 18;
  reg.SRCLR_PIN = 21;

  pinMode(16, INPUT);

  reg.setup();

}

void loop() {
  // put your main code here, to run repeatedly:

  frame++;

  int x = frame%8;
  int y = (frame/8)%8;

  if ((x+y < 8))
    return;

  for (int i = 0; i < 8; i++)
  {
      
      values[rows[i]] = x == i;
      values[columns[i]] = 1 - (y == i);
  }
  reg.setPins(values);

  // delay(100);
  

  // Serial.println(frame);
  // Serial.println(digitalRead(16));

  if (frame%100==0)
    Serial.println(frame);
}
