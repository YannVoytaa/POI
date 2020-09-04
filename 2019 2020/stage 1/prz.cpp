#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
//b967c9a47eabf4a5
using namespace std;
stack<int>st;
long long eny,ind,ind2,wszystkie=1,wszystkiexd=1;
pair<int,int>p[25][500][2];
long long n,m,a,b,zeta,akt,mod=1000000007,pot,konc,wyniczek;
long long lol[125005][16],we[100005];
bool odw[100005],zab[60];
map<int,int>ma,mli;
// ..
vector<int> g(16);
long long kolor,wynik;
vector<int>vek[100005],liczby,liczba;

void countt()
{
for(int i=1;i<(1<<n);i++)
    {
    int x=i;
    bool nie=0;
    while(x)
        {
        int ost=__builtin_ctz(x);
        x=x& ~(1<<ost);
        if(g[ost]&i)nie=1;
        if(nie)break;
        }
    if(nie==0)lol[i][1]=1;
    }
for(int i=2;i<=n;i++)
    {
int    z=0;
int    x=0;
int lacz=0;
    for(int j=0;j<pow(3,n-1);j++)
        {
        //cout<<i<<' '<<x<<' '<<z<<' '<<lacz<<'\n';
        if(x>z)
            {
            //if(lol[z][i-1]*lol[x][1]>0)cout<<i<<' '<<x<<' '<<z<<' '<<lacz<<' '<<lol[z][i-1]*lol[x][1]<<'\n';
            lol[lacz][i]+=lol[z][i-1]*lol[x][1];
            lol[lacz][i]=lol[lacz][i]%mod;
            }
int        akt=j+1;
int        poz=0;
        while(true)
            {
            if(akt%3==1)
                {
                z|=(1<<poz);
                lacz|=(1<<poz);
                break;
                }
            if(akt%3==2)
                {
                z&=(~(1<<poz));
                x|=(1<<poz);
                break;
                }
            x&=(~(1<<poz));
            lacz&=(~(1<<poz));
            akt/=3;
            poz++;
            }
        }
    for(int j=0;j<(1<<(n-1));j++)
        {
        lol[(1<<n)-1][i]+=lol[((1<<(n-1))-1)&(~j)][i-1]*lol[j|(1<<(n-1))][1];
        lol[(1<<n)-1][i]=lol[(1<<n)-1][i]%mod;
        }
    }
//for(int i=1;i<=n;i++)cout<<lol[(1<<n)-1][i]<<' ';
}
void pomnoz2(int x,int y)
{
pot=wynik;
if(y)pot-=kolor;
else pot+=kolor;
pot=(pot%mod+mod)%mod;
while(x)
    {
    if(x%2)
        {
        konc*=pot;
        konc=konc%mod;
        }
    pot*=pot;
    pot=pot%mod;
    x/=2;
    }
}
void pomnoz(int x)
{
pot=kolor;
while(x)
    {
    if(x%2)
        {
        wynik*=pot;
        wynik=wynik%mod;
        }
    pot*=pot;
    pot=pot%mod;
    x/=2;
    }
}
void pomnoz3(long long x)
{
pot=kolor;
while(x)
    {
    if(x%2)
        {
        konc*=pot;
        konc=konc%mod;
        }
    pot*=pot;
    pot=pot%mod;
    x/=2;
    }
}
void dfs(int x)
{
odw[x]=1;
wynik++;
for(int j=0;j<vek[x].size();j++)
    {
    if(odw[vek[x][j]]==0)dfs(vek[x][j]);
    }
}
void zra(int wierzcholki,int krawedzie,int znak,int in,int oj,int kto){
//cout<<wierzcholki<<' '<<krawedzie<<' '<<znak<<' '<<in<<' '<<oj<<' '<<kto<<'\n';
//pair<int,int>para[27];
//for(int i=1;i<=krawedzie;i++){para[i]=p[i];/*cout<<para[i].first<<' '<<para[i].second<<"      ";*/}
//cout<<'\n';
if(krawedzie==0){mli[wierzcholki]+=znak/*.push_back(znak*(wierzcholki))*/;st.push(in);/*cout<<wierzcholki;*/return;}
int ind=0;
int ind2=0;
for(int i=1;i<=krawedzie;i++)
    {
    if((p[i][oj][kto].first==p[1][oj][kto].first&&p[i][oj][kto].second==p[1][oj][kto].second)||(p[i][oj][kto].second==p[1][oj][kto].first&&p[i][oj][kto].first==p[1][oj][kto].second)){}
    else
        {
        //cout<<para[1].first<<' '<<para[1].second<<"   ";
        p[++ind][in][0]=make_pair(p[i][oj][kto].first,p[i][oj][kto].second);
        if(p[i][oj][kto].first==p[1][oj][kto].first){p[++ind2][in][1]=make_pair(p[1][oj][kto].second,p[i][oj][kto].second);}
        else if(p[i][oj][kto].second==p[1][oj][kto].first){p[++ind2][in][1]=make_pair(p[i][oj][kto].first,p[1][oj][kto].second);}
        else {p[++ind2][in][1]=make_pair(p[i][oj][kto].first,p[i][oj][kto].second);}
        }
    }
//for(int i=1;i<=ind2;i++){para[i]=p2[i];cout<<para[i].first<<' '<<para[i].second<<"    ";}
//cout<<'\n';
if(st.empty()){wszystkiexd++;wszystkie=wszystkiexd;}
else
    {
    wszystkie=st.top();
    st.pop();
    }
zra(wierzcholki,ind,znak,wszystkie,in,0);
//for(int i=1;i<=ind2;i++){p[i][in]=p2[i][in];/*;cout<<p[i].first<<' '<<p[i].second<<"     ";*/}
//cout<<'\n';
if(st.empty()){wszystkiexd++;wszystkie=wszystkiexd;}
else
    {
    wszystkie=st.top();
    st.pop();
    }
zra(wierzcholki-1,ind2,-znak,wszystkie,in,1);
st.push(in);
}
void zrob(int aktn,int aktsas,int znak)
{
/*if(m==0){liczby.push_back(znak*(liczba.size()+eny));return;}
for(;aktn<liczba.size();aktn++)
    {
    if(zab[aktn])continue;
    for(;aktsas<liczba.size();aktsas++)
        {
        if(zab[aktsas]||zab[aktn])continue;
        if(gg[aktn]&(1<<aktsas))
            {
            //cout<<aktn<<' '<<aktsas<<'\n';
            //int zmienna;
            //cin>>zmienna;
            long long zapas1=gg[aktn];
            long long zapas2=gg[aktsas];
            int zapas3=0;
            gg[aktn]&= (~(1<<(aktsas)));
            gg[aktsas]&= (~(1<<(aktn)));
            m--;
            zapas3++;
            zrob(aktn,aktsas+1,znak);
            gg[aktn]&= (~(1<<(aktsas)));
            gg[aktsas]&= (~(1<<(aktn)));
long long            odpada=gg[aktn]&gg[aktsas];
            m-=__builtin_popcount(odpada);
            zapas3+=__builtin_popcount(odpada);
            zab[aktsas]=1;
            gg[aktn]|=gg[aktsas];
            eny--;
            zrob(aktn,0,-znak);
            eny++;
            m+=zapas3;
            gg[aktn]=zapas1;
            gg[aktsas]=zapas2;
            zab[aktsas]=0;
            return;
            }
        }
    aktsas=0;
    }*/
}
void zrx(vector<long long>wektor,long long wi,long long znak,int start)
{
//for(int j=0;j<wektor.size();j++)cout<<wektor[j]<<' ';
//cout<<"      "<<wi<<' '<<znak<<' '<<start<<'\n';
for(int j=start;j<wektor.size();j++)
    {
    if(wektor[j]!=0)
        {
        long long x=__builtin_ctz(wektor[j]);
        wektor[j]&=(~(1<<(x)));
        wektor[x]&=(~(1<<(j)));
        zrx(wektor,wi,znak,start);
        while(wektor[x])
            {
            int y=__builtin_ctz(wektor[x]);
            wektor[y]&=(~(1<<(x)));
            wektor[x]&=(~(1<<(y)));
            wektor[j]|=(1<<y);
            }
        zrx(wektor,wi-1,-znak,start);
        delete &wektor;
        return;
        }
    else start++;
    }
liczby.push_back(wi*znak);
delete &wektor;
//cout<<wi*znak<<'\n';
}
int main() {
    ios_base::sync_with_stdio(0);
        cin>>n>>m>>zeta;
        for(int i=1;i<=m;i++)
            {
            cin>>a>>b;
            if(n<=15)
                {
                g[a-1]|=(1<<(b-1));
                g[b-1]|=(1<<(a-1));
                }
            else if(m<=24)
                {
                we[a]++;
                we[b]++;
                p[i][0][0]=make_pair(a,b);
                }
            else
                {
                vek[a].push_back(b);
                vek[b].push_back(a);
                }
            }
if(n<=15)
    {
    countt();
    for(int i=1;i<=zeta;i++)
        {
        cin>>kolor;
        kolor=kolor-n+1;
        wynik=0;
        for(int j=n;j>=1;j--)
            {
            wynik+=lol[(1<<n)-1][j];
            wynik=wynik%mod;
            wynik*=(kolor);
            wynik=wynik%mod;
            kolor++;
            }
        cout<<wynik<<'\n';
        }
    }
else if(m<=24)
    {
    for(int i=1;i<=n;i++)
        {
        if(we[i]==0)wyniczek++;
        else
            {
            liczba.push_back(i);
            ma[i]=liczba.size()-1;
            }
        }
    vector<long long>gg(n-wyniczek+1);
    for(int i=1;i<=m;i++)
        {
        a=ma[p[i][0][0].first];
        b=ma[p[i][0][0].second];
        gg[a]|=(1<<(b));
        gg[b]|=(1<<(a));
        }
        //zrx(gg,n-wyniczek,1,0);
    //zrob(0,0,1);
    zra(n-wyniczek,m,1,1,0,0);
    for(int i=1;i<=zeta;i++)
        {
        cin>>kolor;
        konc=0;
        for(int j=0;j<=n-wyniczek;j++)
            {
            //cout<<liczby[j]<<'\n';
            wynik=abs(mli[j]);
            pomnoz(j);
            if(mli[j]<0)wynik=mod-wynik;
            konc+=wynik;
            konc=konc%mod;
            //konc=((konc%mod)+mod)%mod;
            }
        pomnoz3(wyniczek);
        cout<<konc<<'\n';
        }
    }
else
    {
    for(int i=1;i<=n;i++)
        {
        if(odw[i]==0){wynik=0;dfs(i);ma[wynik]++;}
        }
    for(int i=1;i<=n;i++)
        {
        if(ma[i]>0)liczby.push_back(i);
        }
    for(int i=1;i<=zeta;i++)
        {
        cin>>kolor;
        kolor--;
        pot=kolor;
        wynik=1;
        konc=1;
        akt=0;
        for(int j=0;j<liczby.size();j++)
            {
            pomnoz(liczby[j]-akt);
            pomnoz2(ma[liczby[j]],liczby[j]%2);
            akt=liczby[j];
            }
        cout<<konc<<'\n';
        }
    }
}
