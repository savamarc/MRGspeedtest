#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define NORM 1.084202172485507082161126333319239663395452304275062989889766296158768454915843904018402099609375e-19
#define MOD1 9223372036854754679
#define MOD2 9223372036854500783

#define a12 1959243308
#define q12 4707619517
#define r12 1562312443

#define a13 1434117900
#define q13 6431390359
#define r13 1125428579

#define a21 2301631445
#define q21 4007319267
#define r21 1772949968

#define a23 1105728549
#define q23 8341443336
#define r23 373501319

uint64_t x11, x12, x13, x21, x22, x23;

void init(void) {
  srand(time(NULL));
  x11 = rand();
  x12 = rand();
  x13 = rand();
  x21 = rand();
  x22 = rand();
  x23 = rand();
}

double next (void)
{
  uint64_t y1, y2, r, k;

  /* First component*/
  k = x12/q12;
  y1 = (a12*(x12 - k*q12) + MOD1 - k*r12)%MOD1;
  k = x13/q13;
  y2 = (a13*(x13 - k*q13) + MOD1 - k*r13)%MOD1;

  y1 = (y1 + y2)%MOD1;

  x13 = x12; x12 = x11; x11 = y1;

  /* Second component*/
  k = x21/q21;
  y1 = (a21*(x21 - k*q21) + MOD2 - k*r21)%MOD1;
  k = x23/q23;
  y2 = (a23*(x23 - k*q23) + MOD2 - k*r23)%MOD1;

  y1 = (y1 + y2)%MOD2;

  x23 = x12; x22 = x21; x21 = y1;

  /*Combination*/
  return ((x11 + x21)%MOD1)*NORM;

}

#define INIT init();
#define HARNESS_DOUBLE
#include "harness.c"
