
#include <DHT.h>

// Konfigurasi pin
#define DHTPIN 4
#define DHTTYPE DHT22
#define PIRPIN 27

// Inisialisasi sensor DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();
  pinMode(PIRPIN, INPUT);

  Serial.println("==============================");
  Serial.println(" SMART ROOM MONITORING SYSTEM");
  Serial.println("==============================");
  Serial.println("Memulai sensor...");
  Serial.println("Tunggu kalibrasi PIR sekitar 30-60 detik.");
}

void loop() {
  // Membaca sensor PIR
  int motion = digitalRead(PIRPIN);

  // Membaca DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.println("\n------------------------------");

  // Menampilkan suhu dan kelembapan
  Serial.println("[DHT22]");

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Gagal membaca DHT22!");
  } else {
    Serial.print("Suhu        : ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Kelembapan  : ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  // Menampilkan hasil PIR
  Serial.println("\n[PIR]");

  if (motion == HIGH) {
    Serial.println("Gerakan     : TERDETEKSI");
  } else {
    Serial.println("Gerakan     : TIDAK TERDETEKSI");
  }

  Serial.println("------------------------------");

  delay(2000);
}
