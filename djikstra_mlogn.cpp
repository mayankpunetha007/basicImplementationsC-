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
#define MAX 10001
using namespace std;
const int INF = 1000000000 ;
int n, m, s, t;
vector < vector < pair < int , int > > > g ( MAX ) ;
vector < int > d ( MAX, INF ) ,  p ( MAX ) , dd ( MAX, INF );

void djikstra()
{
    priority_queue < pair < int , int > > q ;
    d[s-1]=0;
	q.push( make_pair( 0 , s-1 ) ) ;
	while ( !q.empty() ) {
		int v = q.top().second , cur_d = -q.top().first ;
		q.pop() ;
		if ( cur_d > d[v] )
            continue ;
		for ( int j = 0 ; j < g[v].size () ; ++j ) {
			int to = g[v][j].first , len = g[v][j].second ;
			if ( d[v] + len < d[to] ) {
				d[to] = d[v] + len ;
				p[to] = v ;
				q.push(make_pair( -d[to] , to ) ) ;
			}
		}
	}
}

/*void path()
{
    vector < int > path ;
    for ( int v = t ; v != s ; v = p[v] )
        path. push_back(v) ;
    path. push_back(s) ;
    reverse ( path.begin() , path.end() ) ;
    for(int i=0; i<path.size(); ++i)
    {
        cout<<path[i]<<" ";
    }
}*/

int main()
{
    int test, final=INF;
    scanf("%d",&test);
    while(test--){
    int k;//two way edges
    scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);
    for (int i=0; i<m; ++i)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a-1].push_back(make_pair(b-1,c));
    }
    for (int i=0; i<k; ++i)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a-1].push_back(make_pair(b-1,c));
        g[b-1].push_back(make_pair(a-1,c));
        djikstra();
        if(d[t-1]<final)
            final=d[t-1];
        g[a-1].pop_back();
        g[b-1].pop_back();
        d=dd;
    }
    if(final!=INF)
    {
        printf("%d\n",final);
        //path();
    }
    else
        cout<<"-1"<<endl;
    }
    return 0;
}
