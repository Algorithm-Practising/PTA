#include<iostream>
#include<string>

using namespace std;

typedef struct Student
{
	string name;
	string sno;
	string score;
}Stu;

int main()
{
	int n;
	cin >> n;
	Stu stop,sdown,st;
	cin >> st.name;
	cin >> st.sno;
	cin >> st.score;
	stop = st;
	sdown = st;
	for (size_t i = 1; i < n; i++)
	{
		cin >> st.name;
		cin >> st.sno;
		cin >> st.score;
		if (stoi(st.score)>stoi(stop.score))
		{
			stop = st;
		}
		if (stoi(st.score) < stoi(sdown.score))
		{
			sdown = st;
		}
	}
	cout << stop.name << " " << stop.sno << endl;
	cout << sdown.name << " " << sdown.sno;
	return 0;
}
