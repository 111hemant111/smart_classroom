#include <Servo.h>
#include <Keypad.h>

Servo lock;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad
int key1,key2,key3,key4;
int a;
int pos = 0;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  lock.attach(9);
}

void loop(){
  while(1)
  {
    key1=keypad.getKey()-48;
    if(key1!=-48)
    {digitalWrite(10,HIGH);
     break;
    }
  }

  while(1)
  {
    key2=keypad.getKey()-48;
    if(key2!=-48)
     {digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      break;
      }
  }

  while(1)
  {
    key3=keypad.getKey()-48;
    if(key3!=-48)
     {digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      break;
      }
  }

  while(1)
  {
    key4=keypad.getKey()-48;
    if(key4!=-48)
     {digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      break;
      }
  }

  a=1000*key1+100*key2+10*key3+key4;
  Serial.println(a);


  if (a==2411)
    {
      digitalWrite(13,HIGH);
      for(pos = 120; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
        {                                
        lock.write(pos);                // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
        } 
      
    }
  else
    { 
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);     
    }

}
