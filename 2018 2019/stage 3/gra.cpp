#include<bits/stdc++.h>
#include "gralib.hpp"
using namespace std;
int n,a,mm,b,k,dp[260005],zlicz[260005],poz,akt,wynik;
vector<int>wzial[260005];
map<int,bool>m[260005];
void przygotuj()
{
for(int i=0;i<=n;i++)
    {
    wzial[i].clear();
    dp[i]=0;
    zlicz[i]=0;
    }
for(int i=1;i<=k;i++){dp[i]=1;wzial[i].push_back(0);}
for(int i=1;i<=n;i++)
    {
    m[i].clear();
    for(int j=1;j<=min((int)sqrt(i),k);j++)
        {
        if(i%j==0)
            {
            if(dp[i+j]==0||dp[i+j]>dp[i]+1)
                {
                dp[i+j]=dp[i]+1;
                wzial[i+j].clear();
                wzial[i+j].push_back(i);
                }
            else if(dp[i+j]==dp[i]+1)
                {
                wzial[i+j].push_back(i);
                }
            }
        }
    }
/*for(int i=1;i<=n;i++)
    {
    cout<<i<<' '<<dp[i]<<' ';
    for(int j=0;j<wzial[i].size();j++)
        {
        cout<<wzial[i][j]<<' ';
        }
    cout<<'\n';
    }*/
zlicz[n]=1;
for(int i=n;i>=0;i--)
    {
    if(zlicz[i]==1)
        {
        for(int j=0;j<wzial[i].size();j++)
            {
            zlicz[wzial[i][j]]=1;
            m[wzial[i][j]][i-wzial[i][j]]=1;
            }
        }
    }
}
/*int dajN()
{
return 50000;
}
int dajK()
{
return 3;
}
int dajM()
{
return 100;
}
int nastepna()
{
return rand()%k+1;
}
void zwieksz(){cout<<akt<<'\n';}
void koniec(){cout<<wynik<<'\n';}*/
void zagraj()
{
n=dajN();
k=dajK();
mm=dajM();
poz=0;
wynik=0;
//przygotuj();
while(poz!=n)
    {
    akt=nastepna();
    wynik++;
    if(poz%akt==0&&poz+akt<=n)
        {
        zwieksz();
        poz+=akt;
        }
    }
koniec();
}
int main()
{
for(int i=1;i<=100;i++)zagraj();
}
