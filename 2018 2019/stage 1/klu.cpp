#include<iostream>
#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;
int n,m,t[2000005],pocz,temppocz,tempkon,tempkoniec,tempi,spelnia,x,koniec[2000005],j,pierwszy,zapy,a,c,ogol[33][2],wynik[33][2];
bool wyn[33][2000005];
long long wynikkonc;
int main()
{
ios_base::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<m;i++)
    {
    cin>>t[i];
    a=t[i];
    c=0;
    while(a)
        {
        wyn[c++][i]=a%2;a/=2;
        }
    for(int j=0;j<n;j++)
        {
        if(wyn[j][i]==0)ogol[j][0]=1;
        else ogol[j][1]=1;
        }
    }
for(int i=0;i<n;i++)
    {
    if(ogol[i][0]==1)spelnia++;
    if(ogol[i][1]==1)spelnia++;
    }
x=0;
for(int i=0;i<m;i++)
    {
    for(int j=0;j<n;j++)
        {
        wynik[j][wyn[j][i]]++;if(wynik[j][wyn[j][i]]==1)spelnia--;
        }
    while(spelnia==0)
        {
        koniec[x]=i;
        //cout<<x<<' '<<koniec[x]<<'\n';
        for(int j=0;j<n;j++)
            {
            wynik[j][wyn[j][x]]--;if(wynik[j][wyn[j][x]]==0)spelnia++;
            }
        x++;
        if(x==m)break;
        }
    if(x==m)break;
    if(i==m-1)i=-1;
    }
pocz=koniec[0]+1;
for(int i=0;i<m;i++)
    {
    if((i<=koniec[i]&&pocz>=i&&pocz<=koniec[i])||(i>=koniec[i]&&((pocz>=i||pocz<=koniec[i]))))
        pocz=koniec[i]+1;
    pocz=pocz%m;
    while(1)
        {
        temppocz=pocz+1;
        temppocz=temppocz%m;
        tempkon=koniec[temppocz];
        tempi=i;
        tempkoniec=koniec[i];
        if((tempi<=tempkoniec&&((temppocz>=tempi&&temppocz<=tempkoniec)||(tempkon>=tempi&&tempkon<=tempkoniec)))||(tempi>tempkoniec&&((temppocz>=tempi||temppocz<=tempkoniec)||(tempkon>=tempi||tempkon<=tempkoniec))))break;
        else
           {
           pocz++;
           pocz=pocz%m;
           }
        }
        //cout<<i<<' '<<koniec[i]<<' '<<pocz<<' '<<koniec[pocz]<<' '<<wynikkonc<<'\n';
        temppocz=pocz;
        temppocz=temppocz%m;
        tempkon=koniec[temppocz];
        tempi=i;
        tempkoniec=koniec[i];
        if((tempi<=tempkoniec&&((temppocz>=tempi&&temppocz<=tempkoniec)||(tempkon>=tempi&&tempkon<=tempkoniec)))||(tempi>tempkoniec&&((temppocz>=tempi||temppocz<=tempkoniec)||(tempkon>=tempi||tempkon<=tempkoniec))))continue;
        else
            {
            if(temppocz>tempkoniec)wynikkonc+=temppocz-tempkoniec;
            else wynikkonc+=temppocz+m-tempkoniec;
            }

    }
cout<<wynikkonc/2;
}
