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
#define MAX 50001
using namespace std;
vector<vector<int> > g(MAX); // Count
int n; // number of vertices
vector <int> color(MAX); // color of the vertex (0, 1, or 2)
vector <int> time_in(MAX), time_out(MAX); // "days" coming and going from the top
int dfs_timer = 0; // ​​"Program" to determine the time
void dfs (int v) {
	 time_in [v] = dfs_timer++;
	 color [v] = 1;
	 for (int i = 0; i!= g [v].size(); ++i)
		 if (color [g[v][i]] == 0)
			 dfs (g[v][i]);
	 color [v] = 2;
	 time_out [v] = dfs_timer++;
 }
int main()
{
    n=3;
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(0);
    g[2].push_back(0);
    g[2].push_back(1);
    dfs(1);
    cout<<time_in[0]<<" "<<time_in[1]<<" "<<time_in[2]<<endl;
    cout<<time_out[0]<<" "<<time_out[1]<<" "<<time_out[2]<<endl;
    //cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
	return 0;
}
