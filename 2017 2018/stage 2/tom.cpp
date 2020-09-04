#include<bits/stdc++.h>
using namespace std;
int n,m,t[1000005],jest1,xd,jest2,xxx,jest3,jest4,zlicz1[1000005],koniec,wskaznik[1000005],ruch1,ruch2,ruch3,ruch4,zlicz2[1000005],zlicz3[1000005],zlicz4[1000005],wynik1,wynik2,wynik3,wynik4,a,b,c,d,c1,c2,c3,c4;
queue<int>q1,q2,q3,q4;
vector<int>g[1000005];
int main()
{
scanf("%d %d",&n,&m);
xxx=n;
for(int i=1;i<=xxx;i++)
    {
    scanf("%d",&t[i]);
    t[i]++;
    t[i]=t[i]%m;
    g[t[i]].push_back(i);
    if(t[i]==0)
        {
        q1.push(0);
        q2.push(0);
        q3.push(0);
        q4.push(0);
        n--;
        }
    else
        {
        zlicz1[t[i]]++;
        zlicz2[t[i]]++;
        zlicz3[t[i]]++;
        zlicz4[t[i]]++;
        }
    }
for(int i=1;i<=m;i++)
    {
    while(jest1!=m-1-i&&zlicz1[i]>0)
        {
        jest1+=i;
        jest1=jest1%m;
        q1.push(i);
        zlicz1[i]--;
        c1++;
        }
    if(i==m&&c1!=n&&a<100)
        {
        a++;
        i=0;
        }
    }
for(int i=1;i<=m;i++)
    {
    while(zlicz1[i]>0)
        {
        jest1+=i;
        jest1=jest1%m;
        q1.push(i);
        zlicz1[i]--;
        if(jest1==m-1)
            {
            wynik1++;
            jest1=0;
            ruch1=1;
            }
        }
    }
if(jest1==0&&ruch1==1)wynik1--;
for(int i=m;i>0;i--)
    {
    while(jest2!=m-1-i&&zlicz2[i]>0)
        {
        jest2+=i;
        jest2=jest2%m;
        q2.push(i);
        zlicz2[i]--;
        c2++;
        }
    if(i==1&&c2!=n&&b<100)
        {
        b++;
        i=m;
        }
    }
for(int i=m;i>0;i--)
    {
    while(zlicz2[i]>0)
        {
        jest2+=i;
        jest2=jest2%m;
        q2.push(i);
        zlicz2[i]--;
        if(jest2==m-1)
            {
            wynik2++;
            jest2=0;
            ruch2=1;
            }
        }
    }
if(jest2==0&&ruch2==1)wynik2--;
for(int i=1;i<m;i++)
    {
    if(zlicz3[m-i]>0&&zlicz3[i]>0&&m-i!=1)
        {
        xd=min(zlicz3[i],zlicz3[m-i]);
        zlicz3[i]-=xd;
        zlicz3[m-1]-=xd;
        zlicz4[i]-=xd;
        zlicz4[m-i]-=xd;
        for(int o=1;o<=xd;o++)
            {
            q3.push(i);
            q3.push(m-i);
            q4.push(i);
            q4.push(m-i);
            }
        c3+=2*xd;
        c4+=2*xd;
        }
    }
for(int i=1;i<=m;i++)
    {
    while(jest3!=m-1-i&&zlicz3[i]>0)
        {
        jest3+=i;
        jest3=jest3%m;
        q3.push(i);
        zlicz3[i]--;
        c3++;
        }
    if(i==m&&c3!=n&&c<100)
        {
        c++;
        i=0;
        }
    }
for(int i=1;i<=m;i++)
    {
    while(zlicz3[i]>0)
        {
        jest3+=i;
        jest3=jest3%m;
        q3.push(i);
        zlicz3[i]--;
        if(jest3==m-1)
            {
            wynik3++;
            jest3=0;
            ruch3=1;
            }
        }
    }
if(jest3==0&&ruch3==1)wynik3--;
for(int i=m;i>0;i--)
    {
    while(jest4!=m-1-i&&zlicz4[i]>0)
        {
        jest4+=i;
        jest4=jest4%m;
        q4.push(i);
        zlicz4[i]--;
        c4++;
        }
    if(i==1&&c4!=n&&d<100)
        {
        d++;
        i=m;
        }
    }
for(int i=m;i>0;i--)
    {
    while(zlicz4[i]>0)
        {
        jest4+=i;
        jest4=jest4%m;
        q4.push(i);
        zlicz4[i]--;
        if(jest4==m-1)
            {
            wynik4++;
            jest4=0;
            ruch4=1;
            }
        }
    }
if(jest4==m-1&&ruch4==1)wynik4--;
koniec=min(min(wynik1,wynik2),min(wynik3,wynik4));
if(koniec==wynik1)
    {
    printf("%d\n",wynik1);
    for(int i=1;i<=xxx;i++)
        {
        printf("%d ",g[q1.front()][wskaznik[q1.front()]++]);
        q1.pop();
        }
    }
else if(koniec==wynik2)
    {
    printf("%d\n",wynik2);
    for(int i=1;i<=xxx;i++)
        {
        printf("%d ",g[q2.front()][wskaznik[q2.front()]++]);
        q2.pop();
        }
    }
else if(koniec==wynik3)
    {
    printf("%d\n",wynik3);
    for(int i=1;i<=xxx;i++)
        {
        printf("%d ",g[q3.front()][wskaznik[q3.front()]++]);
        q3.pop();
        }
    }
else if(koniec==wynik4)
    {
    printf("%d\n",wynik4);
    for(int i=1;i<=xxx;i++)
        {
        printf("%d ",g[q4.front()][wskaznik[q4.front()]++]);
        q4.pop();
        }
    }
}
