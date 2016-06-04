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
#define MAXN 100001//.201s
using namespace std;
const unsigned long long MOD=1000000007;
unsigned long long f[MAXN], g[MAXN];
unsigned long long powmod(unsigned long long a,unsigned long long b) {
if (b == 0) return 1;
unsigned long long res = powmod(a, b >> 1);
(res *= res) %= MOD;
return b & 1 ? res * a % MOD : res;
}
unsigned long long C(int n, int m) {
    return f[n] * g[m] % MOD * g[n - m] % MOD;
}
int main()
{
    f[0] = 1;
    for (int i = 1; i < MAXN; i++)
        f[i] = (f[i - 1] * i) % MOD;
    for (int i = 0; i < MAXN; i++)
        g[i] = powmod(f[i], MOD - 2);
    cout<<C(100000,50000);
    return 0;
}
