//підключаємо бібліотеки
  #include <DFPlayer_Mini_Mp3.h> // Бібліотека МП3хи
  #include <RemoteReceiver.h>
//Оголошуємо контакти і змінні

  //1st room sensors
    int sens_light = 30; //датчик освітлення: горить = LOW, не горить = HIGH
    int sens_fakel1 = 31;
    int sens_fakel2 = 32;
    int sens_fakel3 = 33;
    int sens_fakel4 = 34;
    int sens_fakel5 = 35;
    int sens_fakel6 = 36;
    int sens_fakel7 = 37;

  //1st room actuators
    int rel_door_fake =22;
    int rel_door1 = 23;

    int led_fakel12 = 38;
    int led_fakel3 = 39;
    int led_fakel4 = 40;
    int led_fakel5 = 41;
    int led_fakel6 = 42;
    int led_fakel7 = 43;

  //1st room global flags
    boolean q_light_done = 0; // флаг, що завдання1 виконане
    byte counter_fakely = 0; // при значенні counter_fakely = 6, останній факел вставлено правильно, завдання виконане
 
  //1st room local flags
    boolean w_light = 0; //flags for light sensor
    boolean q_light = 1;
    boolean w_open_fake = 0;
    boolean w_open_door1 = 0;
    byte last_fakely = 0;

  //2nd room sensors
    int sens_cherep = A0;
    byte micPin = A1;

  //2nd room actuators
    int rel_lampa = 24;
    int rel_sunduk = 25;
    int rel_kletka = 26;

  //2nd room global flags
    boolean q_sunduk_done = 0; // флаг, що сундук відстукав
    boolean q_cherep_done = 0; // флаг, що череп - дан

  //2nd room local flags
    boolean w_open_sunduk = 0;
    boolean w_open_kletka = 0;
    boolean q_cherep = 1;
    boolean w_cherep = 0;

  //2nd room knock_setup
    int dotDuration = 200; //dot duration time
    int threshold = 150;
    boolean listenFlag = false;

  //3rd room sensors
    int sens_cracken = 44;

    int sens_bochka0 = A2;
    int sens_bochka1 = A3;
    int sens_bochka2 = A4;
    int sens_bochka3 = A5;
    int sens_bochka4 = A6;
    int sens_bochka5 = A7;
    int sens_bochka6 = A8;
    int sens_bochka7 = A9;

    int sens_podsvechnik1 = A10;
    int sens_podsvechnik2 = A11;
    int sens_podsvechnik3 = A12;
    int sens_podsvechnik4 = A13;

    int sens_armikrog1 = A14;
    int sens_armikrog2 = A15;
    int sens_armikrog3 = 20;
    int sens_armikrog4 = 21;

    int sens_kartina1 = 6;
    int sens_kartina2 = 7;
    int sens_kartina3 = 8;
    int sens_kartina4 = 9;

    int sens_korabl1 = 10;
    int sens_korabl2 = 11;
    int sens_korabl3 = 12;
    int sens_korabl4 = 5;

  //3rd room actuators
    int rel_cracken = 27;
    int rel_led_cracken = 28;
    int rel_8 = 47;

    int led_cracken = 45;

    int rel_moneta1 = 46;
    int rel_moneta2 = 29;
    int rel_moneta3 = 48;
    int rel_moneta4 = 49;
    int rel_moneta5 = 50;
    int rel_door2 = 51;
    int rel_door3 = 52;
    int rel_prikol = 53;


  //3rd room global flags
    boolean q_arm_done = 0; //флаг, що армікрог - дан
    boolean q_podsvechniki_done = 0; //флаг, що підсвічники - дан
    boolean q_korabliki_done = 0; // флаг, що кораблики - дан
    boolean q_kartiny_done = 0; // флаг, що картини - дан
    long bochka_counter = 0; //счьотчик монет на бочці
    boolean q_open_cracken_done = 0; // флаг, що ніша для кракена відкрилася
    boolean q_cracken_done = 0; //флаг, що кракен дан
    boolean q_bochka_done = 0; // флаг, що бочка - дан
    boolean q_bochka_no_cherep_done = 0;

  //3rd room local flags
    boolean w_fakel12 = 0;
    boolean w_fakel3 = 0;
    boolean w_fakel4 = 0;
    boolean w_fakel5 = 0;
    boolean w_fakel6 = 0;
    boolean w_fakel7 = 0;

    boolean q_arm = 1;
    boolean w_arm = 0;
    boolean q_podsv = 1;
    boolean w_podsv = 0;
    boolean q_korabl = 1;
    boolean w_korabl = 0;
    boolean q_kart = 1;
    boolean w_kart = 0;
    boolean q_crack = 1;
    boolean w_crack = 0;
    boolean w_open_cracken = 0;
    boolean q_bochka = 1;
    boolean w_bochka = 0;
    boolean q_bochka_no_cherep = 1;
    boolean w_bochka_no_cherep = 0;
    boolean q_bochka0 = 1;
    boolean w_bochka0 = 0;
    boolean q_bochka1 = 1;
    boolean w_bochka1 = 0;
    boolean q_bochka2 = 1;
    boolean w_bochka2 = 0;
    boolean q_bochka3 = 1;
    boolean w_bochka3 = 0;
    boolean q_bochka4 = 1;
    boolean w_bochka4 = 0;
    boolean q_bochka5 = 1;
    boolean w_bochka5 = 0;
    boolean q_bochka6 = 1;
    boolean w_bochka6 = 0;
    boolean q_bochka7 = 1;
    boolean w_bochka7 = 0;
    boolean w_open_moneta1 = 0;
    boolean w_open_moneta2 = 0;
    boolean w_open_moneta3 = 0;
    boolean w_open_moneta4 = 0;
    boolean w_open_moneta5 = 0;
    boolean w_exit = 0;
    boolean w_prikol = 0;
    boolean w_open_kletka_alternate = 0;
    boolean q_open_kletka_alternate = 0;
    boolean w_exit_alternate = 0;
    boolean q_exit_alternate = 0;
    boolean w_timer_one_hour = 0;
    boolean q_timer_one_hour = 0;

    //audio flags
    boolean w_audio0001 = 0;
    boolean q_audio0001 = 0;
    boolean w_audio0002 = 0;
    boolean q_audio0002 = 0;
    boolean w_audio0003 = 0;
    boolean q_audio0003 = 0;
    boolean w_audio0004 = 0;
    boolean q_audio0004 = 0;
    boolean w_audio0005 = 0;
    boolean q_audio0005 = 0;
    boolean w_audio0051 = 0;
    boolean q_audio0051 = 0;
    boolean w_audio0006 = 0;
    boolean q_audio0006 = 0;
    boolean w_audio0007 = 0;
    boolean q_audio0007 = 0;
    boolean w_audio0008 = 0;
    boolean q_audio0008 = 0;
    boolean w_audio0009 = 0;
    boolean q_audio0009 = 0;
    boolean w_audio0010 = 0;
    boolean q_audio0010 = 0;
    boolean w_audio0011 = 0;
    boolean q_audio0011 = 0;
    boolean w_audio0012 = 0;
    boolean q_audio0012 = 0;
    boolean w_audio0013 = 0;
    boolean q_audio0013 = 0;
    boolean w_audio0014 = 0;
    boolean q_audio0014 = 0;
    boolean w_audio0015 = 0;
    boolean q_audio0015 = 0;
    boolean w_audio0016 = 0;
    boolean q_audio0016 = 0;
    boolean w_audio0017 = 0;
    boolean q_audio0017 = 0;
    boolean w_audio0018 = 0;
    boolean q_audio0018 = 0;
    boolean w_audio0019 = 0;
    boolean q_audio0019 = 0;
    boolean w_audio00191 = 0;
    boolean q_audio00191 = 0;
    boolean w_audio0020 = 0;
    boolean q_audio0020 = 0;
    boolean w_audio0021 = 0;
    boolean q_audio0021 = 0;
    boolean w_audio0022 = 0;
    boolean q_audio0022 = 0;
    boolean w_audio0023 = 0;
    boolean q_audio0023 = 0;
    boolean w_audio0024 = 0;
    boolean q_audio0024 = 0;
    boolean w_audio0025 = 0;
    boolean q_audio0025 = 0;
    boolean w_audio0026 = 0;
    boolean q_audio0026 = 0;
    boolean w_audio0027 = 0;
    boolean q_audio0027 = 0;
    boolean w_audio0028 = 0;
    boolean q_audio0028 = 0;
    boolean w_audio0029 = 0;
    boolean q_audio0029 = 0;
    boolean w_audio0291 = 0;
    boolean q_audio0291 = 0;
    boolean w_audio0292 = 0;
    boolean q_audio0292 = 0;
    boolean w_audio0293 = 0;
    boolean q_audio0293 = 0;
    boolean w_audio0294 = 0;
    boolean q_audio0294 = 0;

    //3rd room audio timers and integers
    unsigned long t_audio0001;
    unsigned long t_audio0002;
    unsigned long t_audio0003;
    unsigned long t_audio0004;
    unsigned long t_audio0005;
    unsigned long t_audio0051;
    unsigned long t_audio0006;
    unsigned long t_audio0007;
    unsigned long t_audio0008;
    unsigned long t_audio0009;
    unsigned long t_audio0010;
    unsigned long t_audio0011;
    unsigned long t_audio0012;
    unsigned long t_audio0013;
    unsigned long t_audio0014;
    unsigned long t_audio0015;
    unsigned long t_audio0016;
    unsigned long t_audio0017;
    unsigned long t_audio0018;
    unsigned long t_audio0019;
    unsigned long t_audio00191;
    unsigned long t_audio0020;
    unsigned long t_audio0021;
    unsigned long t_audio0022;
    unsigned long t_audio0023;
    unsigned long t_audio0024;
    unsigned long t_audio0025;
    unsigned long t_audio0026;
    unsigned long t_audio0027;
    unsigned long t_audio0028;
    unsigned long t_audio0029;
    unsigned long t_audio0291;
    unsigned long t_audio0292;
    unsigned long t_audio0293;
    unsigned long t_audio0294;
    unsigned long t_open_kletka_alternate;
    unsigned long t_exit_alternate;
    unsigned long t_timer_one_hour;

