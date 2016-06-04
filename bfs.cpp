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
#include <stack>
#define MAX 50000
using namespace std;
vector < vector < int > > g(MAX) ;
vector < bool > used (MAX) ;
vector < int > d (MAX) , p (MAX) ;
int n ;
int s ;
void bfs()
{
    queue < int > q ;
    q. push ( s ) ;
    used [ s ] = true ;
    d[s]=0;
    p [ s ] = - 1 ;
    while ( ! q. empty ( ) ) {
        int v = q. front ( ) ;
        //cout<<v<<endl;
        q. pop ( ) ;
        for (int i = 0 ; i < g [v].size () ; ++ i ) {
            int to = g [ v ] [ i ] ;
            //cout<<to<<endl;
            if ( ! used [ to ] ) {
                used [ to ] = true ;
                q. push ( to ) ;
                d [ to ] = d [ v ] + 1 ;
                //cout<<d[to]<<" ";
                p [ to ] = v ;
            }
        }
    }
    //cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
}
void path(int to)
{
    if ( ! used [ to ] )
	cout << "No path!" ;
    else {
	vector < int > path;
	for ( int v = to; v != -1 ; v = p [v])
		path. push_back ( v ) ;
	reverse ( path. begin ( ) , path. end ( ) ) ;
	cout << "Path: " ;
	for ( size_t i = 0 ; i < path. size ( ) ; ++ i )
		cout << path [ i ] << " " ;//path[i]+1
}
}
int main()
{
    n=3;
    s=1;
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(0);
    g[2].push_back(0);
    g[2].push_back(1);
    bfs();
    cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
    path(2);
	return 0;
}
