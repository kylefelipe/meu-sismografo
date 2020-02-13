#include "stdio.h"
//#include "virtuabotixRTC.h"
#include "DS1302.h"

const int ClkPino = 5; // Pino Clk
const int DatPino = 6; // Pino Dat
const int RstPino = 7; // Pino Rst

// Quando for acertar a hora

#define segL 0
#define minL 33
#define horL 23
#define d_semL 5
#define d_mesL 12
#define mesL 2
#define anoL 2020

 
// Cria um objeto para o dispositivo.
 
DS1302 rtc(RstPino, DatPino, ClkPino);
 
String dayAsString(const Time::Day day) {
 switch (day) {
 case Time::kSunday: return "Domingo";
 case Time::kMonday: return "Segunda-Feira";
 case Time::kTuesday: return "Terca-Feira";
 case Time::kWednesday: return "Quarta-Feira";
 case Time::kThursday: return "Quinta-Feira";
 case Time::kFriday: return "Sexta-Feira";
 case Time::kSaturday: return "Sabado";
 }
 return "(Dia nao encontrado)";
}
 
void printTime() 
{
 Time t = rtc.time();
 
 const String day = dayAsString(t.day);
 
 char buf[50];
 snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02u",
          day.c_str(),
          t.yr,t.mon, t.date,
          t.hr, t.min, t.sec);
 
 Serial.println(buf);
// Serial.println(t.day);
}
 
//} // namespace
 
void setup() {
 Serial.begin(9600);
 
 // Configura o Chip
 rtc.writeProtect(false);
 rtc.halt(false);
 
 // Defina a hora nesta linha e descomente-as para setar a hora no chip
// 
  //Time t(2020, 2, 12, 23, 57, 0, Time::kWednesday);
  //rtc.time(t);
  
}
 
 
void loop() {
 printTime();
 delay(500);
}
