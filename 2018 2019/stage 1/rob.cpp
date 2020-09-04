#include <bits/stdc++.h>
using namespace std;
long long oaktx,oakty,wynik,n,ruchy,wsumie,czas,t[4000005],pierwszy,drugi,xx,yy,terx,tery,kraniec,zero;
void pion(long long malx,long long maly,long long duzy,long long x,long long y,long long aktx,long long akty)
{

 if(aktx<0&&akty<0)
                {
                if(x>malx)return;
                if(y>duzy)return;
                if((malx-x)%(-aktx)!=0)return;
                ruchy=(malx-x)/-aktx;
                if(ruchy>czas/wsumie-1)return;
                if(maly+ruchy*akty<=y&&duzy+ruchy*akty>=y)wynik++;
                if(maly+ruchy*akty==y||duzy+ruchy*akty==y)kraniec++;
                }
            else if(aktx<0&&akty==0)
                {
                if(x>malx)return;
                if(y<maly||y>duzy)return;
                if((malx-x)%(-aktx)!=0)return;
                ruchy=(malx-x)/-aktx;
                if(ruchy>czas/wsumie-1)return;
                if(maly<=y&&duzy>=y)wynik++;
                if(maly==y||duzy==y)kraniec++;
                }
            else if(aktx<0&&akty>0)
                {
                if(x>malx)return;
                if(y<maly)return;
                if((malx-x)%(-aktx)!=0)return;
                ruchy=(malx-x)/-aktx;
                if(ruchy>czas/wsumie-1)return;
                if(maly+ruchy*akty<=y&&duzy+ruchy*akty>=y)wynik++;
                if(maly+ruchy*akty==y||duzy+ruchy*akty==y)kraniec++;
                }
            else if(aktx==0&&akty<0)
                {
                if(x!=malx)return;
                if(y>duzy)return;
                pierwszy=max(zero,(y-maly)/akty);
                if((y-maly)%akty!=0&&y-maly<0)pierwszy++;
                drugi=(y-duzy)/akty;
                if(pierwszy>czas/wsumie-1)return;
                drugi=min(drugi,czas/wsumie-1);
                wynik+=drugi-pierwszy+1;
                if((y-maly)%akty==0&&y-maly<=0)kraniec++;
                if((y-duzy)%akty==0&&(y-duzy)/akty<=czas/wsumie-1)kraniec++;
                }
            else if(aktx==0&&akty==0)
                {
                if(x!=malx)return;
                if(y<maly||y>duzy)return;
                wynik+=czas/wsumie;
                if(y==maly||y==duzy)kraniec+=czas/wsumie;
                }
            else if(aktx==0&&akty>0)
                {
                if(x!=malx)return;
                if(y<maly)return;
                pierwszy=max(zero,(y-duzy)/akty);
                if((y-duzy)%akty!=0&&y-duzy>0)pierwszy++;
                drugi=(y-maly)/akty;
                if(pierwszy>czas/wsumie-1)return;
                drugi=min(drugi,czas/wsumie-1);
                wynik+=drugi-pierwszy+1;
                if((y-duzy)%akty==0&&y-duzy>=0)kraniec++;
                if((y-maly)%akty==0&&(y-maly)/akty<=czas/wsumie-1)kraniec++;
                }
            else if(aktx>0&&akty<0)
                {
                if(x<malx)return;
                if(y>duzy)return;
                if((malx-x)%(-aktx)!=0)return;
                ruchy=(malx-x)/-aktx;
                if(ruchy>czas/wsumie-1)return;
                if(maly+ruchy*akty<=y&&duzy+ruchy*akty>=y)wynik++;
                if(maly+ruchy*akty==y||duzy+ruchy*akty==y)kraniec++;
                }
            else if(aktx>0&&akty==0)
                {
                if(x<malx)return;
                if(y<maly||y>duzy)return;
                if((malx-x)%(-aktx)!=0)return;
                ruchy=(malx-x)/-aktx;
                if(ruchy>czas/wsumie-1)return;
                if(maly<=y&&duzy>=y)wynik++;
                if(maly==y||duzy==y)kraniec++;
                }
            else if(aktx>0&&akty>0)
                {
                if(x<malx)return;
                if(y<maly)return;
                if((malx-x)%(-aktx)!=0)return;
                ruchy=(malx-x)/-aktx;
                if(ruchy>czas/wsumie-1)return;
                if(maly+ruchy*akty<=y&&duzy+ruchy*akty>=y)wynik++;
                if(maly+ruchy*akty==y||duzy+ruchy*akty==y)kraniec++;
                }
            //malx,maly,duzy,xx,yy
}

