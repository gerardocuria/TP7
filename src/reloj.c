#include "reloj.h"
#include <string.h>

typedef struct clock_s * clock_t;

clock_t ClockCreate(int tics_por_segundo){

}

bool ClockGetTime(clock_t reloj,uint8_t * hora, int size){
    memset(hora,0,size);
    return false;
}