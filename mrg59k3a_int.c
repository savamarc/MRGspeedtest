#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define NORM 1.7347234759772307989996896732795790534286186840100783823626073854029527865350246429443359375e-18 // 1.0/MOD1
#define MOD1 576460752303282719 // 2^59 - 140769
#define MOD2 576460752303228743 // 2^59 - 194745

#define a12 756990256
#define a13 443897406
#define a21 512643533
#define a23 516293997

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

static int64_t inline next (void)
{
  const int64_t q12 = MOD1/a12;
  const int64_t r12 = MOD1 - MOD1/a12 * a12;
  const int64_t q13 = MOD1/a13;
  const int64_t r13 = MOD1 - MOD1/a13 * a13;
  const int64_t q21 = MOD2/a21;
  const int64_t r21 = MOD2 - MOD2/a21 * a21;
  const int64_t q23 = MOD2/a23;
  const int64_t r23 = MOD2 - MOD2/a23 * a23;

  int64_t y1, y2, r, k;

  /* First component*/
  k = x12/q12;
  y1 = (a12*(x12 - k*q12) + MOD1 - k*r12);
  k = x13/q13;
  y2 = (a13*(x13 - k*q13) + MOD1 - k*r13);

  y1 = (y1 + y2)%MOD1;

  x13 = x12; x12 = x11; x11 = y1;

  /* Second component*/
  k = x21/q21;
  y1 = (a21*(x21 - k*q21) + MOD2 - k*r21);
  k = x23/q23;
  y2 = (a23*(x23 - k*q23) + MOD2 - k*r23);

  y1 = (y1 + y2)%MOD2;

  x23 = x12; x22 = x21; x21 = y1;

  /*Combination*/
  return (x11 + x21)%MOD1;
}

#define INIT init();
#include "harness.c"
