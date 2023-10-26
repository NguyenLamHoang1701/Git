int relay = 6 ;
int trig = 9 ;
int echo = 10;

int thoigian;
int khoangcach;  


void setup() {
  pinMode(relay , OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);  
  Serial.begin(9600);
}

void loop() {
  Serial.println(khoangcach);

  
  dokhoangcach();
  if (khoangcach >= 15 ){
      digitalWrite(relay , HIGH);

  }
  else{
    digitalWrite(relay , LOW );
  }



}

void dokhoangcach()
{

  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 


  // Đo độ rộng xung HIGH ở chân echo.
  thoigian = pulseIn(echo, HIGH);

  khoangcach = thoigian / 2 / 29.412;

}

