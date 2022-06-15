#include <stdio.h>
#include <stdlib.h>
#include <phobos/demangle/demangle.h>

int main()
{
 char* s = demangle("_D1a1bi");
 printf("%s", s);
 free(s);
 return 0;
}
