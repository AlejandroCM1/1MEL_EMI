// include the library code:
#include <Keypad.h> // Añade la librería del teclado.

const byte ROWS = 4; //Configura 4 filas.
const byte COLS = 4; //Configura 4 filas.
char keys[ROWS][COLS] = { // asigna a cada tecla del teclado, una variable.
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; //Define los pines de salida de las filas del teclado.
byte colPins[COLS] = {A4, A5, 4, 10}; //Define los pines de salida de las columnas del teclado.

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Le decimos a la librería del teclado, cuáles son los pines referentes a las filas y columnas previamente definidos.

#include <LiquidCrystal.h> // Incluimos la librería de la pantalla.

const int rs = 12, en = 11, d4 = 5, d5 = 6, d6 = 3, d7 = 2; // Asigna a cada pin de salida de la pantalla, un pin de entrada en el Arduino.
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);// Define los pines de la pantalla que se van a usar.
int operacion;// Se definen las variables que se van a usar.
int res;
char igual;
int NumI;
int NumII;
char op;
char reset;
char aux1;
char aux2;
void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2); // Define el número de columnas y filas de la pantalla.
  lcd.setCursor(0, 0); // Coloca el cursor en la primera casilla de la primera fila.
  lcd.print ("Calculadora:"); // Estabalece un mensaje fijo en la primera línea.
  lcd.setCursor(0, 1); // Coloca el cursor en la primera posición de la segunda fila.


}

void loop() {

  do
  {
    aux1 = keypad.getKey(); //Conseguir el valor de una tecla y lo asigna a la variable aux1, que es tipo "caracter".*****************************FASE 1*********************************
    Serial.print("NumI vale: ");//Comprobacion en puerto serie.
  Serial.println(NumI);//Comprobacion en puerto serie.Imprime la variable NumI.
    if (String(aux1).toInt() <= 9 && String(aux1).toInt() >= 0) //si el dato introducido en aux1 (en modo int) es menor o igual a 9 y mayor o igual a cero, se guarda en la variable.
    {
      NumI = String(aux1).toInt() + NumI * 10;
    }

  }
  while (NumI <= 9 && NumI >= 0); // El bucle no avanza hasta que se introduce un signo de operación en la variable.
  Serial.print("NumI vale: ");//Comprobacion en puerto serie.
  Serial.println(NumI);//Comprobacion en puerto serie.Imprime la variable NumI.
  lcd.print(NumI); // escribe su símbolo en la pantalla.

  do
  {
    op = keypad.getKey(); //Conseguir el valor de una tecla y lo asigna a la variable op, que es tipo "caracter".*******************************FASE 2************************************
  }
  while (!op);// El bucle no avanza hasta que se introduce un valor no nulo en la variable.
  Serial.print("op vale: ");
  Serial.println(op);
  lcd.print(op); //Cada vez que se pulsa una tecla, escribe su símbolo en la pantalla.

  switch (op) //Se asigna un valor numérico a cada valor tipo caracter de la variable operación.
  {
    case '+':
      operacion = 0;
      break;
    case '-':
      operacion = 1;
      break;
    case '*':
      operacion = 2;
      break;
    case '/':
      operacion = 3;
      break;
  }
  Serial.print("operacion es: ");
  Serial.println(operacion);

  do
  {
    aux2 = keypad.getKey(); //Conseguir el valor de una tecla y lo asigna a la variable aux1, que es tipo "caracter".*****************************FASE 1*********************************
    if (String(aux2).toInt() <= 9 && String(aux2).toInt() >= 0) //si el dato introducido en aux1 (en modo int) es menor o igual a 9 y mayor o igual a cero, se guarda en la variable.
    {
      NumII = String(aux2).toInt() + NumII * 10;
    }

  }
  while (String(aux2).toInt() <= 9 && String(aux2).toInt() >= 0); // El bucle no avanza hasta que se introduce un signo de operación en la variable.
  Serial.print("NumII vale: ");//Comprobacion en puerto serie.
  Serial.println(NumII);//Comprobacion en puerto serie.Imprime la variable NumI.
  lcd.print(NumII); // escribe su símbolo en la pantalla.

  switch (operacion)// Se definen matemáticamente las operaciones, una vez conocidas todas las variables implicadas.
  {
    case 0:
      res = String(NumI).toInt() + (String(NumII).toInt()) ; //define la operación suma (traduciendo la variable tipo caracter a tipo Int).
      break;
    case 1:
      res = String(NumI).toInt() - (String(NumII).toInt()) ; //define la operación resta (traduciendo la variable tipo caracter a tipo Int).
      break;
    case 2:
      res = String(NumI).toInt() * (String(NumII).toInt()) ; //define la operación multiplicación (traduciendo la variable tipo caracter a tipo Int).
      break;
    case 3:
      res = String(NumI).toInt() / (String(NumII).toInt()) ; //define la operación división (traduciendo la variable tipo caracter a tipo Int).
      break;
  }

  do
  {
    igual = keypad.getKey(); //Conseguir el valor de una tecla y lo asigna a la variable igual, que es tipo "caracter".*********************************FASE 4****************************
  }
  while (igual != '='); // El bucle no avanza hasta que se introduce el valor '=' en la variable.
  Serial.print("= ");
  Serial.println(res);
  lcd.print(igual); //Escribe el simbolo = en pantalla.
  lcd.print(res);//Muestra el resultado en pantalla.

  do
  {
    reset = keypad.getKey();
  }
  while (reset != 'C'); //cuando se pulsa la tecla 'C', el bucle avanza.***********************************************************Fase 5************************************************
  Serial.print(reset);
  Serial.println(reset);

  operacion = 0;//Resetea la variable a valor 0.
  res = 0;//Resetea la variable a valor 0.
  igual = 0;//Resetea la variable a valor 0.
  NumI = 0;//Resetea la variable a valor 0.
  NumII = 0;//Resetea la variable a valor 0.
  op = 0;//Resetea la variable a valor 0.
  reset = 0;//Resetea la variable a valor 0.
  lcd.clear();//Resetea la pantalla LCD.
  lcd.setCursor(0, 0); // Coloca el cursor en la primera casilla de la primera fila.
  lcd.print ("Calculadora:"); // Estabalece un mensaje fijo en la primera línea.
  lcd.setCursor(0, 1); // Coloca el cursor en la primera posición de la segunda fila.


}
