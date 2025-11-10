/*Change all the ? in the code and add code in ??? to Control 2 DC Motors.*/

#define IN1   15  // Replace the ? with the GPIO pin you selected to connect IN1
#define IN2   2  // Replace the ? with the GPIO pin you selected to connect IN2
#define AL  26 // Replace the ? with the GPIO pin you selected to connect encoder A of Motor L
#define BL  25 // Replace the ? with the GPIO pin you selected to connect encoder B of Motor L

#define IN3  16  // Replace the ? with the GPIO pin you selected to connect IN3
#define IN4   17  // Replace the ? with the GPIO pin you selected to connect IN4
#define AR  33  // Replace the ? with the GPIO pin you selected to connect encoder A of Motor R
#define BR 32 // Replace the ? with the GPIO pin you selected to connect encoder B of Motor R


int AL_data=0;
int BL_data=0;

int AR_data=0;
int BR_data=0;

String command;


  /*setup baud and pin mode */
void setup() {
Serial.begin(115200); //Define baud

  pinMode(IN1, OUTPUT);  // Set IN1 as an output pin  (Left motor)
  pinMode(IN2, OUTPUT);  // Set IN2 as an output pin  (Left motor)
  pinMode(IN3, OUTPUT);  // Right motor
  pinMode(IN4, OUTPUT);  // Right motor

  pinMode(AL, INPUT);  // Set A as an input pin
  pinMode(BL, INPUT);  // Set B as an input pin
  pinMode(AR, INPUT);  // Set A as an input pin
  pinMode(BR, INPUT);  // Set B as an input pin


}

void loop() {
   
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the incoming command
        command.trim(); // Remove any leading or trailing whitespace
    if (command == "F") 
    { 
      // Move forward 
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 1);

      } 
    else if (command == "B") 
    { // Move Backward 
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);
      } 
    else if (command == "R") 
    { // Turn right 
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);
    } 
    else if (command == "L") { 
    // Turn left 
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 1);
   } 
  else if (command == "S") { 
    // Stop 
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 0);
     } 
        }
    // Read values of A and B of both Motor L and R
    AL_data=digitalRead(AL);
    BL_data=digitalRead(BL);
    AR_data=digitalRead(AR);
    BR_data=digitalRead(BR);
    // Plot A and B of both Motor L and R in Serial Plotter
    Serial.print("AL:");
    Serial.print(AL_data);
    Serial.print(",");
    Serial.print("BL:");
    Serial.print(BL_data);
    Serial.print(",");
    Serial.print("AR:");
    Serial.print(AR_data);
    Serial.print(",");
    Serial.print("BR:");
    Serial.print(BR_data);
    Serial.println("\t");
    
}
