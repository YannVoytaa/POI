#include<bits/stdc++.h>
using namespace std;
int odw[100005],gleb[100005],par[100005][21],pot,wynik,n,m,qq,a,b,odl[100005],x;
queue<int>q;
vector<int>g[100005];
void dfs(int x)
{
odw[x]=1;
for(int j=0;j<g[x].size();j++)
    {
    if(odw[g[x][j]]==0)
        {
        gleb[g[x][j]]=gleb[x]+1;
        par[g[x][j]][0]=x;
        dfs(g[x][j]);
        }
    }
}
void lca(int x,int y)
{
pot=20;
if(gleb[x]<gleb[y])swap(x,y);
while(pot>=0)
    {
    if(gleb[par[x][pot]]>=gleb[y])
        {
        x=par[x][pot];
        }
    pot--;
    }
pot=20;
while(pot>=0)
    {
    if(par[x][pot]!=par[y][pot])
        {
        x=par[x][pot];
        y=par[y][pot];
        }
    pot--;
    }
if(x!=y)x=par[x][0];
wynik=x;
}
int main()
{
ios_base::sync_with_stdio(0);
cin>>n>>m>>qq;
for(int i=1;i<=m;i++)
    {
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    }
if(m==n-1)
    {
    gleb[1]=1;
    dfs(1);
    for(int j=1;j<=20;j++)
        {
        for(int i=1;i<=n;i++)
            {
            par[i][j]=par[par[i][j-1]][j-1];
            }
        }
    for(int i=1;i<=qq;i++)
        {
        cin>>a>>b;
        lca(a,b);
        cout<<gleb[a]+gleb[b]-2*gleb[wynik]<<'\n';
        }
    }
else if(qq<=5000)
    {
    for(int i=1;i<=qq;i++)
        {
        cin>>a>>b;
        for(int j=1;j<=n;j++)
            {
            odl[j]=0;
            odw[j]=0;
            }
        q.push(a);
        while(!q.empty())
            {
            x=q.front();
            q.pop();
            odw[x]=1;
            for(int j=0;j<g[x].size();j++)
                {
                if(odw[g[x][j]]==0)
                    {
                    odw[g[x][j]]=1;
                    q.push(g[x][j]);
                    odl[g[x][j]]=odl[x]+1;
                    }
                }
            }
        cout<<odl[b]<<'\n';
        }
    }
else
    {
    for(int i=1;i<=qq;i++)
        {
        cin>>a>>b;
        if(a>b)swap(a,b);
        wynik=(b-a)/5;
        a+=wynik*5;
        if(b-a<1+(a+5-b))wynik+=b-a;
        else wynik+=a+6-b;
        cout<<wynik<<'\n';
        }
    }
}
