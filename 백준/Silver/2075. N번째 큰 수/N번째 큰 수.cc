#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>,greater<int>>pq;

	int n, num;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> num;
		pq.push(num);
		if (pq.size() > n) {
			pq.pop();
		}
	}
	cout << pq.top();
}