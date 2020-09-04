#include<iostream>
#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;
int n,m,t[1000005],p[1000005],wynik,j,pierwszy,zapy;
int wynikkonc;
int main()
{
ios_base::sync_with_stdio(0);
cin>>zapy;
while(zapy--)
{
cin>>n>>m;
wynik=0;
for(int i=1;i<=n;i++)
    {
    if(n>m)
        {
        cin>>t[i];
        t[i]=t[i]%2;
        }
    else
        {
        cin>>p[i];
        p[i]=p[i]%2;
        wynik+=p[i];
        }
    }
for(int i=1;i<=m;i++)
    {
    if(n<=m)
        {
        cin>>t[i];
        t[i]=t[i]%2;
        }
    else
        {
        cin>>p[i];
        p[i]=p[i]%2;
        wynik+=p[i];
        wynik=wynik%2;
        }
    }
if(n<m)swap(n,m);
for(int i=1;i<=m;i++)
    {
    wynik-=t[i];if(wynik<0)wynik+=2;
    wynik=wynik%2;
    }
j=m+1;
while(wynik!=0&&j<=n)
    {
    wynik+=t[j-m]-t[j];
    if(wynik<0)wynik+=2;
    wynik=wynik%2;
    j++;
    }
if(wynik==0)
    {
    cout<<m<<'\n';
    continue;
    }
wynik=t[1];
j=2;
while(j<=n&&t[j]==wynik)j++;
pierwszy=max(1,j-(n-m));
j=m;
while(j>=1&&t[j]==wynik)j--;
pierwszy=min(pierwszy,m-j+1);
j=1;
while(j<=m&&p[j]==wynik)j++;
pierwszy=min(pierwszy,j);
j=m;
while(j>=1&&p[j]==wynik)j--;
pierwszy=min(pierwszy,m-j+1);
cout<<m-pierwszy<<'\n';
}
}
