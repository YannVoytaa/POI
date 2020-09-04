#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int zapy,n,t[25],k;
map<pair<int,int>,int>m;
bool fajne(int x,map<pair<int,int>,int> ma)
{
if(x>n)return 1;
else if(x==n)return 0;
if(ma[mp(t[x],t[x+1])]==0)
    {
    ma[mp(t[x],t[x+1])]++;
    return fajne(x+1,ma)|fajne(x+2,ma);
    }
else return 0;
}
int main()
{
ios_base::sync_with_stdio(0);
cin>>zapy;
while(zapy--)
    {
    cin>>n>>k;
    m.clear();
    for(int i=1;i<=n;i++)
        {
        cin>>t[i];
        }
    if(fajne(1,m))cout<<"TAK"<<'\n';
    else cout<<"NIE"<<'\n';
    }
}
