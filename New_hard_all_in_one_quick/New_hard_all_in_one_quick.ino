//підключаємо бібліотеки
  #include <SoftwareSerial.h> // Бібліотека серійного порта
  #include <DFPlayer_Mini_Mp3.h> // Бібліотека МП3хи
  #include <Stepper_28BYJ.h> // Бібліотека Шаговика
  #include <RemoteReceiver.h> // Бібліотека радіокерування 315 МГц

//Оголошуємо цифрові контакти і змінні для них
  int buttonPin22 = 22; //кнопка2 - стіл щоденник
  int buttonPin23 = 23; //кнопка3 - ручка жаба
  int buttonPin24 = 24; //кнопка4 - пульт кварц-2
  int buttonPin25 = 25; //кнопка5 - любитель
  int buttonPin26 = 26; //кнопка6 - полки книги
  int buttonPin27 = 27; //кнопка7 - оскари
  int buttonPin28 = 28; //кнопка8 - датчики пол, але вони аналогові, так що... тут просто для ясності
  int buttonPin29 = 29; //кнопка9 - хлопушка
  int buttonPin30 = 30; //кнопка10 - тєлєжка
  int buttonPin31 = 31; //кнопка11 - датчик руху

  boolean w22 = 0; //проверка кнопки2
  boolean w23 = 0; //проверка кнопки3
  boolean w24 = 0; //проверка кнопки4
  boolean w25 = 0; //проверка кнопки5
  boolean w26 = 0; //проверка кнопки6
  boolean w27 = 0; //проверка кнопки7
  boolean w28 = 0; //проверка кнопки8
  boolean w29 = 0; //проверка кнопки9
  boolean w30 = 0; //проверка кнопки10
  boolean w31 = 0; //проверка кнопки11

  boolean q22 = 1; //проверка кнопки2
  boolean q23 = 1; //проверка кнопки3
  boolean q24 = 1; //проверка кнопки4
  boolean q25 = 1; //проверка кнопки5
  boolean q26 = 1; //проверка кнопки6
  boolean q27 = 1; //проверка кнопки7
  boolean q28 = 1; //проверка кнопки8
  boolean q29 = 1; //проверка кнопки9
  boolean q30 = 1; //проверка кнопки10
  boolean q31 = 1; //проверка кнопки11

  boolean rcA = 1; // змінні на радіокерування
  boolean rcB = 1;
  boolean rcC = 1;
  boolean rcD = 1;

//Оголошуємо аналогові контакти і змінні для них
  #define SENSOR_PINA0 A0
  #define SENSOR_PINA1 A1
  #define SENSOR_PINA2 A2
  #define SENSOR_PINA3 A3
  #define SENSOR_PINA4 A4
  #define SENSOR_PINA5 A5
  #define SENSOR_PINA6 A6
  #define SENSOR_PINA7 A7
  
  long valA0 = 0;
  long valA1 = 0;
  long valA2 = 0;
  long valA3 = 0;
  long valA4 = 0;
  long valA5 = 0;
  long valA6 = 0;
  long valA7 = 0;

  boolean qA0 = 0;
  boolean qA1 = 0;
  boolean qA2 = 0;
  boolean qA3 = 0;
  boolean qA4 = 0;
  boolean qA5 = 0;
  boolean qA6 = 0;
  boolean qA7 = 0;

  boolean wA0 = 0;
  boolean wA1 = 0;
  boolean wA2 = 0;
  boolean wA3 = 0;
  boolean wA4 = 0;
  boolean wA5 = 0;
  boolean wA6 = 0;
  boolean wA7 = 0; 
//Оголошуємо контакти, змінні і кількість кроків на оберт для Шаговика, а також - пару контактів для перемотки
  #define STEPS 4096
  Stepper_28BYJ stepper(STEPS, 35, 37, 39, 41);

  int buttonPin36 = 36;
  int buttonPin38 = 38;
  boolean q34 = 0;
