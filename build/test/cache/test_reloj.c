#include "src/reloj.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void test_reloj_arranca_hora_invalida(void){

    static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};

    uint8_t hora[6]= {0xFF};

    clock_t reloj = ClockCreate(5);

    do {if (!(ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(20)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_ajustar_hora(void){

    static const uint8_t ESPERANDO[] = {1,2,3,4,0,0};

    uint8_t hora[6]= {0xFF};



    clock_t reloj = ClockCreate(5);



    do {if ((ClockSetTime(reloj,ESPERANDO,4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(35)));}} while(0);

    do {if ((ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(36)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void SimulateTime(uint32_t seconds, clock_t reloj){

    for(int second = 0; second < seconds; second++){

        for(int index= 0;index < 5; index++){

            ClockTick(reloj);

        }

    }

}





void test_tiempo_unsegundo(void){

        static const uint8_t ESPERANDO[] = {0,0,0,0,0,1};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5);

        ClockSetTime(reloj,hora,6);



        SimulateTime(1, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_diezsegundo(void){

        static const uint8_t ESPERANDO[] = {0,0,0,0,1,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5);

        ClockSetTime(reloj,hora,6);



        SimulateTime(10, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_unminuto(void){

        static const uint8_t ESPERANDO[] = {0,0,0,1,0,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5);

        ClockSetTime(reloj,hora,6);



        SimulateTime(60, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_diezminutos(void){

        static const uint8_t ESPERANDO[] = {0,0,1,0,0,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5);

        ClockSetTime(reloj,hora,6);



        SimulateTime(600, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_unahora(void){

        static const uint8_t ESPERANDO[] = {0,1,0,0,0,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5);

        ClockSetTime(reloj,hora,6);



        SimulateTime(3600, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_24horas(void){

        static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5);

        ClockSetTime(reloj,hora,6);



        SimulateTime(3600*24, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(119), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_ajustar_alarma(void){

    static const uint8_t ESPERANDO[] = {0,0,1,2,3,0};

    uint8_t hora[6]= {0x00};

    uint8_t alarma[6]= {0x00};



    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj,hora,6);

    ClockGetTime(reloj,hora,6);

    do {if ((ClockSetAlarm(reloj,ESPERANDO,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(132)));}} while(0);

    do {if ((ClockGetAlarm(reloj,alarma,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(133)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_habilitar__alarma(void){

    uint8_t hora[6]= {0x00};

    uint8_t alarma[6]= {0x00};



    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj,hora,6);

    ClockSetAlarm(reloj,alarma,6);



    Alarmon(reloj);



    do {if ((consultaralarma(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(149)));}} while(0);

}



void test_deshabilitar_alarma(void){

    uint8_t hora[6]= {0x00};

    uint8_t alarma[6]= {0x00};



    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj,hora,6);

    ClockSetAlarm(reloj,alarma,6);



    Alarmoff(reloj);



    do {if (!(consultaralarma(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(163)));}} while(0);

}





void test_alarma_igual_reloj(void){

    uint8_t hora[6]={0,0,1,2,3,5};

    uint8_t alarma[6]={0,0,1,2,3,5};



    clock_t reloj = ClockCreate(5);





    ClockSetTime(reloj,hora,6);

    ClockSetAlarm(reloj,alarma,6);



    ClockGetTime(reloj,hora,6);

    ClockGetAlarm(reloj,alarma,6);



    Alarmon(reloj);



    UnityAssertEqualIntArray(( const void*)((hora)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(182), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((compara(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(183)));}} while(0);

}











void test_avanzar_reloj_suenaalarma(void){

    uint8_t hora[6]={0,0,0,0,0,0};

    uint8_t alarma[6]={0,0,0,1,0,0};



    clock_t reloj = ClockCreate(5);





    ClockSetTime(reloj,hora,6);

    ClockSetAlarm(reloj,alarma,6);







    Alarmon(reloj);



    SimulateTime(60, reloj);



    ClockGetTime(reloj,hora,6);

    ClockGetAlarm(reloj,alarma,6);



    UnityAssertEqualIntArray(( const void*)((hora)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(209), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((compara(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(210)));}} while(0);

}











void test_avanzar_reloj_nosuenaalarma(void){

    uint8_t hora[6]={0,0,0,0,0,0};

    uint8_t alarma[6]={0,0,0,1,0,0};



    clock_t reloj = ClockCreate(5);





    ClockSetTime(reloj,hora,6);

    ClockSetAlarm(reloj,alarma,6);







    Alarmoff(reloj);



    SimulateTime(60, reloj);



    ClockGetTime(reloj,hora,6);

    ClockGetAlarm(reloj,alarma,6);



    UnityAssertEqualIntArray(( const void*)((hora)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(236), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if (!(compara(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(237)));}} while(0);

}