//Створюємо таблицю морзе для декодера-енкодера
  static const struct {const char letter, *code;} MorseMap[] =
  {
    { 'A', ".-" },
    { 'B', "-..." },
    { 'C', "-.-." },
    { 'D', "-.." },
    { 'E', "." },
    { 'F', "..-." },
    { 'G', "--." },
    { 'H', "...." },
    { 'I', ".." },
    { 'J', ".---" },
    { 'K', ".-.-" },
    { 'L', ".-.." },
    { 'M', "--" },
    { 'N', "-." },
    { 'O', "---" },
    { 'P', ".--." },
    { 'Q', "--.-" },
    { 'R', ".-." },
    { 'S', "..." },
    { 'T', "-" },
    { 'U', "..-" },
    { 'V', "...-" },
    { 'W', ".--" },
    { 'X', "-..-" },
    { 'Y', "-.--" },
    { 'Z', "--.." },
    { ' ', "     " }, //Gap between word, seven units 
      
    { '1', ".----" },
    { '2', "..---" },
    { '3', "...--" },
    { '4', "....-" },
    { '5', "....." },
    { '6', "-...." },
    { '7', "--..." },
    { '8', "---.." },
    { '9', "----." },
    { '0', "-----" },
      
    { '.', ".-.-.-" },
    { ',', "--..--" },
    { '?', "..--.." },
    { '!', "-.-.--" },
    { ':', "---..." },
    { ';', "-.-.-." },
    { '(', "-.--." },
    { ')', "-.--.-" },
    { '"', ".-..-." },
    { '@', ".--.-." },
    { '&', ".-..." },
  };

void setup() // попередня настройка проги. Виконується 1 раз з моменту запуску
  {

  // сетуп для МП3х
  Serial.begin (9600);  //SFX sunduk
  Serial1.begin (9600); //sfx 1st room
  Serial2.begin (9600); //Music all
  Serial3.begin (9600); //MAIN+ Voice, SFX 1st, 2nd room

  mp3_set_serial(Serial1);
  mp3_set_volume(25);
  mp3_play(70);

  setup_all_pins(); //сетуп для всіх вводів-виводів
  ready_to_start(); //початковий стан всіх релех і ледів
  RemoteReceiver::init(0, 1, showCode); //interrupt 0 - пін 2. Настройка на проходження хоча б одного пакету
  }

void setup_all_pins() // призначення пінів всіх входів-виходів
  {
    //1st room sensors
      pinMode(sens_light, INPUT_PULLUP); //датчик освітлення: горить = LOW, не горить = HIGH
      pinMode(sens_fakel1, INPUT_PULLUP);
      pinMode(sens_fakel2, INPUT_PULLUP);
      pinMode(sens_fakel3, INPUT_PULLUP);
      pinMode(sens_fakel4, INPUT_PULLUP);
      pinMode(sens_fakel5, INPUT_PULLUP);
      pinMode(sens_fakel6, INPUT_PULLUP);
      pinMode(sens_fakel7, INPUT_PULLUP);

    //1st room actuators
      pinMode(rel_door_fake, OUTPUT);
      pinMode(rel_door1, OUTPUT);

      pinMode(led_fakel12, OUTPUT);
      pinMode(led_fakel3, OUTPUT);
      pinMode(led_fakel4, OUTPUT);
      pinMode(led_fakel5, OUTPUT);
      pinMode(led_fakel6, OUTPUT);
      pinMode(led_fakel7, OUTPUT);

    //2nd room sensors
      //sens_cherep  і так працюють, як входи аналогові

    //2nd room actuators
      pinMode(rel_lampa, OUTPUT);
      pinMode(rel_sunduk, OUTPUT);
      pinMode(rel_kletka, OUTPUT);
      pinMode(micPin,INPUT);


    //3rd room sensors
      pinMode(sens_cracken, INPUT_PULLUP);

      //int sens_bochka0 = A2; // і так працюють, як входи аналогові
      //int sens_bochka1 = A3; // і так працюють, як входи аналогові
      //int sens_bochka2 = A4; // і так працюють, як входи аналогові
      //int sens_bochka3 = A5; // і так працюють, як входи аналогові
      //int sens_bochka4 = A6; // і так працюють, як входи аналогові
      //int sens_bochka5 = A7; // і так працюють, як входи аналогові
      //int sens_bochka6 = A8; // і так працюють, як входи аналогові
      //int sens_bochka7 = A9; // і так працюють, як входи аналогові

      pinMode(sens_podsvechnik1, INPUT_PULLUP); // робимо з аналогового входу цифровий з подтяжкою
      pinMode(sens_podsvechnik2, INPUT_PULLUP); // робимо з аналогового входу цифровий з подтяжкою
      pinMode(sens_podsvechnik3, INPUT_PULLUP); // робимо з аналогового входу цифровий з подтяжкою
      pinMode(sens_podsvechnik4, INPUT_PULLUP); // робимо з аналогового входу цифровий з подтяжкою

      pinMode(sens_armikrog1, INPUT_PULLUP); // робимо з аналогового входу цифровий з подтяжкою
      pinMode(sens_armikrog2, INPUT_PULLUP);  // робимо з аналогового входу цифровий з подтяжкою
      pinMode(sens_armikrog3, INPUT_PULLUP);
      pinMode(sens_armikrog4, INPUT_PULLUP);

      pinMode(sens_kartina1, INPUT_PULLUP);
      pinMode(sens_kartina2, INPUT_PULLUP);
      pinMode(sens_kartina3, INPUT_PULLUP);
      pinMode(sens_kartina4, INPUT_PULLUP);

      pinMode(sens_korabl1, INPUT_PULLUP);
      pinMode(sens_korabl2, INPUT_PULLUP);
      pinMode(sens_korabl3, INPUT_PULLUP);
      pinMode(sens_korabl4, INPUT_PULLUP);

    //3rd room actuators
      pinMode(rel_cracken, OUTPUT);
      pinMode(rel_led_cracken, OUTPUT);
      pinMode(rel_8, OUTPUT);

      pinMode(led_cracken, OUTPUT);

      pinMode(rel_moneta1, OUTPUT);
      pinMode(rel_moneta2, OUTPUT);
      pinMode(rel_moneta3, OUTPUT);
      pinMode(rel_moneta4, OUTPUT);
      pinMode(rel_moneta5, OUTPUT);
      pinMode(rel_door2, OUTPUT);
      pinMode(rel_door3, OUTPUT);
      pinMode(rel_prikol, OUTPUT);
  }

void ready_to_start() //обнулення флагів і релех
  {
  //початковий стан всіх релех і виводів
  digitalWrite(rel_door_fake, HIGH);
  digitalWrite(rel_door1, LOW);

  digitalWrite(led_fakel12, LOW);
  digitalWrite(led_fakel3, LOW);
  digitalWrite(led_fakel4, LOW);
  digitalWrite(led_fakel5, LOW);
  digitalWrite(led_fakel6, LOW);
  digitalWrite(led_fakel7, LOW);

  digitalWrite(rel_lampa, HIGH);
  digitalWrite(rel_sunduk, HIGH);
  digitalWrite(rel_kletka, HIGH);

  digitalWrite(rel_cracken, HIGH);
  digitalWrite(led_cracken, LOW);
  digitalWrite(rel_led_cracken, HIGH);
  digitalWrite(rel_8, HIGH);

  digitalWrite(rel_moneta1, HIGH);
  digitalWrite(rel_moneta2, HIGH);
  digitalWrite(rel_moneta3, HIGH);
  digitalWrite(rel_moneta4, HIGH);
  digitalWrite(rel_moneta5, HIGH);
  digitalWrite(rel_door2, HIGH);
  digitalWrite(rel_door3, HIGH);
  digitalWrite(rel_prikol, HIGH);

  //обнулення всіх флагів (це на даний момент непотрібна дія, але коли буде пульт управління, то - це необхідний луп. 
  //Щоб робити скидання системи без перезавантаження)

  q_light_done = 0; // флаг, що завдання1 виконане
  counter_fakely = 0; // при значенні counter_fakely = 6, останній факел вставлено правильно, завдання виконане

  q_sunduk_done = 0; // флаг, що сундук відстукав
  q_cherep_done = 0; // флаг, що череп - дан

  q_arm_done = 0; //флаг, що армікрог - дан
  q_podsvechniki_done = 0; //флаг, що підсвічники - дан
  q_korabliki_done = 0; // флаг, що кораблики - дан
  q_kartiny_done = 0; // флаг, що картини - дан
  bochka_counter = 0; //счьотчик монет на бочці
  q_open_cracken_done = 0; // флаг, що ніша для кракена відкрилася
  q_cracken_done = 0; //флаг, що кракен дан
  q_bochka_done = 0; // флаг, що бочка - дан
  }

