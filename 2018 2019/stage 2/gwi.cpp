#include<bits/stdc++.h>
using namespace std;
long long t[1000005],p[1000005],suma,maksik;
int n,poz,poczatek,lewy,prawy,domysl,koniec,lewo[1000005],prawo[1000005],kier[1000005],sym,ind,akt,akt2,po[1000005];
void wywal()
{
cout<<poz<<' ';
if(poz==poczatek)poczatek=prawo[poz];
if(poz==koniec)koniec=lewo[poz];
lewy=lewo[poz];
prawy=prawo[poz];
prawo[lewy]=prawy;
lewo[prawy]=lewy;
}
void wlewoojeden()
{
poz=lewo[poz];
}
void wprawoojeden()
{
poz=prawo[poz];
}
void wlewoodkonca(int x)
{
domysl=koniec;
for(int j=1;j<=x;j++)
    {
    domysl=lewo[domysl];
    }
if(domysl<poz)
    {
    poz=domysl;
    }
else wlewoojeden();
}
void wprawoodpoczatku(int x)
{
domysl=poczatek;
for(int j=1;j<=x;j++)
    {
    domysl=prawo[domysl];
    }
if(domysl>poz)
    {
    poz=domysl;
    }
else wprawoojeden();
}
int main()
{
ios_base::sync_with_stdio(0);
cin>>n>>poz;
//W sumie to excel tez wydaje sie byc spoko
poczatek=1;
koniec=n;
for(int i=1;i<=n;i++)
    {
    lewo[i]=i-1;
    prawo[i]=i+1;
    }
for(int i=1;i<n;i++)
    {
    cin>>t[i]>>p[i];
    if(t[i]<=p[i])kier[i]=1;
    else kier[i]=0;
    }
sym=poz;
for(int i=1;i<n;i++)
    {
    if(kier[i]==1)sym--;
    else sym++;
    if(sym<=0||sym>n)
        {
        maksik=INT_MAX;
        for(int j=1;j<=i;j++)
            {
            if(maksik>abs(t[j]-p[j]))
                {
                ind=j;
                maksik=abs(t[j]-p[j]);
                }
            }
        kier[ind]=1-kier[ind];
        break;
        }
    if(i==n-1)break;
    if(kier[i+1]!=kier[i])break;
    }
akt=0;
akt2=0;
for(int i=n-1;i>=1;i--)
    {
    if(kier[i]==1)
        {
        akt++;
        suma+=t[i];
        po[i]=akt2;
        akt2=0;
        }
    else
        {
        suma+=p[i];
        po[i]=akt;
        akt=0;
        akt2++;
        }
    }
cout<<suma<<'\n';
for(int i=1;i<n;i++)
    {
    wywal();
    if(kier[i]==1)
        {
        if(i==n-1)
            {
            wlewoojeden();
            break;
            }
        else if(kier[i+1]==0)
            {
            wlewoodkonca(po[i]);
            }
        else wlewoojeden();
        }
    if(kier[i]==0)
        {
        if(i==n-1)
            {
            wprawoojeden();
            break;
            }
        else if(kier[i+1]==1)
            {
            wprawoodpoczatku(po[i]);
            }
        else wprawoojeden();
        }
    }
wywal();
}
