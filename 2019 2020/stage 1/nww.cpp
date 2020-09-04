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
//    k=getchar_unlocked();
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
  //  k=getchar_unlocked();
}while(k>33);
}
int zapy,pocz;
long long nww,x,y,a,l,r,sr,wynik;
map<long long,pair<int,int> >m;
bool tak;
int main()
{
ios_base::sync_with_stdio(0);
for(int i=1;i<=10000;i++)
    {
    nww=i;
    for(int j=i+1;j<=10000;j++)
        {
        x=nww;
        y=j;
        while(x!=0&&y!=0)
            {
            if(x>y)x=x%y;
            else y=y%x;
            }
        nww/=(x+y);
        x=j;
        y=nww;
        nww*=x;
        if(y>LONG_LONG_MAX/x)break;
        if(m[nww].first==0)m[nww]=make_pair(i,j);
        //if(nww<0){cout<<i<<' '<<j-1<<' '<<nww<<'\n';wynik+=j-1;break;}
        }
    }
fastint(zapy);
while(zapy--)
    {
    fast(a);
    tak=1;
    if(m[a].first!=0)cout<<m[a].first<<' '<<m[a].second<<'\n';
    else tak=0;
    /*nww=1;
    pocz=1;
    for(int i=2;i<=10000;i++)
        {
        if(a%i!=0)
            {
            nww=1;
            pocz=i+1;
            }
        else
            {
            x=nww;
            y=i;
            while(x!=0&&y!=0)
                {
                if(x>y)x=x%y;
                else y=y%x;
                }
            x+=y;
            y=i;
            nww/=x;
            nww*=y;
            if(nww==a&&pocz!=i)
                {
                cout<<pocz<<' '<<i<<'\n';
                tak=1;
                }
            }
        if(tak)break;
        }*/
    if(tak)continue;
    l=9998;
    r=50000;
    while(l<r)
        {
        sr=(l+r)/2;
        if(sr*(sr+1)*(sr+2)*(sr+3)<a*2)l=sr+1;
        else r=sr;
        }
    if(l%3!=0&&l*(l+1)*(l+2)*(l+3)==a*2)
        {
        cout<<l<<' '<<l+3<<'\n';
        continue;
        }

    l=9998;
    r=50000;
    while(l<r)
        {
        sr=(l+r)/2;
        if(sr*(sr+1)*(sr+2)*(sr+3)<a*6)l=sr+1;
        else r=sr;
        }
    if(l%3==0&&l*(l+1)*(l+2)*(l+3)==a*6)
        {
        cout<<l<<' '<<l+3<<'\n';
        continue;
        }

    l=9998;
    r=1500000;
    while(l<r)
        {
        sr=(l+r)/2;
        if(sr*(sr+1)*(sr+2)<a*2)l=sr+1;
        else r=sr;
        }
    if(l%2==0&&l*(l+1)*(l+2)==a*2)
        {
        cout<<l<<' '<<l+2<<'\n';
        continue;
        }
    l=9998;
    r=1500000;
    while(l<r)
        {
        sr=(l+r)/2;
        if(sr*(sr+1)*(sr+2)<a)l=sr+1;
        else r=sr;
        }
    if(l%2!=0&&l*(l+1)*(l+2)==a)
        {
        cout<<l<<' '<<l+2<<'\n';
        continue;
        }

    l=9998;
    r=1000000000;
    while(l<r)
        {
        sr=(l+r)/2;
        if(sr*(sr+1)<a)l=sr+1;
        else r=sr;
        }
    if(l*(l+1)==a)
        {
        cout<<l<<' '<<l+1<<'\n';
        continue;
        }
    cout<<"NIE"<<'\n';
    }
}
