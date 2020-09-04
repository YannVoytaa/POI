#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;
int t[1000005],lol,poz,n,tak,odw[1000005],par[1000005],gleb[1000005],mm,a,b,osiedla,p[1000005];
vector<int>g[1000005],nowy[1000005],odwr[1000005];
map<pair<int,int>,int>m,lewa;
stack<int>st;
void dfs(int x)
{
odw[x]=1;
for(int j=0;j<g[x].size();j++)
    {
    if(odw[g[x][j]]==0)
        {
        m[mp(x,g[x][j])]++;
        nowy[x].push_back(g[x][j]);
        lewa[mp(x,g[x][j])]++;
        odwr[g[x][j]].push_back(x);
        par[g[x][j]]=x;
        gleb[g[x][j]]=gleb[x]+1;
        dfs(g[x][j]);
        }
    }
}
void dfs2(int x)
{
odw[x]=1;
for(int j=0;j<nowy[x].size();j++)
    {
    if(odw[nowy[x][j]]==0)
        {
        dfs2(nowy[x][j]);
        }
    }
st.push(x);
}
void dfs3(int x)
{
odw[x]=1;
for(int j=0;j<odwr[x].size();j++)
    {
    if(odw[odwr[x][j]]==0)
        {
        dfs3(odwr[x][j]);
        }
    }
}
void dorzuc(int x,int y)
{
if(gleb[x]>gleb[y])
    {
    nowy[x].push_back(y);
    lewa[mp(x,y)]++;
    odwr[y].push_back(x);
    }
else
    {
    nowy[y].push_back(x);
    lewa[mp(y,x)]++;
    odwr[x].push_back(y);
    }
}
int main()
{
ios_base::sync_with_stdio(0);
cin>>n>>mm;
for(int i=1;i<=mm;i++)
    {
    cin>>a>>b;
    t[i]=a;
    p[i]=b;
    g[a].push_back(b);
    g[b].push_back(a);
    }
for(int i=1;i<=n;i++)
    {
    if(odw[i]==0)dfs(i);
    }
for(int i=1;i<=mm;i++)
    {
    if(m[mp(t[i],p[i])]+m[mp(p[i],t[i])]==0)dorzuc(t[i],p[i]);
    else m[mp(t[i],p[i])]--;
    }
for(int i=1;i<=n;i++)odw[i]=0;
for(int i=1;i<=n;i++)if(odw[i]==0)dfs2(i);
for(int i=1;i<=n;i++)odw[i]=0;
while(!st.empty())
    {
    a=st.top();st.pop();
    if(odw[a]==0){osiedla++;dfs3(a);}
    }
cout<<osiedla<<'\n';
for(int i=1;i<=mm;i++)
    {
    if(lewa[mp(t[i],p[i])]>0)
        {
        cout<<'>';
        lewa[mp(t[i],p[i])]--;
        }
    else
        {
        cout<<'<';
        }
    }
}
/*
5 10
5 2
1 5
1 3
4 5
2 4
1 5
2 3
4 5
1 2
5 2
*/
