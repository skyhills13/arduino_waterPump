import processing.serial.*;     // import the Processing serial library
Serial myPort;
char val;


void setup() {
  size(640, 360);
  println(Serial.list());

  //Choose usb adapter
  String portName = Serial.list()[0];
  println("portName:" + portName);
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  if ( myPort.available() > 0) {
    String buffer = myPort.readStringUntil('\n');
    
    if ( buffer == null )
      return;
    println("DATA : " + buffer);
    println("parse result : "+ Float.parseFloat(buffer));
    if(Float.parseFloat(buffer) < 50.0f)
    {
      myPort.write('a');
      delay(100);
    }
  } 
  
}

//    println(Float.parseFloat(buffer) > 50.0f);
//    println(Float.parseFloat(buffer) > 50);

//  if ( mousePressed )
//  {
//    println("MousePressed");

//  }
