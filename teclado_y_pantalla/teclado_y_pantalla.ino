// include the library code:
#include <Keypad.h> // Añade la librería del teclado.

const byte ROWS = 4; //Configura 4 filas.
const byte COLS = 3; //Configura 3 filas.
char keys[ROWS][COLS] = { // asigna a cada tecla del teclado, una variable.
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; //Define los pines de salida de las filas del teclado.
byte colPins[COLS] = {A4, A5, 4}; //Define los pines de salida de las columnas del teclado.

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Le decimos a la librería del teclado, cuáles son los pines referentes a las filas y columnas previamente definidos.

#include <LiquidCrystal.h> // Incluimos la librería de la pantalla.

const int rs = 12, en = 11, d4 = 5, d5 = 6, d6 = 3, d7 = 2; // Asigna a cada pin de salida de la pantalla, un pin de entrada en el Arduino.
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);// Define los pines de la pantalla que se van a usar.

void setup() {


  lcd.begin(16, 2); // Define el número de columnas y filas de la pantalla.
  lcd.setCursor(0, 0); // Coloca el cursor en la primera casilla de la primera fila.
  lcd.print ("Numeros:"); // Estabalece un mensaje fijo en la primera línea.
  lcd.setCursor(0, 1); // Coloca el cursor en la primera posición de la segunda fila.


}

void loop() {

  char key = keypad.getKey(); //Conseguir el valor de una tecla y lo asigna a la variable key, que es tipo "caracter".
  if (key) {
    lcd.print(key); //Cada vez que se pulsa una tecla, escribe su símbolo en la pantalla.
  }
}
