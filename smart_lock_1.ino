

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
//--------------------LCD-----------------------------------------//
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
//--------------------------------Keypad----------------------------//
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the symbols on the buttons of the keypad
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect the keypad rows and columns to the Arduino
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // Connect to the column pinouts of the keypad

// Create the Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
//-------------------lock---------------------------------//
int lock=13;
String inputPass="";
String  systemPass="13579";
int passLen=5;
void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.clear();
  // Turn on the backlight
  lcd.backlight();
  
  pinMode(lock,OUTPUT);
  
  
}
void loop()
{
   lcd.clear();
lcd.setCursor(0,0);
lcd.print("Enter ur pass");
 int i=0;
  while(1)
{char key=keypad.getKey();
 if(key){
   
   if(inputPass.length()<passLen){
     inputPass=inputPass+key;
     lcd.clear();
     lcd.setCursor(i,1);
     lcd.print("*");
     i++;
   
 if(inputPass.length()==passLen){
  
   if(inputPass==systemPass){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Door Unlocked");
     digitalWrite(lock,HIGH);
     delay(5000);
     inputPass="";
     break;}
   else{
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Access denied");
     digitalWrite(lock,LOW);
     delay(1000);
      inputPass="";
     break;
   }}}}}
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Door gets locked again");
   digitalWrite(lock,LOW);
  delay(2000);
 
  
 
 
   
       
}