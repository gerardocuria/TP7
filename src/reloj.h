#include <stdbool.h>
#include <stdint.h>

typedef struct clock_s * clock_t;
typedef struct alarm_s * alarm_t;

clock_t ClockCreate(int tics_por_segundo);

bool ClockGetTime(clock_t reloj,uint8_t * hora, int size);

bool ClockSetTime(clock_t reloj,const uint8_t * hora, int size);     //const ya que en la segunda prueba ingreso ESPERADO

void ClockTick(clock_t reloj);

bool ClockGetAlarm(clock_t reloj,uint8_t * alarma, int size);


bool ClockSetAlarm(clock_t reloj,const uint8_t * alarma, int size);
