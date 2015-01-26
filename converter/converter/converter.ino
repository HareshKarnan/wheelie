const int potPin = A5;
const int pwmPin = 14;
float voltage = A3;
float current = A4;
volatile int potVal = 0;
volatile int dutyCycle = 0;
float vol1,vol0,curr;
float power0=0;
float power1=0;
int baseduty=60;   // 23% duty initially
float voltdisplay=0;
float currdisplay=0;
float powerdisplay=0;
void setup()
{   Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(pwmPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(voltage,INPUT);
  pinMode(current,INPUT);
  analogFrequency(6000);
}

void loop()
{ potVal = analogRead(potPin);
//  float offset=(potVal/1024.0)*255;
   power1=0;
   vol1=0;
   for(int i=0;i<4;i++)     
  {
    vol1=analogRead(voltage);
    //voltdisplay=map(vol,0,1023,0,3.3);
    //voltdisplay=voltdisplay*12 ;   // resistors are 11k and 1k and drop taken across 1k;
    curr=analogRead(current);
    //currdisplay=map(curr, 505, 715, 2.5,3.425);     
    //currdisplay=currdisplay*0.185; // 0-5 vollts module giving 2.5v for 0A and 3.425V for 5A ;
    
    power1+=vol1*curr;
    //powerdisplay+=voltdisplay*currdisplay;
  }
  power1=power1/4;
//  powerdisplay=powerdisplay/4;
//  Serial.println(powerdisplay);
  if(power1>power0 and vol1<vol0)
  { 
    baseduty=baseduty--;
    dutyCycle=floor(baseduty);
  }
  else if (power0>power1)
  { 
    baseduty=baseduty--;
    dutyCycle=floor(baseduty);
  }
  
  power0=power1;
   vol0=vol1;
 if(dutyCycle>238)
  dutyCycle=238;
 else if(dutyCycle<50)
  dutyCycle=50;
  analogWrite(pwmPin, dutyCycle);
  delay(30);
}
