#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int A[70000];
int main()
{
    int t;
    scanf("%d",&t);
    int k=0;
    while(t--){
        scanf("%d",&A[k]);
        k++;
    }
    int sqr=ceil(sqrt(k/1.0));
    vector< vector<int> > cities(k/sqr+1);//sqrtn data structure
    for(int i=0;i<k;i++)
    {
        cities[i/sqr].push_back(A[i]);
        //cout<<k/sqr;
    }
    //cout<<"YO";
    for(int i=0;i<cities.size();i++)
        sort(cities[i].begin(),cities[i].end());
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        l-=1;
        r-=1;
        int first=l/sqr;
        int second=r/sqr;
        if(first==second){
            bool ya=0;
            for(int i=l;i<=r;i++){
                if(A[i]==x){
                    ya=1;
                    break;
                }
            }
            if(ya)
                cout<<1;
            else
                cout<<0;
        }
        else{
            bool ya=0;
            for(int i=l;i<(first+1)*sqr;i++){
                if(A[i]==x){
                    ya=1;
                    break;
                }
            }
            for(int j=first+1;j<second;j++){
                if(binary_search(cities[j].begin(),cities[j].end(),x)){
                    ya=1;
                    break;
                }
            }
            for(int i=(second)*sqr;i<=r;i++){
                if(A[i]==x){
                    ya=1;
                    break;
                }
            }
            if(ya)
                cout<<1;
            else
                cout<<0;

        }

    }
}
