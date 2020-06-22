/***********************APPROACH****************************************
1) number of patients will be between 0 to 52 only
2) so find that pre-defined array initially
3) finding revenue starts from 0 TV to n TV
4) 2 cases ... patients less than room and greater than available rooms
5) if the revenue gets exceed from given break from that loop
*************************************************************************/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
      //Number of Patients configuration pre-defined 
      int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
      int config[53];

      for(int i=0;i<53;i++)
            config[i] = 0;

      for(int i=0;i<12;i++)
      {
            for(int j=1;j<=month[i];j++)
            {
                  int xx = pow((6-i-1),2) + abs(j-15) ;
                  config[xx] += 1;
            }
      }

      //Input Section
      int n, r1, r2, revenue, res=0, req=0;
      scanf("%d",&n);
      scanf("%d %d",&r2,&r1);
      scanf("%d",&revenue);
      printf("| %d |\n",revenue);
      //Finding Number of TV's Needed to met the required revenue
      for(int i=0;i<=n;i++)
      {
            res = 0;
            for(int j=0;j<53;j++)
            {
                  if(j > n)
                  {
                        res += (((n-i)*r1) + (i*r2)) * config[j];
                  }
                  else if(j < n)
                  {
                        res += (((n-i)*r1) + ((j-(n-i))*r2)) * config[j];
                  }
                  else
                  {
                        res += (((n-i)*r1) + (i*r2)) * config[j];
                  }
            }

            printf("%d -> %d \n",i,res);
            if(res > revenue)
            {
                  req = i;
                  break;
            }
      }

      if(req == 0)
            printf("%d",n);
      else
            printf("%d",req);
}
