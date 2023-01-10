#include<iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
queue<int> q;
vector<int>* nodes;
int* depth;
bool* visited;
int* parent;

int LCA(int a, int b) {

	while (depth[a] != depth[b])
		b = parent[b];

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;

}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	nodes = new vector<int>[n+1];
	depth = new int[n + 1];
	fill(depth, depth + n + 1, 0);
	visited = new bool[n + 1];
	fill(visited, visited + n + 1, false);
	parent = new int[n + 1];
	fill(parent, parent + n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		int first, second;
		cin >> first >> second;
		
		nodes[first].push_back(second);
		nodes[second].push_back(first);
	}

	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < nodes[x].size(); i++) {
			if (!visited[nodes[x][i]]) {
				depth[nodes[x][i]] = depth[x] + 1;
				visited[nodes[x][i]] = true;
				parent[nodes[x][i]] = x;
				q.push(nodes[x][i]);
			} 
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (depth[u] < depth[v])
			cout << LCA(u, v) << "\n";
		else
			cout << LCA(v, u) << "\n";
	}
	
}