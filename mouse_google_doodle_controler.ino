
#include "Mouse.h"

// 5 buttons connected between GND and digitalPin 2,3,4,5,6
int buttons[5] = {2,3,4,5,6};

int vMove = 50;
int hMove = 10;
int cMove = 15;

int delayBetweenActions = 5;


void setup() {
  // make the pushbutton's pin an input:
  for (int i = 0; i < 5; ++i)
  {
    pinMode(buttons[i], INPUT);
    digitalWrite(buttons[i], HIGH); 
  }

  
}

void loop() {
  // read the input pins:
  int vButton = digitalRead(buttons[1]);
  int hButton = digitalRead(buttons[0]);
  int upButton = digitalRead(buttons[2]);
  int downButton = digitalRead(buttons[3]);
  int thunderboldButton = digitalRead(buttons[4]);
  if(vButton == 0){
    hline();
  }else if(hButton == 0){
    vline();
  }else if(upButton == 0){
    circumflexUp();
  }else if(downButton == 0){
    circumflexDown();
    thunderbolt();
  }else if(thunderboldButton == 0){
    thunderbolt();
  }
}

// Natural mouse movement
boolean mouseMove(int x, int y, int dist){
  for (int i=1; i <= dist - 1; i++){
    Mouse.move(x, y, 0);
    delay(1);
  }
}

boolean vline() {
  Mouse.begin();
  Mouse.press(MOUSE_LEFT);
  delay(delayBetweenActions);

  mouseMove(1,0,vMove);    
  delay(delayBetweenActions);
  Mouse.release(MOUSE_LEFT);
  delay(delayBetweenActions);
  mouseMove(-1,0,vMove);    
  Mouse.end();
  delay(delayBetweenActions);
}

boolean hline() {
  Mouse.begin();
  Mouse.press(MOUSE_LEFT);
  delay(delayBetweenActions);
  mouseMove(0,1,hMove);    
  delay(delayBetweenActions);
  Mouse.release(MOUSE_LEFT);
  delay(delayBetweenActions);
  mouseMove(0,-1,hMove);    
  Mouse.end();
  delay(delayBetweenActions);
}

boolean circumflexDown() {
  Mouse.begin();
  Mouse.press(MOUSE_LEFT);
  delay(delayBetweenActions);
  mouseMove(1,1,cMove);    
  mouseMove(1,-1,cMove);         
  delay(delayBetweenActions);
  Mouse.release(MOUSE_LEFT);
  delay(delayBetweenActions);
  mouseMove(-1,-1,cMove);    
  mouseMove(-1,1,cMove);    
  Mouse.end();
  delay(delayBetweenActions);
}

boolean circumflexUp() {
  Mouse.begin();
  Mouse.press(MOUSE_LEFT);
  delay(delayBetweenActions);
  mouseMove(1,-1,cMove);    
  mouseMove(1,1,cMove);        
  delay(delayBetweenActions);
  Mouse.release(MOUSE_LEFT);
  delay(delayBetweenActions);
  mouseMove(-1,1,cMove);    
  mouseMove(-1,-1,cMove);     
  Mouse.end();
  delay(delayBetweenActions);
}

boolean thunderbolt() {
  Mouse.begin();
  Mouse.press(MOUSE_LEFT);
  delay(delayBetweenActions);
  mouseMove(-1,-1,cMove);    
  mouseMove(1,0,cMove);    
  mouseMove(-1,-1,cMove);          
  delay(delayBetweenActions);
  Mouse.release(MOUSE_LEFT);
  delay(delayBetweenActions);
  mouseMove(1,1,cMove);    
  mouseMove(-1,0,cMove);    
  mouseMove(1,1,cMove);  
  Mouse.end();
  delay(delayBetweenActions);
}
