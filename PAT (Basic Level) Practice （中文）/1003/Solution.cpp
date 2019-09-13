#include<iostream>
#include<string>

using namespace std;

string fun(string str)
{
	if (str.find("A")==str.npos|| str.find("P") == str.npos || str.find("T") == str.npos|| str.find("P") > str.find("T")|| str.find("P") - str.find("T")==-1)
	{
		return "NO";
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i]!='P'&& str[i] != 'A'&&str[i] != 'T')
		{
			return "NO";
		}
	}
	int start, mid;
	start = str.find("P");
	mid = str.find("T");
	if (((start)*(mid-start-1))!=(str.length()-mid-1))
	{
		return "NO";
	}
	return "YES";
}

int main()
{
	int count;
	string str,r;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> str;
		r += fun(str)+"\n";
	}
	cout << r;
	
	return 0;
}
