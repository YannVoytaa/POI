#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,spec[255],b,minik,minikkonc,wynik,odl[255],odw[255],zlicz[255],unikalny,xd;
queue<int>q;
vector<int>g[255],odwr[255],vek;
bitset<255>bit[255],bitbasic[255],nowybit,bitzero,bits;
int main()
{
ios_base::sync_with_stdio(0);
cin>>n>>m>>k;
for(int i=1;i<=k;i++)
    {
    cin>>a;
    spec[a]++;
    if(zlicz[a]==0)unikalny++;
    zlicz[a]=1;
    vek.push_back(a);
    }
if(unikalny==1){cout<<"TAK"<<'\n'<<0;return 0;}
for(int i=1;i<=m;i++)
    {
    cin>>a>>b;
    g[a].push_back(b);
    odwr[b].push_back(a);
    if(a==b)xd++;
    bitbasic[a][b]=1;
    bit[a][b]=1;
    }
if(xd==n)
    {
    minikkonc=INT_MAX;
    for(int i=1;i<=n;i++)
        {
        wynik=0;
        minik=-INT_MAX;
        for(int j=1;j<=n;j++)
            {
            odl[j]=0;
            odw[j]=0;
            }
        q.push(i);
        while(!q.empty())
            {
            a=q.front();
            q.pop();
            odw[a]=1;
            if(spec[a])
                {
                wynik+=spec[a];
                minik=max(minik,odl[a]);
                }
            for(int j=0;j<odwr[a].size();j++)
                {
                if(odw[odwr[a][j]]==0)
                    {
                    odl[odwr[a][j]]=odl[a]+1;
                    q.push(odwr[a][j]);
                    odw[odwr[a][j]]=1;
                    }
                }
            }
        if(wynik==k)minikkonc=min(minikkonc,minik);
        }
    if(minikkonc==INT_MAX)cout<<"NIE";
    else cout<<"TAK"<<'\n'<<minikkonc;
    }
else
    {
    minikkonc=INT_MAX;
    for(int i=1;i<=n;i++)
        {
        bits=bit[vek[0]];
        for(int j=1;j<vek.size();j++)
            {
            bits=bits&bit[vek[j]];
            }
        if(bits.count()!=0)
            {
            minikkonc=i;
            break;
            }
        for(int j=0;j<vek.size();j++)
            {
            nowybit=bitzero;
            for(int k=1;k<=n;k++)
                {
                if(bit[vek[j]][k]==1)
                    {
                    nowybit=nowybit|bitbasic[k];
                    }
                }
            bit[vek[j]]=nowybit;
            }
        }
if(minikkonc==INT_MAX)cout<<"NIE";
else cout<<"TAK"<<'\n'<<minikkonc;
    }
}
