//al iniciar el reloj deberia estar en 00:00 y con hora invalida


#include "unity.h"
/*
void test_start_up(void){
    static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};
    uint8_t hora[6];
    clock_t reloj = ClockCreate(5);
    TEST_ASSERT_FALSE(ClockGetTime(reloj,hora,6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(esperando,hora,6);
}
*/

void test_inicializacion(void){
    TEST_FAIL_MESSAGE("Funciona");
}