#include <stdbool.h>
#include <stdint.h>

typedef struct clock_s * clock_t;
typedef struct alarm_s * alarm_t;
typedef void (*funcion_alarma)(clock_t reloj);
clock_t ClockCreate(int tics_por_segundo,funcion_alarma alarma);

bool ClockGetTime(clock_t reloj,uint8_t * hora, int size);

bool ClockSetTime(clock_t reloj,const uint8_t * hora, int size);     //const ya que en la segunda prueba ingreso ESPERADO

void ClockTick(clock_t reloj);

bool ClockGetAlarm(clock_t reloj,uint8_t * alarma, int size);


bool ClockSetAlarm(clock_t reloj,const uint8_t * alarma, int size);

bool Alarmon(clock_t reloj);

bool Alarmoff(clock_t reloj);

bool consultaralarma(clock_t reloj);



