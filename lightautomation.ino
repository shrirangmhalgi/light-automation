int ledpin1 = 8; //output for led1 
int ledpin2 = 10; //output for led2 
int ldrpin1 = A0; //output of ldr1 to a0 pin 
int ldrpin2 = A1; //output of ldr2 to a1 pin 
int motionsensor1 = 7; //setting pin of motion sensor1 
int ldrpin3 = A2; //output of ldr to a2 pin
int sensorValue = 0; //variable to store value coming from ldr
int relaypin = 2; //output for relay

void setup()
{
  Serial.begin(9600);//selection of port
  pinMode(ledpin1, OUTPUT); //selection of output (part A)
  pinMode(ledpin2, OUTPUT); //selection of output (part B)
  pinMode(ldrpin1, INPUT); //taking input from ldr1
  pinMode(ldrpin2, INPUT); //taking input from ldr2
  pinMode(motionsensor1, INPUT); // selection of input
  pinMode(relaypin, OUTPUT); //output for part
}

void loop()
{
  int ldrstatus1 = analogRead(ldrpin1); //read status of ldr value (part A)
  int ldrstatus2 = analogRead(ldrpin2); //read status of ldr value (part B)
  int ldrstatus3 = analogRead(ldrpin3); //read the status of ldr value for (part C)

  //part A condition

  if (ldrstatus1 < 300) //setting threshold
  {
    digitalWrite(ledpin1, HIGH);
    Serial.print("led is on");
    Serial.print("                ");
  }
  else
  {
    digitalWrite(ledpin1, LOW);
    Serial.print("------");
    Serial.print("                 ");
  }

  //part B  condition

    if(ldrstatus1<300)//setting threshold
    {
      digitalWrite(relaypin,HIGH);//relay on
      Serial.println("relay triggered");
    }
    else
    {
      digitalWrite(relaypin,LOW);//relay off
      Serial.println("smthings wrong");
    }
}


