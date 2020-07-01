/*******************************************************************************
      
      KNIGHT Travel from given point to Destination
                 with Shortest Distance

      Approach :
            1)Initialize the common 8 paths that knight can travel
            2)Make the board as 8x8 matrix
            3)Initialize 8x8 matrix as 0 ...incase of visit make it as 1
            4)Using BFS travel the path .. incase destination reached 
            return the distance of that cell from start cell.

********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int front=0,rear=0;
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };

struct node
{
    int x;
    int y;
    int dist;
}q[1000];

void  enq(struct node data)
{
    if(front == 0 && rear == 0)
    {
        rear++;
        q[rear] = data;
        front++;
    }
    else{
        rear++;
        q[rear] = data;
    }
}

struct node* deq(void)
{
    struct node *res;
    if(front != 0 && rear != 0)
    {
        res = &q[front];
        front++;
    }
    else if(front == rear && front != 0)
    {
        res = &q[front];
        front = 0;
        rear = 0;
    } else{
        res->x = -99;
        res->y = -99;
    }

    return res;
}

int qemp(void)
{
    if(front == 0 && rear == 0)
        return 0;
    else
        return 1;
}

int valid(struct node t)
{
    if(t.x >= 0 && t.x < 8 && t.y >= 0 && t.y < 8)
        return 1;
    else
        return 0;
}

int check(struct node *t, int g[8][8])
{
    if(g[t->x][t->y] == 1)
        return 0;
    else
        return 1;
}
int bfs(struct node s, struct node d)
{

    int g[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            g[i][j] = 0;

    s.dist = 0;
    enq(s);
    //struct node *t = deq();
    //printf("%d\n",t->visit);
    while(qemp())
    {
        struct node *sou = deq();
        int r = sou->dist;
        printf("%d %d %d \n",sou->x,sou->y,sou->dist);
        if(sou->x == d.x && sou->y == d.y)
            return sou->dist;

        if(check(sou,g) == 1)
        {

            g[sou->x][sou->y] = 1;
            struct node dummy;
            for(int i=0;i<8;i++)
            {
                dummy.x = sou->x + row[i];
                dummy.y = sou->y + col[i];
                if(valid(dummy) == 1)
                {
                    dummy.dist = r+1;
                    enq(dummy);
                }
            }
        }
    }

    return 0;
}

int main()
{
    struct node s,d;
    s.x = 0;
    s.y = 0;
    d.x = 0;
    d.y = 2;
    int path = bfs(s,d);
    //printf("%d",path);

    printf("\n\n\nShortest path : %d ",path);
}
