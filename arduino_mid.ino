
int analogSENSOR = A0;
int PUMP= 13;

int sensorValue = 0;
float outputValue = 0;

void setup()
{
  // initialize the LED pin as an output:
  pinMode(PUMP, OUTPUT); //use 13 as output      
  Serial.begin(9600);  //will open port 9600
}

void loop()
{  
  sensorValue = analogRead(analogSENSOR);
  
  outputValue = map(sensorValue, 0, 600, 0, 255); 
  //through serial monitor, you should find the sensitive min and max value 
  //and chang 900, 1024 which is min and max
  
  //Serial.print("SENSOR VALUE: ");
  Serial.println(outputValue); 
  
  if(Serial.available() == 0){
    digitalWrite(PUMP, LOW);
  } else {
    char inByte = Serial.read();
    if(inByte == 'a')
    {
      digitalWrite(PUMP, HIGH);
      delay(100); 
      digitalWrite(PUMP, LOW);
    }
  }
  delay(10);
}
