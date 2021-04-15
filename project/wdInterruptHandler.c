#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char state_count = 0;
  if (++blink_count == 40 && switch_state == 1) {
    RG_toggle();
    blink_count = 0;
  }
  else if (blink_count == 40 && switch_state == 3){
    RG_on();
    blink_count = 0;
  }
  else if (blink_count == 40 && switch_state == 2){
    dim_RG();
    blink_count = 0;
  }
  else if (blink_count == 40 && switch_state == 4){
    sound();
    blink_count = 0;
  }
}
