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
bool binary_add(vector<int> data,int low,int high,int b)
{
     long mid=(low+high)/2;
     while(high>low)
     {
        mid=(low+high)/2;
       if(b<=data[mid-1] && b>=data[mid]){
            data.insert(data.begin()+mid,b);
            return 1;
        }
        if(b<=data[mid] && b>=data[mid+1]){
            data.insert(data.begin()+mid+1,b);
            return 1;
        }
        if(data[mid]==b){
            data.insert(data.begin()+mid,b);
            return 1;
        }
        else if(data[mid]<b)
            high=mid;
        else
            low=mid;
    }

	return 0;
}
int binary_search(vector<int> data,int low,int high,int b)
{
    long mid=(low+high)/2;
    if(data[low]==b)
        return low;
    else if(data[high]==b)
        return high;
    if(data[low]<b && data[high]>b)
    while(high>low)
    {
        //cout<<low<<" "<<high<<" "<<data[low]<<" "<<data[high]<<endl;
        mid=(low+high)/2;
        if(data[mid]==b)
            return mid;
        else if(data[mid]>b)
            high=mid;
        else
            low=mid;
    }

	return -1;
}
int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10,11};
    vector<int> as(A,A+11);
    cout<<binary_search(as,0,4,4);

}
