//Here are some pin definitions that correspond to the circuit layout
//They are not yet used. Be sure to begin using them
const int Red1=30;
const int Red2=29;
const int Grn1=28;
const int Grn2=27;
const int Blu1=26;
const int Blu2=25;
const int Ylw1=24;
const int Ylw2=23;

void setup() {
  // put your setup code here, to run once:
  //8 output LEDs
  pinMode(Red1,OUTPUT);
  pinMode(Red2,OUTPUT);
  pinMode(Grn1,OUTPUT);
  pinMode(Grn2,OUTPUT);
  pinMode(Blu1,OUTPUT);
  pinMode(Blu2,OUTPUT);
  pinMode(Ylw1,OUTPUT);
  pinMode(Ylw2,OUTPUT);
}

void loop() {
  //We iterate through all available LEDs
  for(int i=30;i>=23;i--){
    delay(250);
    digitalWrite(i,HIGH);
    delay(250);
    digitalWrite(i,LOW);
  }
}
