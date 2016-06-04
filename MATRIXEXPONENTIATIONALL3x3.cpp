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
const long long mod = 1000000007;
using namespace std;

void multiply(long long F[3][3], long long M[3][3]) {
    long long a, b, c, d, e, f, g, h, i;
    a = ((F[0][0] * M[0][0] + mod) % mod + (F[0][1] * M[1][0] + mod) % mod + (F[0][2] * M[2][0] + mod) % mod) % mod;
    b = ((F[0][0] * M[0][1] + mod) % mod + (F[0][1] * M[1][1] + mod) % mod + (F[0][2] * M[2][1] + mod) % mod) % mod;
    c = ((F[0][0] * M[0][2] + mod) % mod + (F[0][1] * M[1][2] + mod) % mod + (F[0][2] * M[2][2] + mod) % mod) % mod;
    d = ((F[1][0] * M[0][0] + mod) % mod + (F[1][1] * M[1][0] + mod) % mod + (F[1][2] * M[2][0] + mod) % mod) % mod;
    e = ((F[1][0] * M[0][1] + mod) % mod + (F[1][1] * M[1][1] + mod) % mod + (F[1][2] * M[2][1] + mod) % mod) % mod;
    f = ((F[1][0] * M[0][2] + mod) % mod + (F[1][1] * M[1][2] + mod) % mod + (F[1][2] * M[2][2] + mod) % mod) % mod;
    g = ((F[2][0] * M[0][0] + mod) % mod + (F[2][1] * M[1][0] + mod) % mod + (F[2][2] * M[2][0] + mod) % mod) % mod;
    h = ((F[2][0] * M[0][1] + mod) % mod + (F[2][1] * M[1][1] + mod) % mod + (F[2][2] * M[2][1] + mod) % mod) % mod;
    i = ((F[2][0] * M[0][2] + mod) % mod + (F[2][1] * M[1][2] + mod) % mod + (F[2][2] * M[2][2] + mod) % mod) % mod;
    F[0][0] = a % mod;
    F[0][1] = b % mod;
    F[0][2] = c % mod;
    F[1][0] = d % mod;
    F[1][1] = e % mod;
    F[1][2] = f % mod;
    F[2][0] = g % mod;
    F[2][1] = h % mod;
    F[2][2] = i % mod;
}

void power(long long F[3][3], long long n) {
    if (n == 0 || n == 1)
        return;
    power(F, n / 2);
    long long M[][3] = {
        {-1, 0, 4},
        {1, 0, 0},
        {0, 0, 3}
    };
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}

long long solve(long long n) {
    long long ans[] = {0, 4, 12, 24};
    if (n < 4)
        return ans[n];
    n -= 3;
    long long A[][3] = {
        {-1, 0, 4},
        {1, 0, 0},
        {0, 0, 3}
    };
    power(A, n);
    //cout<<A[0][0]<<" "<<A[1][0]<<" "<<A[2][1]<<endl;
    return ((24 * A[0][0]) % mod + (12 * A[0][1]) % mod + (27 * A[0][2]) % mod) % mod;
}

int main() {
    long long T;
    scanf("%lld", &T);
    while (T--) {
        long long N;
        scanf("%lld", &N);
        long long ans = solve(N);
        printf("%lld\n", ans);
    }
    return 0;
}
