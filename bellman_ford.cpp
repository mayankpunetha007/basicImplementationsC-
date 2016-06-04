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

struct edge {
	int a, b, cost ;
};

int n, m, s, t ;
vector < edge > e (100005);
const int INF = 1000000000 ;

int bellman_ford()
{
    vector < int > d ( n, INF ) ;
	d[s-1] = 0 ;
	for ( ;; ) {
		bool any = false ;
		for ( int j = 0 ; j <= m+1 ; ++j )
			if ( d[e[j].a] < INF )
				if ( d[e[j].b] > d[e[j].a] + e[j].cost ) {
					d[e[j].b] = d[e[j].a] + e[j].cost ;
					any = true ;
				}
		if ( ! any )  break ;
	}
	return d[t-1];
}

int main()
{
    int test, final=INF;
    cin>>test;
    while(test--){
    int k;//two way edges
    cin>>n>>m>>k>>s>>t;
    for (int i=0; i<m; ++i)
    {
        int a,b,c;
        cin>>a>>b>>e[i].cost;
        e[i].a=a-1;
        e[i].b=b-1;
    }
    for (int i=0; i<k; ++i)
    {
        int a,b,c;
        cin>>a>>b>>e[m].cost;
        e[m].a=a-1;
        e[m].b=b-1;
        e[m+1].a=b-1;
        e[m+1].b=a-1;
        e[m+1].cost=e[m].cost;
        int cur=bellman_ford();
        if(final>cur)
            final=cur;
    }
    if(final!=INF)
        cout<<final<<endl;
    else
        cout<<"-1";
	return 0;
    }
}
