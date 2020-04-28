#include <stdio.h>
#include "libque.h"

int main()
{
   int T;
   do{
   printf("Enter Time in seconds ");
   scanf("%d", &T);
   if(T <= 0)
       printf("\7");
   }while(T <= 0);
   struct Queue* queue = createQueue(100);
   int timeBuying, timeCome;
   timeBuying = 5 + rand()%90;
   timeCome = 5 + rand()%90;
   int i = 0, j = i;
   int time1 = timeCome, time2 = timeBuying + timeCome;
   srand(100);
   while(time1 < T || time2 < T)
   {
       if(!isFull(queue) &&  time1 <= time2 && time1 <= 300)
       {
           enQueue(queue,i);
           printf("\n%d client came in %d seconds, at %d time", i, timeCome, time1);
           timeCome = 5 + rand()%45;
           time1+=timeCome;
           showArray(queue);
           i++;
       }
       if(!isEmpty(queue) && time2 < time1 && time2 <= 300)
       {
           deQueue(queue);
           printf("\n%d client served in %d seconds, at %d time\n", j, timeBuying, time2);
           timeBuying = 5 + rand()%90;
           time2 += timeBuying;
           showArray(queue);
           j++;
       }

   }
   printf("next coming %d second, next buying in %d seconds", timeCome, timeBuying);
   return 0;
}
