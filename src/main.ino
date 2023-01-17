#define HAVE_PRR
#include <cryptoauth.h>
#include <Wire.h>

// Change to AtSha204() to use the 204
#define BAUD_RATE 230400
#define RANDOM_SIZE 32
#define USE_ECC false

auto g_ecc = AtEcc108();
auto g_sha = AtSha204();

void setup() {
  Serial.begin(BAUD_RATE);

#if USE_ECC
  g_ecc.personalize();
#else
  g_sha.enableDebug(&Serial);
#endif
}


uint8_t getRandom() {
#if USE_ECC
  return g_ecc.getRandom(false) != 0;
#else
  return g_sha.getRandom();
#endif
}

void writeRandom() {
#if USE_ECC
  Serial.write(g_ecc.rsp.getPointer(), RANDOM_SIZE);
#else
for(auto i = 0; i < RANDOM_SIZE; ++i) {
Serial.print(g_sha.rsp.getPointer()[i], HEX);
Serial.print(" ");

}
Serial.println();
return;
  Serial.write(g_sha.rsp.getPointer(), RANDOM_SIZE);
#endif
}

void generateRandom(long byteCount) {
  Serial.println("START");
  #if 0
  while(byteCount--)
    Serial.write("a", 1);
  Serial.println("\nDONE");
  return;
  #endif


#if 1
  for(auto count = byteCount / RANDOM_SIZE; count > 0; --count) {
    if(getRandom()) {
      Serial.println("ERROR");
      break;
    }
    writeRandom();
  }
#else 
  while(byteCount > 0) {
    if(g_ecc.getRandom(false) != 0) {
      Serial.println("ERROR");
      break;
    }
  
    auto len = g_ecc.rsp.getLength();
    Serial.write(g_ecc.rsp.getPointer(), len);
    byteCount -= len;
  }
#endif
  Serial.println("\nDONE");
}


void loop() {
  if(!Serial.available())
    return;
  auto in = Serial.readString();
  auto count = in.toInt();

  generateRandom(count);
}
