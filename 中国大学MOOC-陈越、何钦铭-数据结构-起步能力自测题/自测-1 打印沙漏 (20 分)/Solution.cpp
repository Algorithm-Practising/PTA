#include<iostream>
#include<string>

using namespace std;

int fun(int num, int * seed)
{
	int i = 1;
	int t = i;

	while (i < num)
	{
		t = i;
		(*seed) += 2;
		i += (*seed) * 2;
		if (i == num)
		{
			(*seed) += 2;
			return i;
		}
	}
	return t;
}

int main()
{
	int n, a, seed = 1;
	string str;
	cin >> n;
	cin >> str;

	if (n < 7)
	{
		cout << str;

		cout << endl << n - 1;

		return 0;
	}

	int num = fun(n, &seed);
	seed -= 2;
	a = n - num;
	int t = seed, flag = 0;
	for (; t > 0; t -= 2)
	{
		for (size_t i = 0; i < flag; i++)
		{
			cout << " ";
		}
		flag++;
		for (size_t i = 0; i < t; i++)
		{
			cout << str;
		}
		cout << endl;
	}
	for (size_t i = t + 4; i <= seed; i += 2)
	{
		for (size_t j = flag - 2; j > 0; j--)
		{
			cout << " ";
		}
		flag--;
		for (size_t j = i; j > 0; j--)
		{
			cout << str;
		}
		if (i != seed)
		{
			cout << endl;
		}
	}

	cout << endl << a;

	return 0;
}
