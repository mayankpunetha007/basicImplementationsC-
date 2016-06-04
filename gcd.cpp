 #include<iostream>
 using namespace std;

 int x,y;

 int gcd ( int a, int b ) {
	if ( b == 0 )
		return a ;
	else
		return gcd ( b, a % b ) ;
}
 int main()
 {
     cin>>x>>y;
     int ans = gcd(x,y);
     cout<<ans;
 }
