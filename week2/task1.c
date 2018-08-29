#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
  int a=INT_MAX;
  float b=FLT_MAX;
  double d=DBL_MAX;
  printf("The maximum value of INT = %d\n", a);
  printf("The maximum value of FLOAT %lf\n", b);
  printf("The maximum value of DOUBLE %f\n", d);
}

