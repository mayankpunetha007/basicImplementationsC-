#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

const int SQRT_MAXN = 100000 ; //root of the maximum value of N
const int S = 10000 ;
bool nprime [ SQRT_MAXN ] , bl [ S ] ;
int primes [ SQRT_MAXN ] , cnt ;
int n,res;

int calprime(int n)
 {
	int nsqrt = ( int ) sqrt ( n + .0 ) ;
	for ( int i = 2 ; i <= nsqrt ; ++ i )
		if ( ! nprime [ i ] ) {
			primes [ cnt ++ ] = i ;
			if ( i * 1ll * i <= nsqrt )
				for (int j = i * i ; j <= nsqrt ; j += i )
					nprime [ j ] = true ;
		}

	int result = 0 ;
	for ( int k = 0 , maxk = n / S ; k <= maxk ; ++ k ) {
		memset ( bl, 0 , sizeof bl ) ;
		int start = k * S ;
		for ( int i = 0 ; i < cnt ; ++ i ) {
			int start_idx = ( start + primes [ i ] - 1 ) / primes [ i ] ;
			int j = max ( start_idx, 2 ) * primes [ i ] - start ;
			for ( ; j < S ; j += primes [ i ] )
				bl [ j ] = true ;
		}
		if ( k == 0 )
			bl [ 0 ] = bl [ 1 ] = true ;
		for ( int i = 0 ; i < S && start + i <= n ; ++ i )
			if ( ! bl [ i ] )
				++ result ;
	}
	return result;
}

int main ( )
{
	cin >> n ;
	res = calprime(n);
    cout << res<<endl;
}


