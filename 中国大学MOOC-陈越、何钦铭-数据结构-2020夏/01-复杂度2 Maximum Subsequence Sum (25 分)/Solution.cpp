#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int a[N];
	int nownum = 0, rnum = -1, start = 0, estart = 0, end = N-1;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		nownum += a[i];
		if (nownum < 0)
		{
			nownum = 0;
			start = i + 1;
		}else if (nownum > rnum)
		{
			estart = start;
			rnum = nownum;
			end = i;
		}
	}
    if(rnum == -1)
    {
        rnum = 0;
    }
	cout << rnum << " " << a[estart] << " " << a[end];
	
	return 0;
}