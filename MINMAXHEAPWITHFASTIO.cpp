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
using namespace std;
#define MAX 400005
const int SIZE = 1 << 19;
char buff[SIZE], *p = buff + SIZE;

char read_char() {
    if (p == buff + SIZE) {
        fread(buff, 1, SIZE, stdin);
        p = buff;
    }
    return *(p++);
}

bool cmp(int a, int b) {
    return a>b;
}

int read_int() {
    register char c;

    while (!isdigit(c = read_char()));

    register int r = c - '0';
    while (isdigit(c = read_char())) r = 10 * r + c - '0';

    return r;
}

int main() {
    //freopen("1.txt", "r", stdin);
    int N, W;
    N = read_int();
    W = read_int();
    //scanf("%d %d",&N,&W);
    int H[N];
    int k = 0;
    while (k != N) {
        H[k] = read_int();
        k++;
    }
    vector<int> min, max;
    for (int i = 0; i < W; i++) {
        min.push_back(H[i]);
        max.push_back(H[i]);
    }
    make_heap(max.begin(), max.end());
    make_heap(min.begin(), min.end(), cmp);
    int count = 0;
    bool A[N + 1];
    for (int i = 0; i <= N; i++)
        A[i] = 0;
    for (int ia = W; ia < N; ia++) {
        int i = max.front();
        int j = min.front();
        while (A[i]) {
            pop_heap(max.begin(), max.end());
            max.pop_back();
            i = max.front();
        }
        while (A[j]) {
            pop_heap(min.begin(), min.end(), cmp);
            min.pop_back();
            j = min.front();
        }
        if (i - j + 1 == W)
            count++;
        A[H[ia - W]] = 1;
        max.push_back(H[ia]);
        min.push_back(H[ia]);
        push_heap(min.begin(), min.end(), cmp);
        push_heap(max.begin(), max.end());
    }
    int i = max.front();
    int j = min.front();
    while (A[i]) {
        i = max.front();
        pop_heap(max.begin(), max.end());
        max.pop_back();
    }
    while (A[j]) {
        j = min.front();
        pop_heap(min.begin(), min.end(), cmp);
        min.pop_back();
    }
    if (i - j + 1 == W)
        count++;
    printf("%d\n", count);
}
