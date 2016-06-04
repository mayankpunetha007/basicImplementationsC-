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
#define MAX 135
long long tree[MAX][MAX][MAX];
void update(int x,int y,int z,int K)
{
    while(x<MAX){
        int i=y;
        while(i<MAX){
            int j=z;
            while(j<MAX){
                tree[x][i][j]+=K;
                j+=(j&-j);
            }
            i+=(i&-i);
        }
        x+=(x&-x);
    }
}
long long querry(int x2,int y2,int z2)
{
    long long sum=0;
    while(x2>0){
        int i=y2;
        while(i>0){
            int j=z2;
            while(j>0){
                sum+=tree[x2][i][j];
                j-=(j&-j);
            }
            i-=(i&-i);
        }
        x2-=(x2&-x2);
    }
    return sum;
}
int main()
{
    int N;
    scanf("%d",&N);
    memset(tree,0,sizeof(tree));
    while(1){
        int M;
        scanf("%d",&M);
        if(M==1){
            int x,y,z,K;
            scanf("%d %d %d %d",&x,&y,&z,&K);
            update(x+1,y+1,z+1,K);
        }
        else if(M==2){
            int x1,y1,z1,x2,y2,z2;
            scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
            long long m=querry(x2+1,y2+1,z2+1)-querry(x1,y2+1,z2+1)-querry(x2+1,y1,z2+1) - querry(x2+1, y2+1, z1) -querry(x1, y1, z1) + querry(x1, y1, z2+1) + querry(x1, y2+1, z1) + querry(x2+1, y1, z1);
            printf("%lld\n",m);
        }
        else
            break;
    }
	return 0;
}
