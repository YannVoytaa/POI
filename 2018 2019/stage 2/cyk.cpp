#include<bits/stdc++.h>
#include "cyklib.hpp"
using namespace std;
int a;
map<long long,int> zlicz;
int main()
{
a=circular_shift(0);
zlicz[a]=-1;
for(int i=1;i<=99;i++)
    {
    a=circular_shift(1);
    if(zlicz[a]!=0)
        {
        if(zlicz[a]==-1)zlicz[a]=0;
        give_answer(i-zlicz[a]);
        return 0;
        }
    else zlicz[a]=i;
    }
give_answer(rand()%500000);
}
