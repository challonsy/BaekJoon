#include<iostream>
#include<vector>
using namespace std;

int n, s;
vector<int>arr;
int count;
void func(int, int);


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	func(0, 0);

	if (s == 0) count--;
	cout << count;

	return 0;
}

void func(int cur, int total)
{
	if (cur == n)
	{
		if (total == s)
			count++;
		return;
	}
	func(cur + 1, total);
	func(cur + 1, total + arr[cur]);
}