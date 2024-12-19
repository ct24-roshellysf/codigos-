const int pinFotoresistor=15; // pin analogico de la esp32

void setup() {
  Serial.begin(115200);       // Inicia comunicación serial
  pinMode(pinFotoresistor, INPUT);    // Configura el pin de la LDR como entrada
}

void loop() {
  int ldrValue = analogRead(pinFotoresistor); // Lee el valor analógico de la LDR
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Define un umbral para determinar si hay luz o no
  if (ldrValue < 2000) { 
    Serial.println("Hay luz");
  } else {
    Serial.println("No hay luz");
  }

  delay(1000); // Espera 1s antes de leer de nuevo
}
