#include<bits/stdc++.h>
using namespace std;

struct edge
{
    char source,dest;
    int weight;

};
int parent[101];
int findparent(int v)
{
    if(parent[v]==v) return v;
    else return findparent(parent[v]);
}
bool cmp(edge a,edge b)
{
    return a.weight<b.weight;
}
void kruskals(edge a[],int n,int e)
{
    edge mst[n-1];
    sort(a,a+e,cmp);
    for(int i=0; i<n; i++) parent[i]=i;
    int count=0,i=0;
    while(count!=n-1)
    {
        edge ce=a[i];
        char sp=findparent(ce.source);
        char dp=findparent(ce.dest);
        if(sp!=dp)
        {
            mst[count]=ce;
            count++;
            parent[dp]=sp;
        }
        i++;
    }

    for(i=0; i<n-1; i++)
    {
        cout<<mst[i].source<<" "<<mst[i].dest<<" "<<mst[i].weight;
        cout<<endl;
    }

}

int main()
{

    int i,n,E,s,d,w;
    cin>>n>>E;
    edge a[E];
    char s , d;
    for(i=0; i<E; i++)
    {
        cin>>s>>d>>w;
        a[i].source=s;
        a[i].dest=d;
        a[i].weight=w;
    }
    kruskals(a,n,E);

    return 0;
}
