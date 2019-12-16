#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* The current state of the generator. */
static uint16_t s = 1;
#define MULT 12253
#define MOD 65536
#define NORM 1.5259e-5

static double inline next(void) {
  s *= MULT;
  return s*NORM;
}

#ifndef INIT
#define INIT init();
void init(void) {
  srand(time(NULL));
  s = rand()%MOD;
}
#endif

#define HARNESS_DOUBLE
#include "harness.c"
