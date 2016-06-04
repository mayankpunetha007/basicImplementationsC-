#include <iostream>
using namespace std;
long long phi(long long n)
{
    long long result=n;
    for(long long i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;

            result-=result/i;
        }
    }
    if(n>1)
    {
        result-=result/n;
    }
    return result;
}
int main()
{
    long long result=0;
  for(int i=0;i<=200000;++i)
  {
      result+=phi(i);
  }
  cout<<result<<endl;
}
