#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<int> v;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(),v.end());
    
    for (int i=0;i<n;i++){
        cout<<v[i]<<'\n';
    }
    
    return 0;
}