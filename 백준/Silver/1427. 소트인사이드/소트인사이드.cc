#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string num;
    cin>>num;
    
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    
    cout<<num;
    
    return 0;
}