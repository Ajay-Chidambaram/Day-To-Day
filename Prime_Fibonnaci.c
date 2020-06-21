#include<stdio.h>
#include<string.h>
#include<math.h>

// Function to check whether the number is prime or not //
// If prime return 1 else return 0 //
int prime_check(int a)
{
  for(int i=2;i<=sqrt(a);i++)
  {
    if(a%i == 0)
    {
      return 0;
    }
  }
  return 1;
}

// Main Function //
int main()
{
  int a,b;
  scanf("%d %d",&a,&b);

  int prime[b];
  int prime_count = 0;
  int p[b], p2[10000], count=0;
  int max = 0, min = 100000;

  for(int i=0;i<b;i++)
    prime[i] = 0;

  // Find prime numbers between range using sieve of eratosthenes //
  for(int i=2;i<b;i++)
  {
    if(prime[i] == 0){
      for(int j=i*2;j<b;j=j+i)
      {
        prime[j] = 1;
      }
    }
  }

  // Store only prime numbers //
  for(int i=a;i<b;i++)
  {
    if(prime[i] == 0){
      p[prime_count++] = i; 
    }
  }

  int digit = floor(log10(p[prime_count-1])+1);
  int limit = (p[prime_count-1]*pow(10,digit)) + p[prime_count-1] ;
  int hash[limit];

  // Create hash for removing duplicates during all combinations //
  for(int i=0;i<limit;i++)
    hash[i] = 0;

  printf("\n1st Prime LIST : ");
  for(int i=0;i<prime_count;i++)
    printf("%d ",p[i]);

  // Forming all combination and finding small, large and count of prime numbers //
  for(int i=0;i<prime_count;i++)
  {
    for(int j=0;j<prime_count;j++)
    {
      if(i == j)
        continue;

      int d = floor(log10(p[j])+1);
      int s = (p[i]*pow(10,d)) + p[j];
      hash[s] += 1;
      if(s == 6761)
        printf("$$$ YES $$$");
      if(prime_check(s) == 1 && hash[s] == 1){
        p2[count++] = s;

        if(s > max)
          max = s;
        if(s < min)
          min = s;
      }
    }
  }

  printf("\n2nd Prime LIST :");
  for(int i=0;i<count;i++)
    printf("%d ",p2[i]);

  printf("\n||min: %d, max: %d, count: %d || \n",min,max,count);

  // Extracting the fibonnaci by choosing min and max as 1st and 2nd element;
  long long int fib[count];
  fib[0] = (long long int)min;
  fib[1] = (long long int)max;
  for(int i=2;i<count;i++)
  {
    fib[i] = fib[i-1] + fib[i-2];
  }

  printf("RESULT = %lld ",fib[count-1]);
 // printf("\n ||%lld %lld %lld ||",fib[0],fib[1],fib[count-1]);
}
