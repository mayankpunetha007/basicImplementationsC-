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
#define MAXN 100
using namespace std;
 int n ;
vector < vector<int> > g (MAXN) ;
bool used [ MAXN ] ;
vector < int > comp ;

void dfs ( int v ) {
	used [ v ] = true ;
	comp. push_back ( v ) ;
	for ( size_t i = 0 ; i < g [ v ] . size ( ) ; ++ i ) {
		int to = g [ v ] [ i ] ;
		if ( ! used [ to ] )
			dfs ( to ) ;
	}
}

void find_comps ( ) {
	for ( int i = 0 ; i < n ; ++ i )
		used [ i ] = false ;
	for ( int i = 0 ; i < n ; ++ i )
		if ( ! used [ i ] ) {
			comp. clear ( ) ;
			dfs ( i ) ;

			cout << "Component:" ;
			for ( size_t j = 0 ; j < comp. size ( ) ; ++ j )
				cout << ' ' << comp [ j ] ;
			cout << endl ;
		}
}
int main()
{
    n=3;
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(0);
    g[2].push_back(0);
    g[2].push_back(1);
    find_comps();
    //cout<<time_in[0]<<" "<<time_in[1]<<" "<<time_in[2]<<endl;
    //cout<<time_out[0]<<" "<<time_out[1]<<" "<<time_out[2]<<endl;
    //cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
	return 0;
	return 0;
}
