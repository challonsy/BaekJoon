#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector <int> v;
void bt(int num);

int main()
{
    cin>>n>>m;
    bt(1);
    return 0;
}

void bt(int num){
    if (v.size()==m){
        for (int &k :v) cout<<k<<" ";
        cout<<"\n";
        return;
    }
    for (int i=num;i<=n;i++){
        v.push_back(i);
        bt(i+1);
        v.pop_back();
    }
    
    return;
}
