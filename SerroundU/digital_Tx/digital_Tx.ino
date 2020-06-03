
#define button 8


int trigPinRight = 11;    
int echoPinRight = 12;   

int trigPinMiddle = 7;    
int echoPinMiddle = 8;   

int trigPinLeft = 9;    
int echoPinLeft = 10;    


long duration,distanceRight,distanceMiddle,distanceLeft;

void setup() {

  Serial.begin(115200); // Default communication rate of the Bluetooth module
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);

  pinMode(trigPinMiddle, OUTPUT);
  pinMode(echoPinMiddle, INPUT);

  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);

}

void loop() {
 digitalWrite(trigPinRight, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW);

 pinMode(echoPinRight, INPUT);
  duration = pulseIn(echoPinRight, HIGH);
  distanceRight = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343

   digitalWrite(trigPinMiddle, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinMiddle, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinMiddle, LOW);

 pinMode(echoPinMiddle, INPUT);
  duration = pulseIn(echoPinMiddle, HIGH);
  distanceMiddle = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343

  digitalWrite(trigPinLeft, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);

 pinMode(echoPinLeft, INPUT);
  duration = pulseIn(echoPinLeft, HIGH);
  distanceLeft = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  
  
 if (distanceRight < 10) {
   Serial.print('1');
   
 delay(80);}
   if (distanceMiddle < 10) {
   Serial.print('2'); 
      
 delay(80);}
    if (distanceLeft < 10) {
   Serial.print('3');
      
    }
 
}
