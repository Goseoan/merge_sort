#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge.h"

int main(int argc, char * argv[]) 
{ 
   int i,max;
   float gap =0, gap2= 0;
   time_t startTime=0, endTime=0;
   time_t startTime2=0, endTime2=0;

   // input value check
   if( argc >2)
   {
      printf("Input Size 1 ~ 500000 <size>\n");
      exit(1);
   }

   max= atoi(argv[1]);

   // input size check
   if( max<0 || max > 500000 )
   {
      printf("Input Size 1 ~ 500000 \n");
      exit(1);
   }
  
   // make array
   int randAry[max]; 
   int copyAry1[max];
   int copyAry2[max];


   randome_generate(randAry, max); 

   for (i=0; i < max; i++)
   {
      copyAry1[i] = randAry[i];
      copyAry2[i] = randAry[i];
   }
   
   //printArray(randAry,max);
   
   startTime = clock();
   mergeSort(copyAry1, 0, max-1);
   endTime = clock();

   //printArray(copyAry1,max);
  
   startTime2 = clock(); 
   bubble(copyAry2,max);
   mergeSort(copyAry2, 0, max-1);  
   endTime2 = clock();

   //printArray(copyAry2,max);
   
   gap = (float)(endTime - startTime) /(CLOCKS_PER_SEC);
   gap2 = (float)(endTime2 - startTime2) /(CLOCKS_PER_SEC);

   printf("Original     : %f \n",gap);
   printf("Improve      : %f \n",gap2);
   printf("Diff         : %f \n",gap-gap2);
   
   return 0;
}

void randome_generate(int *ary, int max)
{
   int i;
   time_t t;   

   srand((unsigned) time(&t));

   for( i = 0 ; i < max; i++ ) 
      ary[i]= rand() % RAND_MAX;   
}

void printArray(int *a,int max)
{
    int i;
    printf("\n------------------------\n");
    for (i=0; i < max; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("\n------------------------\n");
}

