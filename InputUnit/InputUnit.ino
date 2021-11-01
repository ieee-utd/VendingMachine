// C++ code
//

// define output pin positions
#define Led00 27
#define Led01 7
#define Led10 28
#define Led11 8
#define Led20 29
#define Led21 9
#define Led30 30
#define Led31 10

// define input pin positions
#define UP 39
#define DOWN 18
#define RIGHT 37
#define LEFT 36
#define CONFIRM 24

int row = 0;
int column = 0;
int Led[4][2] = {Led00,Led01,Led10,Led11,Led20,Led21,Led30,Led31};
int Button[5] = {UP, DOWN, RIGHT, LEFT,CONFIRM};

// Turn on Led at row a and column b
void turnOnLed (int a, int b)
{
  for ( int i=0; i < 4; i++)
      for ( int j=0; j < 2; j++) 
      {
        if (i == a && j == b)
        {
           digitalWrite(Led[i][j], HIGH);
        }
        else
        {
           digitalWrite(Led[i][j], LOW);
        }
        
      }
  
}

void turnOffLed ()
 {
  for ( int i=0; i < 4; i++)
      for ( int j=0; j < 2; j++) 
      {
           digitalWrite(Led[i][j], LOW);
      }
}

// Change row or column when pushing button
void pushButtons (int a)
{
      // UP
      if (a == 0)
      {
        if (row == 0)
        {
           row = 3;
        }
        else
        {
          row--;
        }
      }
      
      // DOWN
      if (a == 1)
      {
        if (row == 3)
        {
           row = 0;
        }
        else
        {
          row++;
        }
      }
      
      // RIGHT
      if (a == 2)
      {
        if (column == 1)
        {
           column = 0;
        }
        else
        {
          column++;
        }
      }
      
      // LEFT
      if (a == 3)
      {
        if (column == 0)
        {
           column = 1;
        }
       else
        {
          column--;
        }
      }
      // CONFIRM
      if (a == 4)
      {
        turnOffLed();
        delay(500);
        turnOnLed(row,column);
        delay(500);
        turnOffLed();
        delay(500);
        turnOnLed(row,column);
        // Control motor
        delay(1000);
        row = 0;
        column = 0;
      }      
}

  
void setup()
{
  pinMode(Led00, OUTPUT);
  pinMode(Led01, OUTPUT);
  pinMode(Led10, OUTPUT);
  pinMode(Led11, OUTPUT);
  pinMode(Led20, OUTPUT);
  pinMode(Led21, OUTPUT);
  pinMode(Led30, OUTPUT);
  pinMode(Led31, OUTPUT);
  
  pinMode(UP, INPUT); 
  pinMode(DOWN, INPUT);
  pinMode(RIGHT, INPUT); 
  pinMode(LEFT, INPUT);
  pinMode(CONFIRM, INPUT); 
    
  // Start the selection, turn on led 00
  turnOnLed (0,0);
}

void loop()
{ 
  //Check if any button is pushed
    for (int i=0; i < 5; i++)
    {
      if (digitalRead(Button[i]) == HIGH)
      {
      pushButtons(i);
      turnOnLed(row,column);
      }
      while(digitalRead(Button[i]) == HIGH);
    }
    
    delay(1); // Delay a little bit to improve simulation performance
  
}
