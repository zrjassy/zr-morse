void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  pinMode(2,OUTPUT);  //右下
  pinMode(3,OUTPUT);  //左下
  pinMode(7,OUTPUT);  //右上
  pinMode(8,OUTPUT);  //左上
}


int income=0;
void loop()
{
  if(Serial.available()>0)
  {
    income=Serial.read();
    switch(income)
    {
      case 'f':forward();break;
      case 'b':backward();break;
      case 'r':right();break;
      case 'l':left();break;
      case 's':stop();break;
      default:break;
    }
  }  
}

void forward()
{
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}

void backward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void right()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}
void left()
{
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}
void stop()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
