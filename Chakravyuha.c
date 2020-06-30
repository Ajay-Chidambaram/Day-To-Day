/*************************************************
               Chakravyuha CodeVita
*************************************************/

#include<stdio.h>

int main()
{
      int n;
      printf("\nEnter N Value : ");
      scanf("%d",&n);

      int a[n][n];
      int r = n, c = n;
      int start = 0, end = c-1;
      int count = 1;
      int x[100], y[100];
      int c1 = 1, c2 = 1;

      x[0] = 0;
      y[0] = 0;

      // Number of Spirals
      for(int s=0;s<r/2;s++)
      {
            //Upper Horizontal Line (Left to Right)
            for(int j=start;j<end+1;j++)
            {
                  a[start][j] = count;
                  if(count % 11 == 0)
                  {
                        x[c1++] = start;
                        y[c2++] = j;
                  }
                  count = count + 1;
            }
            //Downward Line (Top to Bottom)
            for(int i=start+1;i<end+1;i++)
            {
                  a[i][end] = count;
                  if(count % 11 == 0)
                  {
                        x[c1++] = i;
                        y[c2++] = end;
                  }
                  count = count + 1;
            }
            //Lower Horizontal Line (Right to Left)
            for(int j=end-1;j>=start;j--)
            {
                  a[end][j] = count;
                  if(count % 11 == 0)
                  {
                        x[c1++] = end;
                        y[c2++] = j;
                  }
                  count = count + 1;
            }
            //Upper Line (Bottom to Up)
            for(int i=end-1;i>=start+1;i--)
            {
                  a[i][start] = count;
                  if(count % 11 == 0)
                  {
                        x[c1++] = i;
                        y[c2++] = start;
                  }
                  count = count + 1;
            }

            start++;
            end--;
      }
      
      //Centre Element In case of Odd number of rows and columns
      if(r%2 == 1)
      {
            a[r/2][c/2] = count;
            if(count % 11 == 0)
                  {
                        x[c1++] = r/2;
                        y[c2++] = c/2;
                  }
            count = count + 1;
      }

      printf("\n\n!! Chakravyuha !! \n\n");

      for(int i=0;i<n;i++)
      {
            for(int j=0;j<n;j++)
            {
                  printf("%d ",a[i][j]);
            }
            printf("\n");
      }

      printf("\nPower Points : %d ",c1);
      
      for(int i=0;i<c1;i++)
      {
            printf("\n(%d, %d)",x[i],y[i]);
      }
}
