//SMART DUSTBIN
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);


const int TranUl_PIN = 9;       
const int ReciUl_PIN = 8;       
//const int Waste_Tran = 7;    
//const int Waste_Reci = 6;     
const int Servo_Lid_PIN = 3;  
//const int temp_PIN= A
//const int Gas_PIN = A0;       
const int Light_PIN = A1;     
//const int Tilt_PIN = 4;       
//const int Fan_PIN = 10;      
//const int Heater_PIN = 11;    
//const int Buzzer_PIN = 12;    
const int LED_LIGHT = 13;     
//const int IR_PIN = 5;         

Servo lidServo;

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    
    pinMode(TranUl_PIN, OUTPUT);
    pinMode(ReciUl_PIN, INPUT);
    //pinMode(Waste_Tran, OUTPUT);
    //pinMode(Waste_Reci, INPUT);
    //pinMode(Gas_PIN, INPUT);
    pinMode(Light_PIN, INPUT);
    //pinMode(Tilt_PIN, INPUT);
    //pinMode(Fan_PIN, OUTPUT);
    //pinMode(Heater_PIN, OUTPUT);
    //pinMode(Buzzer_PIN, OUTPUT);
    pinMode(LED_LIGHT, OUTPUT);
    //pinMode(IR_PIN, INPUT);
    //pinMode(temp_PIN, INPUT);
    lidServo.attach(Servo_Lid_PIN);
}


int distancedata(int TranPin, int ReciPin) {
    digitalWrite(TranPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TranPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TranPin, LOW);
    long duration = pulseIn(ReciPin, HIGH);
    return duration * 0.034 / 2;
}

void loop() {
    int personDistance = distancedata(TranUl_PIN, ReciUl_PIN);
    //int wasteLevel = distancedata(Waste_Tran, Waste_Reci);
    //int gasValue = analogRead(Gas_PIN);
    int lightLevel = analogRead(Light_PIN);
    //int tiltState = digitalRead(Tilt_PIN);
    //int IRValue = digitalRead(IR_PIN);

    //lcd.clear();
    
    
    //lcd.setCursor(0, 0);
    if (personDistance > 0 && personDistance < 30) {
        //if (IRValue == HIGH) {
            lidServo.write(90); 
            //lcd.print("BIN IS OPEN");
        //} else {
            //lidServo.write(0);
            //lcd.print("BIN IS CLOSED");
        //}
    } else {
        delay(3000);
        lidServo.write(0);
      //  lcd.print("BIN IS CLOSED");

    }
    if (lightLevel < 900) { 
        digitalWrite(LED_LIGHT, HIGH);
    }
    
    else {
        digitalWrite(LED_LIGHT, LOW);
       
     }
     Serial.println(lightLevel);

     delay(1000);
}

    
    //lcd.setCursor(0, 1);
    //cd.print("Waste Level: ");
    //lcd.print(wasteLevel);

    //if (wasteLevel < 5) {
      //  Serial.println("BIN IS FULL, PLEASE REMOVE");
      //  digitalWrite(LED_LIGHT, HIGH);
   // } else {
     //   Serial.println("BIN HAS SPACE");
  //  }

    //delay(3000);
   // lcd.clear();

    
    //lcd.setCursor(0, 0);
   // lcd.print("Gas Level: ");
   //lcd.print(gasValue);

   // if (gasValue > 600) {
  //      lcd.setCursor(0, 1);
    //    lcd.print("High Odor, Remove trash");
    //    digitalWrite(Buzzer_PIN, HIGH);
   // } else {
    //    lcd.setCursor(0, 1);
     //   lcd.print("No Odor");
     //   digitalWrite(Buzzer_PIN, LOW);
   // }

   // delay(3000);
   // lcd.clear();

    
   // lcd.setCursor(0, 0);
   // lcd.print("temp:");
  //  int tempinc =0;
  //  tempinc=map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
// if (tempinc>30){
    //  lcd.setCursor(0.1);
    //  lcd.print("HOT");
//   digital.write(Heater_PIN, HIGH);
   //   digital.write(Fan_PIN, LOW);
    
  //  else if(tempinc<10){
   //   lcd.setCursor(0.1);
   //   lcd.print("COLD");
    //  digital.write(Heater_PIN, LOW);
    //  digital.write(Fan_PIN, HIGH);
    //}
   // else{
    //  lcd.setCursor(0.1);
   //  lcd.print("MODERATE");
     // digital.write(Heater_PIN, LOW);
      //digital.write(Fan_PIN, LOW);
   // }

   // delay(3000);
    //lcd.clear();


    
   // lcd.setCursor(0, 0);
   // lcd.print("Light Level: ");
   // lcd.print(lightLevel);

  //if (lightLevel < 300) { 
        //digitalWrite(LED_LIGHT, HIGH);
      //  lcd.setCursor(0, 1);
       // lcd.print("LED ON");
  //} else {
        //digitalWrite(LED_LIGHT, LOW);
       // lcd.setCursor(0, 1);
       // lcd.print("LED OFF");
     //}

  //delay(3000);
   // lcd.clear();

    
   // lcd.setCursor(0, 0);
   // if (tiltState == HIGH) {
   //     lcd.print("BIN HAS FALLEN!!!");
   //     digitalWrite(Buzzer_PIN, HIGH);
   // } else {
  //     lcd.print("BIN IS STABLE :)");
   //     digitalWrite(Buzzer_PIN, LOW);
  //  }

   // lcd.clear();