int main() {
  ios_base::sync_with_stdio(0);
  cin>>n>>czas;
  for(int i=0;i<n;i++)
    {
    cin>>t[i];
    wsumie+=t[i];
    if(i%4==0)oakty+=t[i];
    if(i%4==1)oaktx+=t[i];
    if(i%4==2)oakty-=t[i];
    if(i%4==3)oaktx-=t[i];
    }
  cin >> xx >> yy;
  if(czas==0&&xx==0&&yy==0)wynik++;
  if(n%4!=0)
    {
    for(int j=n;j<4*n;j++)
        {
        t[j]=t[j%n];
        wsumie+=t[j];
        if(j%4==0)oakty+=t[j];
        if(j%4==1)oaktx+=t[j];
        if(j%4==2)oakty-=t[j];
        if(j%4==3)oaktx-=t[j];
        }
    n*=4;
    }
wsumie+=n;
terx=0;tery=0;
if(wsumie<=czas)
    {
    for(int i=0;i<n;i++)
        {
        if(i%4==0)
            {
            pion(terx,tery,tery+t[i],xx,yy,oaktx,oakty);
            tery+=t[i];
            }
        if(i%4==1)
            {
            pion(-tery,terx,terx+t[i],-yy,xx,-oakty,oaktx);
            terx+=t[i];
            }
        if(i%4==2)
            {
            pion(terx,tery-t[i],tery,xx,yy,oaktx,oakty);
            tery-=t[i];
            }
        if(i%4==3)
            {
            pion(-tery,terx-t[i],terx,-yy,xx,-oakty,oaktx);
            terx-=t[i];
            }
        //cout<<wynik<<' '<<kraniec<<'\n';
        }
    }
    terx=(czas/wsumie)*oaktx;
    tery=(czas/wsumie)*oakty;
    wsumie=czas%wsumie;
    for(int i=0;i<n;i++)
        {
        if(wsumie<=0)break;
        if(wsumie-t[i]<0)
                {
                t[i]=wsumie;
                }
        if(i%4==1)
                {
                if(tery==yy&&terx<=xx&&terx+t[i]>=xx)
                    {
                    wynik++;
                    if(terx==xx||terx+t[i]==xx)kraniec++;
                    }
                terx+=t[i];
                wsumie-=(t[i]+1);
                }
        if(i%4==0)
                {
                if(terx==xx&&tery<=yy&&tery+t[i]>=yy)
                    {
                    wynik++;
                    if(tery==yy||tery+t[i]==yy)kraniec++;
                    }
                tery+=t[i];
                wsumie-=(t[i]+1);
                }
            if(i%4==3)
                {
                if(tery==yy&&terx>=xx&&terx-t[i]<=xx)
                    {
                    wynik++;
                    if(terx==xx||terx-t[i]==xx)kraniec++;
                    }
                terx-=t[i];
                wsumie-=(t[i]+1);
                }
            if(i%4==2)
                {
                if(terx==xx&&tery>=yy&&tery-t[i]<=yy)
                    {
                    wynik++;
                    if(tery==yy||tery-t[i]==yy)kraniec++;
                    }
                tery-=t[i];
                wsumie-=(t[i]+1);
                }
        }
if(xx==0&&yy==0)kraniec--;
cout<<wynik-kraniec/2;
}
