#include<bits/stdc++.h>
using namespace std;
int n,m,baza=1048576,x,s,a,pierwszy,drugi,b;
pair<int,int>wieza[1000005];
long long wynik,t[2000005];
char c[1000005];
void wrzuc(int x,int w)
    {
    x+=baza;
    while(x!=0)
        {
        t[x]+=w;
        x/=2;
        }
    }
void query(int a,int b)
    {
    a+=baza;
    b+=baza;
    wynik+=t[a];
    if(a!=b)wynik+=t[b];
    while(a/2!=b/2)
        {
        if(a%2==0)wynik+=t[a+1];
        if(b%2==1)wynik+=t[b-1];
        a/=2;
        b/=2;
        }
    }
int main()
{
scanf("%d %d",&n,&m);
for(int i=1;i<=m;i++)
    {
    cin>>c[i];
    if(c[i]=='P')
        {
        scanf("%d %d %d",&x,&s,&a);
        wieza[x]=make_pair(s,a);
        wrzuc(x,s);
        pierwszy=x-1;
        drugi=x+1;
        s-=a;
        while(s>0)
            {
            if(pierwszy>0)wrzuc(pierwszy,s);
            if(drugi<=n)wrzuc(drugi,s);
            pierwszy--;
            drugi++;
            s-=a;
            }
        }
    else if(c[i]=='U')
        {
        scanf("%d",&x);
        s=wieza[x].first;
        a=wieza[x].second;
        wrzuc(x,-s);
        pierwszy=x-1;
        drugi=x+1;
        s-=a;
        while(s>0)
            {
            if(pierwszy>0)wrzuc(pierwszy,-s);
            if(drugi<=n)wrzuc(drugi,-s);
            pierwszy--;
            drugi++;
            s-=a;
            }
        }
    else
        {
        wynik=0;
        scanf("%d %d",&a,&b);
        query(a,b);
        printf("%lld\n",wynik/(b-a+1));
        }
    }
}
