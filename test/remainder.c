#include <stdio.h>
#include <phobos/math/remainder.h>

int main()
{
 long double intpart;
 printf("%Lf\n", math_remainder_modf(3.14159, &intpart));
 printf("%Lf", intpart);
 return 0;
}