
/************************Remote controlled switches************************/
/*************************MADE BY HEMANT AND GIRISH************************/
#include<SPI.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd1(7,6,5,4,3,2);
LiquidCrystal lcd2(27,26,25,24,23,22);


#define f1 9
#define f2 10
#define f3 11
#define f4 12

int i=0,j=0,k=0,l=0;
int power1=0;
float temp, tempraw;

void setup()
{
  
  analogReference(INTERNAL1V1);
  Serial.begin(9600);
  lcd1.begin(16,2);
  lcd2.begin(16,2);
  lcd1.setCursor(0,0);
  lcd1.print(" Welcome to the ");
  lcd1.setCursor(0,1);
  lcd1.print("  world of IoT  ");
  lcd2.setCursor(0,0);
  lcd2.print("    ECE Expo    ");  
  lcd2.setCursor(0,1);
  lcd2.print("   Project TK   ");

  pinMode(f1,OUTPUT);
  pinMode(f2,OUTPUT);
  pinMode(f3,OUTPUT);
  pinMode(f4,OUTPUT);

  pinMode(28,INPUT);
  pinMode(29,INPUT);
  pinMode(30,INPUT);
  pinMode(31,INPUT);
  pinMode(32,INPUT);
  pinMode(33,INPUT);
  
  pinMode(13,OUTPUT);
  
  pinMode(8,INPUT);

}

//float humi, pretruehumconst,pretruehum,truehum;
//float samples[8];
//float tempc=0;

int a=0;
void loop()
{   
    if (a==0)
    {
    delay(3000);
    lcd1.clear();
    lcd2.clear();
    a=1;
    }
    
    digitalWrite(13, LOW);
    tempraw=analogRead(0);
    temp=tempraw/9.31;
    delay(300);
/*
    humi = (analogRead(1)/5) - 25.8;
    pretruehumconst = 0.00216*temp;
    pretruehum = 1.0546-pretruehumconst;
    truehum = humi/pretruehum ;
*/
    lcd2.setCursor(0,0);
    lcd2.print("  Temperature:  ");
    lcd2.setCursor(4,1);
    lcd2.print(temp);
    lcd2.print(" C");
    /*
    lcd2.setCursor(0,1);
    lcd2.print("Humidity: ");
    lcd2.print(truehum);
    lcd2.print(" %");
    */
    if(digitalRead(28)==HIGH)        // key 1
     {
        digitalWrite(f1, HIGH);
        lcd1.setCursor(0,0);
        lcd1.print("  AC   ");
       }
       else
       {
        digitalWrite(f1, LOW);
          lcd1.setCursor(0,0);
          lcd1.print("        ");
       }

    
    if(digitalRead(29)==HIGH)    //  key 2
     {
       digitalWrite(f2, HIGH);
       lcd1.setCursor(8,0);
       lcd1.print(" Light  ");
      }
      else
      {
        digitalWrite(f2, LOW);
       lcd1.setCursor(8,0);
       lcd1.print("        ");
      }
  
   
    if(digitalRead(30)==HIGH)    //  key 3
     {
       digitalWrite(f3, HIGH);
       lcd1.setCursor(0,1);
       lcd1.print("   TV   ");
      }
      else
      {
        digitalWrite(f3, LOW);
       lcd1.setCursor(0,1);
       lcd1.print("        ");
      }
  
   
    if(digitalRead(31)==HIGH)    //  key 4
     {
       digitalWrite(f4, HIGH);
       lcd1.setCursor(8,1);
       lcd1.print("Zerobulb");
      }
      else
      {
        digitalWrite(f4, LOW);
       lcd1.setCursor(8,1);
       lcd1.print("        ");
      }


     /***************SLEEP**************
     
     if(digitalRead(32)==HIGH)  //Red key
      {
        for (power1=9;power1<13;power1++)
          {
            digitalWrite(power1,LOW);
          }

    lcd1.setCursor(0,0);
    lcd1.print(" Welcome to the ");
    lcd1.setCursor(0,1);
    lcd1.print("  world of IoT  ");
    lcd2.setCursor(0,0);
    lcd2.print("    ECE Expo    ");  
    lcd2.setCursor(0,1);
    lcd2.print("   Project TK   ");
        i=0;
        j=0;
        k=0;
        l=0;
        }   
        
    /************All HIGH*************
    
     if (digitalRead(33)==HIGH)
      {
        for (power1=9;power1<13;power1++)
          {
            digitalWrite(power1,HIGH);
          }
       lcd1.setCursor(0,0);
       lcd1.print("  Fan   ");
       lcd1.setCursor(8,0);
       lcd1.print(" Light  ");
       lcd1.setCursor(0,1);
       lcd1.print("   TV   ");
       lcd1.setCursor(8,1);
       lcd1.print("Zerobulb");  
   }
   */
}

