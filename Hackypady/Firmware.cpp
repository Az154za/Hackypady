/*
 * XIAO RP2040 Keyboard Controller
 * Features:
 * - 3x3 Button Matrix (9 switches)
 * - Rotary Encoder (volume/pitch control)
 * - 3x SK6812 Mini RGB LEDs (volume indicator)
 * - 0.91" OLED Display
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>
#include <Consumer.h>  // For media keys (volume control)

// ========== PIN DEFINITIONS ==========

// Button Matrix Pins
const int rowPins[3] = {11, 6, 9};    // Row 0, Row 1, Row 2
const int colPins[3] = {A0, A1, A2};  // Column 0, 1, 2

// Rotary Encoder Pins
#define ENCODER_A  10  // Adjust based on your actual connection
#define ENCODER_B  8   // Adjust based on your actual connection

// SK6812 LED Strip
#define LED_PIN    A3
#define LED_COUNT  3

// OLED Display (I2C)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

// ========== OBJECTS ==========
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// ========== VARIABLES ==========

// Button Matrix
bool buttonState[3][3] = {false};
bool lastButtonState[3][3] = {false};
unsigned long lastDebounceTime[3][3] = {0};
const unsigned long debounceDelay = 50;

// Rotary Encoder
volatile int encoderPosition = 50;  // Start at 50% volume
int lastEncoderPosition = 50;
volatile bool encoderA_state;
volatile bool encoderB_state;

// Volume Control
int volumeLevel = 50;    // 0-100
int lastVolumeLevel = 50;

// LED Colors for volume levels
uint32_t colorLow = strip.Color(0, 255, 0);      // Green
uint32_t colorMid = strip.Color(255, 255, 0);    // Yellow
uint32_t colorHigh = strip.Color(255, 0, 0);     // Red

// ========== SETUP ==========
void setup() {
  Serial.begin(115200);
  
  // Initialize Keyboard
  Keyboard.begin();
  Consumer.begin();
  
  // Initialize button matrix
  setupButtonMatrix();
  
  // Initialize rotary encoder
  setupEncoder();
  
  // Initialize LED strip
  strip.begin();
  strip.show();
  strip.setBrightness(50);
  
  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("XIAO Keyboard"));
  display.println(F("Ready!"));
  display.display();
  delay(1000);
  
  updateDisplay();
  updateLEDs();
  
  Serial.println("XIAO RP2040 Keyboard Initialized!");
}

// ========== MAIN LOOP ==========
void loop() {
  // Scan button matrix
  scanButtonMatrix();
  
  // Check encoder changes
  if (encoderPosition != lastEncoderPosition) {
    handleEncoderChange();
    lastEncoderPosition = encoderPosition;
  }
  
  delay(10);
}

// ========== BUTTON MATRIX FUNCTIONS ==========
void setupButtonMatrix() {
  // Setup row pins as OUTPUT
  for (int r = 0; r < 3; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }
  
  // Setup column pins as INPUT_PULLUP
  for (int c = 0; c < 3; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }
}

void scanButtonMatrix() {
  for (int r = 0; r < 3; r++) {
    // Activate current row (LOW)
    digitalWrite(rowPins[r], LOW);
    delayMicroseconds(10);
    
    // Read all columns
    for (int c = 0; c < 3; c++) {
      bool reading = !digitalRead(colPins[c]);  // Invert (pressed = LOW)
      
      // Debouncing
      if (reading != lastButtonState[r][c]) {
        lastDebounceTime[r][c] = millis();
      }
      
      if ((millis() - lastDebounceTime[r][c]) > debounceDelay) {
        if (reading != buttonState[r][c]) {
          buttonState[r][c] = reading;
          
          if (buttonState[r][c]) {
            handleButtonPress(r, c);
          } else {
            handleButtonRelease(r, c);
          }
        }
      }
      
      lastButtonState[r][c] = reading;
    }
    
    // Deactivate row (HIGH)
    digitalWrite(rowPins[r], HIGH);
  }
}

void handleButtonPress(int row, int col) {
  int buttonNum = row * 3 + col + 1;  // Button 1-9
  
  Serial.print("Button ");
  Serial.print(buttonNum);
  Serial.println(" PRESSED - Opening App");
  
  // Each button opens a different application
  switch(buttonNum) {
    case 1:
      openApp("Browser");
      break;
      
    case 2:
      openApp("VSCode");
      break;
      
    case 3:
      openApp("Spotify");
      break;
      
    case 4:
      openApp("Discord");
      break;
      
    case 5:
      openApp("Terminal");
      break;
      
    case 6:
      openApp("FileManager");
      break;
      
    case 7:
      openApp("Email");
      break;
      
    case 8:
      openApp("Calculator");
      break;
      
    case 9:
      openApp("Settings");
      break;
  }
  
  // Flash LEDs when button pressed
  flashLEDs();
}

void openApp(const char* appName) {
  Serial.print("Opening: ");
  Serial.println(appName);
  
  // Display app name on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Opening:");
  display.setTextSize(2);
  display.setCursor(0, 12);
  display.println(appName);
  display.display();
  
  // Wait a moment for display
  delay(100);
  
  // Windows: Press Win+R to open Run dialog
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(300);
  
  // Type the application command
  if (strcmp(appName, "Browser") == 0) {
    Keyboard.print("chrome");  // or "firefox", "msedge"
  } 
  else if (strcmp(appName, "VSCode") == 0) {
    Keyboard.print("code");
  }
  else if (strcmp(appName, "Spotify") == 0) {
    Keyboard.print("spotify");
  }
  else if (strcmp(appName, "Discord") == 0) {
    Keyboard.print("discord");
  }
  else if (strcmp(appName, "Terminal") == 0) {
    Keyboard.print("cmd");  // or "wt" for Windows Terminal
  }
  else if (strcmp(appName, "FileManager") == 0) {
    Keyboard.print("explorer");
  }
  else if (strcmp(appName, "Email") == 0) {
    Keyboard.print("outlook");  // or your email client
  }
  else if (strcmp(appName, "Calculator") == 0) {
    Keyboard.print("calc");
  }
  else if (strcmp(appName, "Settings") == 0) {
    Keyboard.print("ms-settings:");
  }
  
  delay(100);
  
  // Press Enter to execute
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  
  delay(1000);
  updateDisplay();  // Return to volume display
}

void handleButtonRelease(int row, int col) {
  int buttonNum = row * 3 + col + 1;
  Serial.print("Button ");
  Serial.print(buttonNum);
  Serial.println(" RELEASED");
}

// ========== ROTARY ENCODER FUNCTIONS ==========
void setupEncoder() {
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), readEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B), readEncoder, CHANGE);
}

void readEncoder() {
  encoderA_state = digitalRead(ENCODER_A);
  encoderB_state = digitalRead(ENCODER_B);
  
  if (encoderA_state == encoderB_state) {
    encoderPosition++;
  } else {
    encoderPosition--;
  }
  
  // Constrain position
  encoderPosition = constrain(encoderPosition, 0, 100);
}

void handleEncoderChange() {
  volumeLevel = encoderPosition;
  
  // Send volume change to computer
  int volumeDiff = volumeLevel - lastVolumeLevel;
  
  if (volumeDiff > 0) {
    // Volume up
    for (int i = 0; i < abs(volumeDiff); i++) {
      Consumer.write(MEDIA_VOLUME_UP);
      delay(10);
    }
    Serial.print("Volume UP: ");
  } else if (volumeDiff < 0) {
    // Volume down
    for (int i = 0; i < abs(volumeDiff); i++) {
      Consumer.write(MEDIA_VOLUME_DOWN);
      delay(10);
    }
    Serial.print("Volume DOWN: ");
  }
  
  lastVolumeLevel = volumeLevel;
  Serial.println(volumeLevel);
  
  updateDisplay();
  updateLEDs();
}

// ========== DISPLAY FUNCTIONS ==========
void updateDisplay() {
  display.clearDisplay();
  
  // Title
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("VOLUME CONTROL");
  
  // Current volume - large text
  display.setTextSize(2);
  display.setCursor(0, 12);
  display.print("VOL: ");
  display.print(volumeLevel);
  display.print("%");
  
  display.display();
}

// ========== LED FUNCTIONS ==========
void updateLEDs() {
  int level = volumeLevel;
  int numLEDs = map(level, 0, 100, 0, 3);
  
  for (int i = 0; i < LED_COUNT; i++) {
    if (i < numLEDs) {
      // Set color based on level
      if (level < 33) {
        strip.setPixelColor(i, colorLow);    // Green
      } else if (level < 66) {
        strip.setPixelColor(i, colorMid);    // Yellow
      } else {
        strip.setPixelColor(i, colorHigh);   // Red
      }
    } else {
      strip.setPixelColor(i, 0);  // Off
    }
  }
  
  strip.show();
}

void flashLEDs() {
  // Flash white when button pressed
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255));
  }
  strip.show();
  delay(100);
  updateLEDs();  // Return to volume display
}
