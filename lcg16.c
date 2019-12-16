#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* The current state of the generator. */
static uint16_t s = 1;
#define MULT 53283
#define MOD 65536
#define CONST 12345
#define NORM 1.5259e-5

static double inline next(void) {
  s = s*MULT + CONST;
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
