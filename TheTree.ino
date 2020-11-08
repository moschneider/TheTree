#include "pitches.h"

int soundPos = 0;
int lightPos = 0;

int buzzerPin = 2;

int redLedsPin = 3;
int greenLedsPin = 5;

int whiteLedPin = 10;

int yellowButton = 12;
int redButton = 13;

int soundSensor = A0;

int valYButton = 0;
int valRButton = 0;
int valSSensor = 0;

const int R = 0;
const int G = 1;
const int W = 2;
const int RG = 3;
const int ALL = 4;

int melodyWeWish[] = {
  NOTE_D4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_A4, 
  NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_D4, NOTE_D4, NOTE_B4, NOTE_B4, NOTE_C5, 
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_A4, NOTE_FS4, NOTE_G4, 
  NOTE_D4
};

int durationWeWish[] = {
  4,4,8,8,8,8,4,4,4,4,
  8,8,8,8,4,4,4,4,8,8,
  8,8,4,4,8,8,4,4,4,2 
};

int melodyJingleBells[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4, 
  NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, 
  NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, 
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, 
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_D4, 
  NOTE_C4
};

int durationJingleBells[] = {
  4,4,2,4,4,2,4,4,3,8,
  1,4,4,3,8,4,4,4,8,8,
  4,4,4,4,2,2,4,4,2,4,
  4,2,4,4,3,8,1,4,4,4,
  4,4,4,4,8,8,4,4,4,4,
  1
};

int melodySilentNight[] = {
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, 0, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, 0, 
  NOTE_D5, NOTE_D5, NOTE_B4, 0, NOTE_C5, NOTE_C5, NOTE_G4, 0, NOTE_A4, NOTE_A4, 
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, 0, NOTE_A4, NOTE_A4,   
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, 0, NOTE_D5, NOTE_D5, 
  NOTE_F5, NOTE_D5, NOTE_B4, NOTE_C5, 0, NOTE_E5, 0, NOTE_C5, NOTE_G4, NOTE_E4,
  NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C4
};

int durationSilentNight[] = {
  3,8,4,2,4,3,8,4,2,4,
  2,4,2,4,2,4,2,4,2,4,
  3,8,4,3,8,4,2,4,2,4,
  3,8,4,3,8,4,2,4,2,4,
  3,8,4,2,4,2,4,4,4,4,
  3,8,4,1
};

int melodySuesser[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_D4, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, 0, 
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_C5, NOTE_A4, 0, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C4, 0, 
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_E4, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4, 
  NOTE_G4, NOTE_F4, NOTE_D4, NOTE_E4, 0, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C5, NOTE_A4, 0, 
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C4
};

int durationSuesser[] = {
  6,16,8,8,8,8,3,4,8,6,16,8,8,8,8,2,4,
  6,16,8,8,8,8,3,4,8,6,16,8,8,8,8,2,4,
  6,16,8,8,8,8,6,16,8,4,8,6,16,8,8,8,8,
  6,16,8,4,8,6,16,8,8,8,8,3,4,8,
  6,16,8,8,8,8,2
};

int melodyLeiseRieselt[] = {
  NOTE_B4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, 0, 
  NOTE_G4, NOTE_E4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4, 0, 
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, 0, 
  NOTE_A4, NOTE_FS4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G4, 0 
};

int durationLeiseRieselt[] = {
  2,4,4,4,4,1,2,2,
  4,4,4,4,1,2,4,4,
  4,4,4,4,1,2,3,8,
  4,4,4,4,1,2
};

int melodyLetItBe[] = {
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_C5, NOTE_D5, 
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, 0, NOTE_E5, NOTE_E5, 
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_D5
};

int noteDurationLetItBe[] = {
  8,8,4,4,4,4,4,4,8,3,
  4,4,4,4,4,4,4,8,8,4,
  4,4,4,4,4,4,4,2
};

void setup() {

  Serial.begin(9600);
  
   pinMode(buzzerPin,OUTPUT);

   pinMode(redLedsPin,OUTPUT);
   pinMode(greenLedsPin,OUTPUT);

   pinMode(whiteLedPin,OUTPUT);
   
   pinMode(yellowButton,INPUT_PULLUP);
   pinMode(redButton,INPUT_PULLUP);

   pinMode(soundSensor,INPUT);

   digitalWrite(buzzerPin,HIGH);
   delay(100);
   digitalWrite(buzzerPin,LOW);
}

void on(int col)
{
  switch(col)
  {
    case R : digitalWrite(redLedsPin,HIGH); break;
    case G : digitalWrite(greenLedsPin,HIGH); break;
    case W : wMed(); break;
    case RG : digitalWrite(redLedsPin,HIGH);
              digitalWrite(greenLedsPin,HIGH); break;
    case ALL : digitalWrite(redLedsPin,HIGH);
              digitalWrite(greenLedsPin,HIGH);
              wMed(); break; 
  }
}

void off(int col)
{
  switch(col)
  {
    case R : digitalWrite(redLedsPin,LOW); break;
    case G : digitalWrite(greenLedsPin,LOW); break;
    case W : digitalWrite(whiteLedPin,LOW); break;
    case RG : digitalWrite(redLedsPin,LOW);
              digitalWrite(greenLedsPin,LOW); break;
    case ALL : digitalWrite(redLedsPin,LOW);
              digitalWrite(greenLedsPin,LOW);
              digitalWrite(whiteLedPin,LOW); break;
  }
}

