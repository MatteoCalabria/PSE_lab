#ifndef __define_UT_h__
#define __define_UT_h__

#include <systemc.h>

struct iostruct {
  double a;
  double b;
  double result;
};

#define ADDRESS_TYPE int
#define DATA_TYPE iostruct

#endif
