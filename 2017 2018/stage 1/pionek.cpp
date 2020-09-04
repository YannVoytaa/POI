#include <iostream>
#include <cstdio>
#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define PI 3,14159265
long long p,haha,j,nadpisz0,xd0,k,nadpisz1,nadpisz2,nadpisz3,o,lol1,lol2,lol3,xd1,xd2,xd3,lol0,zero,pion0,pion1,pion2,pion3,poziom0,poziom1,poziom2,poziom3,xd,a,b1,z=1,d=1,e,b2,b3,b4,a1,a2,a3,a4,n,c,pion,poziom,wynik2,wynik3,x[200005],y[200005];
long double wynik[200005];
pair<long double,pair<long long,long long> > para[200005];
pair<long long,long long> parka[200005];
int main()
{
cin>>n;
for(int i=0;i<n;i++)
    {
    cin>>x[i]>>y[i];
    if(x[i]==0&&y[i]==0)
        {
        n--;
        i--;
        continue;
        }
    wynik[i]=atan2(y[i],x[i])*10000000/PI;
    parka[i]=make_pair(x[i],y[i]);
    para[i]=make_pair(wynik[i],parka[i]);
    }
sort(para,para+n);
for(int i=0;i<n;i++)
    {
    while(j<n)
        {
        if(o==n)o=0;
        if(((para[o].second.first+pion)*(para[o].second.first+pion)+(para[o].second.second+poziom)*(para[o].second.second+poziom)-pion*pion-poziom*poziom)>0)
            {
            pion+=para[o].second.first;
            poziom+=para[o].second.second;
            j++;
            o++;
            }
        else break;
        }

    if(j==n+1&&j!=1)
        {
        pion-=para[i].second.first;
        poziom-=para[i].second.second;
        }
    if(pion*pion+poziom*poziom-wynik2*wynik2-wynik3*wynik3>0)
        {
        wynik2=pion;
        wynik3=poziom;
        }
    if(j!=n+1||j==1)
        {
        pion-=para[i].second.first;
        poziom-=para[i].second.second;
        }
    j--;
    }
printf("%lld",wynik3*wynik3+wynik2*wynik2);
}
