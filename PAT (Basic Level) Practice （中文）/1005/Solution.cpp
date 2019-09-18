#include<iostream>
#include<string>
#include<set>
using namespace std;

struct Data
{
	int num;
	string str;
	struct Data * d;
};

int fun(struct Data * data,string * str,int num)
{
	int n = num;
	*str = to_string(num);
	while (num!=1)
	{
		if (num%2)
		{
			num = ((num * 3) + 1) / 2;
		}
		else
		{
			num /= 2;
		}
		*str += to_string(num);
	}
	while (NULL!=(*data).d)
	{
		data = data->d;
		if ((*data).str.find(*str)!=string::npos)
		{
			return -1;
		}
		else if ((*str).find((*data).str)!=string::npos)
		{
			(*data).num = n;
			(*data).str = *str;
			return 1;
		}
	}
	


	return 0;
}

int main()
{
	int n;
	cin >> n;
	struct Data * data = new struct Data();
	struct Data * data2 = data;
	(*data).d = NULL;
	struct Data * data1 = data;
	for (size_t i = 0; i < n; i++)
	{
		struct Data * dat = new struct Data();//(struct Data *)malloc(sizeof(struct Data));
		(*dat).d = NULL;
		cin >> (*dat).num;
		(*dat).str = "";
		data1 = data;
		if (!fun(data1, &((*dat).str), (*dat).num))
		{
			data2->d = dat;
			data2 = dat;
		}
	}
	set<int> s;
	while (NULL != (*data).d)
	{
		data = data->d;
		s.insert(data->num);
	}
	set<int>::iterator itor = s.end();
	while (itor!=s.begin())
	{
		if (itor!=s.end())
		{
			cout << " ";
		}
		itor--;
		cout << *itor;
	}

	return 0;
}
