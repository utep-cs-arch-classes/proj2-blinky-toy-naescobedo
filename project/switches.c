#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

char switch_state;
char button_click1 = 0;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  char s1_state_down = (p2val & S1);
  char s2_state_down = (p2val & S2);
  char s3_state_down = (p2val & S3);
  char s4_state_down = (p2val & S4);
  
 if (s1_state_down == 0){
    switch_state = 1;
    button_click1 +=1;
  }
 else if (s2_state_down == 0){
   switch_state =2;
 }
 else if (s3_state_down == 0){
   switch_state = 3;
 }
 else if (s4_state_down == 0){
   switch_state = 4;
 }
  switch_state_changed = 1;
  led_update();
}
