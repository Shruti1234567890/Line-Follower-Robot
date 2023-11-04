int S_A = 10;     //speed motor a
int M_Right1 = 2; //motor Right = +
int M_Right = 3;  //motor Right = -
int M_Left = 4;   //motor Left = -
int M_Left1 = 5;  //motor Left = +
int S_B = 9;      //speed motor b

int R_S = A0; //s Right
int C_S = A1; //s Centre
int L_S = A2; //s Left

void setup() 
{
pinMode(M_Left, OUTPUT);
pinMode(M_Right, OUTPUT);
pinMode(M_Left1, OUTPUT);
pinMode(M_Right1, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);

pinMode(L_S, INPUT);
pinMode(C_S, INPUT);
pinMode(R_S, INPUT);

analogWrite(S_A, 120); 
analogWrite(S_B, 120); 
delay(200);
}
void loop()
{  
if ((digitalRead(L_S) == 0)&&(digitalRead(C_S) == 1)&&(digitalRead(R_S) == 0)){
  forword();
  }

if ((digitalRead(L_S) == 1)&&(digitalRead(C_S) == 1)&&(digitalRead(R_S) == 0)){
  turnLeft();
  }
if ((digitalRead(L_S) == 1)&&(digitalRead(C_S) ==0)&&(digitalRead(R_S) == 0)) {
  turnLeft();
  }

if ((digitalRead(L_S) == 0)&&(digitalRead(C_S) == 1)&&(digitalRead(R_S) == 1)){
  turnRight();
  }
if ((digitalRead(L_S) == 0)&&(digitalRead(C_S) == 0)&&(digitalRead(R_S) == 1)){
  turnRight();
  }

if ((digitalRead(L_S) == 1)&&(digitalRead(C_S) == 1)&&(digitalRead(R_S) == 1)){
  Stop();
  }
}

void forword(){
digitalWrite(M_Right, HIGH);
digitalWrite(M_Left, HIGH);
}


void turnRight(){
digitalWrite(M_Right, LOW);
digitalWrite(M_Left, HIGH); 
}

void turnLeft(){
digitalWrite(M_Right, HIGH);
digitalWrite(M_Left, LOW);
}

void Stop(){
digitalWrite(M_Right, LOW);
digitalWrite(M_Left, LOW);
}