void loop() //Логіка проги, порядку завдань
  {
    //1st room
    if (q_light_done == 0) //якщо завдання1 до цього не було виконане
      {
        pogasit_svet(); //старт завдання 1
      }

    else if(q_light_done == 1) //якщо виконане завд 1
      {
        while(w_open_fake == 0) // [щоб виконувалося 1 раз]
          {
            open_fake(); //відкрити ничку
            w_open_fake++;
          }
      }

    if(q_light_done == 1) //якщо виконане завд 1
      {
        fakel_easy(); //запустити завдання з факелами
      }
    
    if(counter_fakely == 5) //якщо завдання 2 виконане
      {
        while(w_open_door1 == 0) // [щоб виконувалося 1 раз]
          {
            open_door1(); //відкрити двері в 2 кімнату
            w_open_door1++;
          }
      }

  //2nd room
    if(counter_fakely == 5)
      {
       sunduk();
      }

    if(q_sunduk_done == 1) // якщо завдання 3 виконане
      {
        while(w_open_sunduk == 0) // [щоб виконувалося 1 раз]
          {
            open_sunduk(); //відкрити сундук
            w_open_sunduk++;
          }
      }

    if(w_open_sunduk == 1)
      { 
        cherep();
      }

if(w_open_sunduk == 1)
    //if(q_cherep_done == 1)
    //if(w_open_sunduk == 1)
      {
        audio0001();
        //audio0002();
        //audio0004();
        //while(w_open_kletka == 0) // [щоб виконувалося 1 раз]
          //{
            open_kletka_alternate();  //відкрити клітку 1 раз
            audio0026();
            audio0020();
            //w_open_kletka ++;
          //}
      }

  //3rd room
    armikrog();
    if(q_arm_done == 1)// якщо завдання 4 виконане
      {
        audio0010();
        audio0021();
        audio0027();
        while(w_open_moneta1 == 0) // [щоб виконувалося 1 раз]
          {
            open_moneta1();  //1 монета відпала
            delay(1000);
            mp3_set_serial(Serial2);
            mp3_set_volume(7);
            mp3_play(81);
            w_open_moneta1 ++;
          }
      }

    podsvechniki();
    if(q_podsvechniki_done == 1) // якщо завдання 5 виконане
      {
        audio0011();
        audio0022();
        audio0028();
        while(w_open_moneta2 == 0) // [щоб виконувалося 1 раз]
          {
            open_moneta2();  //1 монета відпала
            delay(1000);
            mp3_set_serial(Serial2);
            mp3_set_volume(5);
            mp3_play(82);
            w_open_moneta2 ++;
          }
      }

    korabliki();
    if(q_korabliki_done == 1) // якщо завдання 6 виконане
      {
        audio0012();
        audio0023();
        audio0291();
        while(w_open_moneta3 == 0) // [щоб виконувалося 1 раз]
          {
            open_moneta3();  //1 монета відпала
            delay(1000);
            mp3_set_serial(Serial2);
            mp3_set_volume(5);
            mp3_play(83);
            w_open_moneta3 ++;
          } 
      }

    kartiny();
    if(q_kartiny_done == 1) // якщо завдання 7 виконане
      {
        audio0013();
        audio0294();
        audio0292();
        while(w_open_moneta4 == 0) // [щоб виконувалося 1 раз]
        {
          open_moneta4();  //1 монета відпала
          delay(1000);
            mp3_set_serial(Serial2);
            mp3_set_volume(5);
            mp3_play(84);
          w_open_moneta4 ++;
        }
      }

    bochka_coin_counter();
    if(bochka_counter >= 4 && q_arm_done == 1 && q_korabliki_done == 1 && q_podsvechniki_done == 1 && q_kartiny_done == 1)
      {
        while(w_open_cracken == 0) // [щоб виконувалося 1 раз]
          {
            open_cracken();  //кракен відкрився
            w_open_cracken ++;
          }
        q_open_cracken_done = 1;
      }

    if(q_open_cracken_done == 1 && q_cracken_done == 0)
      {
        cracken();
      }

    if(q_cracken_done == 1) // якщо завдання 8 виконане
      {
        audio0014();
        audio0025();
        audio0293();
        while(w_open_moneta5 == 0) // [щоб виконувалося 1 раз]
          {
            open_moneta5();  //1 монета відпала
            delay(1000);
            mp3_set_serial(Serial2);
            mp3_set_volume(5);
            mp3_play(85);
            w_open_moneta5 ++;
          }
      }

    bochka();
    bochka_no_cherep();
    if (q_bochka_done == 1) // якщо всі монети на бочці і при цьому, попередні 5 завдань були виконані (прописано у void bochka)
      {
        //while(w_exit == 0) // [щоб виконувалося 1 раз]
            //{
              exit_alternate();
              //w_exit ++;
            //}
        /*while(w_prikol == 0) // [щоб виконувалося 1 раз]
            {
              prikol();
              w_prikol ++;
            }
        */      
      }
  } 

void pogasit_svet() //Завдання1 - вимкнути всі лампи в 1 кімнаті, спрацьовує датчик освітлення = відкриваються факели
 {
   if (digitalRead(sens_light) == LOW)
    {
      delay (50);
      q_light = 0;
    }

  if (digitalRead(sens_light) == HIGH && w_light == 0 && q_light == 0)
    {
      delay (50);
      w_light = 1;
      q_light = 1;

      q_light_done = 1;
      
      delay(50);
    }

  if (digitalRead(sens_light) == LOW)
    {
      delay (50); // защита от дребезга кнопки.
      w_light = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }
 }

void open_fake()
  {
    mp3_set_serial(Serial2);
    mp3_set_volume(20);
    mp3_play(64);

    mp3_set_serial(Serial1);
    mp3_pause();

    delay(10000);
    digitalWrite(rel_door_fake, LOW);
  }

//переписати цю хрєнь))
void fakely() //Завдання2 - перейти факелами по черзі до останніх підставок біля дверей = відкриваються двері
  {
    //два перші вставлені - світимо діод, ставимо флаг
    if(digitalRead(sens_fakel1) == LOW && digitalRead(sens_fakel2) == LOW) 
      {
        while(w_fakel12 == 0) // [щоб виконувалося 1 раз]
          {
            mp3_set_serial(Serial1);
            mp3_set_volume(20);
            mp3_play(52);// fx fakel burned

            delay (50);
            counter_fakely = 1;
            last_fakely = 0;
            digitalWrite(led_fakel12, HIGH);
            w_fakel12 = 1;
          }
      }
    //виймаємо один з 1-2го (залишається 1) - просто горить діод
    else if(digitalRead(sens_fakel1) == LOW || digitalRead(sens_fakel2) == LOW && counter_fakely == 1) 
      {
        delay (50);
        digitalWrite(led_fakel12, HIGH);
      }
    //якщо вийняті обидва (вставлено 0) - діод гасне
    else
      {
        delay (50);
        digitalWrite(led_fakel12, LOW);
        w_fakel12 = 0;
      }
    //вставлено в 1/2 і 3 - світимо і ставимо флаг
    if((digitalRead(sens_fakel1) == LOW || digitalRead(sens_fakel2) == LOW) && digitalRead(sens_fakel3) == LOW && last_fakely == 0)
      {
        while(w_fakel3 == 0)
          {
            mp3_set_serial(Serial1);
            mp3_set_volume(20);
            mp3_play(2);// fx fakel burned

            delay (50);
            counter_fakely = 2;
            last_fakely = 1;
            digitalWrite(led_fakel3, HIGH);
            w_fakel3 = 1;
          }
      }
    //виймаємо з 1/2 (вставлений тільки 3), але перед цим були вставлені обидва - просто горить діод
    else if(digitalRead(sens_fakel3) == LOW && last_fakely == 1)
      {
        delay (50);
        digitalWrite(led_fakel3, HIGH);
      }
    //не вставлений жоден - діод гасне
    else
      {
        delay (50);
        digitalWrite(led_fakel3, LOW);
        w_fakel3 = 0;
      }

    //вставлено 3 і 4 - світимо і ставимо флаг
    if(digitalRead(sens_fakel3) == LOW && digitalRead(sens_fakel4) == LOW && last_fakely == 1)
      {
        while(w_fakel4 == 0)
          {
            mp3_set_serial(Serial1);
            mp3_set_volume(20);
            mp3_play(2);// fx fakel burned

            delay (50);
            counter_fakely = 3;
            last_fakely = 2;
            digitalWrite(led_fakel4, HIGH);
            w_fakel4 = 1;
          }
      }
    //виймаємо 3 (вставлений тільки 4), але перед цим були вставлені обидва - просто горить діод
    else if(digitalRead(sens_fakel4) == LOW && last_fakely == 2)
      {
        delay (50);
        digitalWrite(led_fakel4, HIGH);
      }
    //не вставлений жоден - діод гасне
    else
      {
        delay (50);
        digitalWrite(led_fakel4, LOW);
        w_fakel4 = 0;
      }

    //вставлено 4 і 5 - світимо і ставимо флаг
    if(digitalRead(sens_fakel4) == LOW && digitalRead(sens_fakel5) == LOW && last_fakely == 2)
      {
        while (w_fakel5 == 0)
          {
            mp3_set_serial(Serial1);
            mp3_set_volume(20);
            mp3_play(2);// fx fakel burned

            delay (50);
            counter_fakely = 4;
            last_fakely = 3;
            digitalWrite(led_fakel5, HIGH);
            w_fakel5 = 1;
          }
      }
    //виймаємо 4 (вставлений тільки 5), але перед цим були вставлені обидва - просто горить діод
    else if(digitalRead(sens_fakel5) == LOW && last_fakely == 3)
      {
        delay (50);
        digitalWrite(led_fakel5, HIGH);
      }
    //не вставлений жоден - діод гасне
    else
      {
        delay (50);
        digitalWrite(led_fakel5, LOW);
        w_fakel5 = 0;
      }

    //вставлено 5 і 6 - світимо і ставимо флаг
    if(digitalRead(sens_fakel5) == LOW && digitalRead(sens_fakel6) == LOW && last_fakely == 3)
      {
        while (w_fakel6 == 0)
          {
            mp3_set_serial(Serial1);
            mp3_set_volume(20);
            mp3_play(2);// fx fakel burned

            delay (50);
            counter_fakely = 5;
            last_fakely = 4;
            digitalWrite(led_fakel5, HIGH);
            w_fakel6 = 1;
          }
      }
    //виймаємо 5 (вставлений тільки 6), але перед цим були вставлені обидва - просто горить діод
    else if(digitalRead(sens_fakel6) == LOW && last_fakely == 4)
      {
        delay (50);
        digitalWrite(led_fakel6, HIGH);
      }
    //не вставлений жоден - діод гасне
    else
      {
        delay (50);
        digitalWrite(led_fakel6, LOW);
        w_fakel6 = 0;
      }

        //вставлено 6 і 7 - світимо і ставимо флаг
    if(digitalRead(sens_fakel6) == LOW && digitalRead(sens_fakel7) == LOW && last_fakely == 4)
      {
        while(w_fakel7 == 0)
          {
            mp3_set_serial(Serial1);
            mp3_set_volume(20);
            mp3_play(2);// fx fakel burned

            delay (50);
            counter_fakely = 6;
            last_fakely = 5;
            digitalWrite(led_fakel7, HIGH);
            digitalWrite(led_fakel6, HIGH);
            w_fakel7 = 1;
          }
      }
    //не вставлений жоден - діод гасне
    else
      {
        delay (50);
        digitalWrite(led_fakel7, LOW);
        w_fakel7 = 0;
      }
  }

