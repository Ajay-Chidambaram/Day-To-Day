/*******************************************************
           Binary Search in an Array
        The array need to be sorted order
*******************************************************/

#include<stdio.h>

int binary_search(int a[], int start, int end, int data)
{
      if(a[start] == data)
            return 1;
      if(start != end)
      {
            int mid = (start + end) / 2;
            if(a[mid] == data)
                  return 1;
            if(a[mid] > data)
                  return binary_search(a,start,mid,data);
            else
                  return binary_search(a,mid+1,end,data);
      }
      return 0;
}

int main()
{
      int a[] = {1,2,3,4,5,6};
      int n = 6;

      int start = 0;
      int data = -1;
      int x = binary_search(a,start,n-1,data);

      if(x == 0)
            printf("%d not found",data);
      else
            printf("%d found",data);
      
}