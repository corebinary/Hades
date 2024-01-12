
void setup(){
	//USB SERIAL
  Serial.begin(9600);  

  //STARTUP IN STOPPED POSITION
  analogWrite(15, 0);
  analogWrite(4, 0);
}

void loop() {

    //serial_test();
    //read_rc();
    rc2_hb();

}

void serial_test(){

if(Serial.available() > 0)  {
    int incomingData = Serial.read(); // can be -1 if read error
    switch(incomingData) { 
        case '0':
           Serial.println("0.0 ms");
           //myservo1.write(0);
           analogWrite(4, 0);
           break;
        case '1':
           Serial.println("1.0 ms");
           //myservo1.write(0);
           analogWrite(4, 50);
           break;
        case '2':
           Serial.println("1.5 ms");
           //myservo1.write(90);
           analogWrite(4, 128);
           break;
        case '3':
           Serial.println("2.0 ms");
           //myservo1.write(180);
           analogWrite(4, 255);
           break;
        default:
           // handle unwanted input here
           break;
   }
}

}


void read_rc(){

  //val = analogRead(2);  // read the input pin
  int val = pulseIn(2, HIGH, 50000);
  Serial.println(val);

}

void rc2_hb(){

  int val = pulseIn(2, HIGH, 50000);

  //PREVENT RUNAWAY MOTOR ON STARTUP 
  if (val > 2000 || val < 1000){
    val = 1500; //SETS RC SIGNAL to ZERO
  }

  int rc_sig = map(val, 1500, 2000, 0, 255);

  //DRIVE FORWARD
  if (rc_sig > 1){
    analogWrite(15, 0);
    analogWrite(4, rc_sig);
    Serial.print("FWD");
    Serial.println(rc_sig);
  }

  //DRIVE REVERSE
  if (rc_sig < 0){
    rc_sig = rc_sig * -1;
    analogWrite(4, 0);
    analogWrite(15, rc_sig);
    Serial.print("BCK");
    Serial.println(rc_sig);
  }

}




