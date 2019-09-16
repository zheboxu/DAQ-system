#include <FreqMeasure.h>
int blade=2;

void setup() {

  Serial.begin(9600);

  FreqMeasure.begin();

}



double sum=0;

int count=0;




void loop() {

  if (FreqMeasure.available()) {

    // average several reading together
  

    sum = sum + FreqMeasure.read();

    count = count + 1;

    if (count > 30) {

      float frequency = FreqMeasure.countToFrequency(sum / count);
      
      float RPM=frequency*60/blade;
      Serial.println(RPM);

      sum = 0;

      count = 0;
      delay(500);
    }

  }

}
