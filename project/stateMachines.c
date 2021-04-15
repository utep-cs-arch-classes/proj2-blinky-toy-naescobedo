
#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachines.h"
#include <msp430.h>


static char green =0;
static char red =0;
static char rg = 0;
static char dim =0;
static char state = 0;
static char sound1 = 0;

void off_state(){
  green_on=0;
  red_on=0;
  led_changed = 0;
}

void RG_toggle(){
  static enum {R = 0, G = 1} color =G;
  switch(color){
  case R:
    green_on =1;
    red_on=0;
    color = G;
    break;
  case G:
    green_on = 0;
    red_on = 1;
    color = R;
    break;
  }
  led_changed =1;
  led_update();
  
  
}

void red_blink(){
  static char state =0;

  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on =0;
    state = 0;
    break;
  }
}

void RG_on(){
  static enum {RG =2} color =RG;
  green_on = 1;
  red_on = 1;
  color = RG;
}

void RG_blink(){
  static enum {R =0, G=1} color=G;
  switch(color){
  case R:
    green_on = 1;
    red_on =0;
    color = G;
    break;
  case G:
    green_on = 0;
    red_on =1;
    color = R;
    break;
  }
  led_changed = 1;
  led_update();
}

void sound(){
  buzzer_set_period(800);
}

void dim_RG(){
  switch(dim){
  case 0:
    RG_blink();
  case 1:
    RG_on();
    break;
  }
  led_changed =1;
  led_update();
}

void change_state(){
  if(dim==0){
    dim =1;
  }
  else{
    dim =0;
  }
}


