#include<iostream>
#include<string>
#include<vector>
int a[10], b[10];
using namespace std;
int main()
{
	string str;
	cin >> str;
	vector<int> c;
	for (int i = str.size() - 1; i >= 0; i--)c.push_back(str[i] - '0');
	int t = 0;
	for (int i = 0; i < c.size(); i++) {
		c[i] *= 2;
		c[i] += t;
		t = c[i] > 9 ? 1 : 0;
		if (t)c[i] %= 10;
	}
	if (t)c.push_back(1);
	if (c.size() != str.size()) {
		cout << "No" << endl;
		for (int i = c.size() - 1; i >= 0; i--)
			cout << c[i];
		return 0;
	}
	for (int i = 0; i < str.size(); i++) {
		a[str[i] - '0']++;
		b[c[i]]++;
	}
	for (int i = 0; i < 10; i++)
		if (a[i] != b[i]) {
			cout << "No" << endl;
			for (int i = c.size() - 1; i >= 0; i--)
				cout << c[i];
			return 0;
		}
	cout << "Yes" << endl;
	for (int i = c.size() - 1; i >= 0; i--)
		cout << c[i];
	return 0;
}