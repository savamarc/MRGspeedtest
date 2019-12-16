#include "powers.h"
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// A lot of definitions to make it easier to create a new generator from this
#define MOD1 576460752303282719 // 2^59 - 140769
#define MOD2 576460752303228743 // 2^59 - 194745
#define H1 140769
#define H2 194745
// This does not loose precision with gcc, but this should be specified with HEX
// to avoid precision losses
#define NORM 1.7347234759772307989996896732795790534286186840100783823626073854029527865350246429443359375e-18 // 1.0/MOD1
#define MASK121 P2_22
#define MASK122 P2_27
#define MASK123 P2_38
#define MASK131 P2_18
#define MASK132 P2_25
#define MASK133 P2_39
#define MASK211 P2_19
#define MASK212 P2_26
#define MASK213 P2_27
#define MASK231 P2_28
#define MASK232 P2_37
#define MASK233 P2_41

int64_t x11, x12, x13, x21, x22, x23;

void init(void) {
  srand(time(NULL));
  x11 = rand()%MOD1;
  x12 = rand()%MOD1;
  x13 = rand()%MOD1;
  x21 = rand()%MOD2;
  x22 = rand()%MOD2;
  x23 = rand()%MOD2;
}

double next (void) {
  const int64_t corr1 = 4*MOD1;
  const int64_t corr2 = 8*MOD2;

  int64_t y1, r; /* For intermediate results */
  r = (x11 + x21)%MOD1;

  /* First component */
  y1 = ((x12 & MASK121) << 37) - ((x12 & MASK122) << 32) + ((x12 & MASK123) << 21)
    + ((x13 & MASK131) << 41) + ((x13 & MASK132) << 34) - ((x13 & MASK133) << 20);
  y1 += H1*((x12 >> 22) - (x12 >> 27) + (x12 >> 38)
      + (x13 >> 18) + (x13 >> 25) - (x13 >> 39));
  y1 = (y1+corr1)%MOD1;

  x13 = x12; x12 = x11; x11 = y1;


  /* Second component */
  y1 = (-(x21 & MASK211) << 40) - ((x21 & MASK212) << 33) - ((x21 & MASK213) << 32)
    + ((x23 & MASK231) << 31) + ((x23 & MASK232) << 22) - ((x23 & MASK233) << 18);
  y1 += H2*(-(x21 >> 19) - (x21 >> 26) - (x21 >> 27)
      + (x23 >> 28) + (x23 >> 37) - (x23 >> 41));
  y1 = (y1+corr2)%MOD2;

  x23 = x22; x22 = x21; x21 = y1;

  /* Combination */
  return r*NORM;
}

#define INIT init();
#define HARNESS_DOUBLE
#include "harness.c"
