#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#define MAX 100001
#define mod 1000000007
int N;
set<int> indices;
int c=0;
long long treemin[4*MAX],treemax[4*MAX],A[MAX+1],product[4*MAX];
long long min(long long a,long long b){ if(a<b)return a; else return b;}
long long max(long long a,long long b){ if(a>b)return a; else return b;}
void createmin(int p,int l,int h){
    int mid=(l+h)/2;
    if(l==h){
        treemin[p]=A[l];
        return;
    }
    createmin(2*p,l,mid);
    createmin(2*p+1,mid+1,h);
    indices.insert(p);
    c++;
    treemin[p]=min(treemin[2*p],treemin[2*p+1]);
}
void createmax(int p,int l,int h){
    int mid=(l+h)/2;
    if(l==h){
        treemax[p]=A[l];
        return;
    }
    createmax(2*p,l,mid);
    createmax(2*p+1,mid+1,h);
    treemax[p]=max(treemax[2*p],treemax[2*p+1]);
}
int main()
{
   // memset(A,0,sizeof(A));
    scanf("%d",&N);
    int k=1;
    while(k!=N+1){
        scanf("%lld",&A[k]);
        k++;
    }
    createmin(1,1,N);
    createmax(1,1,N);
    long long ans=1;
    for(set<int>::iterator it;it!=indices.end();it++){
        //printf("%lld\n",treemax[indices[i]]-treemin[indices[i]]);
        ans=(ans*(treemax[*it]-treemin[*it]))%mod;
    }
    printf("%lld",ans);
	return 0;
}
