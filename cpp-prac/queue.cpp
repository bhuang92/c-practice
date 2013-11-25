#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void queueExample();
void stackExample();

int main()
{
	cout << "Queue!" << endl;
	queueExample();
	cout << "Stack!" << endl;
	stackExample();
	return 0;
}

void queueExample() 
{

	queue<int> q;

	q.push(3);
	q.push(2);
	q.push(1);

	while(!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}

void stackExample()
{
	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);

	while(!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}