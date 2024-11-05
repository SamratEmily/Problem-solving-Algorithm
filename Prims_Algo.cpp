#include<bits/stdc++.h>
using namespace std;
#define v 5
void printmst(int parent[],int Graph[v][v])
{
    printf("Edge         Weight\n");
    for(int i=1; i<v; i++)
    {
        printf("%d-----%d = %d\n",parent[i],i,Graph[parent[i]][i]);
    }
}
int minval(bool mstset[],int val[])
{
    int minindx,min=INT_MAX;
    for(int i=0; i<v; i++)
    {
        if(mstset[i]==false && val[i]<min)
        {
            min=val[i];
            minindx=i;
        }
    }
    return minindx;
}

void Prims(int Graph[v][v])
{
    int parent[v],val[v];
    bool mstset[v];
    int i;
    for(i=0; i<v; i++)
    {
        val[i]=INT_MAX;
        mstset[i]=false;
    }
    parent[0]=-1;
    val[0]=0;
    for(int c=0; c<v-1; c++)
    {
        int u=minval(mstset,val);
        mstset[u]=true;
        for(i=0; i<v; i++)
        {
            if(Graph[u][i] && mstset[i]==false && Graph[u][i]<val[i])
            {
                val[i]=Graph[u][v];
                parent[i]=u;
            }
        }
    }
    printmst(parent,Graph);

}

int main()
{
    int Graph[v][v]= {{0,2,0,6,0},
                    {2,0,3,8,5},
                    {0,3,0,0,7},
                    {6,8,0,0,9},
                    {0,5,7,9,0}
    };

    Prims(Graph);

    return 0;
}

