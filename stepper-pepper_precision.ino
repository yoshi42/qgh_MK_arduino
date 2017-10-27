//подключаем библиотеки шаговика
#include <Stepper_28BYJ.h>
// изменить количество шагов для вашего мотора
#define STEPS 4096
Stepper_28BYJ stepper(STEPS, 2, 3, 4, 5);

int buttonPin7 = 7;
int buttonPin8 = 8;
int buttonPin6 = 6;
boolean q7 = 0;

//контакти реле
#define SENSOR_PIN A0
int relay1 = 10;
int buttonPin12 = 12;
int relay2 = 9;

long val = 0;
boolean q11 = 0;
boolean x11 = 0;
boolean q12 = 0;
void setup()

{

  pinMode(buttonPin7, INPUT);
  digitalWrite(buttonPin7, HIGH);
  pinMode(buttonPin8, INPUT);
  digitalWrite(buttonPin8, HIGH);
  pinMode(buttonPin6, INPUT);
  digitalWrite(buttonPin6, HIGH);

  // установим скорость вращения об/мин
  stepper.setSpeed(14);

  ////реле
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);

  pinMode(buttonPin12, INPUT);
  digitalWrite(buttonPin12, HIGH);

  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, HIGH);

}

void loop()

//моторчик почав крутитися
{
  if (digitalRead(buttonPin7) == LOW && q7 == 0) // если кнопка 1 нажата.
  {
    q7 = 1; // меняем значение q7 на противоположное 0 на 1 или 1 на 0.
    delay(200); // защита от дребезга кнопки.

    /*stepper.step(-4120*2); // Переходим на 2ку
      delay(1000);
      stepper.step(-4120); // Переходим на 3ку
      delay(1000);
      stepper.step(-4100*2); // Переходим на 5ку
      delay(1000);
      stepper.step(-4100*2); // Переходим на 7ку
      delay(1000);
      stepper.step(-4080*5); // Переходим на 12ку
      delay(1000);
    */
    stepper.step(-341 * 2); // 1 оберт
    delay(1500);
    stepper.step(-345); // 1 оберт
    delay(1500);
    stepper.step(-341 * 2); // 1 оберт
    delay(1500);
    stepper.step(-341 * 2); // 1 оберт
    delay(1500);
    stepper.step(-341 * 5); // 1 оберт
    delay(2000);

    stepper.step(-341 * 2); // 1 оберт
    delay(1500);
    stepper.step(-345); // 1 оберт
    delay(1500);
    stepper.step(-341 * 2); // 1 оберт
    delay(1500);
    stepper.step(-341 * 2); // 1 оберт
    delay(1500);
    stepper.step(-341 * 5); // 1 оберт
    delay(2000);

    stepper.step(-341 * 2); // 1 оберт
    delay(1500);
    stepper.step(-345); // 1 оберт
    delay(1500);
    stepper.step(-341 * 2); // 1 оберт
    delay(1500);
    stepper.step(-341 * 2); // 1 оберт
    delay(1500);
    stepper.step(-341 * 5); // 1 оберт
    delay(2000);
  }

  if (digitalRead(buttonPin7) == HIGH)
  {
    q7 = 0; // меняем значение q на противоположное 0 на 1 или 1 на 0.
  }

  if (digitalRead(buttonPin8) == LOW) // если кнопка 2 нажата.
  {
    stepper.step(-15); // Делаем 15 шагов в одну строну
  }

  if (digitalRead(buttonPin6) == LOW) // если кнопка 3 нажата.
  {
    stepper.step(15); // Делаем 15 шагов в другую строну
  }

  ////моторчик докрутився
  /*
    //// релеха1 пішла :)

    /*робимо тактову кнопку: коли контакт замкнувся,
      реле перемкнулося і на 5 сек нічого робити не можна.
      Якщо ще раз замкнулося, то  * реле знову перемкнулося і
      на 2 сек знову зависло.
  */
  //робимо, щоб значення з датчика не розкидало

  for (int i = 0; i < 200; ++i)
  {
    val = val + analogRead(SENSOR_PIN);
  }
  val = val / 50;
  Serial.println(val);

  //зробили

  if (val <= 500 && q11 == 0 && x11 == 0) // якщо датчики нажаті.
  {
    q11 = 1; // меняем значение q11 на противоположное 0 на 1 или 1 на 0.
    delay(500); // защита от дребезга кнопки.

    digitalWrite (relay1, LOW); //переключаємо реле
    delay(1000);
    Serial.println("ВКЛ"); //показує, що ВКЛ
  }
  if (val >= 500 && q11 == 1)
  {
    x11 = 1;
  }

  if (val <= 500 && q11 == 1 && x11 == 1) // якщо датчики нажаті.
  {
    q11 = 0; // меняем значение q11 на противоположное 0 на 1 или 1 на 0.
    delay(500); // защита от дребезга кнопки.

    digitalWrite (relay1, HIGH); //переключаємо реле
    delay(1000);
    Serial.println("ВИКЛ"); //показує, що ВИКЛ
  }

  if (val >= 500 && q11 == 0)
  {
    x11 = 0;
  }

  //Прийшла



  //// релеха2 пішла :)

  /*робимо тактову кнопку: коли контакт замкнувся,
    реле перемкнулося і на 2 сек нічого робити не можна.
    Якщо ще раз замкнулося, то  * реле знову перемкнулося і
    на 2 сек знову зависло.
  */

  if (digitalRead(buttonPin12) == LOW && q12 == 0) // если кнопка 12 нажата.
  {
    q12 = 1; // меняем значение q12 на противоположное 0 на 1 или 1 на 0.
    delay(100); // защита от дребезга кнопки.

    digitalWrite (relay2, LOW);
    delay(20000);
    digitalWrite (relay2, HIGH);
  }

  if (digitalRead(buttonPin12) == HIGH && q12 == 1) // если кнопка 12 нажата.
  {
    q12 = 0; // меняем значение q12 на противоположное 0 на 1 или 1 на 0.
    delay(100); // защита от дребезга кнопки.

    digitalWrite (relay2, HIGH);
    delay(2000);
  }

  //Прийшла

}
