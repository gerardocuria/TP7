#include "src/reloj.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






static 

      _Bool 

           buzzer;



void sonaralarma(void);



void sonaralarma(void){

    buzzer=

          1

              ;

}



void test_reloj_arranca_hora_invalida(void){

    static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};

    uint8_t hora[6]= {0xFF};

    clock_t reloj = ClockCreate(5,sonaralarma);

    do {if (!(ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(28)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_ajustar_hora(void){

    static const uint8_t ESPERANDO[] = {1,2,3,4,0,0};

    uint8_t hora[6]= {0xFF};



    clock_t reloj = ClockCreate(5,sonaralarma);



    do {if ((ClockSetTime(reloj,ESPERANDO,4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(43)));}} while(0);

    do {if ((ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(44)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

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

        clock_t reloj = ClockCreate(5,sonaralarma);

        ClockSetTime(reloj,hora,6);



        SimulateTime(1, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_diezsegundo(void){

        static const uint8_t ESPERANDO[] = {0,0,0,0,1,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5,sonaralarma);

        ClockSetTime(reloj,hora,6);



        SimulateTime(10, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_unminuto(void){

        static const uint8_t ESPERANDO[] = {0,0,0,1,0,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5,sonaralarma);

        ClockSetTime(reloj,hora,6);



        SimulateTime(60, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_diezminutos(void){

        static const uint8_t ESPERANDO[] = {0,0,1,0,0,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5,sonaralarma);

        ClockSetTime(reloj,hora,6);



        SimulateTime(600, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_unahora(void){

        static const uint8_t ESPERANDO[] = {0,1,0,0,0,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5,sonaralarma);

        ClockSetTime(reloj,hora,6);



        SimulateTime(3600, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}



void test_tiempo_24horas(void){

        static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};

        uint8_t hora[6]= {0x00};

        clock_t reloj = ClockCreate(5,sonaralarma);

        ClockSetTime(reloj,hora,6);



        SimulateTime(3600*24, reloj);



        ClockGetTime(reloj,hora,6);

        UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

       ((void *)0)

       ), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_ajustar_alarma(void){

    static const uint8_t ESPERANDO[] = {0,0,1,2,3,0};

    uint8_t hora[6]= {0x00};

    uint8_t alarma[6]= {0x00};



    clock_t reloj = ClockCreate(5,sonaralarma);



    ClockSetTime(reloj,hora,6);

    ClockGetTime(reloj,hora,6);

    do {if ((ClockSetAlarm(reloj,ESPERANDO,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(140)));}} while(0);

    do {if ((ClockGetAlarm(reloj,alarma,6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(141)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(142), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_habilitar__alarma(void){

    uint8_t hora[6]= {0x00};

    uint8_t alarma[6]= {0x00};



    clock_t reloj = ClockCreate(5,sonaralarma);



    ClockSetTime(reloj,hora,6);

    ClockSetAlarm(reloj,alarma,6);



    Alarmon(reloj);



    do {if ((consultaralarma(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(157)));}} while(0);

}



void test_deshabilitar_alarma(void){

    uint8_t hora[6]= {0x00};

    uint8_t alarma[6]= {0x00};



    clock_t reloj = ClockCreate(5,sonaralarma);



    ClockSetTime(reloj,hora,6);

    ClockSetAlarm(reloj,alarma,6);



    Alarmoff(reloj);



    do {if (!(consultaralarma(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(171)));}} while(0);

}

void test_avanzar_reloj_suenaalarma(void){



    buzzer=

          0

               ;

    uint8_t hora[6]={0,0,0,0,0,0};

    uint8_t alarma[6]={0,0,0,1,0,0};



    clock_t reloj = ClockCreate(5,sonaralarma);





    ClockSetTime(reloj,hora,6);

    ClockSetAlarm(reloj,alarma,6);







    Alarmon(reloj);



    SimulateTime(60, reloj);



    ClockGetTime(reloj,hora,6);

    ClockGetAlarm(reloj,alarma,6);



    UnityAssertEqualIntArray(( const void*)((hora)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(221), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if ((Alarmon(reloj))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(222)));}} while(0);

    do {if ((buzzer)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(223)));}} while(0);

}









void test_avanzar_reloj_nosuenaalarma(void){



    buzzer=

          0

               ;

    uint8_t hora[6]={0,0,0,0,0,0};

    uint8_t alarma[6]={0,0,0,1,0,0};



    clock_t reloj = ClockCreate(5,sonaralarma);





    ClockSetTime(reloj,hora,6);

    ClockSetAlarm(reloj,alarma,6);



    Alarmoff(reloj);



    SimulateTime(60, reloj);



    ClockGetTime(reloj,hora,6);

    ClockGetAlarm(reloj,alarma,6);



    UnityAssertEqualIntArray(( const void*)((hora)), ( const void*)((alarma)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(248), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if (!(Alarmoff(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(249)));}} while(0);

    do {if (!(buzzer)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(250)));}} while(0);

}
