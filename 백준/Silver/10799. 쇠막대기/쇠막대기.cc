#include <iostream>
#include<stack>
#include <string>

using namespace std;

stack <char> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	char a;
	cin >> a;
	s.push(a);
	string str;
	//while(getline(cin,str)!= NULL)

	while (cin>>a) {
		if (cin.eof())
			break;
		char last = s.top();
		if (a == '(')
			s.push(a);
		else if (a == ')' && last == '(') {
			s.pop();
			s.push('l');
		}
		else if (a == ')')
			s.push(a);
		
	}
	int pipe = 0;
	int total = 0;
	for (int i = 0; !s.empty(); i++) {
		
		char check = s.top();
		s.pop();
		if (check == ')')
			pipe++;
		else if (check == 'l')
			total += pipe;
		else if (check == '(') {
			total += 1;
			pipe--;
		}

	}

	cout << total;
}