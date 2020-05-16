ndo #include <Keypad.h>
#include <LiquidCrystal.h>
const int rs = 27, en = 26, d4 = 25, d5 = 24, d6 = 23, d7 = 22;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
////////////////////////////////////////////////////////////
//declaracion de variables
///////////////////////////////////////////////////////////
unsigned long Tiempo=0;
extern volatile unsigned long timer0_millis;
long periodo1=2000;
int i = 0; 
int j = 5;
char pulsacion = 0;
char tiempo[5] = "0000"; 
int tiempo2;
int tiempo3;
int f ;
int q ;
int h ;
int l ;
char tecla; 
byte indice = 0; // vector de tiempo
const byte Filas = 4;
const byte Cols = 3;
char Teclas[ Filas ][ Cols ] =
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte Pins_Filas[Filas] = {28, 29, 30, 31};
byte Pins_Cols[Cols] = {32, 33, 34};
Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols); //  para guardar el caracter en el momento en que se este eligiendo el tiempo
Keypad Teclado2 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols); //  para guarda el caracter en cualquier momento diferente en el que se elige el tiempo
byte led = 35;
byte motor = 36;
void valor0() // relacionamos cada caracter comn un numeropara para tener el valor de la decena de los minutos
{
  if (tiempo[0] == '0')
  {
    h= 0;
  }
  if (tiempo[0] == '1')
  {
    h= 1;
  }
  if (tiempo[0] == '2')
  {
    h = 2;
  }
  if (tiempo[0] == '3')
  {
    h = 3;
  }
  if (tiempo[0] == '4')
  {
    h = 4;
  }
  if (tiempo[0] == '5')
  {
    h = 5;
  }
  if (tiempo[0] == '6')
  {
    h = 6;
  }
  if (tiempo[0] == '7')
  {
    h = 7;
  }
  if (tiempo[0] == '8')
  {
    h = 8;
  }
  if (tiempo[0] == '9')
  {
    h = 9;
  }
}
void valor1()// relacionamos cada caracter comn un numeropara para tener el valor menos significativo de los munutos 
{
  if (tiempo[1] == '0')
  {
    q = 0;
  }
  if (tiempo[1] == '1')
  {
    q = 1;
  }
  if (tiempo[1] == '2')
  {
    q = 2;
  }
  if (tiempo[1] == '3')
  {
    q = 3;
  }
  if (tiempo[1] == '4')
  {
    q = 4;
  }
  if (tiempo[1] == '5')
  {
    q = 5;
  }
  if (tiempo[1] == '6')
  {
    q = 6;
  }
  if (tiempo[1] == '7')
  {
    q = 7;
  }
  if (tiempo[1] == '8')
  {
    q = 8;
  }
  if (tiempo[1] == '9')
  {
    q = 9;
  }
}
void valor2()// relacionamos cada caracter comn un numeropara para tener el valor de la decena de los segundos
{
{
  if (tiempo[2] == '0')
  {
    f = 0;
  }
  if (tiempo[2] == '1')
  {
    f = 1;
  }
  if (tiempo[2] == '2')
  {
    f = 2;
  }
  if (tiempo[2] == '3')
  {
    f = 3;
  }
  if (tiempo[2] == '4')
  {
    f = 4;
  }
  if (tiempo[2] == '5')
  {
    f = 5;
  }
  if (tiempo[2] == '6')
  {
    f = 6;
  }
  if (tiempo[2] == '7')
  {
    f = 7;
  }
  if (tiempo[2] == '8')
  {
    f = 8;
  }
  if (tiempo[2] == '9')
  {
    f = 9;
  }
}
void valor3()// relacionamos cada caracter comn un numeropara para tener el valor menos significativo de los segundos 
{
  if (tiempo[3] == '0')
  {
    l = 0;
  }
  if (tiempo[3] == '1')
  {
    l = 1;
  }
  if (tiempo[3] == '2')
  {
    l = 2;
  }
  if (tiempo[3] == '3')
  {
    l = 3;
  }
  if (tiempo[3] == '4')
  {
    l = 4;
  }
  if (tiempo[3] == '5')
  {
    l = 5;
  }
  if (tiempo[3] == '6')
  {
    l = 6;
  }
  if (tiempo[3] == '7')
  {
    l = 7;
  }
  if (tiempo[3] == '8')
  {
    l = 8;
  }
  if (tiempo[3] == '9')
  {
    l = 9;
  }
}

void setup()
{
  lcd.begin(16, 2);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
}
void Motor()// esta funcion hace que el motor funcione con el tiempo deseado por el usuario
{
    lcd.clear();
    lcd.setCursor(0, 0);  
    lcd.print("espere" ); 
    lcd.setCursor(0, 1);  
    lcd.print("un momento");
    Tiempo = millis();
    while (Tiempo<= tiempo2+tiempo3 &&  pulsacion != '#')
    {
    pulsacion = Teclado2.getKey();
    if (pulsacion == '#')
    {
      i = 1;
    }
    digitalWrite(36, HIGH); // 
    digitalWrite(35, LOW);
    }
}
void setMillis(unsigned long Tiempo){
  uint8_t oldSREG = SREG;                 // abrimos por defecto los parametro del timer0 para alterar las funciones de millis
  cli();                                  // alteramos los parametros
  Tiempo=0;
  timer0_millis = Tiempo;                 //Reiniciar la funcion millis() para reiniciar el loop.
  SREG = oldSREG;                         // guardamos el cambio del timer
}

void loop()
{
  valor0();                              //llamamos a las funciones para gusradar el valor de los caracteres
  valor1();
  valor2();
  valor3();
  switch (i)
  {
    case 0: digitalWrite(35, LOW); 
            digitalWrite(36, LOW); 
            lcd.clear();           // saludo de bienvenida
            lcd.setCursor(3, 0);
            lcd.print("Bienvenido");
            delay(1000);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("ingres el tiempo");
            lcd.setCursor(2, 1);
            lcd.print("de coccion");
            delay(1000);
            lcd.clear();
            i = 1;
            lcd.setCursor(5, 1);
            lcd.print("00:00");
            indice = 0;
            break;

    case 1: tecla = Teclado1.getKey(); // guardamos el valor igual a un tiempo
            lcd.setCursor(5, 0);
            lcd.print("tiempo");
            if (tecla) // si se pulsa cualquier tecla entra en este if
            {
              if (tecla != '*' && tecla != '#') // si la tecla es diferente a * o # para la siguiente if 
              {
                if (tiempo[1] != '6' && tiempo[1] != '7' && tiempo[1] != '8' && tiempo[1] != '9') // si el tercer vaolr del timpo no es mayor a 6 se gusradar 
                {
                  tiempo[indice] = tecla; // se guarda el caracter en la matris de tiempo y se muestra en la pantalla
                  indice++;
                  lcd.setCursor(j, 1);
                  lcd.print(tecla);
                  j++;
                  if (j == 7) // nos saltamos ":" para diferenciar los minutos de los segundo
                  {
                    j++;
                  }
                }
                else
                {
                  lcd.clear(); // si el 3 valor del tiempo es mallor a 6 dara error
                  lcd.setCursor(0, 0);
                  lcd.print("tiempo no valido");
                  delay(2000);
                  lcd.clear();
                  j = 5;
                  tiempo[1] = '0';
                  i = 0;
                  indice = 0;
                  
                }
              }
              else
              {
                lcd.clear(); // si en algun momento se oprime # o * manda error
                lcd.setCursor(0, 0);
                lcd.print("no es un carcter");
                lcd.setCursor(5, 1);
                lcd.print("valido");
                delay(2000);
                lcd.clear();
                indice = 0;
                i = 0;
              }
            }
            tiempo3 = (h*10+q)*60000; // convertimos minutos a milisegundos
            tiempo2 = (f*10+l)*1000; // convertimos segundo a milisegundos
            if (indice == 4 ) // cuando se llege al cuarto dijitos de tiempo entra en if para saber si quiere iniciar la coccion o no
            {
              lcd.clear();
              indice = 0;
              while (pulsacion != '*' && pulsacion != '#')
              {
                lcd.setCursor(0, 0);                                    
                lcd.print("Start=> *");                             
                lcd.setCursor(0, 1);                                    
                lcd.print("Cancel=> #");
                pulsacion = Teclado2.getKey();
                j = 5;
                if (pulsacion == '*')
                {
                  i = 2;
                  setMillis(Tiempo);// aplicamos el timer0
                }
                if (pulsacion == '#')
                {
                  i = 3;
                }
              }
            }
            break;
    case 2: 
            delay(50);
            Motor(); // aplicamos la libreria del motor
            lcd.clear();
            lcd.setCursor(0, 0);         
            lcd.print("coccion terminda");
            Tiempo = millis(); 
            if (Tiempo<= tiempo2+tiempo3+periodo1) // encendemos un led para denotar que termino la coccion
            {
             digitalWrite(36, LOW);
             digitalWrite(35, HIGH);
            }
            
            pulsacion = 0;
            i = 0;
            break;

    case 3: digitalWrite(36, LOW); //si se oprime "#" bota error
            digitalWrite(35, LOW);
            lcd.clear();
            lcd.setCursor(4, 0);
            lcd.print("Tiempo"); 
            lcd.setCursor(3, 1);
            lcd.print("cancelado");
            delay(2000);
            pulsacion = 0;
            indice = 0;
            i = 0 ; 
            tiempo[1] == '0';         
  }
}
