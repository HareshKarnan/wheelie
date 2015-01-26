int error=0,drive;
int kp=3;

void setup()
{
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
}

int sample()
{
    return (analogRead(A2)-analogRead(A3));
}

void move(int drive)
{
    if(drive>0)
    {
      //forward
      digitalWrite(11,1);
      digitalWrite(12,0);
      analogWrite(14,abs(drive));
    }
    else
    {
      //backward
      digitalWrite(11,0);
      digitalWrite(12,1);
      analogWrite(14,abs(drive));
    }
}

void loop()
{
  drive = 50;
  error=sample();
  drive += error*kp ;
  Serial.println(drive);
  if(drive >255)
    drive = 255 ; //cap it at 255
  move(drive);
}
