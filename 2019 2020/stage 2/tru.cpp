#include<bits/stdc++.h>
using namespace std;
long long n,wynik,ind1,ind2,wyn1,wyn2,wyn3,dz[1000005],indeks1,indeks2,indeks3,pierwsze[1000005],akt,dzielniki,licznik,teraz,last,maxdzielniki,kolejna[1000005],ind,wyniczek;
vector<long long>g,vek;
int nwd(int x,int y)
{
while(x!=0&&y!=0)
    {
    if(x>y)x%=y;
    else y%=x;
    }
return x+y;
}
void rek(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j,int k,int l,long long wynik)
{
dz[wynik]=(a+1)*(b+1)*(c+1)*(d+1)*(e+1)*(f+1)*(g+1)*(h+1)*(i+1)*(j+1)*(k+1)*(l+1);
vek.push_back(wynik);
if(a!=0)
    {
    if(wynik*2<=1e6)
        {
        rek(a+1,b,c,d,e,f,g,h,i,j,k,l,wynik*2);
        }
    return;
    }
if(wynik*2<=n)rek(a+1,b,c,d,e,f,g,h,i,j,k,l,wynik*2);
if(b!=0)
    {
    if(wynik*2<=1e6)
        {
        rek(a+1,b,c,d,e,f,g,h,i,j,k,l,wynik*2);
        }
    if(wynik*3<=1e6)
        {
        rek(a,b+1,c,d,e,f,g,h,i,j,k,l,wynik*3);
        }
    return;
    }
if(wynik*3<=n)rek(a,b+1,c,d,e,f,g,h,i,j,k,l,wynik*3);
if(c!=0)
    {
    if(wynik*3<=1e6)
        {
        rek(a,b+1,c,d,e,f,g,h,i,j,k,l,wynik*3);
        }
    if(wynik*5<=1e6)
        {
        rek(a,b,c+1,d,e,f,g,h,i,j,k,l,wynik*5);
        }    return;
    }
if(wynik*5<=n)rek(a,b,c+1,d,e,f,g,h,i,j,k,l,wynik*5);
if(d!=0)
    {
    if(wynik*5<=1e6)
        {
        rek(a,b,c+1,d,e,f,g,h,i,j,k,l,wynik*5);
        }
    if(wynik*7<=1e6)
        {
        rek(a,b,c,d+1,e,f,g,h,i,j,k,l,wynik*7);
        }    return;
    }
if(wynik*7<=n)rek(a,b,c,d+1,e,f,g,h,i,j,k,l,wynik*7);
if(e!=0)
    {
    if(wynik*7<=1e6)
        {
        rek(a,b,c,d+1,e,f,g,h,i,j,k,l,wynik*7);
        }
    if(wynik*11<=1e6)
        {
        rek(a,b,c,d,e+1,f,g,h,i,j,k,l,wynik*11);
        }    return;
    }
if(wynik*11<=n)rek(a,b,c,d,e+1,f,g,h,i,j,k,l,wynik*11);
if(f!=0)
    {
    if(wynik*11<=1e6)
        {
        rek(a,b,c,d,e+1,f,g,h,i,j,k,l,wynik*11);
        }
    if(wynik*13<=1e6)
        {
        rek(a,b,c,d,e,f+1,g,h,i,j,k,l,wynik*13);
        }    return;
    }
if(wynik*13<=n)rek(a,b,c,d,e,f+1,g,h,i,j,k,l,wynik*13);
if(g!=0)
    {
    if(wynik*13<=1e6)
        {
        rek(a,b,c,d,e,f+1,g,h,i,j,k,l,wynik*13);
        }
    if(wynik*17<=1e6)
        {
        rek(a,b,c,d,e,f,g+1,h,i,j,k,l,wynik*17);
        }    return;
    }
if(wynik*17<=n)rek(a,b,c,d,e,f,g+1,h,i,j,k,l,wynik*17);
if(h!=0)
    {
    if(wynik*17<=1e6)
        {
        rek(a,b,c,d,e,f,g+1,h,i,j,k,l,wynik*17);
        }
    if(wynik*19<=1e6)
        {
        rek(a,b,c,d,e,f,g,h+1,i,j,k,l,wynik*19);
        }    return;
    }
if(wynik*19<=n)rek(a,b,c,d,e,f,g,h+1,i,j,k,l,wynik*19);
if(i!=0)
    {
    if(wynik*19<=1e6)
        {
        rek(a,b,c,d,e,f,g,h+1,i,j,k,l,wynik*19);
        }
    if(wynik*23<=1e6)
        {
        rek(a,b,c,d,e,f,g,h,i+1,j,k,l,wynik*23);
        }    return;
    }
if(j!=0)
    {
    if(wynik*23<=1e6)
        {
        rek(a,b,c,d,e,f,g,h,i+1,j,k,l,wynik*23);
        }
    if(wynik*29<=1e6)
        {
        rek(a,b,c,d,e,f,g,h,i,j+1,k,l,wynik*29);
        }    return;
    }
if(k!=0)
    {
    if(wynik*29<=1e6)
        {
        rek(a,b,c,d,e,f,g,h,i,j+1,k,l,wynik*29);
        }
    if(wynik*31<=1e6)
        {
        rek(a,b,c,d,e,f,g,h,i,j,k+1,l,wynik*31);
        }    return;
    }
if(l!=0)
    {
    if(wynik*31<=1e6)
        {
        rek(a,b,c,d,e,f,g,h,i,j,k+1,l,wynik*31);
        }
    if(wynik*41<=1e6)
        {
        rek(a,b,c,d,e,f,g,h,i,j,k,l+1,wynik*41);
        }    return;
    }
}
int main()
{
ios_base::sync_with_stdio(0);
/*rek(1,0,0,0,0,0,0,0,0,0,0,0,2);
rek(0,1,0,0,0,0,0,0,0,0,0,0,3);
rek(0,0,1,0,0,0,0,0,0,0,0,0,5);
rek(0,0,0,1,0,0,0,0,0,0,0,0,7);
rek(0,0,0,0,1,0,0,0,0,0,0,0,11);
rek(0,0,0,0,0,1,0,0,0,0,0,0,13);
rek(0,0,0,0,0,0,1,0,0,0,0,0,17);
rek(0,0,0,0,0,0,0,1,0,0,0,0,19);
rek(0,0,0,0,0,0,0,0,1,0,0,0,23);
rek(0,0,0,0,0,0,0,0,0,1,0,0,29);*/
cin>>n;
rek(0,0,0,0,0,0,0,0,0,0,0,0,1);
dz[1]=1;
//864 840
//924 1080
//cout<<dz[924]<<' '<<dz[1080]<<' '<<dz[nwd(924,1080)];
//return 0;
vek.push_back(1);
sort(vek.begin(),vek.end());
for(int i=0;i<vek.size();i++)
    {
    for(int j=0;j<vek.size();j++)
        {
        //if(i==0&&vek[j]<=n)cout<<vek[j]<<' ';
        if(vek[i]<=n&&vek[j]<=n&&wyniczek<dz[vek[i]]+dz[vek[j]]-dz[nwd(vek[i],vek[j])])
            {
            wyniczek=dz[vek[i]]+dz[vek[j]]-dz[nwd(vek[i],vek[j])];
            ind1=vek[i];
            ind2=vek[j];
            }
        }
    }
cout<<wyniczek<<'\n'<<ind1<<' '<<ind2<<'\n';
return 0;
pierwsze[1]=1;
for(int i=2;i<=n;i++)
    {
    if(pierwsze[i]==0)
        {
        pierwsze[i]=i;
        akt=i;
        for(long long j=akt*akt;j<=n;j+=i)
            {
            if(pierwsze[j]==0)pierwsze[j]=i;
            }
        }
    }
for(int i=2;i<=n;i++)
    {
    if(pierwsze[i]==i)
        {
        kolejna[i]=++ind;
        g.push_back(i);
        }
    }
long long ilo=1;
for(int i=0;i<g.size();i++)
    {
    ilo*=g[i];
    if(ilo>1e16)
        {
        cout<<i<<' '<<g[i]<<'\n';
        break;
        }
    }
for(int i=0;i<=12;i++)
    {

    }
return 0;
for(int i=1;i<=n;i++)
    {
    akt=i;
    last=0;
    licznik=0;
    dzielniki=1;
    while(akt!=1)
        {
        teraz=pierwsze[akt];
        if(teraz==last)licznik++;
        else
            {
            last=teraz;
            dzielniki*=licznik+1;
            licznik=1;
            }
        akt/=teraz;
        }
    dzielniki*=licznik+1;
    dz[i]=dzielniki;
    if(dz[i]>maxdzielniki)
        {
        maxdzielniki=dz[i];
        indeks1=i;
        }
    }
for(int nwd=1;nwd<=n;nwd++)
    {
    for(int i=nwd;i<=n;i+=nwd)
        {
        akt=i;

        }
    }
for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=n;j++)
        {
        if(dz[i]+dz[j]-dz[__gcd(i,j)]>wynik)
            {
            wynik=dz[i]+dz[j]-dz[__gcd(i,j)];
            indeks1=i;
            indeks2=j;
            }
        }
    }
cout<<wynik<<'\n'<<indeks1<<' '<<indeks2<<'\n';
}