//Оголошуємо контакти і змінні для реле
  int rel42 = 42;
  int rel43 = 43;
  int rel44 = 44;
  int rel45 = 45;
  int rel46 = 46;
  int rel47 = 47;
  int rel48 = 48;
  int rel49 = 49;

  boolean w42 = 0; //проверка кнопки2
  boolean w43 = 0; //проверка кнопки3
  boolean w44 = 0; //проверка кнопки4
  boolean w45 = 0; //проверка кнопки5
  boolean w46 = 0; //проверка кнопки6
  boolean w47 = 0; //проверка кнопки7
  boolean w48 = 0; //проверка кнопки8
  boolean w49 = 0; //проверка кнопки9

  boolean telega = 0;

  int on = LOW;
  int off = HIGH;
//Оголошуємо контакти для радіокерування
  /*int rc1 = 2;
  int rc2 = 3;
  int rc3 = 4;
  int rc4 = 5;
  int rc5 = 8;
  int rc6 = 9;
  int rc7 = 10;
  int rc8 = 11;
  */
void setup()
{

  RemoteReceiver::init(0, 1, showCode); // налаштування приймача 315 МГц на роботу

//ВИЗНАЧАЄМО ЦИФРОВІ ВХОДИ І ПІДТЯГУЄМО КНОПКИ ВБУД РЕЗИСТОРОМ
  pinMode(buttonPin22, INPUT); //Ініціалізація кнопки
  digitalWrite(buttonPin22, HIGH); //Підтягування кнопки доверху вбудованим резистором 20к

  pinMode(buttonPin23, INPUT);
  digitalWrite(buttonPin23, HIGH);

  pinMode(buttonPin24, INPUT);
  digitalWrite(buttonPin24, HIGH);

  pinMode(buttonPin25, INPUT);
  digitalWrite(buttonPin25, HIGH);

  pinMode(buttonPin26, INPUT);
  digitalWrite(buttonPin26, HIGH);

  pinMode(buttonPin27, INPUT);
  digitalWrite(buttonPin27, HIGH);

  pinMode(buttonPin28, INPUT);
  digitalWrite(buttonPin28, HIGH);

  pinMode(buttonPin29, INPUT);
  digitalWrite(buttonPin29, HIGH);

  pinMode(buttonPin30, INPUT);
  digitalWrite(buttonPin30, HIGH);

  pinMode(buttonPin31, INPUT);
  digitalWrite(buttonPin31, HIGH);
// сетуп для МП3
    Serial.begin (9600);
    mp3_set_serial (Serial);  //set Serial for DFPlayer-mini mp3 module
    mp3_set_volume (30);
//ВИЗНАЧАЄМО ВХОДИ ДЛЯ ШАГОВИКА, ЗАДАЄМО ЙОГО ШВИДКІСТЬ І ПІДТЯГУЄМО КНОПКИ ВБУД РЕЗИСТОРОМ
  
  pinMode(buttonPin36, INPUT);
  //digitalWrite(buttonPin36, HIGH);
  
  pinMode(buttonPin38, INPUT);
  //digitalWrite(buttonPin38, HIGH);

  stepper.setSpeed(14);  // Встановимо швидкість крокового двигуна
//ВИЗНАЧАЄМО ВИХОДИ ДЛЯ РЕЛЕ І ПІДТЯГУЄМО КНОПКИ ВБУД РЕЗИСТОРОМ
  pinMode(rel42, OUTPUT);
  digitalWrite(rel42, HIGH);

  pinMode(rel43, OUTPUT);
  digitalWrite(rel43, HIGH);

  pinMode(rel44, OUTPUT);
  digitalWrite(rel44, HIGH);

  pinMode(rel45, OUTPUT);
  digitalWrite(rel45, HIGH);

  pinMode(rel46, OUTPUT);
  digitalWrite(rel46, HIGH);

  pinMode(rel47, OUTPUT);
  digitalWrite(rel47, HIGH);

  pinMode(rel48, OUTPUT);
  digitalWrite(rel48, HIGH);

  pinMode(rel49, OUTPUT);
  digitalWrite(rel49, HIGH);

/*/ВИЗНАЧАЄМО ВИХОДИ ДЛЯ РАДІОКЕРУВАННЯ
  pinMode(rc1, INPUT);
  pinMode(rc2, INPUT);
  pinMode(rc3, INPUT);
  pinMode(rc4, INPUT);
  pinMode(rc5, INPUT);
  pinMode(rc6, INPUT);
  pinMode(rc7, INPUT);
  pinMode(rc8, INPUT);
*/
}

