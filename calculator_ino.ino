#include <LiquidCrystal.h>
long first = 0;
long second = 0;
double total = 0;
char customKey;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // set up the LCD's number of columns and rows:
  analogWrite(6,165);
 analogWrite(9,28836);
 Serial.begin(9600);

  lcd.begin(16, 2);
  // Print a message to the LCD.
 lcd.setCursor(0, 0);
 lcd.print("output:");
}


void loop()
{//Serial.println("jkj");
  //lcd.setCursor(0, 1);
   // lcd.print(millis() / 1000);
  if(Serial.available()>0){
  customKey = Serial.read();
  switch(customKey) 
  {
  case '0' ... '9': // This keeps collecting the first value until a operator is pressed "+-"
    lcd.setCursor(0,0);
    first = first * 10 + (customKey - '0');
  // lcd.print(first);
   
 //  Serial.print(first);
    break;

  case '+':
    first = (total != 0 ? total : first);
    //lcd.setCursor   (0,1);
   //Serial.print("+");
    second = SecondNumber(); // get the collected the second number
    total = first + second;
    lcd.setCursor   (0,3);
  lcd.print(total);
   //Serial.println(total)    ;
    first = 0, second = 0; // reset values back to zero for next use
    break;

  case '-':
    first = (total != 0 ? total : first);
   // lcd.setCursor(0,1);
   //Serial.print("-");
    second = SecondNumber();
    total = first - second;
    lcd.setCursor   (0,3);
   lcd.print(total)    ;
   
   //Serial.println(total)    ;
    first = 0, second = 0;
    break;

  case '*':
    first = (total != 0 ? total : first);
    //lcd.setCursor   (0,1);
   //Serial.print("*");
    second = SecondNumber();
    total = first * second;
    lcd.setCursor(0,3);
    lcd.print(total)    ;
   //Serial.println(total)    ;
    first = 0, second = 0;
    break;

  case '/':
    first = (total != 0 ? total : first);
    lcd.setCursor   (0,1);
    //Serial.print("/");
    second = SecondNumber();
    //lcd.setCursor   (0,3);

   second == 0 ?Serial.print("Invalid") : total = (float)first / (float)second;
   lcd.print(total);
   //lcd.print(total);
   //Serial.println(total);
    first = 0, second = 0;
    break;

  case 'C':
    total = 0;
    lcd.clear();
    break;
  }
}
    total = 0;

}

long SecondNumber()
{
  while( 1 )
  {
    customKey = Serial.read();
    if(customKey >= '0' && customKey <= '9')
    {
      second = second * 10 + (customKey - '0');
     // lcd.setCursor (0,2);
    //lcd.print(second);
    
     //Serial.print(second);
    }

    if(customKey == '='){ 
   //lcd.setCursor (0,5);
   
     // Serial.print('=');
    //lcd.print('=');
    break;  //return second;
    }}
 return second; 
}



