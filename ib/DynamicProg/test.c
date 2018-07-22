#include <stdlib.h>
#include <stdio.h>
enum {true, false};
int main()
{
   int i = 1;
   do
   {
      printf("%d\n", i);
      i++;
      if (i < 15)
            continue;
   } while (true);
 
//    getchar();
   return 0;
}
