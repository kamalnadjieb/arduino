//Constants
const int WHITE_BUTTON = 7;
const int YELLOW_BUTTON = 4;
const int BLACK_BUTTON = 2;

//Variables
int white_button_state = 0;
int yellow_button_state = 0;
int black_button_state = 0;

bool isWhiteButtonPressed() {
  return (white_button_state == HIGH);
}

bool isYellowButtonPressed() {
  return (yellow_button_state == HIGH);
}

bool isBlackButtonPressed() {
  return (black_button_state == HIGH);
}

bool isAllButtonsPressed() {
  return (isWhiteButtonPressed() && isYellowButtonPressed() && isBlackButtonPressed());
}

bool isOnlyWhiteButtonPressed() {
  return (isWhiteButtonPressed() && !isYellowButtonPressed() && !isBlackButtonPressed());
}

bool isOnlyYellowButtonPressed() {
  return (!isWhiteButtonPressed() && isYellowButtonPressed() && !isBlackButtonPressed());
}

bool isOnlyBlackButtonPressed() {
  return (!isWhiteButtonPressed() && !isYellowButtonPressed() && isBlackButtonPressed());
}

bool isWhiteButtonAndYellowButtonPressed() {
  return (isWhiteButtonPressed() && isYellowButtonPressed() && !isBlackButtonPressed());
}

bool isWhiteButtonAndBlackButtonPressed() {
  return (isWhiteButtonPressed() && !isYellowButtonPressed() && isBlackButtonPressed());
}

bool isYellowButtonAndBlackButtonPressed() {
  return (!isWhiteButtonPressed() && isYellowButtonPressed() && isBlackButtonPressed());
}

bool isAllButtonsStillPressed() {
  return (isWhiteButtonPressed() || isYellowButtonPressed() || isBlackButtonPressed());
}

bool isOnlyWhiteButtonStillPressed() {
  return (isWhiteButtonPressed());
}

bool isOnlyYellowButtonStillPressed() {
  return (isYellowButtonPressed());
}

bool isOnlyBlackButtonStillPressed() {
  return (isBlackButtonPressed());
}

bool isWhiteButtonAndYellowButtonStillPressed() {
  return (isWhiteButtonPressed() || isYellowButtonPressed());
}

bool isWhiteButtonAndBlackButtonStillPressed() {
  return (isWhiteButtonPressed() || isBlackButtonPressed());
}

bool isYellowButtonAndBlackButtonStillPressed() {
  return (isYellowButtonPressed() || isBlackButtonPressed());
}

void setButtonState() {
  white_button_state = digitalRead(WHITE_BUTTON);
  yellow_button_state = digitalRead(YELLOW_BUTTON);
  black_button_state = digitalRead(BLACK_BUTTON);
}

void setup() {
  pinMode(WHITE_BUTTON, INPUT_PULLUP);
  pinMode(YELLOW_BUTTON, INPUT_PULLUP);
  pinMode(BLACK_BUTTON, INPUT_PULLUP);
  Serial.begin(9600);        // Starts the serial communication
}

void loop() {  
  setButtonState();
  
  if (isAllButtonsPressed()) {
    while (isAllButtonsStillPressed()) {
      setButtonState();
    }
    Serial.println("WHITE YELLOW BLACK");
  } else if (isWhiteButtonAndYellowButtonPressed()) {
    while (isWhiteButtonAndYellowButtonStillPressed()) {
      setButtonState();
    }
    Serial.println("WHITE YELLOW");
  } else if (isWhiteButtonAndBlackButtonPressed()) {
    while (isWhiteButtonAndBlackButtonStillPressed()) {
      setButtonState();
    }
    Serial.println("WHITE BLACK");
  } else if (isOnlyWhiteButtonPressed()) {
    while (isOnlyWhiteButtonStillPressed()) {
      setButtonState();
    }
    Serial.println("WHITE");
  } else if (isYellowButtonAndBlackButtonPressed()) {
    while (isYellowButtonAndBlackButtonStillPressed()) {
      setButtonState();
    }
    Serial.println("YELLOW BLACK");
  } else if (isOnlyYellowButtonPressed()) {
    while (isOnlyYellowButtonStillPressed()) {
      setButtonState();
    }
    Serial.println("YELLOW");
  } else if (isOnlyBlackButtonPressed()) {
    while (isOnlyBlackButtonStillPressed()) {
      setButtonState();
    }
    Serial.println("BLACK");
  } else {
  
  }
  
  delay(100);                        //Small delay
}

