#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int nodes, edges, starting;

int matrix[1001][1001];
bool visited[1001];

void dfs(int cur) {
	cout << cur << " ";
	
	visited[cur] = true;
	
	for (int i = 1; i <= nodes; i++) {
		if (visited[i] || matrix[cur][i] == 0)
			continue;
		dfs(i);
	}

}

void bfs(int cur) {
	queue<int> q;
	q.push(cur);
	visited[cur] = false;
	while (!q.empty()) {
		cur = q.front();
		cout << cur << " ";
		q.pop();
		for (int i = 1; i <= nodes; i++) {
			if (!visited[i] || matrix[cur][i] == 0)
				continue;
			q.push(i);
			visited[i] = false;
		}
		
		
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nodes >> edges >> starting;
	int first, sec;
	
	for (int i = 0; i < edges; i++) {
		cin >> first >> sec;
		matrix[first][sec] = 1;
		matrix[sec][first] = 1;
	}

	dfs(starting);
	cout << "\n";
	bfs(starting);
}