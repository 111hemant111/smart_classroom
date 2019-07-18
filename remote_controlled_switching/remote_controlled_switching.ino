
/************************Remote controlled switches************************/
/************************DEVELOPED BY HEMANT KURUVA************************/
#include<SPI.h>
#include <IRremote.h>
#include <IRremoteInt.h>

#include<LiquidCrystal.h>
IRrecv irrecv(8);
decode_results results;

LiquidCrystal lcd1(8,7,6,5,4,3);
LiquidCrystal lcd2(27,26,25,24,23,22);


#define f1 9
#define f2 10
#define f3 11
#define f4 12
#define l1 29
#define l2 30
#define l3 31
#define l4 32


int i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0;
int x=1;
int power1=0,power2=0;
//int clearall=0;

int motion();

void setup()
{
  Serial.begin(9600);
  lcd1.begin(16,2);
  lcd2.begin(16,2);
  lcd1.setCursor(0,0);
  lcd1.print("   Welcome to  ");
  lcd1.setCursor(0,1);
  lcd1.print("    ECE EXPO   ");
  lcd2.setCursor(0,0);
  lcd2.print("    Project    ");  
  lcd2.setCursor(0,1);
  lcd2.print("       TK      ");
  pinMode(f1,OUTPUT);
  pinMode(f2,OUTPUT);
  pinMode(f3,OUTPUT);
  pinMode(f4,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(l4,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(8,INPUT);
  pinMode(33,INPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
   if (irrecv.decode(&results))
   {
    if (x==1)
      {
      lcd1.clear();
      lcd2.clear();
      x++;
      }
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);

    if((results.value)== 2049||(results.value)== 1)        // key 1
     {
      
       if(i%2==0)
       {
        digitalWrite(f1, HIGH);
        lcd1.setCursor(0,0);
        lcd1.print("Fan 1");
        delay(10);
       }
       else
       {
        digitalWrite(f1, LOW);
          lcd1.setCursor(0,0);
          lcd1.print("        ");
          delay(100);
       }
       i++;
     }
    
    
    
    if((results.value)== 2050||(results.value)== 2)    //  key 2
     {
      if(j%2==0)
      {
       digitalWrite(f2, HIGH);
       lcd1.setCursor(8,0);
       lcd1.print("  Fan 2  ");
       delay(10);
      }
      else
      {
        digitalWrite(f2, LOW);
       lcd1.setCursor(8,0);
       lcd1.print("        ");
       delay(10);
      }
      j++;
     }
  
   
    if((results.value)== 2051||(results.value)== 3)    //  key 3
     {
      if(k%2==0)
      {
       digitalWrite(f3, HIGH);
       lcd1.setCursor(0,1);
       lcd1.print("  Fan 3  ");
       delay(10);
      }
      else
      {
        digitalWrite(f3, LOW);
       lcd1.setCursor(0,1);
       lcd1.print("        ");
       delay(10);
      }
      k++;
     }
  
   
    if((results.value)== 2052||(results.value)== 4)    //  key 4
     {
      if(l%2==0)
      {
       digitalWrite(f4, HIGH);
       lcd1.setCursor(8,1);
       lcd1.print("  Fan 4 ");
       delay(10);
      }
      else
      {
        digitalWrite(f4, LOW);
       lcd1.setCursor(8,1);
       lcd1.print("        ");
       delay(10);
      }
     l++;
     }


     if((results.value)== 2053||(results.value)== 5)    //  key 5
     {
      if(m%2==0)
      {
       digitalWrite(l1, HIGH);
       lcd2.setCursor(0,0);
       lcd2.print(" Light 1  ");
       delay(10);
      }
      else
      {
        digitalWrite(l1, LOW);
       lcd2.setCursor(0,0);
       lcd2.print("        ");
       delay(10);
      }
     m++;
     }


     if((results.value)== 2054||(results.value)== 6)    //  key 6
     {
      if(n%2==0)
      {
       digitalWrite(l2, HIGH);
       lcd2.setCursor(8,0);
       lcd2.print(" Light 2  ");
       delay(10);
      }
      else
      {
        digitalWrite(l2, LOW);
       lcd2.setCursor(8,0);
       lcd2.print("        ");
       delay(10);
      }
     n++;
     }


     if((results.value)== 2055||(results.value)== 7)    //  key 7
     {
      if(o%2==0)
      {
       digitalWrite(l3, HIGH);
       lcd2.setCursor(0,1);
       lcd2.print(" Light 3  ");
       delay(10);
      }
      else
      {
        digitalWrite(l3, LOW);
       lcd2.setCursor(0,1);
       lcd2.print("        ");
       delay(10);
      }
     o++;
     }


     if((results.value)== 2056||(results.value)== 8)    //  key 8
     {
      if(p%2==0)
      {
       digitalWrite(l4, HIGH);
       lcd2.setCursor(8,1);
       lcd2.print(" Light 4  ");
       delay(10);
      }
      else
      {
        digitalWrite(l4, LOW);
       lcd2.setCursor(8,1);
       lcd2.print("        ");
       delay(10);
      }
     p++;
     }
     if((results.value)==1268342361||(results.value)==470820996||motion()==0)  //Red key
      {//Serial.println("Hi");
        for (power1=9;power1<13;power1++)
          {
            digitalWrite(power1,LOW);
          }

        for (power2=29;power2<33;power2++)
          {
            digitalWrite(power2,LOW);
          }
        lcd1.setCursor(0,0);
        lcd1.print(" Welcome to the");
        lcd1.setCursor(0,1);
        lcd1.print("paradise friends");
        lcd2.setCursor(0,0);
        lcd2.print("    Project    ");  
        lcd2.setCursor(0,1);
        lcd2.print("       TK      ");
        x=1;
        i=0;
        j=0;
        k=0;
        l=0;
        m=0;
        n=0;
        o=0;
        p=0;
        }   
    
    
    irrecv.resume();
    
   }
   int v =digitalRead(33);
    Serial.println(v); 
}


int motion()
{
  for (i=0;digitalRead(33)==LOW&&i<10;i++)
    {
      Serial.println("no motion");
      delay(200);
      if (i==9)
        {
          return 0;
        }
    }

  return 1;
}

