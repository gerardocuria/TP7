//al iniciar el reloj deberia estar en 00:00 y con hora invalida


#include "unity.h"
#include "reloj.h"

#define TICKS_PER_SECOND 5

void test_reloj_arranca_hora_invalida(void){
    static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};
    uint8_t hora[6]= {0xFF};
    clock_t reloj = ClockCreate(5);                            //cantidad de tics capara configurar el systick del reloj
    TEST_ASSERT_FALSE(ClockGetTime(reloj,hora,6));             //guarda y compara reloj en hora si no son diferentes pasa el test
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);           //compara hora con esperando si son iguales pasa la prueba
}


//43:35 machete

// al ajustar la hora el reloj queda en hora y es valida

void test_ajustar_hora(void){
    static const uint8_t ESPERANDO[] = {1,2,3,4,0,0};
    uint8_t hora[6]= {0xFF};

    clock_t reloj = ClockCreate(5);             
    //ClockSetTime(reloj,ESPERANDO,4);                            //comparo reloj con esperando (4 xq no comparo los segundos)
    TEST_ASSERT_TRUE(ClockSetTime(reloj,ESPERANDO,4));   
    TEST_ASSERT_TRUE(ClockGetTime(reloj,hora,6));       
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);
}


void SimulateTime(uint32_t seconds, clock_t reloj){
    for(int second = 0; second < seconds; second++){
        for(int index= 0;index < TICKS_PER_SECOND; index++){
            ClockTick(reloj);
        }
    }
}


void test_tiempo_unsegundo(void){
        static const uint8_t ESPERANDO[] = {0,0,0,0,0,1};
        uint8_t hora[6]= {0x00};
        clock_t reloj = ClockCreate(5);             
        ClockSetTime(reloj,hora,6); //lo de hora copio en reloj

        SimulateTime(1, reloj);

        ClockGetTime(reloj,hora,6); //lo de reloj copio en hora
        TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);
}

void test_tiempo_diezsegundo(void){
        static const uint8_t ESPERANDO[] = {0,0,0,0,1,0};
        uint8_t hora[6]= {0x00};
        clock_t reloj = ClockCreate(5);             
        ClockSetTime(reloj,hora,6); //lo de hora copio en reloj

        SimulateTime(10, reloj);

        ClockGetTime(reloj,hora,6); //lo de reloj copio en hora
        TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);
}

void test_tiempo_unminuto(void){
        static const uint8_t ESPERANDO[] = {0,0,0,1,0,0};
        uint8_t hora[6]= {0x00};
        clock_t reloj = ClockCreate(5);             
        ClockSetTime(reloj,hora,6); //lo de hora copio en reloj

        SimulateTime(60, reloj);

        ClockGetTime(reloj,hora,6); //lo de reloj copio en hora
        TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);
}

void test_tiempo_diezminutos(void){
        static const uint8_t ESPERANDO[] = {0,0,1,0,0,0};
        uint8_t hora[6]= {0x00};
        clock_t reloj = ClockCreate(5);             
        ClockSetTime(reloj,hora,6); //lo de hora copio en reloj

        SimulateTime(600, reloj);

        ClockGetTime(reloj,hora,6); //lo de reloj copio en hora
        TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);
}

void test_tiempo_unahora(void){
        static const uint8_t ESPERANDO[] = {0,1,0,0,0,0};
        uint8_t hora[6]= {0x00};
        clock_t reloj = ClockCreate(5);             
        ClockSetTime(reloj,hora,6); //lo de hora copio en reloj

        SimulateTime(3600, reloj);

        ClockGetTime(reloj,hora,6); //lo de reloj copio en hora
        TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);
}

void test_tiempo_24horas(void){
        static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};
        uint8_t hora[6]= {0x00};
        clock_t reloj = ClockCreate(5);             
        ClockSetTime(reloj,hora,6); //lo de hora copio en reloj

        SimulateTime(3600*24, reloj);

        ClockGetTime(reloj,hora,6); //lo de reloj copio en hora
        TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,hora,6);
}



/*
void test_fijar_y_consultar_alarma(void) {
    static const uint8_t HORA_ALARMA[] = {10, 30, 0, 0, 0, 0};
    uint8_t hora_consultada[6] = {0xFF};
    clock_t reloj = ClockCreate(5);
    
    TEST_ASSERT_TRUE(SetAlarmTime(reloj, HORA_ALARMA, 6));
    TEST_ASSERT_TRUE(GetAlarmTime(reloj, hora_consultada, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(HORA_ALARMA, hora_consultada, 6);
}*/
/*
void test_fijar_y_avisar_alarma(void) {
    static const uint8_t HORA_ALARMA[] = {12, 0, 0, 0, 0, 0};
    uint8_t hora_actual[6] = {12, 0, 0, 0, 0, 0};
    clock_t reloj = ClockCreate(5);
    
    TEST_ASSERT_TRUE(ClockSetAlarmTime(reloj, HORA_ALARMA, 6));
    
    // Avanzar el reloj hasta que la hora actual coincida con la alarma
    while (!ClockAlarmActivated(reloj)) {
        ClockUpdate(reloj);
        ClockGetTime(reloj, hora_actual, 6);
    }
    
    TEST_ASSERT_TRUE(ClockAlarmActivated(reloj));
}
*/
//1:09


void test_ajustar_alarma(void){
    static const uint8_t ESPERANDO[] = {0,0,1,2,3,0};
    uint8_t hora[6]= {0x00};
    uint8_t alarma[6]= {0x00};

    clock_t reloj = ClockCreate(5);             
    //ClockSetTime(reloj,ESPERANDO,4);   
    ClockSetTime(reloj,hora,6); //lo de hora copio en reloj
    ClockGetTime(reloj,hora,6); //lo de reloj copio en horaq                   
    TEST_ASSERT_TRUE(ClockSetAlarm(reloj,ESPERANDO,6));   
    TEST_ASSERT_TRUE(ClockGetAlarm(reloj,alarma,6));       
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO,alarma,6);
}


void test_habilitar__alarma(void){
    uint8_t hora[6]= {0x00};
    uint8_t alarma[6]= {0x00};

    clock_t reloj = ClockCreate(5);             
    //ClockSetTime(reloj,ESPERANDO,4);   
    ClockSetTime(reloj,hora,6); //lo de hora copio en reloj                  
    ClockSetAlarm(reloj,alarma,6);   

    Alarmon(reloj);

    TEST_ASSERT_TRUE(consultaralarma(reloj));
}

void test_deshabilitar_alarma(void){
    uint8_t hora[6]= {0x00};
    uint8_t alarma[6]= {0x00};

    clock_t reloj = ClockCreate(5);             
    //ClockSetTime(reloj,ESPERANDO,4);   
    ClockSetTime(reloj,hora,6); //lo de hora copio en reloj                  
    ClockSetAlarm(reloj,alarma,6);   

    Alarmoff(reloj);

    TEST_ASSERT_FALSE(consultaralarma(reloj));
}