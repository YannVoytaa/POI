#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
int kand=1,zliczpierwsze[9000000],wynikpierwszy,x=1,y=0,a=0,b=1,e,ja,zapisz[9000000],zliczaj[9000002],d,w,c=1,zlicz[100005],k,wynik,z,n,m,t[6002][3002];
long long nadwynik;
int main()
{
scanf("%d %d %d",&m,&n,&k);
for(int i=1;i<=m;i++)
    {
    for(int j=1;j<=n;j++)
        {
        scanf("%d",&t[i][j]);
        if(i<=k&&j<=k)
            {
            zlicz[t[i][j]]++;
            if(zlicz[t[i][j]]==1)wynik++;
            }
        }
    }
for(int i=1;i<=(m-k+1);i++)
    {
    for(int j=1;j<=(n-k+1);j++)
        {
        if(j==1)
            {
            c=1;
            y++;
            if(y>1)
                {
                for(int q=y;q<(k+y);q++)
                    {
                    for(int o=1;o<=k;o++)
                        {
                        zlicz[t[q][o]]++;
                        if(zlicz[t[q][o]]==1)wynik++;
                        }
                    }
                }
            }
        else
            {
            for(int q=y;q<(k+y);q++)
                {
                zlicz[t[q][j-1]]--;
                if(zlicz[t[q][j-1]]==0)wynik--;
                }
            for(int q=y;q<(k+y);q++)
                {
                zlicz[t[q][j+k-1]]++;
                if(zlicz[t[q][j+k-1]]==1)wynik++;
                }
            }
                if((j+k-1)>=n)
                    {
                    if(kand<wynik)kand=wynik;
                    nadwynik+=wynik;
                    for(int o=y;o<=(k+y-1);o++)
                        {
                        for(int p=(n-k+1);p<=n;p++)
                            {
                            zlicz[t[o][p]]=0;
                            }
                        }
                    wynik=0;
                    }
        if(kand<wynik)kand=wynik;
        nadwynik+=wynik;
        }
    }
printf("%d %lld\n",kand,nadwynik);
}
