String str="";    //每一个字符对应的Morse电码表示
void transform(int n) //转化函数，根据读取的ASCII码转化为Morse电码表示
{
  switch(n)
  {
    case 97:str="*-  ";break;//a
    case 98:str="-***";break;//b
    case 99:str="-*-*";break;//c
    case 100:str="-** ";break;//d
    case 101:str="*   ";break;//e
    case 102:str="**-*";break;//f
    case 103:str="--* ";break;//g
    case 104:str="****";break;//h
    case 105:str="**  ";break;//i
    case 106:str="*---";break;//j
    case 107:str="-*- ";break;//k
    case 108:str="*-**";break;//l
    case 109:str="--  ";break;//m
    case 110:str="-*  ";break;//n
    case 111:str="--- ";break;//o
    case 112:str="*--*";break;//p
    case 113:str="--*-";break;//q
    case 114:str="*-* ";break;//r
    case 115:str="*** ";break;//s
    case 116:str="-   ";break;//t
    case 117:str="**- ";break;//u
    case 118:str="***-";break;//v
    case 119:str="*-- ";break;//w
    case 120:str="-**-";break;//x
    case 121:str="-*--";break;//y
    case 122:str="--**";break;//z
    case 32:str="*-*-";break;//空格
    case 10:str="----";break;//回车
    default:break;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  // put your main code here, to run repeatedly:
  String morse="";
  int x=0;
  while(Serial.available()>0)
  {
    transform(Serial.read());   //对读取到的ASCII码进行转化
    morse.concat(str);          //将str添加到morse中去
    morse+=' ';                 //字符两两之间添加一个空格
    delay(10);                  //延迟10ms
    x=1;                        //标志
  }
  if(x==1)
  Serial.println(morse);
}
