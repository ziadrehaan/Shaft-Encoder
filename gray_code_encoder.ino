const int grayPins[4] = {6, 7, 8, 9};  // Encoder output pins

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(grayPins[i], INPUT_PULLUP);
  }
}

int grayToBinary(int gray) {
  int binary = gray;
  for (int mask = gray >> 1; mask != 0; mask = mask >> 1) {
    binary ^= mask;
  }
  return binary;
}

void loop() {
  int grayCode = 0;
  for (int i = 0; i < 4; i++) {
    int bitVal = digitalRead(grayPins[i]);
    grayCode |= (bitVal << (3 - i));  // MSB first
  }

  int binaryValue = grayToBinary(grayCode);

  Serial.print("Gray Code: ");
  Serial.print(grayCode, BIN);
  Serial.print(" -> Position: ");
  Serial.println(binaryValue);

  delay(500);
}
