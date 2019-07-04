void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);     //设置2,3,4,5对应CD4211的端口1,2,3,4
  pinMode(6,OUTPUT);     //设置6对应CD4211的端口 锁存启用
  Serial.begin(9600);    //设置波特率
}
int income=0;
void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  {
    income=Serial.read();   
    digitalWrite(6,LOW);
    if(income>='0'&&income<='9')
    {
      income=income-int('0');
      //Serial.println(income,DEC);   //调试观察income的值
      show(income);                   //使数码管显示income值
    } 
    digitalWrite(6,HIGH);   
  }
}

void show(int n)
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
