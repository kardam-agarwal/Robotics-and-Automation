int motorL[]={3,2};  
int motorR[]={5,4}; 
const int zpin = A4;                 
const int ypin = A3;                 
const int xpin = A2;              
const int powerpin = A1;             
const int groundpin = A5;             
void setup()
{   
    Serial.begin(9600);
   

    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);  
    pinMode(5,OUTPUT);
  
    pinMode(groundpin, OUTPUT);
    pinMode(powerpin, OUTPUT);
    digitalWrite(groundpin, LOW);
    digitalWrite(powerpin, HIGH);

}         //end of void setup
void loop()
{             int x=analogRead(xpin); 
              int y=analogRead(ypin);
              int z=analogRead(zpin);            
              if(x<330)
              {
              Serial.println("Moving Backward");
              bck();
              }
              else if(x>430)
              {
              Serial.println("Moving Forward");
              fwd(); 
              }
              else if(y<330)
              {
              Serial.println("Moving Right");
              right();
              }
              else if(y>430)
              {
              Serial.println("Moving Left");
              left();
              }
              else 
              {
              Serial.println("Not moving");
              nomove();
              }
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
