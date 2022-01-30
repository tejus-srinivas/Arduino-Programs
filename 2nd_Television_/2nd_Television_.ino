#include<IRremote.h>
#include<LiquidCrystal.h>

const int button_hold = 4294967295;
int last_button =0;
decode_results data;


// ir pins

const int ir_pin= 9;
IRrecv IR(ir_pin);
const int power_pin= 8;
int power = 0;

//config LCD
LiquidCrystal lcd(12,11,2,3,4,5);

void setup(){
  
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(power_pin, OUTPUT);
  digitalWrite(power_pin, HIGH);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop(){
 
  //9: 16603303, 8: 16619623.....
  
  if(IR.decode(&data)){
  
    
    switch(data.value){
      // for value 9
      case 16603303:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("9");
      last_button= 9;
      break;
      
      case 16619623:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("8");
      last_button= 8;
      break;
      
      case 16586983:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("7");
      last_button= 7;
      break;
      
      case 16607383:
      //Serial.println('6');
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("6");
      last_button = 6;
      break;
      
      // (5) button case
      case 16623703:
      //Serial.println('5');
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("5");
      last_button = 5;
      break;
      
      // (4) button case
      case 16591063:
      //Serial.println('4');
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("4");
      last_button = 4;
      break;
      
      // (3) button case
      case 16599223:
      //Serial.println('3');
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("3");
      last_button = 3;
      break;
      
      // (2) button case
      case 16615543:
      //Serial.println('2');
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("2");
      last_button = 2;
      break;
      
      // (1) button case
      case 16582903:
      Serial.println('1');
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("1");
      last_button = 1;
      break;
      
      case 16593103:
      //Serial.println('0');
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("0");
      last_button = 0;
      break;
      
       case 16580863:
      //power button
      if(power==0){
        power = 1;
        digitalWrite(power_pin, HIGH);
      }
      else{
       
        power=0;
        digitalWrite(power_pin, LOW);
        lcd.clear();
      }
      //Serial.println(power);
      break;
    } IR.resume();
  } delay(1000);
  
}
