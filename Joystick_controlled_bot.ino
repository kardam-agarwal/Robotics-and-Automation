
int motorL[]={3,2};  
int motorR[]={5,4};  
int SW=A5; 
int Vrx=A4; 
int Vry=A3;     
int VCC=A2;        
int GND=A1; 
int flag=0;      

void setup() 
{
  Serial.begin(9600);
  
  
    for(int i=0;i<2;i++)
    {
        pinMode(motorL[i],OUTPUT);
        pinMode(motorR[i],OUTPUT);
    }
        
    pinMode(VCC,OUTPUT);
    pinMode(GND,OUTPUT);
   
    digitalWrite(VCC,HIGH);
    digitalWrite(GND,LOW);

} 

void loop() 
{  
  int read1= analogRead(SW);  
  int read2= analogRead(Vrx);
  int read3= analogRead(Vry); 
     
         if(digitalRead(read1)==LOW)
         { if(flag==0)
              flag=1;
           else
              flag=0;
         } 
          if(flag==1)
          {
            if((read3>900))
            { Serial.println("Moving Forward");
              fwd(); 
            }
             else if((read2<200))
            {Serial.println("Moving Left");
              left();
            }
            else if((read2>900 ))
            {Serial.println("Moving Right");
              right();
            }
            else if((read3<200))
            {Serial.println("Moving Backward");
              bck();
            }
            else
            {Serial.println("Not moving");
            nomove();
            }
      
          }

          else nomove();

}    

     





void fwd()

{ 
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);

}
void bck()
{ 
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);

}
void left()
{
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);

}

void right()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);

}

void nomove()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],LOW);
}
