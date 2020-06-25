/******************************************
To find maximum sum subarray of size k 
Using Sliding-Window-Technique 
******************************************/


#include<stdio.h>

int main()
{
      int n,k;
      scanf("%d %d",&n,&k);
      int a[n];

      for(int i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }

      int sum = 0, max = 0;
      for(int i=0;i<k;i++)
      {
            sum = sum + a[i];
            max = sum;
      }
      for(int i=0;i<n-k;i++)
      {
            sum = sum + a[i+k] - a[i];
            if(sum > max)
                  max = sum;
      }

      printf("%d",max);
}
