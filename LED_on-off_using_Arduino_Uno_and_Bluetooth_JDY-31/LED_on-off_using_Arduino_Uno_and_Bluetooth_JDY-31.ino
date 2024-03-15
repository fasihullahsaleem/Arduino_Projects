
      ///////// READ CAREFULLY !!!!!!!!!

// MICROCONTROLLER TESTED IS IS ARDUINO UNO R3
// BLUETOOTH MODULE IS JDY-31
// CONNECT THE JDY-31 MODULE (TX , RX PINS ) AFTER UPLOADING THE CODE TO MICROCONTROLLER 
// TX OF BLUETOOTH -> RX OF MICROCONTROLLER
// RX OF BLUETOOTH -> TX OF MICROCONTROLLER
// OTHERWISE CODE WILL NOT UPLOAD AS THE SERIAL PORT WILL BE UTILIZED BY JDY-31
// THE DEFAULT PASSWORD OF JDY-31 FOR PAIRING 1234
// USE THE RESPECCTIVE APP ONLY 
//           ENJOY !!!  

// INITIALIZING THE VARIABLES

char data[2] ; 
int myLED = 13;
int check = 0 ;

void setup(){
  Serial.begin(9600);
  pinMode(myLED, OUTPUT);
}
// PROGRAM BY FASIH ULLAH SALEEM
void loop(){
  check = Serial.available();  // RETURNS 1 OR 0
  if(check){

    // Read the incoming DATA
    char incomingData = Serial.read();

    // If the incoming DATA is not a carriage return or newline, process it
    if (incomingData != '\r' && incomingData != '\n') {
      // Store the incoming byte in the data array
      data[0] = incomingData;
      // Null-terminate the string
      data[1] = '\0';
      
      // Check if the received character is '1' and turn on the LED
      if (data[0] == '1') {
        digitalWrite(myLED, HIGH);
      } 
      // Check if the received character is '0' and turn off the LED
      else if (data[0] == '0') {
        digitalWrite(myLED, LOW);
      }
    }
  }
}

