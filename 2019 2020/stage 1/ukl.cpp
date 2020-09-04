#include<bits/stdc++.h>
using namespace std;
char k;
void fast(long long &liczba)
{
liczba=0;
//k=getchar_unlocked();
k=getchar();
do{
    liczba=(liczba<<3)+(liczba<<1)+((int)(k))-48;
    k=getchar();
    //k=getchar_unlocked();
}while(k>33);
}
void fastint(int &liczba)
{
liczba=0;
//k=getchar_unlocked();
 k=getchar();
do{
    liczba=(liczba<<3)+(liczba<<1)+((int)(k))-48;
     k=getchar();
//    k=getchar_unlocked();
}while(k>33);
}
int zapy,rzad,poz,n,m,kk,wynik,sw,t[1005][1005][2],nowy[1005][1005][2];
int main()
{
ios_base::sync_with_stdio(0);
cin>>n>>m>>kk;
if(m%2==0&&n%2==1)
    {
    swap(n,m);
    sw=1;
    }
if(n==2&&kk%2==0)
    {
    swap(n,m);
    sw=1-sw;
    }
if(kk<m/2-1+m/2+n||kk>m*n-1)
    {
    cout<<"NIE";
    return 0;
    }
for(int i=1;i<=n;i++)
    {
    for(int j=1;j<m;j++)
        {
        t[i][j][1]=1;
        }
    if(i!=n)t[i][m/2+1][0]=1;
    }
wynik=m/2-1+m/2+n;
rzad=1;
poz=m/2+1;
while(kk-wynik>1)
    {
    if(rzad%2==1)
        {
        poz++;
        if(poz>m)
            {
            poz=m/2+1;
            rzad++;
            }
        else
            {
            t[rzad][poz-1][0]=0;
            t[rzad][poz][0]=1;
            wynik+=2;
            }
        }
    else
        {
        poz--;
        if(poz<1)
            {
            poz=m/2+1;
            rzad++;
            }
        else
            {
            t[rzad][poz+1][0]=0;
            t[rzad][poz][0]=1;
            wynik+=2;
            }
        }
    }
if(poz==1||poz==m)
    {
    poz=m/2+1;
    rzad++;
    }
if(kk-wynik==1)
    {
    if(n%2==1)
        {
        if(t[n-2][m][0]==1)
            {
            t[n-2][m][0]=0;
            t[n-2][m-1][0]=1;
            t[rzad][poz][0]=0;
            t[rzad][poz-1][0]=1;
            }
        t[n-1][m-1][1]=0;
        t[n-1][m][0]=1;
        }
    if(n%2==0)
        {
        if(t[n-2][1][0]==1)
            {
            t[n-2][1][0]=0;
            t[n-2][2][0]=1;
            t[rzad][poz][0]=0;
            t[rzad][poz+1][0]=1;
            }
        t[n-1][1][1]=0;
        t[n-1][1][0]=1;
        }
    //t[1][1][1]=0;
    //t[1][1][0]=1;
    }
if(sw){///////////////////////
for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=m;j++)
        {
        nowy[j][n-i+1][0]=t[i][j][0];
        nowy[j][n-i+1][1]=t[i][j][1];
        }
    }
swap(n,m);
}
cout<<"TAK"<<'\n';
for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=m;j++)
        {
        if(sw==0)
            {
            if(t[i][j][0])cout<<i<<' '<<j<<' '<<i+1<<' '<<j<<'\n';
            if(t[i][j][1])cout<<i<<' '<<j<<' '<<i<<' '<<j+1<<'\n';
            }
        if(sw==1)
            {
            if(nowy[i][j][0])cout<<i<<' '<<j<<' '<<i<<' '<<j-1<<'\n';
            if(nowy[i][j][1])cout<<i<<' '<<j<<' '<<i+1<<' '<<j<<'\n';
            }
        }
    }
}
