#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n,m,aa,b,odw[500005],maks,wierz,wierz2,odl[500005],par[500005],najgorszygosc,najgorszywynik,ruchy,korzen,baza=1024*1024,czas,pre[500005],post[500005],nie;
vector<int>g[500005];
long long zrzuc[2400005],najg;
pair<long long,int>maksik[2400005];
queue<int>q,wynikowy;
void dodaj(int a,int b,int war,int lo,int hi,int v)
{
if(a>hi||b<lo)return;
else if(a<=lo&&b>=hi)
    {
    if(nie)odl[aa]=maksik[v].f;
    maksik[v].f+=war;
    zrzuc[v]+=war;
    if(a==b)maksik[v].s=aa;
    }
else
    {
    maksik[2*v].f+=zrzuc[v];
    maksik[2*v+1].f+=zrzuc[v];
    zrzuc[2*v]+=zrzuc[v];
    zrzuc[2*v+1]+=zrzuc[v];
    zrzuc[v]=0;
    dodaj(a,b,war,lo,(lo+hi)/2,2*v);
    dodaj(a,b,war,(lo+hi)/2+1,hi,2*v+1);
    //maksik[v]=max(maksik[2*v],maksik[2*v+1]);
    if(maksik[2*v].f>=maksik[2*v+1].f)
        {
        maksik[v].f=maksik[2*v].f;
        maksik[v].s=maksik[2*v].s;
        }
    else
        {
        maksik[v].f=maksik[2*v+1].f;
        maksik[v].s=maksik[2*v+1].s;
        }
    }
}
void dfs(int x)
{
odw[x]=1;
for(int j=0;j<g[x].size();j++)
    {
    if(odw[g[x][j]]==0)
        {
        odl[g[x][j]]=odl[x]+1;
        if(odl[g[x][j]]>maks)
            {
            maks=odl[g[x][j]];
            wierz=g[x][j];
            }
        dfs(g[x][j]);
        }
    }
}
void dfs2(int x)
{
odw[x]=1;
pre[x]=++czas;
for(int j=0;j<g[x].size();j++)
    {
    if(odw[g[x][j]]==0)
        {
        par[g[x][j]]=x;
        odl[g[x][j]]=odl[x]+1;
        if(odl[g[x][j]]>maks)
            {
            maks=odl[g[x][j]];
            wierz2=g[x][j];
            }
        dfs2(g[x][j]);
        }
    }
post[x]=++czas;
}
void bfs()
{
while(!q.empty())
    {
    aa=q.front();
    q.pop();
    odw[aa]=1;
    dodaj(pre[aa]+baza,pre[aa]+baza,odl[aa],baza,2*baza-1,1);
    dodaj(post[aa]+baza,post[aa]+baza,odl[aa],baza,2*baza-1,1);
    for(int j=0;j<g[aa].size();j++)
        {
        if(odw[g[aa][j]]==0)
            {
            odl[g[aa][j]]=odl[aa]+1;
            q.push(g[aa][j]);
            }
        }
    }
}
void sprawdz()
{
/*najg=0;
najgorszygosc=0;
for(int j=1;j<=n;j++)
    {
    if(odl[j]>najg)
        {
        najg=odl[j];
        najgorszygosc=j;
        }
    }*/
najg=maksik[1].f;
najgorszygosc=maksik[1].s;
}
void myk(int x)
{
for(int j=0;j<g[x].size();j++)
    {
    if(g[x][j]!=par[x]&&odl[g[x][j]]>0)
        {
        odl[g[x][j]]=odl[x]+1;
        myk(g[x][j]);
        }
    }
}
int main()
{
ios_base::sync_with_stdio(0);
cin>>n>>m;
for(int i=1;i<n;i++)
    {
    cin>>aa>>b;
    g[aa].push_back(b);
    g[b].push_back(aa);
    }
dfs(1);
maks=0;
for(int i=1;i<=n;i++)
    {
    odw[i]=0;
    odl[i]=0;
    }
dfs2(wierz);
korzen=wierz;
wynikowy.push(wierz);
wynikowy.push(wierz2);
for(int i=1;i<=n;i++)
    {
    odw[i]=0;
    odl[i]=0;
    }
par[wierz]=0;
while(wierz!=0)
    {
    odw[wierz]=1;
    q.push(wierz);
    wierz=par[wierz];
    }
while(wierz2!=korzen)
    {
    if(odw[wierz2]==0)q.push(wierz2);
    odw[wierz2]=1;
    wierz2=par[wierz2];
    }
bfs();
sprawdz();
ruchy=2;
if(najg<0)najg=0;
najgorszywynik=najg;
for(int i=3;i<=m;i++)
    {
    wynikowy.push(najgorszygosc);
    while(odl[najgorszygosc]!=0)
        {
        aa=najgorszygosc;
        nie=1;
        dodaj(pre[aa]+baza,pre[aa]+baza,0,baza,2*baza-1,1);
        nie=0;
        dodaj(pre[aa]+baza,pre[aa]+baza,-odl[aa],baza,2*baza-1,1);
        dodaj(post[aa]+baza,post[aa]+baza,-odl[aa],baza,2*baza-1,1);
        for(int j=0;j<g[najgorszygosc].size();j++)
            {
            if(par[najgorszygosc]!=g[najgorszygosc][j]&&odl[g[najgorszygosc][j]]!=0)
                {
                dodaj(pre[g[najgorszygosc][j]]+baza,post[g[najgorszygosc][j]]+baza,-odl[najgorszygosc],baza,2*baza-1,1);
                }
            }
        odl[najgorszygosc]=0;
        //myk(najgorszygosc);
        najgorszygosc=par[najgorszygosc];
        }
    sprawdz();
    if(najg<0)najg=0;
    if(najg<najgorszywynik)
       {
       ruchy=i;
       najgorszywynik=najg;
       }
    }
cout<<najgorszywynik<<' '<<ruchy<<'\n';
while(ruchy--)
    {
    cout<<wynikowy.front()<<' ';wynikowy.pop();
    }
}
