#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
using namespace std;
int odw[100005],ind,gleb[100005],par[100005][18],lol,n,r,a,b,c,kolor[100005],nr[100005],qq;
long long suma[100005][18],koniec,odl1,odl2,maksik,mini,minik[100005][33][17];
pair<long long,bool>odle[100005];
vector<pair<int,int> >g[100005];
priority_queue<pair<long long,int> >q;
vector<int>v[100005];
void dfs(int x)
{
odw[x]=1;
for(int j=0;j<g[x].size();j++)
    {
    if(odw[g[x][j].f]==0)
        {
        gleb[g[x][j].f]=gleb[x]+1;
        par[g[x][j].f][0]=x;
        suma[g[x][j].f][0]=g[x][j].s;
        dfs(g[x][j].f);
        }
    }
}
long long odl(int x,int y)
{
long long wynik=0;
if(gleb[x]<gleb[y])swap(x,y);
lol=16;
while(lol>=0)
    {
    if(gleb[par[x][lol]]>=gleb[y])
        {
        wynik+=suma[x][lol];
        x=par[x][lol];
        }
    lol--;
    }
lol=16;
while(lol>=0)
    {
    if(par[x][lol]!=par[y][lol])
        {
        wynik+=suma[x][lol];
        wynik+=suma[y][lol];
        x=par[x][lol];
        y=par[y][lol];
        }
    lol--;
    }
if(y!=x)
    {
    wynik+=suma[x][0];
    wynik+=suma[y][0];
    x=par[x][0];
    y=par[y][0];
    }
return wynik;
}
long long szukaj(int x,int y,int z)
{
long long wynik=0;
long long mini=1e18;
if(gleb[x]<gleb[y])swap(x,y);
lol=16;
while(lol>=0)
    {
    if(gleb[par[x][lol]]>=gleb[y])
        {
        wynik+=suma[x][lol];
        mini=min(mini,minik[x][z][lol]);
        x=par[x][lol];
        }
    lol--;
    }
lol=16;
while(lol>=0)
    {
    if(par[x][lol]!=par[y][lol])
        {
        wynik+=suma[x][lol];
        wynik+=suma[y][lol];
        mini=min(mini,minik[x][z][lol]);
        mini=min(mini,minik[y][z][lol]);
        x=par[x][lol];
        y=par[y][lol];
        }
    lol--;
    }
if(y!=x)
    {
    wynik+=suma[x][0];
    mini=min(mini,minik[x][z][0]);
    wynik+=suma[y][0];
    mini=min(mini,minik[x][z][0]);
    x=par[x][0];
    y=par[y][0];
    }
if(mini==1e18)mini=0;
return wynik+(2*mini);
}
int main()
{
//:((
ios_base::sync_with_stdio(0);
cin>>n>>r;
for(int i=1;i<=n;i++)
    {
    cin>>a;
    v[a].push_back(i);
    kolor[i]=a;
    }
for(int i=1;i<n;i++)
    {
    cin>>a>>b>>c;
    g[a].push_back(mp(b,c));
    g[b].push_back(mp(a,c));
    }
dfs(1);
for(int i=1;i<=n;i++)odw[i]=0;
for(int i=1;i<=r;i++)
    {
    if(v[i].size()>=sqrt(n))
        {
        ind++;
        nr[i]=ind;
        if(ind>32)continue;
        for(int j=0;j<v[i].size();j++)
            {
            q.push(mp(0,v[i][j]));
            odle[v[i][j]].s=1;
            }
        while(!q.empty())
            {
            a=q.top().s;
            q.pop();
            if(odw[a])continue;
            odw[a]=1;
            for(int j=0;j<g[a].size();j++)
                {
                if(odw[g[a][j].f]==0&&kolor[g[a][j].f]!=i&&(odle[g[a][j].f].f>odle[a].f+g[a][j].s||odle[g[a][j].f].s==0))
                    {
                    odle[g[a][j].f].f=odle[a].f+g[a][j].s;
                    odle[g[a][j].f].s=1;
                    q.push(mp(-odle[g[a][j].f].f,g[a][j].f));
                    }
                }
            }
        for(int j=1;j<=n;j++)
            {
            odw[j]=0;
            minik[j][ind][0]=odle[i].f;
            odle[i].f=0;
            odle[i].s=0;
            }
        }
    }
for(int i=1;i<17;i++)
    {
    for(int j=1;j<=n;j++)
        {
        par[j][i]=par[par[j][i-1]][i-1];
        suma[j][i]=suma[j][i-1]+suma[par[j][i-1]][i-1];
        for(int k=1;k<=ind;k++)
            {
            if(k>32)break;
            minik[j][k][i]=min(minik[j][k][i-1],minik[par[j][i-1]][k][i-1]);
            }
        }
    }
cin>>qq;
while(qq--)
    {
    cin>>a>>b>>c;
    if(v[c].size()==0)cout<<-1<<'\n';
    else if(v[c].size()<sqrt(n)||nr[c]>32)
        {
        maksik=1e18;
        for(int i=0;i<v[c].size();i++)
            {
            odl1=odl(v[c][i],a);
            odl2=odl(v[c][i],b);
            if(maksik>odl1+odl2)maksik=odl1+odl2;
            }
        koniec=maksik;
        cout<<koniec<<'\n';
        }
    else
        {
        koniec=szukaj(a,b,nr[c]);
        cout<<koniec<<'\n';
        }
    }
}
