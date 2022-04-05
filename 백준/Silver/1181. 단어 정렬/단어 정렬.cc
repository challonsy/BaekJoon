#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string &a, string &b){
    if (a.length() != b.length())
        return a.length()<b.length();
    else
        return a<b;
}

int main(){
    int n;
    cin>>n;
    vector<string> word;
    for (int i=0;i<n;i++){
        string x; cin>>x;
        word.push_back(x);
    }
    
    sort(word.begin(),word.end(),compare);
    
    for (int i=0;i<n;i++){
        if (word[i] != word[i+1])
            cout<<word[i]<<'\n';
    }
    
    return 0;
}