

/***************************STUDENT COUNT****************************/
/******************Developed by Hemant********************/


  int cal1=0;
  int cal2=0;
  int set1=0;
  int set2=0;
  int ir1, ir2,total;
void setup() {
    
  pinMode(0,INPUT);
  pinMode(1,INPUT);
  
  Serial.begin(9600);

  int count();
}

void loop() {
  ir1=analogRead(0);
  //delay(50);
  ir2=analogRead(1);
  //delay(50);
  cal1=0;
  cal2=0;
  if (ir1>10&&set1==0)
    {
      cal1+=1;
      set1+=1;
    }
  
  else if (ir1<10)
    set1=0;
    
  if (ir2>10&&set2==0)
    {
      cal2+=1;
      set2+=1;
    }
 
  else if (ir2<10)
      set2=0;

  if ((cal1!=cal2)&&(set1!=set2))
    count();
  /*if (cal2>cal1)
    total++;
  else if (cal1>cal2)
    total--;
  */
  Serial.println(total);
  delay(100);
}

int count()
  {
    if(cal1>cal2)
      total++;
    else if (cal2>cal1)
      total--;
  }

