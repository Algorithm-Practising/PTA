#include<iostream>

using namespace std;

int main()
{
    long n;
    cin>>n;
    int a[n];
    int nownum = 0,rnum = 0;
    for(long i=0;i<n;i++)
    {
        cin>>a[i];
        nownum+=a[i];
        if(nownum<0)
        {
            nownum=0;
        }
        if(nownum>rnum)
        {
            rnum = nownum;
        }
    }
    cout<<rnum;
    return 0;
}