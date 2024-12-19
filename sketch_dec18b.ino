#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Configuración del DHT11
#define DHTPIN 14       // Pin GPIO donde se conecta el DHT11
#define DHTTYPE DHT11   // Tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE);

// Configuración de LEDs
#define LED_ADVERTENCIA 18  // GPIO para LED de advertencia
#define LED_SEGURIDAD 19   // GPIO para LED de seguridad

void setup() {
  Serial.begin(115200);         // Inicia comunicación serial
  dht.begin();                  // Inicia el sensor DHT11

  pinMode(LED_ADVERTENCIA, OUTPUT); // Configura el LED de advertencia como salida
  pinMode(LED_SEGURIDAD, OUTPUT);   // Configura el LED de seguridad como salida

  digitalWrite(LED_ADVERTENCIA, LOW); // Apaga los LEDs al inicio
  digitalWrite(LED_SEGURIDAD, LOW);
}

void loop() {
  // Lee la temperatura
  float temperatura = dht.readTemperature();

  // Verifica si la lectura es válida
  if (isnan(temperatura)) {
    Serial.println("Error al leer del DHT11");
    delay(2000); // Espera 2 segundos antes de intentar nuevamente
    return;
  }

  // Imprime la temperatura en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println("°C");

  // Lógica para LEDs y mensajes
  if (temperatura > 32.0) {
    digitalWrite(LED_ADVERTENCIA, HIGH); // Enciende LED de advertencia
    digitalWrite(LED_SEGURIDAD, LOW);   // Apaga LED de seguridad
    Serial.println("Advertencia: Temperatura alta");
  } else {
    digitalWrite(LED_ADVERTENCIA, LOW); // Apaga LED de advertencia
    digitalWrite(LED_SEGURIDAD, HIGH); // Enciende LED de seguridad
    Serial.println("Estado seguro: Temperatura normal");
  }

  delay(2000); // Lee y actualiza cada 2 segundos
}

