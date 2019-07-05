void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  Serial.begin(9600);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  
}

int flag=0;   //标志
int i=0,j=0;
int a[4];

void loop()
{
  while(Serial.available()>0)
  {
    reset();    //重置，将四个数码管都为0
    flag=1;
    a[i]=Serial.read();   //将串口通信中传递的值放入数组中
    delay(2);
    i++;
  }
  if(flag==1)
  {
    flag=0;
    while(i!=0)
    {
      digitalWrite(i+7,LOW);    
      int figure=a[j]-int('0');
      showNumber(figure);
      digitalWrite(i+7,HIGH);
      j++;i--;
    }
    j=0;
  }
  
}

void showNumber(int n)
{
  if(n&1)
  digitalWrite(2,HIGH);
  else
  digitalWrite(2,LOW);

  if((n>>1)&1)
  digitalWrite(3,HIGH);
  else
  digitalWrite(3,LOW);  

  if((n>>2)&1)
  digitalWrite(4,HIGH);
  else
  digitalWrite(4,LOW);

  if((n>>3)&1)
  digitalWrite(5,HIGH);
  else
  digitalWrite(5,LOW);
 
}

void reset()
{
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
}
