#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
using namespace std;
int n;
long long a,b,wynik,n1,n2,h1,h2,suma[2500005],baza=1024*1024,ilosc[2500005],wartosc,pierwsze,drugie,ind,akt,teraz,poswiecicduzych,debug=0,c,wynikonc,h[1000005],przekroczylo,pomnozone,tak;
pair<long long,long long>x[1000005];
stack<pair<pair<long long,long long>,int> >st;
vector<pair<pair<long long,long long>,int> >g;
void dodaj(int poz,int il)
{
wartosc=poz;
poz+=baza;
while(poz)
    {
    ilosc[poz]+=il;
    if(wartosc%h2==0)suma[poz]+=wartosc/h2*il;
    else suma[poz]+=(wartosc/h2+1)*il;
    poz/=2;
    }
}
long long rek(int liczba,int poz)
{
if(poz>=baza)
    {
    if((poz-baza)%h2==0)return ((poz-baza)/h2)*liczba;
    return ((poz-baza)/h2+1)*liczba;
    }
if(ilosc[poz]<=liczba)return suma[poz];
else if(ilosc[2*poz+1]>=liczba)return rek(liczba,2*poz+1);
else return suma[2*poz+1]+rek(liczba-ilosc[2*poz+1],2*poz);
}
void pomnoz(long long a,long long b)
{
pomnozone=0;
przekroczylo=0;
while(b)
    {
    if(b%2)pomnozone+=a;
    if(pomnozone>1e18)przekroczylo=1;
    a*=2;
    if(a>1e18)przekroczylo=1;
    b/=2;
    }
}
bool mozna()
{
if(pierwsze>=n1)
    {
    if(debug)cout<<suma[1]<<' '<<(pierwsze-n1)*h1/h2<<' '<<n2<<' ';
    n2-=suma[1];
    pomnoz(pierwsze-n1,h1/h2);
    if(debug)cout<<pomnozone<<' '<<przekroczylo<<' ';
    if(pomnozone>n2||przekroczylo==1)tak=0;
    else tak=1;
    n2+=suma[1];
    if(debug)cout<<tak<<'\n';
    return tak;
    }
else
    {
    if(debug)cout<<suma[1]<<' '<<rek(n1-pierwsze,1)<<' '<<n2<<'!'<<'\n';
    if((suma[1]-rek(n1-pierwsze,1))>n2)return 0;
    else return 1;
    }
}
void zroblewo()
{
for(int i=1;i<=n;i++)
    {
    wynik=1;
    while(!st.empty())
        {
        a=st.top().f.f;
        b=st.top().f.s;
        c=st.top().s;
        if(x[i].f-x[i].s<=a)
            {
            wynik+=b;
            if(x[i].f-x[i].s>a-x[c].s)x[i].s=x[c].s+x[i].f-a;
            st.pop();
            }
        else break;
        }
    st.push(mp(mp(x[i].f,wynik),i));
    }
g.clear();
while(!st.empty())
    {
    g.push_back(mp(mp(st.top().f.f,st.top().f.s),st.top().s));
    wynikonc=max(wynikonc,st.top().f.s);
    if(debug)cout<<st.top().f.f<<' '<<st.top().f.s<<' '<<st.top().s<<'\n';
    st.pop();
    }
ind=1;
pierwsze=0;
drugie=0;
akt=g[0].f.s;
for(int i=1;i<g.size();i++)
    {
    akt+=g[i].f.s;
    if(debug)cout<<g[i].f.s<<'\n';
if(debug)cout<<"DODAJE"<<' '<<i<<' '<<akt<<'\n';
    teraz=g[i-1].f.f-g[i].f.f-x[g[i-1].s].s;
    if(debug)cout<<"TERAZ: "<<teraz<<'\n';
    poswiecicduzych=teraz/h1;
    pierwsze+=poswiecicduzych;
    dodaj(teraz%h1,1);
    while(ind<=i&&!mozna())
        {
    if(debug)cout<<akt<<' '<<g[i].s<<'\n';
        akt-=g[ind-1].f.s;
    if(debug)cout<<"ODEJMUJE"<<' '<<ind-1<<' '<<akt<<'\n';
        teraz=g[ind-1].f.f-g[ind].f.f-x[g[ind-1].s].s;
        poswiecicduzych=teraz/h1;
        pierwsze-=poswiecicduzych;
        dodaj(teraz%h1,-1);
        ind++;
        }
    wynikonc=max(wynikonc,akt);
    }
}
void zrobwprawo()
{
for(int i=n;i>=1;i--)
    {
    wynik=1;
    while(!st.empty())
        {
        a=st.top().f.f;
        b=st.top().f.s;
        c=st.top().s;
        if(x[i].f+x[i].s>=a)
            {
            wynik+=b;
            if(x[i].f+x[i].s<a+x[c].s)x[i].s=x[c].s-x[i].f+a;
            st.pop();
            }
        else break;
        }
    st.push(mp(mp(x[i].f,wynik),i));
    }
g.clear();
while(!st.empty())
    {
    g.push_back(mp(mp(st.top().f.f,st.top().f.s),st.top().s));
    wynik=max(wynik,st.top().f.s);
    if(debug)cout<<st.top().f.f<<' '<<st.top().f.s<<' '<<st.top().s<<'\n';
    st.pop();
    }
ind=1;
pierwsze=0;
drugie=0;
akt=g[0].f.s;
if(debug)cout<<g[2].f.s+g[1].f.s<<"!!!!!!!!!!!!!!!";
for(int i=1;i<g.size();i++)
    {
    akt+=g[i].f.s;
    if(debug)cout<<"DODAJE"<<' '<<i<<' '<<akt<<'\n';
    if(debug)cout<<g[i].f.s<<'\n';
    teraz=g[i].f.f-g[i-1].f.f-x[g[i-1].s].s;
    if(debug)cout<<"TERAZ: "<<teraz<<'\n';
    poswiecicduzych=teraz/h1;
    pierwsze+=poswiecicduzych;
    dodaj(teraz%h1,1);
    while(ind<=i&&!mozna())
        {
    if(debug)cout<<akt<<' '<<g[i].s<<'\n';
        akt-=g[ind-1].f.s;
    if(debug)cout<<"ODEJMUJE"<<' '<<ind-1<<' '<<akt<<'\n';
        teraz=g[ind].f.f-g[ind-1].f.f-x[g[ind-1].s].s;
        poswiecicduzych=teraz/h1;
        pierwsze-=poswiecicduzych;
        dodaj(teraz%h1,-1);
        ind++;
        }
    if(debug)cout<<ind<<' '<<i<<'\n';
    wynikonc=max(wynikonc,akt);
    }
}
int main()
{
ios_base::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++)
    {
    cin>>x[i].f>>x[i].s;
    }
//sort(x+1,x+n+1);
cin>>n1>>h1>>n2>>h2;
if(h1<h2)
    {
    swap(n1,n2);
    swap(h1,h2);
    }
for(int i=1;i<=n;i++)h[i]=x[i].s;
zroblewo();
for(int i=1;i<=n;i++)x[i].s=h[i];
for(int i=1;i<=2*baza-1;i++)
    {
    ilosc[i]=0;
    suma[i]=0;
    }
zrobwprawo();
cout<<wynikonc+n1+n2<<'\n';
}
/*3
1 5
10 6
20 7
1 4 2 1*/
