#include<iostream>
#include<math.h>

using namespace std;

int meth(long long n)
{
	for (long long i = 3; i <= sqrt(n); i+=2)
	{
		if (n%i)
		{
			continue;
		}
        return 0;
	}
	return 1;
}

int fun(long long n)
{
	long long r = 0, a[n+1] = {0};
    a[2] = 1;
	for (long long i = 3; i <= n; i+=2)
	{
		if (a[i] = meth(i))
		{
			
			if (a[i - 2])
			{
				++r;
			}
			
		}
 	}
	return r;
}

int main()
{
	long long n;
	cin >> n;
	cout << fun(n);

	return 0;
}