
/*
Kyle Kessler
Kyk37
Button press for 1 or 3 leds
--> Using manual button debounce instead of a library like ezButton
an odd number of button presses will activate an LED to blink so long as it's held in
an even amount of button presses will activate 3 leds and they will blink once.
both functions will repeat so long as the button is held in.
*/

int count = 0;
int buttonState;
int ledPins[] = {5,6,7};
int ledCount = 3;

int buttonPin = 8;


int lastbuttonState = LOW;

unsigned long lastDebounceTime=0;
unsigned long debounceDelay = 50;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(buttonPin, INPUT);
  for (int myPin = 0; myPin < ledCount; myPin++){
    pinMode(ledPins[myPin], OUTPUT);
    }
    
}


// the loop function runs over and over again forever
void loop() {
  
   int reading = digitalRead(buttonPin); // read button pin
   
   // check button state. If it changed
   if (reading != lastbuttonState) {
     lastDebounceTime = millis(); //set the current time
    }

    //check if the reading has been changed for more than 50ms for debounce
    if ((millis()-lastDebounceTime) > debounceDelay){
      
      //check if button state changed
      if(reading == HIGH){
        buttonState = reading;
      
      //if buttonstate is now HIGH
      
      if (buttonState == HIGH){
        if(count % 2 == 1){ // if the number of times pressed is odd.
          while(reading == HIGH){
                digitalWrite(ledPins[0], HIGH);
                delay(1000);
                digitalWrite(ledPins[0], LOW);
                delay(1000);
                reading = digitalRead(buttonPin);
            }

        }else if (count %2 == 0){ //if number of times pressed is even
          while (reading == HIGH){
          
            for(int myPin = (ledCount-1); myPin >=0; myPin--){
              digitalWrite(ledPins[myPin], HIGH);
              delay(1000);
              digitalWrite(ledPins[myPin], LOW);
            }
           reading = digitalRead(buttonPin);
          }

        }
         count = count + 1;
      }
 
    }
    }

   lastbuttonState = reading;
}

