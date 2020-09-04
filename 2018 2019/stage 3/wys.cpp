#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,sr,baza=1024*512,t[300005];
long long b,a,drzewo[1200005],wartosc,doprzebicia,maks[1200005],zrzuc[1200005],war2;
char k;
long long szukaj(int x)
{
wartosc=0;
x+=baza;
while(x)
    {
    wartosc+=drzewo[x];
    x/=2;
    }
return wartosc;
}
void znajdz(long long x)
{
l=0;r=n-1;
while(l<r)
    {
    sr=(l+r)/2;
    if(szukaj(sr)>x)r=sr;
    else l=sr+1;
    }
}
void znajdz2(long long x)
{
l=0;r=n-1;
while(l<r)
    {
    sr=(l+r)/2;
    if(szukaj(sr)>=x)r=sr;
    else l=sr+1;
    }
}
void dodaj(int a,int b,long long war,int lo,int hi,int v)
{
if(hi<a||lo>b)return;
else if(lo>=a&&hi<=b)
    {
    drzewo[v]+=war;
    maks[v]+=war2;
    zrzuc[v]+=war2;
    }
else
    {
    maks[2*v]+=zrzuc[v];
    maks[2*v+1]+=zrzuc[v];
    zrzuc[2*v]+=zrzuc[v];
    zrzuc[2*v+1]+=zrzuc[v];
    zrzuc[v]=0;
    dodaj(a,b,war,lo,(lo+hi)/2,2*v);
    dodaj(a,b,war,(lo+hi)/2+1,hi,2*v+1);
    maks[v]=max(maks[2*v],maks[2*v+1]);
    }
}
int main()
{
ios_base::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<n;i++)
    {
    cin>>t[i];
    }
sort(t,t+n);
for(int i=n-1;i>=0;i--)
    {
    war2=t[i]+n-i;
    dodaj(i+baza,i+baza,t[i],baza,2*baza-1,1);
    }
for(int i=n;i<=baza-1;i++)
    {
    war2=-LLONG_MAX;
    dodaj(i+baza,i+baza,war2,baza,2*baza-1,1);
    }
for(int i=1;i<=m;i++)
    {
    cin>>k;
    if(k=='K')
        {
        cin>>a>>b;
        znajdz(a);
        if(szukaj(l)>a)l--;
        war2=-b;
        if(l<0)continue;
        else dodaj(baza,l+baza,-b,baza,2*baza-1,1);
        }
    else if(k=='B')
        {
        cin>>a>>b;
        znajdz2(a);
        if(szukaj(l)<a)l++;
        war2=b;
        if(l>=n)continue;
        else dodaj(l+baza,n-1+baza,b,baza,2*baza-1,1);
        }
    else
        {
        doprzebicia=maks[1];
        znajdz2(doprzebicia-n);
        cout<<n-l<<'\n';
        }
    }
}
