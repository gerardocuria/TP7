#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "reloj.h"



struct clock_s {
    uint8_t hora_actual[6];
    bool valida;
    int tics_por_segundo;
    int conteo_tics;
    //uint8_t hora_alarma[6];
    //bool alarma_habilitada;
};


clock_t ClockCreate(int tics_por_segundo) {
    static struct clock_s self[1];
    memset(self, 0, sizeof(self));
    self->tics_por_segundo = tics_por_segundo;
    return self;
}

bool ClockGetTime(clock_t reloj,uint8_t * hora, int size){
    memcpy(hora, reloj->hora_actual, size);
    return reloj->valida;
}

bool ClockSetTime(clock_t reloj,const uint8_t * hora, int size){
    memcpy(reloj->hora_actual,hora, size);
    reloj->valida = true;
    return true;
}

void ClockTick(clock_t reloj){
    reloj->conteo_tics++;
    if(reloj->conteo_tics==reloj->tics_por_segundo){
        reloj->hora_actual[5]++;
        reloj->conteo_tics=0;
    }
}

//tengo que hacer un get time y un set time par la alarmavalida
