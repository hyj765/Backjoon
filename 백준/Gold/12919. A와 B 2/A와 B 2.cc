#include<iostream>
#include<queue>
using namespace std;


string reverse(std::string str)
{
	string temp = "";
	for (int i = str.size()-1; i >= 0; --i)
	{
		temp += str[i];
	}

	return temp;
}


int main()
{
	string a, b;

	cin >> a >> b;

	queue<string> q;
	q.push(b);
	while (q.empty() == false)
	{
		auto cur = q.front();
		q.pop();

		if (cur == a)
		{
			printf("1");
			return 0;
		}
			
		string temp = cur;
		if (temp.back() == 'A') {
			temp.pop_back();
			q.push(temp);
		}
		cur = reverse(cur);
		if (cur.back() == 'B') {
			cur.pop_back();
			q.push(cur);
		}
	}

	printf("0");

	return 0;
}