void writeValue(int col,int value)
{
  switch(col)
  {
    case R : analogWrite(redLedsPin,value); break;
    case G : analogWrite(greenLedsPin,value); break;
    case W : analogWrite(whiteLedPin,value/20);
              break;
    case RG : analogWrite(redLedsPin,value);
              analogWrite(greenLedsPin,value); break;
    case ALL : analogWrite(redLedsPin,value);
              analogWrite(greenLedsPin,value);
              analogWrite(whiteLedPin,value/20);
              break;
  }
}

void wMed()
{
  analogWrite(whiteLedPin,10);
}

void slideOn(int color, int inc){
  for (int value = 0 ; value < 255; value+=inc){
    writeValue(color,value);
    delay(30); 
  } 
}

void slideOff(int color, int dec){
  for (int value = 255; value >0; value-=dec){
    writeValue(color,value);
    delay(30); 
  }

  off(color);
}

void wow(int color, int veloc, int del)
{
  slideOn(color,veloc);
  delay(del);
  slideOff(color,veloc);
}

void readKey()
{
     valYButton = digitalRead(yellowButton);
     valRButton = digitalRead(redButton);

}

bool keyPressed()
{
    readKey();
     
     if(valYButton==0 || valRButton==0)
        return true;

   return false;
}

void cleanBuffer()
{
  while(keyPressed())
    readKey();
}

void testAll()
{
   digitalWrite(buzzerPin,HIGH);
   delay(100);
   digitalWrite(buzzerPin,LOW);

   on(ALL);

   while(true) {
     valYButton = digitalRead(yellowButton);
     Serial.println("Yellow Button");
     Serial.println(valYButton);
     valRButton = digitalRead(redButton);
     Serial.println("Red Button");
     Serial.println(valRButton);
     valSSensor = digitalRead(soundSensor);
     Serial.println("Sound Sensor");
     Serial.println(valSSensor);
     delay(2000);
   }
}

void goNext()
{
  if(valYButton==0)
   nextLight(); else
    nextSound();
}

void onlyOn()
{
  cleanBuffer();
  
  on(ALL);

  while(keyPressed()==false);

  goNext();
}

void effect0()
{
  cleanBuffer();
  
  on(ALL);

  while(keyPressed()==false)
  {
    wow(ALL,5,500);
  }

  goNext();
}

void effect1()
{
  cleanBuffer();
  
  while(keyPressed()==false)
  {
    off(ALL);
    delay(100);
    on(W);
    delay(100);
    on(G);
    delay(100);
    on(R);
    delay(100);
  }

  goNext();
}

void effect2()
{
  cleanBuffer();
  
  while(keyPressed()==false)
  {
    off(ALL);
    delay(500);
    on(R);
    delay(500);
    on(G);
    delay(500);
    on(W);
    delay(500);
  }

  goNext();
}

void effect3()
{
  cleanBuffer();
  
  while(keyPressed()==false)
  {
    on(W);
    wow(R,20,100);
    wow(G,20,100);
    wow(RG,20,100);
  }

  goNext();
}

void effect4()
{
  cleanBuffer();
  
  wow(RG,50,1000);

  wow(W,50,1000); 
  
  while(keyPressed()==false)
  {
     valSSensor = digitalRead(soundSensor);

     if(valSSensor==1)
        on(ALL); else off(ALL);

     delay(50);
  }

  goNext();
}

void doSound(bool slow,int nrNotes,int melody[],int noteDurations[])
{
    int delayConfig;

    cleanBuffer();
  
    if(slow)
      delayConfig=2000;
        else
      delayConfig=1000;
  
    for (int thisNote = 0; thisNote < nrNotes; thisNote++) {
      int noteDuration = delayConfig / noteDurations[thisNote];
      tone(buzzerPin, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(buzzerPin);
      if(keyPressed())
      {
        if(valYButton==0)
          lightPos--;
        
        goNext();
      }
    }

    lightPos--;
    nextLight();
}

void jingleBells()
{
  doSound(false,51,melodyJingleBells,durationJingleBells);
}

void silentNight()
{
  doSound(false,54,melodySilentNight,durationSilentNight);
}

void weWishYou()
{
  doSound(false,31,melodyWeWish,durationWeWish);
}

void suesserDieGlocken()
{
  doSound(true,72,melodySuesser,durationSuesser);
}

void leiseRieselt()
{
  doSound(false,30,melodyLeiseRieselt,durationLeiseRieselt);
}

void nextSound()
{
  soundPos++;

  if(soundPos>5)
    soundPos=1;

  on(ALL);

  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW);

  delay(1000);

  switch(soundPos)
  {
    case 1: weWishYou(); break;
    case 2: jingleBells(); break;
    case 3: silentNight(); break;
    case 4: suesserDieGlocken(); break;
    case 5: leiseRieselt(); leiseRieselt; break;
  }
}

void nextLight()
{
  lightPos++;

  if(lightPos<1)
    lightPos=1;

  if(lightPos>6)
    lightPos=1;

  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW);

  switch(lightPos)
  {
    case 1: onlyOn(); break;
    case 2: effect0(); break;
    case 3: effect1(); break;
    case 4: effect2(); break;
    case 5: effect3(); break;
    case 6: effect4(); break;
  }
}

void loop() {

  onlyOn();
}
