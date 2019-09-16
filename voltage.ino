int volt=0;// set the correction offset value

void setup() {

  // Robojax.com voltage sensor

  Serial.begin(9600);
 
}

void loop() {

  // Robojax.com voltage sensor

  float volt = analogRead(A0);// read the input

  float voltage = volt * 0.024;

 

  Serial.println(voltage);



delay(500);

  

  

}
