/*************************************************************************************************************
          Maximum size element of stack in O(1) time and space complexity
          
      Approach :
         push condition push (2*x – maxEle) and make x as maxEle
         pop condition make maxEle as (2*maxEle - x)
         https://www.geeksforgeeks.org/find-maximum-in-a-stack-in-o1-time-and-o1-extra-space/
         
*************************************************************************************************************/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int s[100000];
int top = 0, max = 0;

void push(void)
{
    int data, maxele;
    scanf("%d",&data);

    if(top == 0)
        max = data;

    if(data > max)
    {
        maxele = data;
        data = (2*data - max);
        max = maxele;
    }

    top++;
    s[top] = data;
}

void pop(void)
{
    int res = s[top--];

    if(res > max)
        max = (2*max - res);
}

void maximum(void)
{
    printf("%d\n",max);
}

int main() {

    int n, ch;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:push(); break;

            case 2:pop(); break;

            case 3:maximum(); break;

            default: break;
        }
    } 

    return 0;
}
