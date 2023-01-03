#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>

using namespace std;

int node, root, q;
vector<int> vec[100001];
vector<bool> visited(100001, false);
int* num;

int find(int n) {

	if (num[n] != 0)
		return num[n];
	
	int ret=1;

	visited[n] = true;

	for (int i = 0; i < vec[n].size(); i++) {
		if (!visited[vec[n][i]])
			ret += find(vec[n][i]);
	}

	num[n] = ret;

	return ret;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> node >> root >> q;

	num = new int[node + 1];
	fill(num, num + node + 1, 0);

	for (int i = 1; i < node; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	num[root] = find(root);

	for (int i = 0; i < q; i++) {
		int whatnode;
		cin >> whatnode;
		cout << num[whatnode]<<"\n";
	}



}