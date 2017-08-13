
#include "merge.h"


// Perform bubble sorting 1 time
void bubble( int * ary,int max)
{
	int i, j, swap;

	for(i = 0 ; i < ( max - 1 ); i++)
	{   
      if (ary[i] > ary[i+1]) /* For decreasing order use < */
		{
			swap       = ary[i];
			ary[i]   = ary[i+1];
			ary[i+1] = swap;
		}

	}
}