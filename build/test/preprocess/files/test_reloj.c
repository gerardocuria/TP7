#include "src/reloj.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"












void test_reloj_arranca_hora_invalida(void){

    static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};

    uint8_t hora[6]= {0xFF};

    clock_t reloj = ClockCreate(5);

    do {if (!(ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(13)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_ajustar_hora(void){

    static const uint8_t ESPERANDO[] = {1,2,3,4,0,0};

    uint8_t hora[6]= {0xFF};



    clock_t reloj = ClockCreate(5);



    do {if ((ClockSetTime(reloj,ESPERANDO,4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(28)));}} while(0);

    do {if ((ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(29)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

       ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

       ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

       ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

       ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

       ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

       ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}

void test_ajustar_alarma(void){

    static const uint8_t ESPERANDO[] = {0,0,1,2,3,0};

    uint8_t hora[6]= {0x00};

    uint8_t alarma[6]= {0x00};



    clock_t reloj = ClockCreate(5);



    ClockSetTime(reloj,hora,6);

    ClockGetTime(reloj,hora,6);

    do {if ((ClockSetAlarm(reloj,ESPERANDO,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(156)));}} while(0);

    do {if ((ClockGetAlarm(reloj,alarma,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(157)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
