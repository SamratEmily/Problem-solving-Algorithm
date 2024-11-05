#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define pb push_back



bool compare(const pair<pair<ll,ll>,char> &i,const pair<pair<ll,ll>,char> &j)
{
    double x= (double)i.first.first/i.first.second;
    double y= (double)j.first.first/j.first.second;

    return x>y;
}


int main()
{
    ll n;  //number of items
    cin>>n;
    ll w;  cin>>w;

    //vector<pair<ll,ll> >v(n);
    vector<pair<pair<ll,ll>,char> >v(n);

    for(ll i=0;i<n;i++)  cin>>v[i].first.first>>v[i].first.second>>v[i].second;  //profit, weight, item

    sort(v.begin(),v.end(),compare);
    vector<pair<double,char> >Final;

    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(w>=v[i].first.second)  //Total-Weight>=item-weight
        {
            ans+=v[i].first.first,  w-=v[i].first.second;
            Final.pb(make_pair(1.0,v[i].second));
            continue;
        }
        double vw=(double)v[i].first.first/(double)v[i].first.second;
        ans+=(vw*w);
        double g=(double)w/(double)v[i].first.second;
        Final.pb(make_pair(g,v[i].second));
        w=0;
        break;
    }
    cout<<ans<<endl;
    for(ll i=0;i<Final.size();i++)   cout<<Final[i].first<<" "<<Final[i].second<<endl;

}
