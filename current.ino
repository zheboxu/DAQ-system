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
float voltage_c;// internal variable of voltage               


void setup() {
     // Robojax.com ACS712 current sensor;
     Serial.begin(9600);//initialize serial monitor;
    
            


}

void loop() {
     float voltage_raw= (5.0/1023.0)*analogRead(VIN);// read output voltage from sensor;
     voltage_c=voltage_raw-QOV+0.027;
     float current=voltage_c/sensitivity[model];
     
     Serial.println(current);

delay(500);
}
