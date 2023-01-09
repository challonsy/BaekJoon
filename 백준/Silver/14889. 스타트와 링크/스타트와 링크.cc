#include <iostream>
#include<string>
#include <algorithm>
#include<cmath>
using namespace std;

int s[401][401] = { 0 };
int minn = 10000;
int total = 0;
int sum = 0;
int n;
int* visited;

void find(int num,int limit) {
	
	if (limit == n / 2 +1 && num == limit)
		return;

	while (num <= limit) {
		int thisone = 0;
		
		visited[num] = 1;

		for (int i = 1; i < num; i++) {
			if (visited[i])
				thisone += s[i][num];
		}
		
		total += thisone;
		
		if (limit < n && num<=limit) {
			find(num + 1, limit + 1);
			total -= thisone;
			visited[num] = 0;
			num++;
			continue;
		}
		
		int linktotal = 0;
		for (int i = 1; i <=n; i++) {
			if (!visited[i]) {
				for (int j = 1; j <=i; j++) {
					if (!visited[j])
						linktotal += s[j][i];
				}
			}
		}
		
		minn = minn < abs(linktotal-total) ? minn : abs(linktotal-total);
		total -= thisone;
		visited[num] = 0;
		num++;
	}

	return;
	
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	visited = new int[n + 1];
	fill(visited, visited + n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			s[i][j] = a;
			s[j][i] += s[i][j];
			sum += a;
		}
	}


	find(1,n/2+1);

	cout << minn;
}