void open_door1()
  {
    delay(2000);
      mp3_set_serial(Serial2);
      mp3_set_volume(30);
      mp3_play(54);

      delay(4000);
      digitalWrite(led_fakel12, LOW);
      digitalWrite(led_fakel3, LOW);
      digitalWrite(led_fakel4, LOW);
      digitalWrite(led_fakel5, LOW);
      digitalWrite(led_fakel6, LOW);
      digitalWrite(led_fakel7, LOW);   
      delay(50);
      digitalWrite(rel_door1, HIGH);

      mp3_set_serial(Serial2);
      mp3_set_volume(15);
      mp3_play(71);
  }

void sunduk()
  {
    if(q_sunduk_done == 0)
      {
        say();
        delay(50);
        listen();
      }
  }
 //тіло проги "сундук мертвеца"
    
  void say()
  {
    //set led state
    String sayString = encode("O"); // codeword: "tuk tuk tuk"
    Serial.println(sayString);
    for(int i=0;i<=sayString.length();i++)
    {
      switch(sayString[i])
      {
      case '.': //dot
        mp3_set_serial(Serial3);
        mp3_set_volume(20);
        mp3_play(55); //Файл тук короткий
        delay(dotDuration);
        delay(dotDuration);
      break;
      case '-': //dash
        mp3_set_serial(Serial3);
        mp3_set_volume(20);      
        mp3_play(55); //Файл тук довгий
        delay(dotDuration*3);
        delay(dotDuration);
      break;
      //case ' ': //gap
      //  delay(dotDuration);
      }
    } 
  }

  String encode(const char *string)
  {  
    size_t i, j;
    String morseWord = "";
    for( i = 0; string[i]; ++i )
    {
      for( j = 0; j < sizeof MorseMap / sizeof *MorseMap; ++j )
      {
        if( toupper(string[i]) == MorseMap[j].letter )
        {
          morseWord += MorseMap[j].code;
          break;
        }
      }
      //morseWord += " "; //Add tailing space to seperate the chars
    }
    return morseWord;
  }

  String decode(String morse)
  {
    String msg = ""; 
    int lastPos = 0;
    int pos = morse.indexOf(' ');
    while( lastPos <= morse.lastIndexOf(' ') )
    {    
      for( int i = 0; i < sizeof MorseMap / sizeof *MorseMap; ++i )
      {
        if( morse.substring(lastPos, pos) == MorseMap[i].code )
        {
          msg += MorseMap[i].letter;
        }
      }
      lastPos = pos+1;
      pos = morse.indexOf(' ', lastPos);
      
      // Handle white-spaces between words (7 spaces)
      while( morse[lastPos] == ' ' && morse[pos+1] == ' ' )
      {
        pos ++;
      }
    }
    return msg;
  } 
   void listen()
  {
    unsigned long millisNow = 0;
    unsigned long millisPrew = 0;
    boolean knockFlag = false;
    boolean first = true;
    String listenString = "";
    long diff = 0;
    for (int i = 0;i<=2500;i++)
    {
      if (analogRead(micPin)>=200) //налаштування чутливості мікрофону
      {
        if (first)
        {
          first = false;
          millisNow = millis();
          millisPrew = millisNow;
        }
        millisPrew = millisNow;
        millisNow = millis();   
        delay(50);
        knockFlag = true;
        diff = millisNow-millisPrew;      
        Serial.print("diff = ");
        Serial.println(diff);
        mp3_set_serial(Serial3);
        mp3_set_volume(40);
        mp3_play(66);
      }

      if ((diff>=dotDuration*2-threshold)&&(diff<=dotDuration*2+threshold)&&knockFlag)
      {
        listenString=listenString+'.';
        knockFlag = false;
        millisPrew = millisNow;
      }
      if ((diff>=dotDuration*4-threshold)&&(diff<=dotDuration*4+threshold)&&knockFlag)
      {

        listenString=listenString+'-';
        knockFlag = false;
        millisPrew = millisNow;
      }
    delay(2);
    }
    Serial.println("Listen string is:");
    Serial.println(listenString);
    String cmpString = "--"; // 
    boolean  result=(listenString == cmpString);
    Serial.print("cmp_q_sunduk_done ");
    Serial.println(result);
    if (result)
    {
       q_sunduk_done = 1;
    }
  }

void open_sunduk()
  {
    mp3_set_serial(Serial2);
    mp3_set_volume(20);
    mp3_play(61);// fx sunduk opening

    digitalWrite(rel_sunduk, LOW);
    digitalWrite(rel_lampa, LOW);
  }

void cherep() //Береш череп - звучить прокляття, гасне світло, відкриваються двері клітки
  {
    if (analogRead(sens_cherep) <= 500)
      {
        delay(50); // защита от дребезга кнопки.    
        q_cherep = 0; // меняем значение q  напротивоположное 0 на 1 или 1 на 0.
      }

    if (analogRead(sens_cherep) >= 500 && w_cherep == 0 && q_cherep == 0)
      {
        delay(50); // защита от дребезга кнопки.    
        w_cherep = 1; // меняем значение w на 1.
        q_cherep = 1; // меняем значение w на 1.
        
        q_cherep_done = 1; // флаг, що череп - дан
        Serial.println(analogRead(sens_cherep));
        Serial.println("CHE");
      }

    if (analogRead(sens_cherep) <= 500)
      {
        delay(50); // защита от дребезга кнопки.    
        w_cherep = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      }

  }

void open_kletka()
  {
    delay(1000);
    digitalWrite(rel_kletka, LOW);
    digitalWrite(rel_lampa, HIGH);
    delay(50);
    mp3_set_serial(Serial3);
    mp3_set_volume(20);
    mp3_play(62); //ефект відкриття клітки
  }

void open_kletka_alternate ()
    {
      while (q_open_kletka_alternate == 0)
        {
          t_open_kletka_alternate = millis();
          q_open_kletka_alternate++;
        } 

      if (millis() >= t_open_kletka_alternate + 22000)
        {
          while (w_open_kletka_alternate == 0)
          { 
            mp3_set_serial(Serial2);
            mp3_set_volume(15);
            mp3_play(62); //ефект відкриття клітки
            delay(50);
            digitalWrite(rel_kletka, LOW);
            digitalWrite(rel_lampa, HIGH);
            delay(20000);
            mp3_set_serial(Serial2);
            mp3_set_volume(10);
            mp3_play(80);
            w_open_kletka_alternate++;
          }
        }
    }

