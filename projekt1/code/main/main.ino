

int hiddenShips[8][8] = {
  { 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 1, 0, 0, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 1 }
};

int discoveredShops[8][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

int cursor_x = 0;
int cursor_y = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    uint8_t inByte = Serial.read();
    Serial.print("\n");

    switch (inByte) {
      case 's':
        cursor_x = add(cursor_x);
        break;
      case 'a':
        cursor_x = sub(cursor_x);
        break;
      case 'w':
        cursor_y = sub(cursor_y);
        break;
      case 'x':
        cursor_y = add(cursor_y);
        break;
      case 'l':
        hasShip();
        break;
      default:
        getCursorPos();
    }
  }
}

bool hasShip() {
  int test = hiddenShips[cursor_y][cursor_x];
  Serial.print("matrix: ");
  Serial.print(test);
  Serial.print("\n");
  return test == 1;
}

int add(int old_pos) {
  return (old_pos + 1) % 8;
}
int sub(int old_pos) {
  return ((old_pos - 1) + 8) % 8;
}

void test() {
  Serial.print("  abcdefgh\n");
  for (int i = 0; i < 8; i++) {
    Serial.print(i + 1);
    Serial.print("|");

    for (int j = 0; j < 8; j++) {
      // Serial.print(j+1 + "|");
      Serial.print(hiddenShips[i][j]);
    }
    Serial.print("\n");
  }
  Serial.print("**********************\n");
}

void getCursorPos() {
  Serial.print("x-cord: ");
  Serial.print(cursor_x);
  Serial.print("\ny-cord: ");
  Serial.print(cursor_y);
  Serial.print("\n");
  Serial.print(hasShip());
}
