#define REMOTEXY_MODE__ESP8266WIFI_LIB
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// настройки соединения 
#define REMOTEXY_WIFI_SSID "TP-Link_97E8"
#define REMOTEXY_WIFI_PASSWORD "72320006"
#define REMOTEXY_SERVER_PORT 6377
// конфигурация интерфейса  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 46 bytes
  { 255,4,0,0,0,39,0,16,31,1,1,0,25,25,12,12,2,31,0,1,
  0,26,54,12,12,2,31,0,1,0,4,40,12,12,2,31,0,1,0,47,
  40,12,12,2,31,0 };
// структура определяет все переменные и события вашего интерфейса управления 
struct {
    // input variables
  uint8_t button_1; // =1 если кнопка нажата, иначе =0 up
  uint8_t button_2; // =1 если кнопка нажата, иначе =0 down
  uint8_t button_3; // =1 если кнопка нажата, иначе =0 left
  uint8_t button_4; // =1 если кнопка нажата, иначе =0 right
    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 
} RemoteXY;
#pragma pack(pop)

// Расшифровка подключений к L298

// Мотор A отвечающий за ускорение
#define MOTORA_1 D7 //IN1
#define MOTORA_2 D6 //IN2
#define ENA D8      //ENA
// Мотор B отвечающий за повороты
#define ENB D3      //ENB
#define MOTORB_1 D4 //IN3
#define MOTORB_2 D5 //IN4
//Переменные моторов вперед\назад - влево\вправо.
int motor_FB = 0;
int motor_LR = 0;

void setup() 
{
  Serial.begin(9600);
  RemoteXY_Init (); 
  pinMode(MOTORA_1, OUTPUT);
  pinMode(MOTORA_2, OUTPUT);
  pinMode(MOTORB_1, OUTPUT);
  pinMode(MOTORB_2, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  if(RemoteXY.button_1 == 1) {
    Serial.println("нажато вверх");
    digitalWrite(MOTORA_1,HIGH);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
  }else if(RemoteXY.button_2 == 1) {
    Serial.println("нажато вниз");
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
  }else if(RemoteXY.button_3 == 1) {
    Serial.println("нажато влево");
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
  }else if(RemoteXY.button_4 == 1) {
    Serial.println("нажато вправо");
    digitalWrite(MOTORA_1,HIGH);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
  } else {
  digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
  
  // TODO you loop code
  // используйте структуру RemoteXY для передачи данных
  // не используйте функцию delay() 


}
