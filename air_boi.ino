int sensorPin = A7;   
int sensorValue = 0; 
double Vout;
float P;
void setup() {
  // declare the ledPin as an OUTPUT:
   Serial.begin(9600); 
}
void loop() {
    int i=0;
    int sum=0;
    int offset=0;
    Serial.println("init...");
    for(i=0;i<10;i++)
    {
         sensorValue = analogRead(sensorPin)-512;
         sum+=sensorValue;
    }
    offset=sum/10.0;
    Serial.println("Ok");
    while(1)
    {
       sensorValue = analogRead(sensorPin)-offset; 
       Vout=(5*sensorValue)/1024.0;
       Serial.print(Vout);
       P=Vout-2.5;
   
       float V = sqrt( (2000*P)/(1.225)  );           
       Serial.print("velocity = " );                       
 
       Serial.println(abs(V));
       delay(1000);   
    }
}
