#define ppmA_pin 2
#define ppmB_pin 3

#define pwmA_pin 10
#define pwmB_pin 11

#define inA1_pin 4
#define inA2_pin 5
#define inB1_pin 6
#define inB2_pin 7
#define stby     8

int ppmA, ppmB, pwmA, pwmB;


void setup() {
  Serial.begin(115200);
  pinMode(ppmA_pin, INPUT);
  pinMode(ppmB_pin, INPUT);
  
  pinMode(pwmA_pin, OUTPUT);
  pinMode(pwmB_pin, OUTPUT);
  pinMode(inA1_pin, OUTPUT);
  pinMode(inA2_pin, OUTPUT);
  pinMode(inB1_pin, OUTPUT);
  pinMode(inB2_pin, OUTPUT);
  pinMode(stby, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(inA1_pin, HIGH);//set motorA direction to forward
  digitalWrite(inA2_pin, LOW);
  digitalWrite(inB1_pin, HIGH);//set motorB direction to forward
  digitalWrite(inB2_pin, LOW);
  digitalWrite(stby, LOW); //disable motors (if stby connected to TB6612 board)

}

void loop() {
 
  pwmA=0;
  pwmB=0;
  delay(10);
  ppmA = pulseIn(ppmA_pin,HIGH,25000);
  ppmB = pulseIn(ppmB_pin,HIGH,25000);
  delay(10);
  
  if(ppmA > 1100){
    pwmA = map(ppmA, 1100, 2000, 0, 255);
    Serial.print(ppmA);
    Serial.print("  :  ");
    Serial.println(pwmA);
    if(pwmA>=0){analogWrite(pwmA_pin, pwmA);}

  }

  if(ppmB > 1100){
    pwmB = map(ppmB, 1100, 2000, 0, 255);
    if(pwmB>=0){analogWrite(pwmB_pin, pwmB);}

  }
 

}
