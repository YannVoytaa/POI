#include<bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;
long long n,wynik,ind1,ind2,wyn1,wyn2,wyn3,dz[1000005],indeks1,indeks2,indeks3,pierwsze[1000005],akt,unikalne[25],l,r,sr,q,a,hasz1,pot1[23],mod1=1e9+93,mod2=1e9+33,podst1=29,potencjalny,pozycja,dwojka[24];
unsigned long long hasz2,pot2[23],podst2=31;
pair<long long,unsigned long long> h[100005][20];
map<pair<long long,unsigned long long>,int>m;
string s,teraz;
/*bool istnieje(int il)
{
unikalne=0;
m.clear();
for(int i=0;i<s.size();i++)
    {
    if(i+il-1>=s.size())break;
    teraz="";
    for(int j=0;j<il;j++)
        {
        teraz+=s[i+j];
        }
    m[teraz]++;
    if(m[teraz]==1)unikalne++;
    }
if(unikalne==pow(2,il))return 1;
else return 0;
}*/
void wywal(int x)
{
for(int dlugosc=1;dlugosc<=potencjalny;dlugosc++)
    {
    for(int j=max(0,x-dlugosc+1);j<=x;j++)
        {
        if(j+dlugosc-1>=s.size())break;
        pozycja=x-j;
        //cout<<j<<' '<<dlugosc<<' '<<h[j][dlugosc].f<<"           ";
        m[h[j][dlugosc]]--;
        if(m[h[j][dlugosc]]==0)unikalne[dlugosc]--;
        if(s[x]=='0')
            {
            h[j][dlugosc].f+=pot1[dlugosc-1-pozycja]*((long long)('1'-'0'));
            h[j][dlugosc].s+=pot2[dlugosc-1-pozycja]*((unsigned long long)('1'-'0'));
            h[j][dlugosc].f%=mod1;
            //h[j][dlugosc].s%=mod2;
            }
        else
            {
            h[j][dlugosc].f-=pot1[dlugosc-1-pozycja]*((long long)(s[x]-'0'));
            h[j][dlugosc].s-=pot2[dlugosc-1-pozycja]*((unsigned long long)(s[x]-'0'));
            h[j][dlugosc].f%=mod1;
            //h[j][dlugosc].s%=mod2;
            if(h[j][dlugosc].f<0)h[j][dlugosc].f+=mod1;
            //if(h[j][dlugosc].s<0)h[j][dlugosc].s+=mod2;
            }
        //cout<<j<<' '<<dlugosc<<' '<<h[j][dlugosc].f<<"           "<<'\n';
        m[h[j][dlugosc]]++;
        if(m[h[j][dlugosc]]==1)unikalne[dlugosc]++;
        }
    }
}
void sprawdz()
{
l=1;
r=potencjalny;
while(l<r)
    {
    sr=(l+r)/2;
    if(unikalne[sr]==dwojka[sr])l=sr+1;
    else r=sr;
    }
cout<<l<<'\n';
}
int main()
{
ios_base::sync_with_stdio(0);
cin>>n>>q>>s;
dwojka[0]=1;
for(int i=1;i<=20;i++)dwojka[i]=dwojka[i-1]*2;
potencjalny=min(18,(int)s.size());
for(int i=1;i<=potencjalny;i++)
    {
    hasz1=0;
    hasz2=0;
    pot1[0]=1;
    pot2[0]=1;
    for(int j=0;j<i;j++)
        {
        hasz1*=podst1;
        hasz1+=s[j]-'0'+1;
        hasz2*=podst2;
        hasz2+=s[j]-'0'+1;
        if(j!=0)pot1[j]=pot1[j-1]*podst1;
        if(j!=0)pot2[j]=pot2[j-1]*podst2;
        hasz1%=mod1;
        //hasz2%=mod2;
        pot1[j]%=mod1;
        //pot2[j]%=mod2;
        }
    m[mp(hasz1,hasz2)]=1;
    h[0][i]=mp(hasz1,hasz2);
    //cout<<0<<' '<<i<<' '<<h[0][i].f<<' '<<h[0][i].s<<'\n';
    unikalne[i]=1;
    for(int j=i;j<s.size();j++)
        {
        hasz1-=pot1[i-1]*((long long)s[j-i]-'0'+1);
        hasz1%=mod1;
        if(hasz1<0)hasz1+=mod1;
        hasz2-=pot2[i-1]*((unsigned long long)s[j-i]-'0'+1);
        //hasz2%=mod2;
        //if(hasz2<0)hasz2+=mod2;

        hasz1*=podst1;
        hasz1+=(long long)(s[j]-'0'+1);
        hasz2*=podst2;
        hasz2+=(unsigned long long)(s[j]-'0'+1);
        hasz1%=mod1;
        //hasz2%=mod2;
        m[mp(hasz1,hasz2)]++;
        if(m[mp(hasz1,hasz2)]==1)unikalne[i]++;
        h[j-i+1][i]=mp(hasz1,hasz2);
    //cout<<j-i+1<<' '<<i<<' '<<h[j-i+1][i].f<<' '<<h[j-i+1][i].s<<'\n';
        }
    }
sprawdz();

for(int i=1;i<=q;i++)
    {
    cin>>a;
    wywal(a-1);
    if(s[a-1]=='0')s[a-1]='1';
    else s[a-1]='0';
    sprawdz();
    }
}

/*
6 2
001010
6 2
*/
