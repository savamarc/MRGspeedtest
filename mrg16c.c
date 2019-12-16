#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* The current state of the generator. */
static uint16_t x11 = 1;
static uint16_t x12 = 1;
static uint16_t x21 = 1;
static uint16_t x22 = 1;
#define a11 29602
#define a12 44944
#define a21 10445
#define a22 7526
#define MOD1 65267
#define MOD2 65147
#define NORM 1.5322e-5

static double inline next(void) {
  uint32_t tmp11 = x11*a11;
  uint32_t tmp12 = x12*a12;
  uint32_t tmp21 = x21*a21;
  uint32_t tmp22 = x22*a22;
  tmp11 %= MOD1;
  tmp12 %= MOD1;
  tmp21 %= MOD2;
  tmp22 %= MOD2;

  tmp11 += tmp12;
  tmp21 += tmp22;

  tmp11 %= MOD1;
  tmp21 %= MOD2;

  x12 = x11; 
  x11 = tmp11;
  x22 = x21;
  x21 = tmp21;

  return ((tmp11+tmp21)%MOD1)*NORM;
}

#ifndef INIT
#define INIT init();
void init(void) {
  srand(time(NULL));
  x11 = rand()%MOD1;
  x12 = rand()%MOD1;
  x21 = rand()%MOD2;
  x22 = rand()%MOD2;
}
#endif

#define HARNESS_DOUBLE
#include "harness.c"
