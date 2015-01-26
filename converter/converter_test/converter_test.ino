const int potPin = A5;
const int pwmPin = 14;
float voltage = A3;
float current = A4;
volatile int potVal = 0;
volatile int dutyCycle = 0;
float vol,curr;
float power0=0;
float power1=0;
int baseduty=50;
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
{
  potVal = analogRead(potPin);
  float offset=(potVal/1024.0) *255;
  dutyCycle=floor(offset);
  analogWrite(pwmPin, dutyCycle);
  delay(60);
}
