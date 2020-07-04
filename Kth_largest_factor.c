#include<stdio.h>

int main()
{
      long long int n,k,i,j=1,index;
      scanf("%lld",&n);
      scanf("%lld",&k);
      long long int factor[100000];

      factor[0] = 1;
      for(i=2;i<=n/2;i++)
      {
            if(n%i == 0)
                  factor[j++] = i;
      }
      factor[j] = n;

      for(long long int x=0;x<=j;x++)
            printf("%d ",factor[x]);

      if(j < k)
            index = 0;
      else
            index = j - k + 1;
      
      printf("\n\nKth largest factor of %lld is | %lld |",n,factor[index]);
}
