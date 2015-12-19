#define CONST 160

int nmos1_p6 = 6;
int nmos2_p9 = 9;
int pmos1_p10 = 10;
int pmos2_p11 = 11;


void setup() {
  pinMode(nmos1_p6, OUTPUT);
  pinMode(nmos2_p9, OUTPUT);
  pinMode(pmos1_p10, OUTPUT);
  pinMode(pmos2_p11, OUTPUT);
}

/* digitalWrite */
void Cw();
void Ccw();
/* analogWrite */
void Cw_pwm01();
void Cw_pwm10();
void Ccw_pwm01();
void Ccw_pwm10();
void Brake();


void loop() {
    
  Cw();
  analogWrite(pmos1_p10, 255 - CONST);
  analogWrite(nmos2_p9, CONST);
  delay(2000);               
  Brake(); 
  

  Ccw();
  analogWrite(pmos2_p11, CONST);
  analogWrite(nmos1_p6, 255 - CONST);
  delay(2000);
  Brake();
}




void Cw()
{
  digitalWrite(pmos1_p10, LOW);
  digitalWrite(nmos2_p9, HIGH);
  delay(2000);               
  digitalWrite(pmos1_p10, HIGH);
  digitalWrite(nmos2_p9, LOW);
  delay(1000);               
}

void Ccw()
{
  digitalWrite(pmos2_p11, LOW);
  digitalWrite(nmos1_p6, HIGH);
  delay(2000);               
  digitalWrite(pmos2_p11, HIGH);
  digitalWrite(nmos1_p6, LOW);
  delay(1000);               
}

// Gradually slow cw
void Cw_pwm10()
{
  for(int i = 0; i < 256; i++){
        analogWrite(pmos1_p10, i);
        analogWrite(nmos2_p9, 255 - i);
        delay(50);               
  }
}


// Gradually fast cw
void Cw_pwm01()
{
  for(int i = 0; i < 256; i++){
        analogWrite(pmos1_p10, 255 - i);
        analogWrite(nmos2_p9, i);
        delay(50);               
  }
}


// Gradually slow ccw
void Ccw_pwm10()
{
  for(int i = 0; i < 256; i++){
        analogWrite(pmos2_p11, i);
        analogWrite(nmos1_p6, 255 - i);
        delay(50);               
  }
}

// Gradually fast ccw
void Ccw_pwm01()
{
  for(int i = 0; i < 256; i++){
        analogWrite(pmos2_p11, 255 - i);
        analogWrite(nmos1_p6, i);
        delay(50);               
  }
}


// Brake
void Brake()
{
  digitalWrite(pmos1_p10, HIGH);
  digitalWrite(pmos2_p11, HIGH);
  digitalWrite(nmos1_p6, LOW);
  digitalWrite(nmos2_p9, LOW);
  delay(500);
}

