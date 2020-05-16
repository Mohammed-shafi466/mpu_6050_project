 #include<Wire.h>

const int MPU6050_addr=0x68;

int16_t AccX,AccY,AccZ;
int AX=0,AY=0,AZ=0;
int p8=8,p9=9,p10=10;
void setup(){
  
  Wire.begin();

  Wire.beginTransmission(MPU6050_addr);

  Wire.write(0x6B);

  Wire.write(0);

  Wire.endTransmission(true);

  Serial.begin(9600);
  pinMode(p8,OUTPUT);
  pinMode(p9,OUTPUT);
  pinMode(p10,OUTPUT);

}

void loop(){

  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,6,true);
  AccX=Wire.read()<<8|Wire.read();
  if (AX != AccX/16384)
  {
    digitalWrite(p8,HIGH);
    }
    else{
      digitalWrite(p8,LOW);
      }
  AX=AccX/16384;
  
  AccY=Wire.read()<<8|Wire.read();
    if (AY != AccY/16384)
  {
    digitalWrite(p9,HIGH);
    }
    else{
      digitalWrite(p9,LOW);
      }
  AY=AccY/16384;
  AccZ=Wire.read()<<8|Wire.read();
    if (AZ != AccZ/16384)
  {
    digitalWrite(p10,HIGH);
    }
    else{
      digitalWrite(p10,LOW);
      }
  AZ=AccZ/16384;
  Serial.print(" || AccX = "); Serial.print(AX);
  Serial.print(" || AccY = "); Serial.print(AY);
  Serial.print(" || AccZ = "); Serial.println(AZ);
  delay(100);
}
