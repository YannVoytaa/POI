#include<iostream>
#include<utility>
#include<bits/stdc++.h>
#include <queue>
using namespace std;
int zlicza[1000005],x,xd,zliczb[1000005],a[1000005],b[1000005],t[1000005],p[1000005],ja,h,d,f,n,m,e,g,kand=0,inimini,manimo=1000000005,k;
pair<int,int> c[1000005];
pair<pair<int,int>,int> q[1000005];
int main()
{
scanf("%d %d",&n,&k);
x=n-k+1;
for(int i=0;i<n;i++)
    {
    scanf("%d %d",&a[i],&b[i]);
    c[i]=make_pair(a[i],b[i]);
    q[i]=make_pair(c[i],i+1);
    t[i]=a[i];
    p[i]=b[i];
    }
sort(q,q+n);
for(int i=0;i<k;i++)
    {
        if(i==k-1) inimini=q[i].first.first;
    swap(q[i].first.first,q[i].first.second);
    }
sort(q,q+k);
for(int i=0;i<k;i++)
    {
    swap(q[i].first.first,q[i].first.second);
    zlicza[i]=q[i].second;
    }
for(int i=0;i<x;i++)
    {
    if(i>0)
        {
        swap(q[0].first.first,q[k+i-1].first.first);
        swap(q[0].first.second,q[k+i-1].first.second);
        swap(q[0].second,q[k+i-1].second);
        inimini=q[0].first.first;
        for(int j=1;j<k;j++)
            {
            if(q[g].first.second>q[j].first.second)
                {
                swap(q[g].first.first,q[j].first.first);
                swap(q[g].first.second,q[j].first.second);
                swap(q[g].second,q[j].second);
                g++;
                }
            else
                {
                break;
                }
            }
        }
        manimo=q[0].first.second;
    if(manimo-inimini>kand)
            {
            kand=manimo-inimini;
            if(xd==1)
                {
                for(int j=0;j<k;j++)
                    {
                    zlicza[j]=q[j].second;
                    }
                xd=0;
                }
            else
                {
                for(int j=0;j<=g;j++)
                    {
                    zlicza[j]=zlicza[j+1];
                    if(j==g)zlicza[j]=q[g].second;
                    }
                }

            }
        else xd=1;
        g=0;
        }
printf("%d \n",kand);
for(int i=0;i<k;i++)
    {
    printf("%d ",zlicza[i]);
    }
}
