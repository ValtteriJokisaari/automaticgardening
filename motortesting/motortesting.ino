//Libraries
#include <DHT.h>;

//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

int motor = 9;
int x = 255;

float hum;  //Stores humidity value
float temp; //Stores temperature value


void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  analogWrite(motor, 0);
  Serial.println(x);

  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  //Print temp and humidity values to serial monitor

  if(hum>50){
    analogWrite(motor, x);
  }
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  
}