#include<iostream>;
#include <vector>

using namespace std;

int m, n, q, fnum;
vector<int>* arr;


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> m;

	arr = new vector<int>[m + 1];

	for (int i = 1; i <= m; i++) {
		cin >> fnum;
		arr[i].push_back(fnum);
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 1; j <= m; j++) {
			arr[j].push_back(arr[arr[j][i]][i]);
		}
	}

	cin >> q;

	while (q--)
	{
		cin >> n >> fnum;
		for (int i = 0; n!=0; i++) {
			if ((n % 2) == 1)
				fnum = arr[fnum][i];
			n= n >> 1;
		}

		cout << fnum << '\n';
	}
}