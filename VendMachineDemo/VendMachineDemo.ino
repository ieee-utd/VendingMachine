//LED pin definitions
const int Red1=30;
const int Red2=10;
const int Grn1=29;
const int Grn2=9;
const int Blu1=28;
const int Blu2=8;
const int Ylw1=27;
const int Ylw2=7;

//buttons pin definitions (should be changed when the button pin is known)
const int upButton = 36;
const int leftButton = 18;
const int rightButton = 39;
const int downButton = 37;
const int resetButton = 6;
const int confirmButton = 24;

//CONFIG
int TIMEOUT = 10; //In Minutes

const int maxX = 4;
const int maxY = 2;
int positionLed[maxX][maxY] = {{Red1,Red2},{Grn1,Grn2},{Blu1,Blu2},{Ylw1,Ylw2}};

int maxButtons = 6;
int buttons[6] = {upButton,leftButton,rightButton,downButton,resetButton,confirmButton};




//Below is code that doesn't need to be changed if adding more LED
//

int r = 0, c = 0;
int timePassed = 0;

bool checkTimeOut(){
  return (timePassed > TIMEOUT * 1000);
}
void OrderConfirmed(){
  //Check if it is in timeout
  if (checkTimeOut()){
    return;
  }
  //the order successfully confirmed
  //Do something lol
  for (int i = 0; i < 5; i++){
   digitalWrite(positionLed[r][c], LOW);
   delay(500);
   digitalWrite(positionLed[r][c], HIGH);
   delay(500);
  }
  
  //Reset the location
  r = 0, c = 0;
  
}

void buttonPressed(int input){
 if (digitalRead(input)) {
  Serial.print(input);
   switch(input) {
     case upButton:{//Up
       c--;
       break;
     }case leftButton:{//Left
       r--;
       break;
     }case rightButton:{//Right
       r++;
       break;
     }case downButton:{//Down
       c++;
       break;
     }case resetButton:{//Reset
       r = 0, c = 0;
       break;
     }case confirmButton:{//Confirm
       OrderConfirmed();
       return;
     }
  }
   
   //check for out of bound, and set it to location
   if (r >= maxX){
     r = 0;
   }else if (r < 0){
     r = maxX - 1;
   }
   if (c >= maxY){
     c = 0;
   }else if (c < 0){
     c = maxY - 1;
   }
   
   do {
     //Keep looping if the button is still pressed
     if (checkTimeOut()){
      r = 0, c = 0;
     }
     timePassed = 0;
   }while(digitalRead(input));
  }
};

void setup() {
  
  //8 output LEDs
  for (int i = 0; i < maxX; i++){
    for (int j = 0; j < maxY; j++){
      pinMode(positionLed[i][j],OUTPUT);
    }
  }

  //6 Input Buttons
  for (int i = 0; i < maxButtons; i++){
    pinMode(buttons[i],INPUT);
  }

  Serial.begin(9600);
  
  
}

void loop() {
  //turn everything off
  for (int i = 0; i < maxX; i++){
    for (int j = 0; j < maxY; j++){
      digitalWrite(positionLed[i][j],LOW);
    }
  }
  
  //check if any buttons is pressed
  for (int i = 0; i < maxButtons; i++){
    buttonPressed(buttons[i]);
  }
  
  //timeOut
  timePassed++;
  if (checkTimeOut()){
    return;
  }
  digitalWrite(positionLed[r][c],HIGH);

  delay(1); //Is this needed? This help with the timeout function that I set up
}
