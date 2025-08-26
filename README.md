## Shaft-Encoder

A Shaft Encoder is an electromechanical device that converts the angular position or motion of a rotating shaft into a digital signal. It is widely used in automation systems, robotics, industrial machinery, and control applications to detect position, direction, and speed.

---


## Hardware Requirements
- Arduino board (Uno, Mega, Nano, etc.)
- 4-bit Gray code rotary or linear encoder
- 4 digital input pins (pins 6 to 9 by default)
- Jumper wires
- Optional: pull-down resistors (if not using `INPUT_PULLUP`)

---

## Pin Connections

| Encoder Output | Arduino Pin |
|----------------|-------------|
| D0 (MSB)       | 6           |
| D1             | 7           |
| D2             | 8           |
| D3 (LSB)       | 9           |

> Note: You can change the pins as you want by modifying the `grayPins[]` array in the code.

---

## How It Works

1. The Arduino reads the **4 digital inputs** representing a 4-bit Gray code from the encoder.
2. It constructs the Gray code value by reading each pin and shifting its value into place.
3. The `grayToBinary()` function converts the Gray code to a **binary value**.
4. The result is printed to the Serial Monitor every 500 milliseconds.

---

## Code Snippet

```cpp
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
```
Serial Output Example:
- Gray Code: 1000 -> Position: 7
- Gray Code: 1001 -> Position: 6
- Gray Code: 1101 -> Position: 5

---

## Applications

- Reading position from rotary encoders
- Motion tracking in robotics
- Building digital dial controls
- Learning about Gray code and binary systems


<div align="right">
<a href="mailto:zezorehan938@gmail.com">𝓩𝓲𝓪𝓭𝓻𝓮𝓱𝓪𝓪𝓷</a>  

</div>