void showCode(unsigned long receivedCode, unsigned int period) 
{
    
  if (receivedCode == 531387) // Button A code
  {
    rcA = 0;
  }

  if (receivedCode == 531369) // Button B code
  {
    rcB = 0;
  }

  if (receivedCode == 531363) // Button C code
  {
    rcC = 0;
  }

  if (receivedCode == 531361) // Button D code
  {
    rcD = 0;
  }

}
void loop()
{
//КОД
 //// 1Стіл щоденник
    if (digitalRead(buttonPin22) == LOW)
    {
      delay(30); // защита от дребезга кнопки.    
      q22 = 0; // меняем значение q  напротивоположное 0 на 1 или 1 на 0.
    }

    if (digitalRead(buttonPin22) == HIGH && w22 == 0 && q22 == 0) // если кнопка 11 нажата и перед этим была отжата
    {
      delay(30); // защита от дребезга кнопки.    
      w22 = 1; // меняем значение w на 1.
      q22 = 1; // меняем значение w на 1.

      mp3_play (1); // Здравствуйте, мои ученики
      delay(101);
    }

    if (digitalRead(buttonPin22) == LOW)
    {
      delay(30); // защита от дребезга кнопки.    
      w22 = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }
 
 //// 2Ручка жаба
    if (digitalRead(buttonPin23) == HIGH) // якщо кнопка 23 при включенні була отжата
    {
      delay(30); // защита от дребезга размыкания кнопки.
      q23 = 0; // то меняем значение q22 на противоположное 0 на 1 или 1 на 0.
    }

    if ((digitalRead(buttonPin23) == LOW || rcB == 0) && w23 == 0 && q23 == 0)  // если кнопка 2 нажата (замкнута с 0) и перед этим была отжата
    {
      rcB = 1;
      delay(30); // защита от дребезга кнопки.
      w23 = 1; // меняем значение w22 на 1.
      q23 = 1; // меняем значение w22 на 1.

      digitalWrite (rel42, LOW);
      mp3_play (2); // грати файл 0002.мп3 (Вот это времена были)
      delay (50);  //тільки через 2 сек можна щось нажати
    }


    if (digitalRead(buttonPin23) == HIGH) // якщо кнопка 2 отжата
    {
      delay(30); // защита от дребезга размыкания кнопки.
      digitalWrite (rel42, HIGH);
      w23 = 0; // меняем значение w23 на противоположное 0 на 1 или 1 на 0.
    }

 //// 3Пульт кварц
    if (digitalRead(buttonPin24) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.    
      q24 = 0; // меняем значение q на противоположное 0 на 1 или 1 на 0.
    }

    if (digitalRead(buttonPin24) == LOW && w24 == 0 && q24 == 0) // если кнопка 10 нажата и перед этим была отжата
    {
      delay(30); // защита от дребезга кнопки.    
      w24 = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q24 = 1;

      digitalWrite (rel43, LOW);
      delay(101);
    }

    if (digitalRead(buttonPin24) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.   
      digitalWrite (rel43, HIGH); 
      w24 = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

 //// 4Любитель
    if (digitalRead(buttonPin25) == LOW)
    {
      delay(30); // защита от дребезга кнопки.
      q25 = 0; // меняем значение q на противоположное 0 на 1 или 1 на 0.
    }

    if ((digitalRead(buttonPin25) == HIGH || rcC == 0) && w25 == 0 && q25 == 0) // если кнопка нажата и перед этим была отжата
    {
      rcC = 1;
      delay(30); // защита от дребезга кнопки.
      w25 = 1; // меняем значение w23 на противоположное 0 на 1 или 1 на 0.
      q25 = 1;

      digitalWrite (rel44, LOW);
      mp3_play (3); // Это - самая старая камера моей коллекции
      delay(101);
    }

    if (digitalRead(buttonPin25) == LOW)
    {
      delay(30); // защита от дребезга кнопки.
      digitalWrite (rel44, HIGH);
      w25 = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

 //// 5Полка книжки
    if (digitalRead(buttonPin26) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.
      q26 = 0; // меняем значение q на противоположное 0 на 1 или 1 на 0.
    }
    if ((digitalRead(buttonPin26) == LOW  || rcD == 0) && w26 == 0 && q26 == 0)// если кнопка нажата и перед этим была отжата
    {
      rcD = 1;
      delay(30); // защита от дребезга кнопки.
      w26 = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q26 = 1;

      mp3_play (4); // Даа, мое святилище !
      delay (100);
      digitalWrite (rel45, LOW);
      
      delay(101);
    }

    if (digitalRead(buttonPin26) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.
    digitalWrite (rel45, HIGH);      
      w26 = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

 //// 6Оскари
    if (digitalRead(buttonPin27) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.    
      q27 = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.

    }

    if (digitalRead(buttonPin27) == LOW && w27 == 0 && q27 == 0) // если кнопка 5 нажата и перед этим была отжата
    {
      delay(30); // защита от дребезга кнопки.
      w27 = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q27 = 1;

      digitalWrite (rel46, LOW);
      mp3_play (5); // Великие гении кино !
      delay(60000);
      digitalWrite (rel46, HIGH);
    }

    if (digitalRead(buttonPin27) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.
    digitalWrite (rel46, HIGH);      
      w27 = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

 //// 7Датчики пол
    //робимо, щоб значення з датчика не розкидало
      for (int iA0 = 0; iA0 < 200; ++iA0)
      {
        valA0 = valA0 + analogRead(SENSOR_PINA0);
      }
      valA0 = valA0 / 50;
      Serial.println(valA0);
    //тактовий перемикач
      if (valA0 <= 500 && qA0 == 0 && wA0 == 0) // якщо датчики нажаті.
      {
        delay(30); // защита от дребезга кнопки.
        qA0 = 1; // меняем значение q на противоположное 0 на 1 или 1 на 0.

        digitalWrite (rel47, on); //переключаємо реле
        delay(101);
        Serial.println("ВКЛ"); //показує, що ВКЛ
      }
      if (valA0 >= 500 && qA0 == 1)
      {
        delay(30); // защита от дребезга кнопки.
        wA0 = 1;
      }

      if (valA0 <= 500 && qA0 == 1 && wA0 == 1) // якщо датчики нажаті.
      {
        delay(30); // защита от дребезга кнопки.
        qA0 = 0; // меняем значение q на противоположное 0 на 1 или 1 на 0.

        digitalWrite (rel47, off); //переключаємо реле
        delay(101);
        Serial.println("ВИКЛ"); //показує, що ВИКЛ
      }

      if (valA0 >= 500 && qA0 == 0)
      {
        delay(30); // защита от дребезга кнопки.
        wA0 = 0;
      }

 //// 8Хлопушка
    if (digitalRead(buttonPin29) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.
      q29 = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.

    }

    if (digitalRead(buttonPin29) == LOW && w29 == 0 && q29 == 0) // если кнопка 6 нажата и перед этим была отжата
    {
      delay(30); // защита от дребезга кнопки.
      w29 = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q29 = 1;

    mp3_play (6); //Гляньте на часы
    delay(101);
    stepper.step(-341 * 2); // 1 оберт
      delay(1500);
      stepper.step(-345); // 1 оберт
      delay(1500);
      stepper.step(-345 * 2); // 1 оберт
      delay(1500);
      stepper.step(-350 * 2); // 1 оберт
      delay(1500);
      stepper.step(-348 * 5); // 1 оберт
      delay(2000);

      stepper.step(-341 * 2); // 1 оберт
      delay(1500);
      stepper.step(-345); // 1 оберт
      delay(1500);
      stepper.step(-350 * 2); // 1 оберт
      delay(1500);
      stepper.step(-348 * 2); // 1 оберт
      delay(1500);
      stepper.step(-345 * 5); // 1 оберт
      delay(2000);
    }

    if (digitalRead(buttonPin29) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.
      w29 = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

 //// 9Тележка
    if (digitalRead(buttonPin30) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.    
      q30 = 0; // меняем значение q на противоположное 0 на 1 или 1 на 0.
      }

    if (digitalRead(buttonPin30) == LOW && w30 == 0 && q30 == 0) // если кнопка 7 нажата и перед этим была отжата
    {
      delay(30); // защита от дребезга кнопки.
      w30 = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q30 = 1;
      
      mp3_play (7); //Сцена первая, дубль первый
      delay(101);
      Serial.println ("Telega_ON");
          }

    if (digitalRead(buttonPin30) == HIGH)
    {
      delay(30); // защита от дребезга кнопки.
      w30 = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      Serial.println ("telega_OFF");
    }

 //// 10Датчик руху
    if ((digitalRead(buttonPin28) == LOW && q28 == 1 && digitalRead(buttonPin30) == LOW) || rcA == 0) //
        {
          rcA = 1;
          delay (50);
          q28 = 0;
      Serial.println ("Datcik_LOW");
      digitalWrite (rel48, LOW);
      mp3_play (8); //Стоп, снято !
      delay(1010);
    } 
    
    if (digitalRead(buttonPin28) == HIGH)
    {
      delay (50);
      q28 = 1;
      Serial.println ("Datchik_HIGH");
      digitalWrite (rel48, HIGH);
    } 
    //ШАГОВИК перемотка

  //Перемотка вперед
    if (digitalRead(buttonPin36) == HIGH) // если кнопка 2 нажата.
    {
      delay (10);
      stepper.step(-50); // Делаем 30 шагов в одну строну
    }
  //Перемотув назад
    if (digitalRead(buttonPin38) == HIGH) // если кнопка 3 нажата.
    {
      delay (10);
      stepper.step(50); // Делаем 30 шагов в другую строну
    }
  
  //Семпли для реле
  
    /*//Цифровий вхід - реж роботи: Кнопка-вимикач з таймером (реле вкл на деякий час. Кнопка віджата - реле викл)

      if (digitalRead(buttonPin) == LOW && w == 0) // если кнопка нажата.
      {
        delay(30); // защита от дребезга кнопки. 
        w = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.

        digitalWrite (rel2, LOW);
        delay(2000);
        digitalWrite (rel, HIGH);
      }

      if (digitalRead(buttonPin) == HIGH && w == 1) // если кнопка 12 нажата.
      {
        delay(30); // защита от дребезга кнопки.      
        w = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.

        digitalWrite (rel, HIGH);
        delay(2000);
      }
    //Аналоговий вхід - Режим роботи: Тактовий вимикач (кнопка нажалася, реле перемкнулося.Кнопка ще раз нажалася, реле знову перемкнулося)
      //робимо, щоб значення з датчика не розкидало
        for (int iA0 = 0; iA0 < 200; ++iA0)
        {
          valA0 = valA0 + analogRead(SENSOR_PINA0);
        }
        valA0 = valA0 / 50;
        Serial.println(valA0);
      //тактовий перемикач
        if (valA0 <= 500 && qA0 == 0 && wA0 == 0) // якщо датчики нажаті.
        {
          delay(200); // защита от дребезга кнопки.
          qA0 = 1; // меняем значение q на противоположное 0 на 1 или 1 на 0.

          digitalWrite (rel42, on); //переключаємо реле
          delay(101);
          Serial.println("ВКЛ"); //показує, що ВКЛ
        }
        if (valA0 >= 500 && qA0 == 1)
        {
          delay(200); // защита от дребезга кнопки.
          wA0 = 1;
        }

        if (valA0 <= 500 && qA0 == 1 && wA0 == 1) // якщо датчики нажаті.
        {
          delay(200); // защита от дребезга кнопки.
          qA0 = 0; // меняем значение q на противоположное 0 на 1 или 1 на 0.

          digitalWrite (rel42, off); //переключаємо реле
          delay(101);
          Serial.println("ВИКЛ"); //показує, що ВИКЛ
        }

        if (valA0 >= 500 && qA0 == 0)
        {
          delay(200); // защита от дребезга кнопки.
          wA0 = 0;
        } */
}

