/****************************************
Kadane's Algorithm
example array = {-2,-3,4,-1,-2,1,5,-3}

****************************************/

#include<stdio.h>

int main()
{
      int n;
      scanf("%d",&n);
      int a[n];

      for(int i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }

      int max = 0, max_end = 0;

      for(int i=0;i<n;i++)
      {
            max_end += a[i];

            if(max_end < 0)
                  max_end = 0;
            if(max_end > max)
                  max = max_end;
      }

      printf("The largest configuous sum  :  %d",max);
}
