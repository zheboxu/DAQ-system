//////////load cell//////////////////
#include <HX711.h>
#define calibration_factor_1 -210000 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define calibration_factor_2 -210000 //This value is obtained using the SparkFun_HX711_Calibration sketch


#define DOUT1  22
#define CLK1  23
#define DOUT2  24
#define CLK2  25
HX711 scale1;
HX711 scale2;

/////////////airspeed/////////////
int sensorPin = A7;   
int sensorValue = 0; 
double Vout;
float P;
float V;



/////////////RPM////////////////
String val_rpm;
float RPM;

///////////fuel_flow_rate/////////
String val_rate;
float fuel_flow_rate;
///////////////

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
//////////load cell//////////////
  scale1.begin(DOUT1,CLK1);
  scale2.begin(DOUT2,CLK2);
  scale1.set_scale(calibration_factor_1);
  scale2.set_scale(calibration_factor_2); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale1.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  scale2.tare();
  
 //////////////airspeed///////////


  ///////////RPM////////////
 

  /////////////Fuel flow rate/////////
 

  
}

void loop() {
  
  ///////////////airspeed///////////////
 int i=0;
    int sum=0;
    int offset=0;
     for(i=0;i<10;i++)
    {
         sensorValue = analogRead(sensorPin)-512;
         sum+=sensorValue;
    }
    offset=sum/10.0;
   
    while(1) {
       sensorValue = analogRead(sensorPin)-offset; 
       Vout=(5*sensorValue)/1024.0;
       
       P=Vout-2.5;
   
       float V = sqrt( (2000*P)/(1.225)  ); 

  ///////////////RPM////////////////
  while(Serial1.available()){
    delay(30);
    val_rpm = Serial1.readStringUntil('\n');
    RPM=val_rpm.toFloat();
  }
  
    
  
      //////////////fuel flow rate//////////
        while(Serial2.available()){
    delay(30);
    val_rate = Serial2.readStringUntil('\n'); 
    fuel_flow_rate=val_rate.toFloat();
        }
        


        
      



 

  Serial.print(scale1.get_units(),2); //scale.get_units() returns a float
  Serial.print("  ");
  Serial.print(scale2.get_units(), 2); //scale.get_units() returns a float
  Serial.print("  ");
Serial.print(abs(V));
Serial.print("  ");
  Serial.print(fuel_flow_rate);
  Serial.print("  ");
  Serial.print(RPM);
  Serial.println();
  
  delay(300);

        }
        
 
    
}
