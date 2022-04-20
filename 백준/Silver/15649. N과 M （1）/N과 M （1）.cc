#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector <int> v;
bool visited[9];
void bt(void);

int main(){
    cin>>n>>m;
    bt();
    
    return 0;
}

void bt(){
    if (v.size()==m){
        for (int k :v)  cout<<k<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if (!visited[i]){
            v.push_back(i);
            visited[i]=1;
            bt();
            visited[i]=0;
            v.pop_back();
        }
    }
}