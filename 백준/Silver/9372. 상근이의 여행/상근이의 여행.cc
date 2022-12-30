#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcasenum, flightnum;
	int* nations;
	
	cin >> testcasenum;
	
	nations = new int[testcasenum];
	
	for (int i = 0; i < testcasenum; i++) {
		int nationnum;
		cin >> nationnum >> flightnum;
		nations[i] = nationnum;
		
		for (int j = 0; j < flightnum; j++) {
			int na1, na2;
			cin >> na1>>na2;
		}
	}

	for (int i = 0; i < testcasenum; i++) {
		cout << nations[i] - 1 << "\n";
	}
}