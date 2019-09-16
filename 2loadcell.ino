#include <HX711.h>
#define calibration_factor_1 -210000 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define calibration_factor_2 -210000 //This value is obtained using the SparkFun_HX711_Calibration sketch


#define DOUT1  22
#define CLK1  23
#define DOUT2  24
#define CLK2  25
HX711 scale1;
HX711 scale2;

void setup() {
Serial.begin(9600);

  scale1.begin(DOUT1,CLK1);
  scale2.begin(DOUT2,CLK2);
  scale1.set_scale(calibration_factor_1);
  scale2.set_scale(calibration_factor_2); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale1.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  scale2.tare();
  Serial.print("torque  ");
  Serial.println("Thrust");
}


void loop() {
  Serial.print(scale1.get_units(),2); //scale.get_units() returns a float
  Serial.print(" kg  "); //You can change this to kg but you'll need to refactor the calibration_factor
   Serial.print(scale2.get_units(), 2); //scale.get_units() returns a float
  Serial.print(" kg"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();
  delay(500);
}
