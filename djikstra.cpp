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
const int INF = 1000000000 ;
int n, m, s, t;
vector < vector < pair < int , int > > > g ( 10001 ) ;
vector < int > d ( 10001, INF ) ,  p ( 10001 ) ;

void djikstra()
{
    vector < char > u(n) ;
	d [ s ] = 0 ;
	for ( int i = 0 ; i < n ; ++i ) {
		int v = - 1 ;
		for ( int j = 0 ; j < n ; ++j )
			if ( !u [j] && (v == -1 || d[j] < d[v] ) )
				v = j ;
		if ( d[v] == INF )
			break ;
		u [ v ] = true ;
		for ( int j = 0 ; j < g[v].size() ; ++j ) {
			int to = g[v][j].first , len = g[v][j].second ;
			if ( d[v] + len < d[to] ) {
				d[to] = d[v] + len ;
				p[to] = v ;
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
    int test;
    cin>>test;
    while(test--){
    int k;//two way edges
    cin>>n>>m>>k>>s>>t;
    for (int i=0; i<m; ++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
    }
    for (int i=0; i<k; ++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    djikstra();
    if(d[t]<INF)
    {
        cout<<d[t]<<endl;
        //path();
    }
    else
        cout<<"-1"<<endl;
    }
    return 0;
}
