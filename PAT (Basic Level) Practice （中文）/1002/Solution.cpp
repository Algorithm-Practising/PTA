#include<iostream>
#include<map>
#include<string>
#include<stack>
using namespace std;

int topy(long long int n, long long int sum, map<int, string> py);
void pt(long long int sum, map<int, string> py);

int main()
{
	map<int, string> py;
	py[1] = "yi";
	py[2] = "er";
	py[3] = "san";
	py[4] = "si";
	py[5] = "wu";
	py[6] = "liu";
	py[7] = "qi";
	py[8] = "ba";
	py[9] = "jiu";
	py[0] = "ling";

	string m;
	long long int n;
	long long int sum = 0;
	cin >> m;

	int r = m.length() / 18;
	if (!(m.length() % 18))
	{
		--r;
	}
	int a = 0, b = 18;
	while (r--)
	{
		n = stoll(m.substr(a, b));
		sum += topy(n, 0, py);
		a += 18;
	}
	n = stoll(m.substr(a, m.length() - a));
	sum += topy(n, 0, py);
	pt(sum, py);

	return 0;
}

int topy(long long int n, long long int sum, map<int, string> py)
{
	while (n > 9)
	{
		sum += n % 10;
		n /= 10;
	}
	sum += n;

	return sum;

}

void pt(long long int sum, map<int, string> py)
{
	stack<string> s;
	while (sum > 9)
	{
		s.push(" " + py[sum % 10]);
		sum /= 10;
	}
	s.push(py[sum]);

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}