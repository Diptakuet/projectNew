#include<LiquidCrystal.h>
int hour = 0;
int minute = 0;
int second = 0;

LiquidCrystal jis(2,3,4,5,6,7);

void setup(){
  jis.begin(20,4);
}

int t = 0;

void loop(){
  if (t == 0){
    jis.setCursor(13,1);
    jis.print("AM");
  }
  else{
    jis.setCursor(13,1);
    jis.print("PM");
  }
  if(hour%12 == 0){
    jis.setCursor(3,1);
    jis.print("00");
  }
  if (hour%12 >= 0 && hour%12 < 10) jis.setCursor(4,1);
  else jis.setCursor(3,1);
  jis.print(hour % 12);
  for(;;){
    if ( minute % 60 == 0){
      jis.setCursor(6,1);
      jis.print("00");
    }
    jis.setCursor(5,1);
    jis.print(":");
    if(minute%60 >= 0 && minute%60 < 10) jis.setCursor(7,1);
    else jis.setCursor(6,1);
    jis.print(minute % 60);
    for(;;){
      if(second % 60 == 0){
        jis.setCursor(9,1);
        jis.print("00");
      }
      jis.setCursor(8,1);
      jis.print(":");
      if(second%60 >=0 && second%60 < 10)jis.setCursor(10,1);
      else jis.setCursor(9,1);
      jis.print(second % 60);
      delay(1000);
      second++;
      if(second % 60 == 0) break;
    }
    minute++;
    if(minute % 60 == 0) break;
  }
  hour++;
  int p = hour / 12;
  t = p % 2;
}
