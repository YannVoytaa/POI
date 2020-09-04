#include<bits/stdc++.h>
using namespace std;
int z,m,n,t[1000005],odwiedzone[1000005],wynik,a,b;
vector<int>g[100005];
void dfsbrut(int w)
    {
    odwiedzone[w]=1;
    for(int j=0;j<g[w].size();j++)
        {
        if(odwiedzone[g[w][j]]==0)
            {
            wynik++;
            dfsbrut(g[w][j]);
            }
        }
    }
void dfsbezcykli(int v)
    {
    odwiedzone[v]=1;
    t[v]-=wynik;
    for(int j=0;j<g[v].size();j++)
        {
        if(odwiedzone[g[v][j]]==0)
            {
            wynik++;
            dfsbezcykli(g[v][j]);
            }
       else wynik+=t[g[v][j]]+1;
        }
    t[v]+=wynik;
    }
int main()
{
scanf("%d %d",&n,&m);
for(int i=1;i<=m;i++)
    {
    scanf("%d %d",&a,&b);
    g[a].push_back(b);
    }
if(n<=10000&&m<=10000)
    {
    for(int i=1;i<=n;i++)
        {
        wynik=0;
        dfsbrut(i);
        printf("%d\n",wynik);
        for(int j=1;j<=n;j++)
            {
            odwiedzone[j]=0;
            }
        }
    }
else
    {
    for(int i=1;i<=n;i++)
        {
        if(odwiedzone[i]==0)
            {
            dfsbezcykli(i);
            printf("%d\n",t[i]);
            }
        else printf("%d\n",t[i]);
        }
    }
}
