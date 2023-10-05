// Switch-Case

const int redPin = 2;
const int yellowPin = 4;
const int greenPin = 7;

int lastActivatedPin = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void waitUserInput() {
  while (Serial.available() <= 0) {}  // Wait for user input
}

void lightUpLED(int pin) {
  digitalWrite(pin, HIGH);
  lastActivatedPin = pin;
}

void turnOffLastActivatedLED() {
  digitalWrite(lastActivatedPin, LOW);
}

void handleUserChoice(int choice) {
  turnOffLastActivatedLED();  // Turn off the last activated LED

  switch (choice) {
    case 1:
      Serial.println("LED Red");
      lightUpLED(redPin);
      break;
    case 2:
      Serial.println("LED Yellow");
      lightUpLED(yellowPin);
      break;
    case 3:
      Serial.println("LED Green");
      lightUpLED(greenPin);
      break;
    default:
      Serial.println("Invalid choice. Please enter a number between 1 and 3.");
  }
}

void loop() {
  Serial.println("Choose an LED to light up (1: Red, 2: Yellow, 3: Green): ");
  waitUserInput();

  if (Serial.available() > 0) {
    int choice = Serial.parseInt();  // Read the user's choice as an integer
    Serial.println();  // Move to the next line in the Serial Monitor

    handleUserChoice(choice);
  }
}
