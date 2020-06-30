/***************************************
         BUBBLE SORT ALGORITHM
***************************************/

#include<stdio.h>

void swap(int *a, int *b)
{
      int temp;
      temp = *a; 
      *a = *b;
      *b = temp;
}

void bubble_sort(int a[], int n)
{
      for(int i=0;i<n-1;i++)
      {
            for(int j=0;j<n-i-1;j++)
            {
                  if(a[j+1] < a[j])
                  {
                        swap(&a[j+1],&a[j]);
                  }
            }
      }
}

int main()
{
      int a[] = {8,1,2,10,9,5};
      int n = 6;

      bubble_sort(a,n);

      for(int i=0;i<6;i++)
            printf("%d ",a[i]);
}