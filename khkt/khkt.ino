#include <Servo.h>;
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position


const int trig = 7;  
const int echo = 4;    
int enbA=3;
int in1 = 5;       
int in2 = 6;        
int in3 = 9;        
int in4 = 10;  
int enbB=11;      
int dongcoservo = 8;   

int gioihan = 25;//khoảng cách nhận biết vật 
int i;
int x = 0;
unsigned long thoigian; 
int khoangcach;          
int khoangcachtrai, khoangcachphai;
int maxspeed=30;
void dithangcham();
void dokhoangcach();
void dithang(int duongdi);
void disangtrai();
void disangphai();
void dilui();
void resetdongco();
void quaycbsangphai();
void quaycbsangtrai();
void setup() {
  // put your setup code here, to run once:
  myservo.attach(dongcoservo); 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);   

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enbA, LOW);
  digitalWrite(enbB, LOW);
  myservo.write(90);
  delay(500);
  Serial.begin(9600);


}










void loop()
{
  khoangcach = 0;
  dokhoangcach();
  Serial.println(khoangcach);
  if (khoangcach > gioihan || khoangcach == 0)
  {
      dithang();
      Serial.println("Di toi");
  }
  else
  {
    dithangcham();delay(200);
    dunglai(); delay(500);
    quaycbsangtrai();
    dokhoangcach();
  
    khoangcachtrai = khoangcach;
    quaycbsangphai();
    dokhoangcach();

    khoangcachphai = khoangcach;
    if (khoangcachphai < 20 && khoangcachtrai < 20) {
      dilui();delay(300);dunglai();delay(300);
      
      
    }
    else
    {
      if (khoangcachphai > khoangcachtrai)
      { dilui();delay(300);dunglai();delay(300); 
        dithangcham() ; delay(2000);
        dilui() ; delay(200);    
        disangtrai(); delay(700);
      
      
        
      }
      if (khoangcachphai < khoangcachtrai)
      { dilui();delay(300);dunglai();delay(300);
      dithangcham() ; delay(2000);
        disangphai();delay(700);
        Serial.println("Di sang trai");
        delay(400);dunglai();delay(300);
      }
    }
  }

}





























void dithangcham(){
  analogWrite(enbA, 0);
  analogWrite(enbB, 0);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}

void dithang()
{
  analogWrite(enbA, 50);
  analogWrite(enbB, 50);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);


}
void dunglai(){
  analogWrite(enbA, 0);
  analogWrite(enbB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }

void disangphai()
{
  analogWrite(enbA, 200);
  analogWrite(enbB, 50);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);


}
void disangtrai()
{
  analogWrite(enbA, 50);
  analogWrite(enbB, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}

void dilui()
{
  analogWrite(enbA, 100);
  analogWrite(enbB, 100);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}



void dokhoangcach()
{

  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);  
  delayMicroseconds(15); 
  digitalWrite(trig, LOW); 


  // Đo độ rộng xung HIGH ở chân echo.
  thoigian = pulseIn(echo, HIGH);

  khoangcach = thoigian / 2 / 29.412;

}


void quaycbsangtrai()
{
  myservo.write(135);              // tell servo to go to position in variable 'pos'
  delay(600);
  dokhoangcach();
  myservo.write(90);              // tell servo to go to position in variable 'pos'
}
void quaycbsangphai()
{
  myservo.write(45);              // tell servo to go to position in variable 'pos'
  delay(600);
  dokhoangcach();
  myservo.write(90);              // tell servo to go to position in variable 'pos'
}
void resetservo()
{
  myservo.write(90);
}