void armikrog() //Завдання4 - Зсуваєш, падає монета, грає аудіо
  {/*
    Serial.println("Arm is running");
    Serial.println(digitalRead(sens_armikrog1));
    Serial.println(digitalRead(sens_armikrog2));
    Serial.println(digitalRead(sens_armikrog3));
    Serial.println(digitalRead(sens_armikrog4));
   // */
    if (digitalRead(sens_armikrog1) == HIGH || digitalRead(sens_armikrog2) == HIGH || digitalRead(sens_armikrog3) == HIGH || digitalRead(sens_armikrog4) == HIGH)
    {
      delay(50); // защита от дребезга кнопки.    
      q_arm = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

    if (digitalRead(sens_armikrog1) == LOW && digitalRead(sens_armikrog2) == LOW && digitalRead(sens_armikrog3) == LOW && digitalRead(sens_armikrog4) == LOW && w_arm == 0 && q_arm == 0) // если кнопка 5 нажата и перед этим была отжата
    {
      delay(50); // защита от дребезга кнопки.
      w_arm = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q_arm = 1;
      q_arm_done = 1;
      delay(50);
    }

    if (digitalRead(sens_armikrog1) == HIGH || digitalRead(sens_armikrog2) == HIGH || digitalRead(sens_armikrog3) == HIGH || digitalRead(sens_armikrog4) == HIGH)
    {
      delay(50); // защита от дребезга кнопки.    
      w_arm = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }
  }

void podsvechniki() //Завдання5 - Повертаєш, падає монета, грає аудіо
  {
    /*
    Serial.println("Podsv is running");
    Serial.println(digitalRead(sens_podsvechnik1));
    Serial.println(digitalRead(sens_podsvechnik2));
    Serial.println(digitalRead(sens_podsvechnik3));
    Serial.println(digitalRead(sens_podsvechnik4));
    //*/
    if (digitalRead(sens_podsvechnik1) == HIGH || digitalRead(sens_podsvechnik2) == HIGH || digitalRead(sens_podsvechnik3) == HIGH || digitalRead(sens_podsvechnik4) == HIGH)
    {
      delay(50); // защита от дребезга кнопки.    
      q_podsv = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

    if (digitalRead(sens_podsvechnik1) == LOW && digitalRead(sens_podsvechnik2) == LOW && digitalRead(sens_podsvechnik3) == LOW && digitalRead(sens_podsvechnik4) == LOW && w_podsv == 0 && q_podsv == 0) // если кнопка 5 нажата и перед этим была отжата
    {
      delay(50); // защита от дребезга кнопки.
      w_podsv = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q_podsv = 1;
      q_podsvechniki_done = 1;
      delay(50);
    }

    if (digitalRead(sens_podsvechnik1) == HIGH || digitalRead(sens_podsvechnik2) == HIGH || digitalRead(sens_podsvechnik3) == HIGH || digitalRead(sens_podsvechnik4) == HIGH)
    {
      delay(50); // защита от дребезга кнопки.    
      w_podsv = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }
  }

void korabliki() //Завдання6 - розставляєш, падає монета, грає аудіо
  {
    /*
    Serial.println("Korabl is running");
    Serial.println(digitalRead(sens_korabl1));
    Serial.println(digitalRead(sens_korabl2));
    Serial.println(digitalRead(sens_korabl3));
    Serial.println(digitalRead(sens_korabl4));
    */
    if (digitalRead(sens_korabl1) == HIGH || digitalRead(sens_korabl2) == HIGH || digitalRead(sens_korabl3) == HIGH || digitalRead(sens_korabl4) == HIGH)
    {
      delay(50); // защита от дребезга кнопки.    
      q_korabl = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

    if (digitalRead(sens_korabl1) == LOW && digitalRead(sens_korabl2) == LOW && digitalRead(sens_korabl3) == LOW && digitalRead(sens_korabl4) == LOW && w_korabl == 0 && q_korabl == 0) // если кнопка 5 нажата и перед этим была отжата
    {
      delay(50); // защита от дребезга кнопки.
      w_korabl = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q_korabl = 1;
      q_korabliki_done = 1;
      delay(50);
    }

    if (digitalRead(sens_korabl1) == HIGH || digitalRead(sens_korabl2) == HIGH || digitalRead(sens_korabl3) == HIGH || digitalRead(sens_korabl4) == HIGH)
    {
      delay(50); // защита от дребезга кнопки.    
      w_korabl = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }
  }

void kartiny() //Завдання7 - Ставиш картини правильно, падає монета, грає аудіо
  {
    /*
    Serial.println("Kartiny is running");
    Serial.println(digitalRead(sens_kartina1));
    Serial.println(digitalRead(sens_kartina2));
    Serial.println(digitalRead(sens_kartina3));
    Serial.println(digitalRead(sens_kartina4));
    //*/
    if (digitalRead(sens_kartina1) == HIGH || digitalRead(sens_kartina2) == HIGH || digitalRead(sens_kartina3) == HIGH || digitalRead(sens_kartina4) == HIGH)
    {
      delay(50); // защита от дребезга кнопки.    
      q_kart = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

    if (digitalRead(sens_kartina1) == LOW && digitalRead(sens_kartina2) == LOW && digitalRead(sens_kartina3) == LOW && digitalRead(sens_kartina4) == LOW && w_kart == 0 && q_kart == 0) // если кнопка 5 нажата и перед этим была отжата
    {
      delay(50); // защита от дребезга кнопки.
      w_kart = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q_kart = 1;
      q_kartiny_done = 1;
      delay(50);
    }

    if (digitalRead(sens_kartina1) == HIGH || digitalRead(sens_kartina2) == HIGH || digitalRead(sens_kartina3) == HIGH || digitalRead(sens_kartina4) == HIGH)
    {
      delay(50); // защита от дребезга кнопки.    
      q_kart = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }
  }

void open_cracken() 
  {
  // ефект відкривання кракена
    delay (50);
    digitalWrite(rel_cracken, LOW);
    digitalWrite(rel_led_cracken, LOW);    
  }

void cracken() //Завдання8 - Якщо N монет стоять на місцях, то відкривається дверця, загорається світло. Вставляєш кріптекс, падає монета, грає аудіо
  {
    digitalWrite(led_cracken, HIGH);
    Serial.println("Cracken_button");
    Serial.println(digitalRead(sens_cracken));

    if (digitalRead(sens_cracken) == LOW)
    {
      delay(50); // защита от дребезга кнопки.    
      q_crack = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }

    if (digitalRead(sens_cracken) == HIGH && w_crack == 0 && q_crack == 0) // если кнопка 5 нажата и перед этим была отжата
    {
      delay(50); // защита от дребезга кнопки.
      w_crack = 1; // меняем значение w на противоположное 0 на 1 или 1 на 0.
      q_crack = 1;
      q_cracken_done = 1;

      digitalWrite(led_cracken, LOW);
      digitalWrite(rel_led_cracken, HIGH);
    }

    if (digitalRead(sens_cracken) == LOW)
    {
      delay(50); // защита от дребезга кнопки.    
      q_crack = 0; // меняем значение w на противоположное 0 на 1 или 1 на 0.
    }
  }

//перевірити
void bochka_coin_counter() //Ставиш певну кількість монет - відкривається ніша в кракен
  { 
    /*
    Serial.print("bochka counter = ");
    Serial.println(bochka_counter);
    Serial.print("Cherep  ");
    Serial.println(analogRead(sens_bochka0));
    Serial.print("Moneta 1  ");
    Serial.println(analogRead(sens_bochka1));
    Serial.print("Moneta 2  ");
    Serial.println(analogRead(sens_bochka2));
    Serial.print("Moneta 3  ");
    Serial.println(analogRead(sens_bochka3));
    Serial.print("Moneta 4  ");
    Serial.println(analogRead(sens_bochka4));
    Serial.print("Moneta 5  ");
    Serial.println(analogRead(sens_bochka5));
    Serial.print("Moneta 6  ");
    Serial.println(analogRead(sens_bochka6));
    Serial.print("Moneta 7  ");
    Serial.println(analogRead(sens_bochka7));
    // */
    if (analogRead(sens_bochka1) >= 500) //якщо монети немає з самого початку
      {
      delay(50);
      q_bochka1 = 0; // то флаг - "монети не було"
      }
    if (analogRead(sens_bochka1) <= 500 && w_bochka1 == 0 && q_bochka1 == 0)  // якщо монетка не лежала, а тепер лежить
      {
        delay(50);
        w_bochka1 = 1; // монета зараз лежиить
        q_bochka1 = 1; // лежить, хоч і не лежала раніше

        bochka_counter++; //каунтер +1 монета на місці
        delay(100);
        if(q_bochka_done == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(15);
          }
        //грай голос з вітаннями "єє, ви поклали монети"
      }
    if (analogRead(sens_bochka1) >= 500 && w_bochka1 == 1) // якщо монету забрали
      {
        delay(50);
        bochka_counter--; //каунтер -1 монета з бочки
        w_bochka1 = 0; // флаг "ой, хтось забрав монету" - тепер не лежить
      }
    
    if (analogRead(sens_bochka2) >= 500) //якщо монети немає з самого початку
      {
      delay(50);
      q_bochka2 = 0; // то флаг - "монети не було"
      }
    if (analogRead(sens_bochka2) <= 500 && w_bochka2 == 0 && q_bochka2 == 0)  // якщо монетка не лежала, а тепер лежить
      {
        delay(50);
        w_bochka2 = 1; // монета зараз лежиить
        q_bochka2 = 1; // лежить, хоч і не лежала раніше

        bochka_counter++; //каунтер +1 монета на місці
        delay(100);
        if(q_bochka_done == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(16);
          }
        //грай голос з вітаннями "єє, ви поклали монети"
      }
    if (analogRead(sens_bochka2) >= 500 && w_bochka2 == 1) // якщо монету забрали
      {
        delay(50);
        bochka_counter--; //каунтер -1 монета з бочки
        w_bochka2 = 0; // флаг "ой, хтось забрав монету" - тепер не лежить
      }


    if (analogRead(sens_bochka3) >= 500) //якщо монети немає з самого початку
      {
      delay(50);
      q_bochka3 = 0; // то флаг - "монети не було"
      }
    if (analogRead(sens_bochka3) <= 500 && w_bochka3 == 0 && q_bochka3 == 0)  // якщо монетка не лежала, а тепер лежить
      {
        delay(50);
        w_bochka3 = 1; // монета зараз лежиить
        q_bochka3 = 1; // лежить, хоч і не лежала раніше

        bochka_counter++; //каунтер +1 монета на місці
        delay(100);
        if(q_bochka_done == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(17);
          }
        //грай голос з вітаннями "єє, ви поклали монети"
      }
    if (analogRead(sens_bochka3) >= 500 && w_bochka3 == 1) // якщо монету забрали
      {
        delay(50);
        bochka_counter--; //каунтер -1 монета з бочки
        w_bochka3 = 0; // флаг "ой, хтось забрав монету" - тепер не лежить 
      }


    if (analogRead(sens_bochka4) >= 500) //якщо монети немає з самого початку
      {
      delay(50);
      q_bochka4 = 0; // то флаг - "монети не було"
      }
    if (analogRead(sens_bochka4) <= 500 && w_bochka4 == 0 && q_bochka4 == 0)  // якщо монетка не лежала, а тепер лежить
      {
        delay(50);
        w_bochka4 = 1; // монета зараз лежиить
        q_bochka4 = 1; // лежить, хоч і не лежала раніше

        bochka_counter++; //каунтер +1 монета на місці
        delay(100);
        if(q_bochka_done == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(18);
          }
        //грай голос з вітаннями "єє, ви поклали монети"
      }
    if (analogRead(sens_bochka4) >= 500 && w_bochka4 == 1) // якщо монету забрали
      {
        delay(50);
        bochka_counter--; //каунтер -1 монета з бочки
        w_bochka4 = 0; // флаг "ой, хтось забрав монету" - тепер не лежить     
      }


    if (analogRead(sens_bochka5) >= 500) //якщо монети немає з самого початку
      {
      delay(50);
      q_bochka5 = 0; // то флаг - "монети не було"
      }
    if (analogRead(sens_bochka5) <= 500 && w_bochka5 == 0 && q_bochka5 == 0)  // якщо монетка не лежала, а тепер лежить
      {
        delay(50);
        w_bochka5 = 1; // монета зараз лежиить
        q_bochka5 = 1; // лежить, хоч і не лежала раніше

        bochka_counter++; //каунтер +1 монета на місці
        delay(100);
        if(q_bochka_done == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(19);
          }
        //грай голос з вітаннями "єє, ви поклали монети"
      }
    if (analogRead(sens_bochka5) >= 500 && w_bochka5 == 1) // якщо монету забрали
      {
        delay(50);
        bochka_counter--; //каунтер -1 монета з бочки
        w_bochka5 = 0; // флаг "ой, хтось забрав монету" - тепер не лежить     
      }


    if (analogRead(sens_bochka6) >= 500) //якщо монети немає з самого початку
      {
      delay(50);
      q_bochka6 = 0; // то флаг - "монети не було"
      }
    if (analogRead(sens_bochka6) <= 500 && w_bochka6 == 0 && q_bochka6 == 0)  // якщо монетка не лежала, а тепер лежить
      {
        delay(50);
        w_bochka6 = 1; // монета зараз лежиить
        q_bochka6 = 1; // лежить, хоч і не лежала раніше

        bochka_counter++; //каунтер +1 монета на місці
        delay(100);
        if(q_bochka_done == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(191);
          }
        //грай голос з вітаннями "єє, ви поклали монети"
      }
    if (analogRead(sens_bochka6) >= 500 && w_bochka6 == 1) // якщо монету забрали
      {
        delay(50);
        bochka_counter--; //каунтер -1 монета з бочки
        w_bochka6 = 0; // флаг "ой, хтось забрав монету" - тепер не лежить     
      }


    if (analogRead(sens_bochka7) >= 500) //якщо монети немає з самого початку
      {
      delay(50);
      q_bochka7 = 0; // то флаг - "монети не було"
      }
    if (analogRead(sens_bochka7) <= 500 && w_bochka7 == 0 && q_bochka7 == 0)  // якщо монетка не лежала, а тепер лежить
      {
        delay(50);
        w_bochka7 = 1; // монета зараз лежиить
        q_bochka7 = 1; // лежить, хоч і не лежала раніше

        bochka_counter++; //каунтер +1 монета на місці
        delay(100);
        if(q_bochka_done == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(29);
          }
        //грай голос з вітаннями "єє, ви поклали монети"
      }
    if (analogRead(sens_bochka7) >= 500 && w_bochka7 == 1) // якщо монету забрали
      {
        delay(50);
        bochka_counter--; //каунтер -1 монета з бочки
        w_bochka7 = 0; // флаг "ой, хтось забрав монету" - тепер не лежить     
      }

  }

void bochka() // Ставиш всі монети і череп - бінго
  {   
    if (analogRead(sens_bochka0) <= 500 || analogRead(sens_bochka1) <= 500 || analogRead(sens_bochka2) <= 500 || analogRead(sens_bochka3) <= 500 || analogRead(sens_bochka4) <= 500 || analogRead(sens_bochka5) <= 500 || analogRead(sens_bochka6) <= 500 || analogRead(sens_bochka7) <= 500) //хоча б одної монети або черепа немає з самого початку
      {
        q_bochka = 0; // то флаг - "як мінімум, однієї монети не було с самого початку"
      }
    if (analogRead(sens_bochka0) <= 500 && analogRead(sens_bochka1) <= 500 && analogRead(sens_bochka2) <= 500 && analogRead(sens_bochka3) <= 500 && analogRead(sens_bochka4) <= 500 && analogRead(sens_bochka5) <= 500 && analogRead(sens_bochka6) <= 500 && analogRead(sens_bochka7) <= 500 && w_bochka == 0 && q_bochka == 0 && q_arm_done == 1 && q_podsvechniki_done == 1 && q_kartiny_done == 1 && q_korabliki_done == 1 && q_cracken_done == 1)  // якщо хоча б одна не лежала, а тепер лежать всі, і при цьому - всі завдання з монетами були виконані
      {
        w_bochka = 1; // монети всі зараз лежать
        q_bochka = 1; // лежать всі, хоч якась і не лежала раніше
        //audio0009();
        q_bochka_done = 1; //все пройшли
      }
    if (analogRead(sens_bochka0) <= 500 || analogRead(sens_bochka1) <= 500 || analogRead(sens_bochka2) <= 500 || analogRead(sens_bochka3) <= 500 || analogRead(sens_bochka4) <= 500 || analogRead(sens_bochka5) <= 500 || analogRead(sens_bochka6) <= 500 || analogRead(sens_bochka7) <= 500) // якщо ж хоч одну забрали
      {
        w_bochka = 0; // флаг "ой, хтось забрав монету" - тепер не лежить
      }
  }

void bochka_no_cherep() // Ставиш всі монети - бінго
  {   
    if (analogRead(sens_bochka0) >= 500 || analogRead(sens_bochka1) >= 500 || analogRead(sens_bochka2) >= 500 || analogRead(sens_bochka3) >= 500 || analogRead(sens_bochka4) >= 500 || analogRead(sens_bochka5) >= 500 || analogRead(sens_bochka6) >= 500 || analogRead(sens_bochka7) >= 500) //хоча б одної монети немає з самого початку
      {
        q_bochka_no_cherep = 0; // то флаг - "як мінімум, однієї монети не було с самого початку"
      }
    if (analogRead(sens_bochka0) >= 500 && analogRead(sens_bochka1) <= 500 && analogRead(sens_bochka2) <= 500 && analogRead(sens_bochka3) <= 500 && analogRead(sens_bochka4) <= 500 && analogRead(sens_bochka5) <= 500 && analogRead(sens_bochka6) <= 500 && analogRead(sens_bochka7) <= 500 && w_bochka_no_cherep == 0 && q_bochka_no_cherep == 0 && q_arm_done == 1 && q_podsvechniki_done == 1 && q_kartiny_done == 1 && q_korabliki_done == 1 && q_cracken_done == 1)  // якщо хоча б одна не лежала, а тепер лежать всі, і при цьому - всі завдання з монетами були виконані
      {
        w_bochka_no_cherep = 1; // монети всі зараз лежать
        q_bochka_no_cherep = 1; // лежать всі, хоч якась і не лежала раніше
        q_bochka_no_cherep_done = 1;
        audio0007();
        audio0008();
      }
    if (analogRead(sens_bochka0) >= 500 || analogRead(sens_bochka1) >= 500 || analogRead(sens_bochka2) >= 500 || analogRead(sens_bochka3) >= 500 || analogRead(sens_bochka4) >= 500 || analogRead(sens_bochka5) >= 500 || analogRead(sens_bochka6) >= 500 || analogRead(sens_bochka7) >= 500) // якщо ж хоч одну забрали
      {
        delay(50);
        w_bochka_no_cherep = 0; // флаг "ой, хтось забрав монету" - тепер не лежить
      }
  }

void open_moneta1() //Дія - падає монета, грає аудіо
  {
    //ефект падіння монети, аудіо
    delay(50);
    mp3_set_serial(Serial3);
    mp3_set_volume(20);
    mp3_play(59); //звук гонгу "ще одну монету добуто"
    digitalWrite(rel_moneta1, LOW);
    delay(20);
    digitalWrite(rel_moneta1, HIGH);
    delay(20);
    digitalWrite(rel_moneta1, LOW);
    delay(20);
  }

void open_moneta2() //Дія - падає монета, грає аудіо
  {
    //ефект падіння монети, аудіо
    delay(50);
    mp3_set_serial(Serial3);
    mp3_set_volume(20);
    mp3_play(59); //звук гонгу "ще одну монету добуто"
    delay(50);
    digitalWrite(rel_moneta2, LOW);
    delay(20);
    digitalWrite(rel_moneta2, HIGH);
    delay(20);
    digitalWrite(rel_moneta2, LOW);
    delay(20);
  }

void open_moneta3() //Дія - падає монета, грає аудіо
  {
    //ефект падіння монети, аудіо
    delay(50);
    mp3_set_serial(Serial3);
    mp3_set_volume(20);
    mp3_play(59); //звук гонгу "ще одну монету добуто"
    digitalWrite(rel_moneta3, LOW);
    delay(20);
    digitalWrite(rel_moneta3, HIGH);
    delay(20);
    digitalWrite(rel_moneta3, LOW);
    delay(20);
  }

void open_moneta4() //Дія - падає монета, грає аудіо
  {
    //ефект падіння монети, аудіо
    delay(50);
    mp3_set_serial(Serial3);
    mp3_set_volume(20);
    mp3_play(59); //звук гонгу "ще одну монету добуто"
    digitalWrite(rel_moneta4, LOW);
    delay(20);
    digitalWrite(rel_moneta4, HIGH);
    delay(20);
    digitalWrite(rel_moneta4, LOW);
    delay(20);
  }

void open_moneta5() //Дія - падає монета, грає аудіо
  {
    //ефект падіння монети, аудіо
    delay(50);
    mp3_set_serial(Serial3);
    mp3_set_volume(20);
    mp3_play(59); //звук гонгу "ще одну монету добуто"
    digitalWrite(rel_moneta5, LOW);
    delay(20);
    digitalWrite(rel_moneta5, HIGH);
    delay(20);
    digitalWrite(rel_moneta5, LOW);
    delay(20);
  }

void exit() //Дія - двері, аудіо
  {
    //ефект відкриття дверей, фінальна промова
    delay(50);
    digitalWrite(rel_door2, LOW);
    digitalWrite(rel_door3, LOW);
  }

  void entrance() //Дія - двері, аудіо
  {
    //ефект відкриття дверей, фінальна промова
    delay(2000);
    digitalWrite(rel_door2, HIGH);
    digitalWrite(rel_door3, HIGH);
  }

void exit_alternate()
    {
      audio0009();
      while (q_exit_alternate == 0)
        {
          t_exit_alternate = millis();
          q_exit_alternate++;
        } 

      if (millis() >= t_exit_alternate + 12000)
        {
          while (w_exit_alternate == 0)
          { 
            mp3_set_serial(Serial2);
            mp3_set_volume(9);
            delay(100);
            mp3_set_volume(7);
            delay(100);
            mp3_set_volume(5);
            delay(100);
            mp3_set_volume(3);
            delay(100);
            mp3_set_volume(1);
            delay(100);
            mp3_set_serial(Serial2);
            mp3_play(100);
            mp3_set_volume(5);
            delay(7000);
            mp3_set_volume(13);
            delay(3000);
            
            delay(25000);
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(59); //звук гонгу "ще одну монету добуто"
            delay(2000);
            digitalWrite(rel_prikol, LOW);
            delay(1000);
            digitalWrite(rel_door2, LOW);
            digitalWrite(rel_door3, LOW);
            w_exit_alternate++;
          }
        }
    }

void timer_one_hour()
    {
      while (q_timer_one_hour == 0)
        {
          t_timer_one_hour = millis();
          q_timer_one_hour++;
        } 

      if (millis() >= t_timer_one_hour + 3600000)
        {
          while (w_timer_one_hour == 0)
          {
            if(q_bochka_done == 0)
              {
                mp3_set_serial(Serial3);
                mp3_set_volume(20);
                mp3_play(24); // похоже, у меня скоро появятся новые слуги
                delay(2000);
                mp3_set_serial(Serial2);
                mp3_set_volume(25);
                mp3_play(65); //гул вулкану
                delay(30000);
                mp3_set_volume(20);
                delay(200);
                mp3_set_volume(15);
                delay(200);
                mp3_set_volume(13);
                delay(200);
                mp3_set_volume(11);
                delay(200);
                mp3_set_volume(9);
                delay(200);
                mp3_set_volume(7);
                delay(200);
                mp3_set_volume(5);
                delay(200);
                mp3_set_volume(3);
                delay(200);
                mp3_pause();
                digitalWrite(rel_door2, LOW);
                digitalWrite(rel_door3, LOW);
              }
            w_timer_one_hour++;
          }
        }
    }

void fakel_easy()// по-черзі вставити у всі -- відкриваються двері
  {
    if (digitalRead(sens_fakel1) == LOW && digitalRead(sens_fakel2) == LOW)
    {
      while(w_fakel12 == 0)
      {
        mp3_set_serial(Serial1);
        mp3_set_volume(24);
        mp3_play(52);
        delay(100);

        digitalWrite(led_fakel12, HIGH);
        counter_fakely++;
        w_fakel12++;
      }
    }

    if (digitalRead(sens_fakel3) == LOW)
    {
      while(w_fakel3 == 0)
      {
        mp3_set_serial(Serial1);
        mp3_set_volume(24);
        mp3_play(52);
        delay(100);

        digitalWrite(led_fakel3, HIGH);
        counter_fakely++;
        w_fakel3++;
      }
    }

    if (digitalRead(sens_fakel4) == LOW)
    {
      while(w_fakel4 == 0)
      {
        mp3_set_serial(Serial1);
        mp3_set_volume(24);
        mp3_play(52);
        delay(100);

        digitalWrite(led_fakel4, HIGH);
        counter_fakely++;
        w_fakel4++;
      }
    }

    if (digitalRead(sens_fakel5) == LOW)
    {
      while(w_fakel5 == 0)
      {
        mp3_set_serial(Serial1);
        mp3_set_volume(24);
        mp3_play(52);
        delay(100);

        digitalWrite(led_fakel5, HIGH);
        counter_fakely++;
        w_fakel5++;
      }
    }

    if (digitalRead(sens_fakel6) == LOW)
    {
      while(w_fakel6 == 0)
      {
        mp3_set_serial(Serial1);
        mp3_set_volume(24);
        mp3_play(52);
        delay(100);

        digitalWrite(led_fakel6, HIGH);
        counter_fakely++;
        w_fakel6++;
      }
    }

    if (digitalRead(sens_fakel7) == LOW)
    {
      while(w_fakel7 == 0)
      {
        mp3_set_serial(Serial1);
        mp3_set_volume(24);
        mp3_play(52);
        delay(100);

        digitalWrite(led_fakel7, HIGH);
        counter_fakely++;
        w_fakel7++;
      }
    }
  }
//пустий войд для програмної тіпа-перезагрузки
  void(* resetFunc) (void) = 0;
//Пульт дистанційного керування
  void showCode(unsigned long receivedCode, unsigned int period) 

{
    //Note: interrupts are disabled. You can re-enable them if needed.
    
   //Print the received code.
    Serial.print("Code: ");
    Serial.print(receivedCode);
    Serial.print(", period duration: ");
    Serial.print(period);
    Serial.println("us.");

  if (receivedCode == 531361) // Button 1 code
  {
    q_light_done = 1;
    Serial.println("B1pressed");
    }

  if (receivedCode == 531363) // Button 2 code
  {
  counter_fakely = 5; // при значенні counter_fakely = 5, останній факел вставлено правильно, завдання виконане
    }

  if (receivedCode == 531364) // Button 3 code
  {
    q_sunduk_done = 1; // флаг, що сундук відстукав
    }

  if (receivedCode == 531369) // Button 4 code
  {
   q_arm_done = 1; //флаг, що армікрог - дан
    }

  if (receivedCode == 531370) // Button 5 code
  {
    q_podsvechniki_done = 1; //флаг, що підсвічники - дан
    }

  if (receivedCode == 531372) // Button 6 code
  {
    q_korabliki_done = 1; // флаг, що кораблики - дан
    }

  if (receivedCode == 531373) // Button 7 code
  {
    q_kartiny_done = 1; // флаг, що картини - дан
    }

  if (receivedCode == 531387) // Button 8 code
  {
    q_cracken_done = 1; // флаг, що кракен - дан
    }

  if (receivedCode == 531388) // Button 9 code
  {
    q_bochka_done = 1;
    }

  if (receivedCode == 531390) // Button 10 code
  {
    mp3_set_serial(Serial3);
    mp3_set_volume(20);
    mp3_play(52);
    delay(100);
    mp3_set_serial(Serial1);
    mp3_set_volume(25);
    mp3_play(70);

    timer_one_hour();
    }

  if (receivedCode == 531391) // Button 11 code
  {
    exit();
    }

  if (receivedCode == 531396) // Button 12 code
  {
    mp3_set_serial(Serial3);
        mp3_set_volume(20);
        mp3_play(52);
        delay(100);
    resetFunc();
    }

}

//audio voice 
  void audio0001()
    {
      while (q_audio0001 == 0)
        {
          t_audio0001 = millis();
          q_audio0001++;
        } 

      if (millis() >= t_audio0001 + 5000)
        {
          while (w_audio0001 == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(1); //голос пірата
            Serial.println("YES");
            w_audio0001++;
          }
        }
    }

  void audio0002()
    {
      while (q_audio0002 == 0)
        {
          t_audio0002 = millis();
          q_audio0002++;
        } 

      if (millis() >= t_audio0002 + 30000)
        {
          while (w_audio0002 == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(2); //голос пірата
            Serial.println("YES");
            w_audio0002++;
          }
        }
    }

  void audio0003()
    {
      while (q_audio0003 == 0)
        {
          t_audio0003 = millis();
          q_audio0003++;
        } 

      if (millis() >= t_audio0003 + 40000)
        {
          while (w_audio0003 == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(3); //голос пірата
            Serial.println("YES");
            w_audio0003++;
          }
        }
    }

  void audio0004()
    {
      while (q_audio0004 == 0)
        {
          t_audio0004 = millis();
          q_audio0004++;
        } 

      if (millis() >= t_audio0004 + 40000)
        {
          while (w_audio0004 == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(4); //голос пірата
            Serial.println("YES");
            w_audio0004++;
          }
        }
    }

  void audio0005()
    {
      while (q_audio0005 == 0)
        {
          t_audio0005 = millis();
          q_audio0005++;
        } 

      if (millis() >= t_audio0005 + 3000)
        {
          while (w_audio0005 == 0)
          {
            mp3_set_serial(Serial3);
            mp3_set_volume(20);
            mp3_play(5); //голос пірата
            Serial.println("YES");
            w_audio0005++;
          }
        }
    }

  void audio0051()
      {
        while (q_audio0051 == 0)
          {
            t_audio0051 = millis();
            q_audio0051++;
          } 

        if (millis() >= t_audio0051 + 69000)
          {
            while (w_audio0051 == 0)
            {
              mp3_set_serial(Serial3);
              mp3_set_volume(20);
              mp3_play(51); //голос пірата
              Serial.println("YES");
              w_audio0051++;
            }
          }
      }   

    void audio0006()
      {
        while (q_audio0006 == 0)
          {
            t_audio0006 = millis();
            q_audio0006++;
          } 

        if (millis() >= t_audio0006 + 3000)
          {
            while (w_audio0006 == 0)
            {
              mp3_set_serial(Serial3);
              mp3_set_volume(20);
              mp3_play(6); //голос пірата
              Serial.println("YES");
              w_audio0006++;
            }
          }
      }

    void audio0007()
      {
        while (q_audio0007 == 0)
          {
            t_audio0007 = millis();
            q_audio0007++;
          } 

        if (millis() >= t_audio0007 + 10)
          {
            while (w_audio0007 == 0)
            {
              mp3_set_serial(Serial3);
              mp3_set_volume(20);
              mp3_play(7); //голос пірата
              Serial.println("YES");
              w_audio0007++;
            }
          }
      }

    void audio0008()
      {
        while (q_audio0008 == 0)
          {
            t_audio0008 = millis();
            q_audio0008++;
          } 

        if (millis() >= t_audio0008 + 7000)
          {
            while (w_audio0008 == 0)
            {
              mp3_set_serial(Serial3);
              mp3_set_volume(20);
              mp3_play(8); //голос пірата
              Serial.println("YES");
              w_audio0008++;
            }
          }
      }

    void audio0009()
      {
        while (q_audio0009 == 0)
          {
            t_audio0009 = millis();
            q_audio0009++;
          } 

        if (millis() >= t_audio0009 + 50)
          {
            while (w_audio0009 == 0)
            {
              mp3_set_serial(Serial3);
              mp3_set_volume(22);
              mp3_play(9); //голос пірата
              Serial.println("YES");
              w_audio0009++;
            }
          }
      }

    void audio0010()
      {
        while (q_audio0010 == 0)
          {
            t_audio0010 = millis();
            q_audio0010++;
          } 

        if (millis() >= t_audio0010 + 3000)
          {
            while (w_audio0010 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(10); //голос пірата
                  Serial.println("YES");
                }
              w_audio0010++;
            }
          }
      }

    void audio0011()
      {
        while (q_audio0011 == 0)
          {
            t_audio0011 = millis();
            q_audio0011++;
          } 
        
        if (millis() >= t_audio0011 + 3000)
          {
            while (w_audio0011 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(11); //голос пірата
                  Serial.println("YES");
                }
              w_audio0011++;
            }
          }
      }

    void audio0012()
      {
        while (q_audio0012 == 0)
          {
            t_audio0012 = millis();
            q_audio0012++;
          } 

        if (millis() >= t_audio0012 + 3000)
          {
            while (w_audio0012 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(12); //голос пірата
                  Serial.println("YES");
                }
              w_audio0012++;
            }
          }
      }

    void audio0013()
      {
        while (q_audio0013 == 0)
          {
            t_audio0013 = millis();
            q_audio0013++;
          } 

        if (millis() >= t_audio0013 + 3000)
          {
            while (w_audio0013 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(13); //голос пірата
                  Serial.println("YES");
                }
              w_audio0013++;
            }
          }
      }

    void audio0014()
      {
        while (q_audio0014 == 0)
          {
            t_audio0014 = millis();
            q_audio0014++;
          } 

        if (millis() >= t_audio0014 + 3000)
          {
            while (w_audio0014 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(14); //голос пірата
                  Serial.println("YES");
                }
              w_audio0014++;
            }
          }
      }


    void audio0015()
      {
        while (q_audio0015 == 0)
          {
            t_audio0015 = millis();
            q_audio0015++;
          } 

        if (millis() >= t_audio0015 + 100)
          {
            while (w_audio0015 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(15); //голос пірата
                  Serial.println("YES");
                }
              w_audio0015++;
            }
          }
      }


    void audio0016()
      {
        while (q_audio0016 == 0)
          {
            t_audio0016 = millis();
            q_audio0016++;
          } 

        if (millis() >= t_audio0016 + 100)
          {
            while (w_audio0016 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(16); //голос пірата
                  Serial.println("YES");
                }
              w_audio0016++;
            }
          }
      }


    void audio0017()
      {
        while (q_audio0017 == 0)
          {
            t_audio0017 = millis();
            q_audio0017++;
          } 

        if (millis() >= t_audio0017 + 100)
          {
            while (w_audio0017 == 0)
            {
                if(q_bochka_done == 0)
                  {
                    mp3_set_serial(Serial3);
                    mp3_set_volume(20);
                    mp3_play(17); //голос пірата
                    Serial.println("YES");
                  }
              w_audio0017++;
            }
          }
      }

    void audio0018()
      {
        while (q_audio0018 == 0)
          {
            t_audio0018 = millis();
            q_audio0018++;
          } 

        if (millis() >= t_audio0018 + 100)
          {
            while (w_audio0018 == 0)
            {
                if(q_bochka_done == 0)
                  {
                    mp3_set_serial(Serial3);
                    mp3_set_volume(20);
                    mp3_play(18); //голос пірата
                    Serial.println("YES");
                  }
              w_audio0018++;
            }
          }
      }

    void audio0019()
      {
        while (q_audio0019 == 0)
          {
            t_audio0019 = millis();
            q_audio0019++;
          } 

        if (millis() >= t_audio0019 + 100)
          {
            while (w_audio0019 == 0)
            {
                if(q_bochka_done == 0)
                  {
                    mp3_set_serial(Serial3);
                    mp3_set_volume(20);
                    mp3_play(19); //голос пірата
                    Serial.println("YES");
                  }
                w_audio0019++;
            }
          }
      }

    void audio0191()
      {
        while (q_audio00191 == 0)
          {
            t_audio00191 = millis();
            q_audio00191++;
          } 

        if (millis() >= t_audio00191 + 100)
          {
            while (w_audio00191 == 0)
            {
                if(q_bochka_done == 0)
                  {
                    mp3_set_serial(Serial3);
                    mp3_set_volume(20);
                    mp3_play(191); //голос пірата
                    Serial.println("YES");
                  }
              w_audio00191++;
            }
          }
      }

    void audio0020()
      {
        while (q_audio0020 == 0)
          {
            t_audio0020 = millis();
            q_audio0020++;
          } 

        if (millis() >= t_audio0020 + 180000)
          {
            while (w_audio0020 == 0)
              {
                if(q_bochka_done == 0)
                  {
                    mp3_set_serial(Serial3);
                    mp3_set_volume(20);
                    mp3_play(20); //голос пірата
                    Serial.println("YES");
                  }
                w_audio0020++;
              }
          }
      }

    void audio0021()
      {
        while (q_audio0021 == 0)
          {
            t_audio0021 = millis();
            q_audio0021++;
          } 

        if (millis() >= t_audio0021 + 180000)
          {
            while (w_audio0021 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(21); //голос пірата
                  Serial.println("YES");
                }
              w_audio0021++;
            }
          }
      }

    void audio0022()
      {
        while (q_audio0022 == 0)
          {
            t_audio0022 = millis();
            q_audio0022++;
          } 

        if (millis() >= t_audio0022 + 180000)
          {
            while (w_audio0022 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(22); //голос пірата
                  Serial.println("YES");
                }
              w_audio0022++;
            }
          }
      }

    void audio0023()
      {
        while (q_audio0023 == 0)
          {
            t_audio0023 = millis();
            q_audio0023++;
          } 

        if (millis() >= t_audio0023 + 180000)
          {
            while (w_audio0023 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(23); //голос пірата
                  Serial.println("YES");
                }
              w_audio0023++;
            }
          }
      }

    void audio0024()
      {
        while (q_audio0024 == 0)
          {
            t_audio0024 = millis();
            q_audio0024++;
          } 

        if (millis() >= t_audio0024 + 3000)
          {
            while (w_audio0024 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(24); //голос пірата
                  Serial.println("YES");
                }
              w_audio0024++;
            }
          }
      }

    void audio0025()
      {
        while (q_audio0025 == 0)
          {
            t_audio0025 = millis();
            q_audio0025++;
          } 

        if (millis() >= t_audio0025 + 180000)
          {
            while (w_audio0025 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(25); //голос пірата
                  Serial.println("YES");
                }
              w_audio0025++;
            }
          }
      }

    void audio0026()
      {
        while (q_audio0026 == 0)
          {
            t_audio0026 = millis();
            q_audio0026++;
          } 

        if (millis() >= t_audio0026 + 300000)
          {
            while (w_audio0026 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(26); //голос пірата
                  Serial.println("YES");
                }
              w_audio0026++;                
            }
          }
      }

    void audio0027()
      {
        while (q_audio0027 == 0)
          {
            t_audio0027 = millis();
            q_audio0027++;
          } 

        if (millis() >= t_audio0027 + 300000)
          {
            while (w_audio0027 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(27); //голос пірата
                  Serial.println("YES");
                }
              w_audio0027++;
            }
          }
      }

    void audio0028()
      {
        while (q_audio0028 == 0)
          {
            t_audio0028 = millis();
            q_audio0028++;
          } 

        if (millis() >= t_audio0028 + 300000)
          {
            while (w_audio0028 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(28); //голос пірата
                  Serial.println("YES");
                }
              w_audio0028++;
            }
          }
      }

    void audio0029()
      {
        while (q_audio0029 == 0)
          {
            t_audio0029 = millis();
            q_audio0029++;
          } 

        if (millis() >= t_audio0029 + 100)
          {
            while (w_audio0029 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(29); //голос пірата
                  Serial.println("YES");
                }
              w_audio0029++;
            }
          }
      }

    void audio0291()
      {
        while (q_audio0291 == 0)
          {
            t_audio0291 = millis();
            q_audio0291++;
          } 

        if (millis() >= t_audio0291 + 300000)
          {
            while (w_audio0291 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(291); //голос пірата
                  Serial.println("YES");
                }
              w_audio0291++;
            }
          }
      }

    void audio0292()
      {
        while (q_audio0292 == 0)
          {
            t_audio0292 = millis();
            q_audio0292++;
          } 

        if (millis() >= t_audio0292 + 300000)
          {
            while (w_audio0292 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(292); //голос пірата
                  Serial.println("YES");
                }
              w_audio0292++;
            }
          }
      }

    void audio0293()
      {
        while (q_audio0293 == 0)
          {
            t_audio0293 = millis();
            q_audio0293++;
          } 

        if (millis() >= t_audio0293 + 300000)
          {
            while (w_audio0293 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(293); //голос пірата
                  Serial.println("YES");
                }
              w_audio0293++;
            }
          }
      }

    void audio0294()
      {
        while (q_audio0294 == 0)
          {
            t_audio0294 = millis();
            q_audio0294++;
          } 

        if (millis() >= t_audio0294 + 300000)
          {
            while (w_audio0294 == 0)
            {
              if(q_bochka_done == 0)
                {
                  mp3_set_serial(Serial3);
                  mp3_set_volume(20);
                  mp3_play(294); //голос пірата
                  Serial.println("YES");
                }
              w_audio0294++;
            }
          }
      }


