#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,t[500005],p[500005],kand=2000001,a[1000005],b,e,roznica,f;
pair<int,int> d[1000005];
pair<int,int> c[1000005];
pair<pair<int,int>,int> q[1000005];
int main()
{
scanf("%d",&n);
for(int i=0;i<n-2;i++)
    {
    scanf("%d",&t[i]);
    }
for(int i=0;i<n-2;i++)
    {
    scanf("%d",&p[i]);
    c[i]=make_pair(t[i],p[i]);
    e=roznica;
    roznica=abs(t[i]-p[i]);
    if(e!=roznica)f++;
    if(kand>t[i]+p[i])
        {
        kand=t[i]+p[i];
        b=0;
        a[b]=i;
        d[b]=c[i];
        q[b]=make_pair(d[b],a[b]);
        }
       else if(kand==t[i]+p[i])
            {
            b++;
            d[b]=c[i];
            a[b]=i;
            q[b]=make_pair(d[b],a[b]);
            }
    }
    if(f==1)b=-1;
    else
    {
    sort(q,q+b+1);
    for(int i=0;i<n-2;i++)
        {
        if(t[i]+p[i]>kand)
            {
            for(int j=0;j<=b;j++)
                {
                if(t[i]-p[i]==q[j].first.first-q[j].first.second||abs(t[i]-p[i])==kand)break;
                else if(j==b)
                    {
                    printf("%s","NIE");
                    return 0;
                    }
                }
            }
        }
    }
if(n<2)
    {
    printf("%s","NIE");
    return 0;
    }
if(n==2)
    {
    printf("%s\n","TAK");
    printf("%d %d %d",1,2,2);
    return 0;
    }
for(int i=0;i<=b;i++)
    {
    if(q[i].first.first==q[i+1].first.first)
        {
        printf("%s","NIE");
        return 0;
        }
    }
printf("%s\n","TAK");
for(int i=0;i<=b;i++)
    {
    if(i==0)
        {
        printf("%d %d %d \n",1,q[i].second+2,q[i].first.first);
        }
        if(i!=0)
        {
        printf("%d %d %d \n",q[i-1].second+2,q[i].second+2,q[i].first.first-q[i-1].first.first);
        }
    if(i==b)
        {
        printf("%d %d %d \n",q[i].second+2,n,q[i].first.second);
        }
    }
if(b==-1)
    {
    printf("%d %d %d \n",1,n,roznica);
    }
for(int i=0;i<n-2;i++)
    {
    if(t[i]+p[i]>kand||b==-1)
        {
        if(abs(t[i]-p[i])==kand)
            {
            if(p[i]>t[i])
                {
                printf("%d %d %d \n",1,i+2,t[i]);
                }
            else printf("%d %d %d \n",n,i+2,p[i]);
            }
        else if(b==-1)
            {
            if(p[i]>t[i])
                {
                printf("%d %d %d \n",1,i+2,t[i]);
                }
            else printf("%d %d %d \n",i+2,n,p[i]);
            }
        else
            {
            for(int j=0;j<=b;j++)
                {
                if((t[i]-p[i])==(q[j].first.first-q[j].first.second))
                    {
                    printf("%d %d %d \n",q[j].second+2,i+2,t[i]-q[j].first.first);
                    break;
                    }
                }
            }
        }
    }
}
