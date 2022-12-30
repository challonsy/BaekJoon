#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<map>

using namespace std;

int wordnum, length;

class WordInfo {
public:
	WordInfo() { rate = 0;	wordlength = 0; }
	int rate;
	int wordlength;
};

void memorize(map<string, WordInfo> &wordList) {
	string thisword;
	for (int i = 0; i < wordnum; i++) {
		cin >> thisword;
		if (thisword.length() < length)
			continue;
		else {
			WordInfo w;
			map<string, WordInfo>::iterator it = wordList.find(thisword);
			if (it == wordList.end()) {
				w.rate++;
				w.wordlength = thisword.length();
				wordList.insert({ thisword,w });
			}
			else
				(it->second.rate)++;
				
		}
	}
}

bool cmp(pair<string, WordInfo> p1, pair<string, WordInfo> p2) {
	if (p1.second.rate == p2.second.rate) {
		if (p1.second.wordlength == p2.second.wordlength)
			return p1.first < p2.first;
		else
			return p1.second.wordlength > p2.second.wordlength;
	}
	else
		return p1.second.rate > p2.second.rate;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, WordInfo> m;

	cin >> wordnum >> length;
	
	memorize(m);

	vector<pair<string, WordInfo>> v(m.begin(),m.end());
	sort(v.begin(), v.end(), cmp);

	for (vector<pair<string,WordInfo>>::iterator it = v.begin(); it !=v.end(); it++) {
		cout << it->first << "\n";
	}
}