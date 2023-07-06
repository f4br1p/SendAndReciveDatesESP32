const int motorPin1 =13;    // 28BYJ48 In1
const int motorPin2 = 12;    // 28BYJ48 In2
const int motorPin3 = 14;   // 28BYJ48 In3
const int motorPin4 = 27;   // 28BYJ48 In4
const int motorPin5 = 26;    // 28BYJ48 In1
const int motorPin6 = 25;    // 28BYJ48 In2
const int motorPin7 = 33;   // 28BYJ48 In3
const int motorPin8 = 32;   // 28BYJ48 In4
const int motorPin9 = 35;    // 28BYJ48 In1
const int motorPin10 = 34;    // 28BYJ48 In2
const int motorPin11 = 18;   // 28BYJ48 In3
const int motorPin12 = 19;   // 28BYJ48 In4
const int ColectivoNum =0;
const char separador=',';
const int dataLenght=3;
int data[dataLenght];
String str="";
int Colectivo1=0;
int Colectivo2=0;
int Colectivo3=0;
      
//definicion variables
int motorSpeed = 2400;   //variable para fijar la velocidad
int stepCounter = 1019;     // contador para los pasos
int stepsPerRev = 4076;  // pasos para una vuelta completa

//tablas con la secuencia de encendido (descomentar la que necesiteis)
//secuencia 1-fase
const int numSteps = 4;
const int stepsLookup[4] = { B1000, B0100, B0010, B0001 };
const float Var=4076;
int a=0;
int b=0;
int c=0;
//secuencia 2-fases
//const int numSteps = 4;
//const int stepsLookup[4] = { B1100, B0110, B0011, B1001 };

//secuencia media fase
//const int numSteps = 8;
//const int stepsLookup[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };

//estas variables almacenan la cara actual de los motores
int motor1Cara = 0;
int motor2Cara = 0;
int motor3Cara = 0;


void setup()
{
  //declarar pines como salida
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  /*pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  pinMode(motorPin7, OUTPUT);
  pinMode(motorPin8, OUTPUT);
  pinMode(motorPin9, OUTPUT);
  pinMode(motorPin10, OUTPUT);
  pinMode(motorPin11, OUTPUT);
  pinMode(motorPin12, OUTPUT);*/
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available()){
    if(Serial.find(',')){
      str = Serial.readStringUntil('\n');
      Serial.println(str);
      const int dataLenght =3;
      for(int i=0;i<dataLenght;i++){
        int index = str.indexOf(separador);//lee hasta el separador
        data[i]=str.substring(0,index).toInt();
        str = str.substring(index + 1);
      }
      Colectivo1=(data[0]);
      /*Colectivo2=(data[1]);
      Colectivo3=(data[2]);*/
    }
    a=Colectivo1-motor1Cara;
    Serial.print("VARIABLE A:");
    Serial.println(a);
    /*b=Colectivo2-motor2Cara;
    Serial.print("VARIABLE B:");
    Serial.println(b);
    c=Colectivo3-motor3Cara;
    Serial.print("VARIABLE C:");
    Serial.println(c);*/
    if (a>0){
      for(int i=motor1Cara; i < Colectivo1;i++){
        for (int i = 0; i < 512; i++)
          {
            clockwise1();
            delayMicroseconds(motorSpeed); //Los microsegundos manejan la velocidad del motor. Menor valor, mayor velocidad.          
          }
          motor1Cara++;
      }
    }
    if (a<0){
      for(int i=motor1Cara; i > Colectivo1;i--){
        for (int i = 0; i < 512; i++)
          {
            anticlockwise1();
            delayMicroseconds(motorSpeed); //Los microsegundos manejan la velocidad del motor. Menor valor, mayor velocidad
          }
          motor1Cara--;
      }
    }
    /*if (b>0){
        for(int i=motor2Cara; i < Colectivo2;i++){
          for (int i = 0; i < 512; i++)
            {
              clockwise2();
              delayMicroseconds(motorSpeed); //Los microsegundos manejan la velocidad del motor. Menor valor, mayor velocidad.          
            }
            motor2Cara++;
        }
      }
    if (b<0){
      for(int i=motor2Cara; i >Colectivo2;i--){
        for (int i = 0; i < 512; i++)
          {
            anticlockwise2();
            delayMicroseconds(motorSpeed); //Los microsegundos manejan la velocidad del motor. Menor valor, mayor velocidad.
          }
          motor2Cara--;
      }
    }
    if (c>0){
        for(int i=motor3Cara; i < Colectivo3;i++){
          for (int i = 0; i < 512; i++)
            {
              clockwise3();
              delayMicroseconds(motorSpeed); //Los microsegundos manejan la velocidad del motor. Menor valor, mayor velocidad.          
            }
            motor3Cara++;
        }
      }
    if (c<0){
      for(int i=motor3Cara; i >Colectivo3 ;i--){
        for (int i = 0; i < 512; i++)
          {
            anticlockwise3();
            delayMicroseconds(motorSpeed); //Los microsegundos manejan la velocidad del motor. Menor valor, mayor velocidad.
          }
          motor3Cara--;
      }
    }*/
  }
}

void clockwise1()
{
  stepCounter++;
  if (stepCounter >= numSteps) stepCounter = 0;
  setOutput1(stepCounter);
}

void anticlockwise1()
{
  stepCounter--;
  if (stepCounter < 0) stepCounter = numSteps - 1;
  setOutput1(stepCounter);
}
/*void clockwise2()
{
  stepCounter++;
  if (stepCounter >= numSteps) stepCounter = 0;
  setOutput2(stepCounter);
}

void anticlockwise2()
{
  stepCounter--;
  if (stepCounter < 0) stepCounter = numSteps - 1;
  setOutput2(stepCounter);
}
void clockwise3()
{
  stepCounter++;
  if (stepCounter >= numSteps) stepCounter = 0;
  setOutput3(stepCounter);
}

void anticlockwise3()
{
  stepCounter--;
  if (stepCounter < 0) stepCounter = numSteps - 1;
  setOutput3(stepCounter);
}*/
void setOutput1(int step){
  digitalWrite(motorPin1, bitRead(stepsLookup[step], 0));
  digitalWrite(motorPin2, bitRead(stepsLookup[step], 1));
  digitalWrite(motorPin3, bitRead(stepsLookup[step], 2));
  digitalWrite(motorPin4, bitRead(stepsLookup[step], 3));
}
/*void setOutput2(int step){
  digitalWrite(motorPin5, bitRead(stepsLookup[step], 0));
  digitalWrite(motorPin6, bitRead(stepsLookup[step], 1));
  digitalWrite(motorPin7, bitRead(stepsLookup[step], 2));
  digitalWrite(motorPin8, bitRead(stepsLookup[step], 3));
}
void setOutput3(int step)
{
  digitalWrite(motorPin9, bitRead(stepsLookup[step], 0));
  digitalWrite(motorPin10, bitRead(stepsLookup[step], 1));
  digitalWrite(motorPin11, bitRead(stepsLookup[step], 2));
  digitalWrite(motorPin12, bitRead(stepsLookup[step], 3));
}*/