//al iniciar el reloj deberia estar en 00:00 y con hora invalida


#include "unity.h"
#include "reloj.h"

void test_reloj_arranca_hora_invalida(void){
    static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};
    uint8_t hora[6]= {0xFF};
    clock_t reloj = ClockCreate(5);                            //cantidad de tics capara configurar el systick del reloj
    TEST_ASSERT_FALSE(ClockGetTime(reloj,hora,6));             //guarda y compara reloj en hora si no son diferentes pasa el test
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);           //compara hora con esperando si son iguales pasa la prueba
}


//43:35 machete

// al ajustar la hora el reloj queda en hora y es valida
/*
void test_ajustar_hora(void){
    static const uint8_t ESPERANDO[] = {1,2,3,4,0,0};
    uint8_t hora[6]= {0xFF};
    clock_t reloj = ClockCreate(5);                     
    TEST_ASSERT_FALSE(ClockGetTime(reloj,hora,6));          
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);
}
*/