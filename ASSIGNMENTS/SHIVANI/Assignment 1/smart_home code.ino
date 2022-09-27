// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(3,INPUT);
  pinMode(A0,INPUT);
  pinMode(7,OUTPUT);//trig
  pinMode(6,INPUT);//echo
}

void loop()
{
   float dur,dist,temp_celsius,temp;
   bool movement;
   
   digitalWrite(7,LOW);
   delay(1000);
   digitalWrite(7,HIGH);
   delay(1000);
   digitalWrite(7,LOW);
   dur = pulseIn(6,HIGH);
  
   dist = dur/29/2;
   //Serial.println(dist); back cam
  if(dist < 30){
     digitalWrite(13,HIGH); 
  }
  else{
     digitalWrite(13,LOW); 
  }
  movement = digitalRead(3);
  if(movement == HIGH){
     digitalWrite(13,HIGH);    
  }
  else{
     digitalWrite(13,LOW); 
  }
  temp = analogRead(A0);
  //Serial.println(temp);
  temp_celsius = temp*(5000/1024);
  Serial.println(temp_celsius);
  if(temp>100){
     digitalWrite(13,HIGH);    
  }
  else{
     digitalWrite(13,LOW); 
  } 
    
}