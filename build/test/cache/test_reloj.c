#include "src/reloj.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








void test_start_up(void){

    static const uint8_t ESPERANDO[] = {0,0,0,0,0,0};

    uint8_t hora[6]= {0xFF};

    clock_t reloj = ClockCreate(5);

    do {if (!(ClockGetTime(reloj,hora,6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(11)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

   ((void *)0)

   ), (UNITY_UINT)(12), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
