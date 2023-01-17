#include <cryptoauth.h>

#define BAUD_RATE 230400
#define RANDOM_SIZE 32

auto g_ecc = AtEcc108();

void setup() {
  Serial.begin(BAUD_RATE);
  g_ecc.personalize();
}

void generateRandom(long byteCount) {
  Serial.println("START");
#if 0
  while(byteCount--)
    Serial.write("a", 1);
  Serial.println("\nDONE");
  return;
#endif


  for(auto count = byteCount / RANDOM_SIZE; count > 0; --count) {
    if(g_ecc.getRandom(false) != 0) {
      Serial.println("ERROR");
      break;
    }
    Serial.write(g_ecc.rsp.getPointer(), RANDOM_SIZE);
  }
  Serial.println("\nDONE");
}


void loop() {
  if(!Serial.available())
    return;
  auto in = Serial.readString();
  auto count = in.toInt();
  
  generateRandom(count);
}
