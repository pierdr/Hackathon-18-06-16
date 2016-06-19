

// parallel port pin# = arduino pin#
const int nStrobe = 37;
const int data_0 = 53;
const int data_1 = 51;
const int data_2 = 49;
const int data_3 = 47;
const int data_4 = 45;
const int data_5 = 43;
const int data_6 = 39;
const int data_7 = 41;

const int busy = 35;

const int strobeWait = 2;   // microseconds to strobe for


void setup() {
  Serial.begin(9600);
  Serial2.begin(115200);

  pinMode(nStrobe, OUTPUT);      // is active LOW
  digitalWrite(nStrobe, HIGH);   // set HIGH
  pinMode(data_0, OUTPUT);
  pinMode(data_1, OUTPUT);
  pinMode(data_2, OUTPUT);
  pinMode(data_3, OUTPUT);
  pinMode(data_4, OUTPUT);
  pinMode(data_5, OUTPUT);
  pinMode(data_6, OUTPUT);
  pinMode(data_7, OUTPUT);

  pinMode(busy, INPUT);  

  
  delay(1000);
  
  resetPrinter();
  
//  printStartupMessage();

//  Serial.println("Printing");
//  for (int i=0; i<200; i++) {
//    printByte('0' + (i % 10));
//  }
//  printByte('\n');
//  Serial.println("Print OK");

  
//  
//  resetPrinter();
//  
//  Serial.println("Delay for 5 sec");
//  delay(5000);
//  
  Serial.println("Startup complete");
}

void loop() {
  if (Serial2.available() > 0) {
    int incomingByte = Serial2.read();
    Serial.print(incomingByte);
    printByte(incomingByte);
  }
}

void printByte(byte inByte) {
  while(digitalRead(busy) == HIGH) {
    // wait for busy to go low
  }

  int b0 = bitRead(inByte, 0);
  int b1 = bitRead(inByte, 1);
  int b2 = bitRead(inByte, 2);
  int b3 = bitRead(inByte, 3);
  int b4 = bitRead(inByte, 4);
  int b5 = bitRead(inByte, 5);
  int b6 = bitRead(inByte, 6);
  int b7 = bitRead(inByte, 7);

  digitalWrite(data_0, b0);        // set data bit pins
  digitalWrite(data_1, b1);
  digitalWrite(data_2, b2);
  digitalWrite(data_3, b3);
  digitalWrite(data_4, b4);
  digitalWrite(data_5, b5);
  digitalWrite(data_6, b6);
  digitalWrite(data_7, b7);

  digitalWrite(nStrobe, LOW);       // strobe nStrobe to input data bits
  delayMicroseconds(strobeWait);
  digitalWrite(nStrobe, HIGH);

  while(digitalRead(busy) == HIGH) {
    // wait for busy line to go low
  } 
}

void resetPrinter() {
  Serial.println("Reseting printer...");
  printByte(27); // reset printer
  printByte('E');
  Serial.println("Printer Reset"); 
}

