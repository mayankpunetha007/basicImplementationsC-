#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <cstring>
using namespace std;
int tree[100005];
int N,K;
void update(int x)
{
    while(x<=N)
    {
        tree[x]++;
        x+=(x&-x);
    }
}
int sum(int x)
{
    //cout<<x<<endl;
    int s=0;
    while(x>0)
    {
        s+=tree[x];
        x-=(x&-x);
    }
    return s;
}
int main()
{
    scanf("%d %d",&N,&K);
    memset(tree,0,sizeof(tree));
    int x=1;
    long long suma=K;
    int prev=0;
    cout<<K<<" ";
    update(K);
    int pos=0;
    while(x!=N){
        int cost=K;
        int m=0;
        while(cost>0){
            //cout<<cost<<endl;
            pos=suma+cost;
            if(pos>N){
                pos=pos%N;
            }
            if(pos==0){
                pos=N;
            }
            if(suma>pos){
                int x=sum(N)-sum(suma);
                int y=sum(pos);
                //cout<<pos<<" "<<suma<<" "<<1<<" "<<x+y<<endl;
                m++;
                cost=cost-(cost-(x+y));
            }
            else if(suma<pos){

                int x=sum(pos)-sum(suma);
                //if(suma==1)
                    //x=sum(pos);
                //cout<<pos<<" "<<suma<<" "<<2<<" "<<x<<endl;
                m++;
                cost=cost-(cost-x);
            }
            else{
                //cout<<"YO"<<endl;
                int x=sum(N);
                //cout<<pos<<" "<<suma<<" "<<3<<" "<<x<<endl;
                cost=cost-(cost-x);
            }
            suma=pos;
        }
        if(suma==0){
                   cout<<N<<" ";
                   suma=N;
        }
        else
        cout<<suma<<" ";
        update(suma);
        x++;
    }
}
