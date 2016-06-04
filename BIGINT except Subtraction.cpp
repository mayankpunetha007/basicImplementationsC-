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
string add(string a1,string b1)
{
    if(b1.length()>a1.length())
    {
        string c=b1;
        b1=a1;
        a1=c;
    }
    string a=a1,b=b1;
    int i=a.length()-1;
    int j=b.length()-1;
    int sum=0,carry=0;
    string result="";
    for(;i>=0 && j>=0;i--,j--){
        sum+=(a[i]+b[j]-48 -48+carry);
        result+=((sum%10)+48);
        carry=(sum)/10;
        sum=0;
    }
    if(j>0){
        i=j;
        a=b;
    }
    for(;i>=0;i--){
        sum+=(a[i]-48+carry);
        result+=((sum%10)+48);
        carry=(sum)/10;
        sum=0;
    }
    while(carry>0){
        result+=((carry%10)+48);
        carry/=10;
    }
    reverse(result.begin(),result.end());
    return result;
}
string mult(string a,string b)//a.length()>b.length()
{
    if(b.length()>a.length())
    {
        string c=b;
        b=a;
        a=c;
    }
    string result="0";
    int carry=0;
    for(int i=a.length()-1;i>=0;i--){
        int sum=0;
        string val="";
    for(int k=a.length()-1;k>i;k--)
        val+="0";
    for(int j=b.length()-1;j>=0;j--){
        sum+=((b[j]-48)*(a[i]-48) + carry);
        val+=((sum%10)+48);
        carry=sum/10;
        sum=0;
    }
    while(carry>0){
        val+=((carry%10)+48);
        carry/=10;
    }
    reverse(val.begin(),val.end());
    result=add(val,result);
    }
    return result;
}
int main(){
    cout<<mult("11232313","345345423123");
}
