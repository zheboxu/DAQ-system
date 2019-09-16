#include <HX711.h>
float V;
#define calibration_factor_1 -210000 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define calibration_factor_2 -210000 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define DOUT1  22
#define CLK1  23
#define DOUT2  24
#define CLK2  25
HX711 scale1;
HX711 scale2;


int volt=0;// set the correction offset value

#define VIN A1//define the arduino pin
const float VCC=5.0;//supply voltage from 4.5 to 5.5V, normally 5V
const int model=2;// enter model number(30A--model=2)
float cutOffLimit=1.01;
/*  
            "ACS712ELCTR-05B-T",//for model use 0
            "ACS712ELCTR-20A-T",//for model use 1
            "ACS712ELCTR-30A-T",//for model use 2
 */

float sensitivity[]={
               0.185,//for ACS712ELCTR-05B-T
               0.100,//for ACS712ELCTR-20A-T
               0.066// for ACS712ELCTR-30A-T
};


const float QOV=0.5*VCC;// set quiescent output voltage of 0.5V               

float voltage_c;    


/////////airspeed////////
int sensorPin = A7;   
int sensorValue = 0; 
float Vout;
float P;


///////////////////




String val_rpm;
float RPM;

void setup() {
  Serial.begin(9600);
 
  Serial1.begin(9600);
  
/////////load cell/////////
  scale1.begin(DOUT1,CLK1);
  scale2.begin(DOUT2,CLK2);
  scale1.set_scale(calibration_factor_1);
  scale2.set_scale(calibration_factor_2); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale1.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  scale2.tare();
/////////////////////////


}


void loop() {
 
      ////////////airspeed////////////////
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
   
        V = sqrt( (2000*P)/(1.225)  ); 
       
       

     
//////////////////rpm/////////////////
    while(Serial1.available()){
    delay(30);
    val_rpm = Serial1.readStringUntil('\n'); 
    RPM=val_rpm.toFloat();
    }

     ////////////voltage////////////
  float volt = analogRead(A0);// read the input
  float voltage = volt * 0.024;
////////////////current///////////////
 
  float voltage_raw= (5.0/1023.0)*analogRead(VIN);// read output voltage from sensor;
      voltage_c=voltage_raw-QOV+0.027;
     float current=voltage_c/sensitivity[model];
    
       
       
    
    
    
    

 
    
       

    
  

 
    

  
  


  //////////electrical power/////////////
   float electrical_power= current*voltage;

   /////////////////////////

   
     Serial.print(scale1.get_units()  , 2); //scale.get_units() returns a float
  Serial.print("  ");
  Serial.print(scale2.get_units()  , 2); //scale.get_units() returns a float
  Serial.print("  ");
 
  Serial.print(voltage);
  Serial.print("  ");
  Serial.print(current);
 Serial.print("  ");

Serial.print(RPM);
Serial.print("  ");
  
 Serial.print(abs(V));
 Serial.print("  ");

  Serial.print(electrical_power);
  Serial.print("  ");
  Serial.println();
  delay(500);
       
    }
       
    
       
}
