#include <stdbool.h>
#include <stdint.h>

typedef struct clock_s * clock_t;

clock_t ClockCreate(int tics_por_segundo);

bool ClockGetTime(clock_t reloj,uint8_t * hora, int size);

bool ClockSetTime(clock_t reloj,const uint8_t * hora, int size);     //const ya que en la segunda prueba ingreso ESPERADO

bool ClockSetTicsPerSecond(clock_t reloj, int tics_por_segundo);

void SetAlarmTime(clock_t reloj, const uint8_t* hora, int size);

const uint8_t* GetAlarmTime(clock_t reloj);