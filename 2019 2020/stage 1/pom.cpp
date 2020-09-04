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
    //k=getchar_unlocked();
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
//    k=getchar_unlocked();
}while(k>33);
}
int pot,zlew,zapy,wynik,pocz,zmiana[1000005],kk;
long long t[1000005],nww,x,y,a,l,r,sr;
bool tak;
string s1,s2;
int main()
{
ios_base::sync_with_stdio(0);
cin>>zapy;
while(zapy--)
    {
    cin>>s1>>s2>>kk;
    pot=-1;
    zlew=0;
    l=0;
    for(int i=0;i<s1.size();i++)zmiana[i]=0;
    for(int i=0;i<s1.size();i++)
        {
        zlew+=l;
        if(s1[i]!=s2[i])l=1;else l=0;
        if(s2[i]=='0')continue;
        if(s1[i]>=s2[i])
            {
            if(zlew+1>kk){continue;}
            if(zlew+s1.size()-i<kk){continue;}
            pot=i;
            }
        else
            {
            if(s2[i]=='1')
                {
                if(zlew>kk){continue;}
                if(zlew+s1.size()-i-1<kk){continue;}
                pot=i;
                }
            else
                {
                if(zlew>kk){continue;}
                if(zlew+s1.size()-i<kk){continue;}
                pot=i;
                }
            }
        }
    if(pot==-1)cout<<-1<<'\n';
    else
        {
        for(int i=0;i<pot;i++)
            {
            if(s1[i]!=s2[i])kk--;
            s1[i]=s2[i];
            }
        if(kk==0)
            {
            cout<<s1<<'\n';
            continue;
            }
        if(s1[pot]!=s2[pot]-1)
            {
            kk--;
            zmiana[pot]=1;
            s1[pot]=s2[pot]-1;
            }
        if(kk==0)
            {
            cout<<s1<<'\n';
            continue;
            }
        for(int i=pot+1;i<s1.size();i++)
            {
            if(kk==0)break;
            if(s1[i]!='9')
                {
                kk--;
                zmiana[i]=1;
                s1[i]='9';
                }
            }
        if(kk==0)
            {
            cout<<s1<<'\n';
            continue;
            }
        for(int i=s1.size()-1;i>=pot+1;i--)
            {
            if(kk==0)break;
            if(zmiana[i]==0)
                {
                kk--;
                zmiana[i]=1;
                s1[i]='8';
                }
            }
        if(kk==0)
            {
            cout<<s1<<'\n';
            continue;
            }
        if(zmiana[pot]==0)
            {
            kk--;
            s1[pot]--;
            }
        if(kk==0)
            {
            cout<<s1<<'\n';
            continue;
            }
        }
    }
}
