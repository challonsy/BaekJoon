#include <iostream>
#include <vector>
using namespace std;

int main(){
    int howmany;
    vector<int> nums;
    
    cin>>howmany;
    
    int max=-1000001;
    int min=1000001;
    
    for (int i=0;i<howmany;i++){
        int x; cin>>x;
        nums.push_back(x);
        max=max>x ? max:x;
        min=min<x ? min:x;
    }
    
    cout<<min<<" "<<max;
    
    return 0;
}