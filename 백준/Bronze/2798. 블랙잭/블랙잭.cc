#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int n, m;
    vector<int> cards;
    
    cin>>n>>m;
    
    for (int i=0;i<n;i++){
        int x; cin>>x;
        cards.push_back(x);
    }
    int max=0;
    
    for (int i=0;i<=n-3;i++){
        for(int j=i+1;j<=n-2;j++){
            for(int k=j+1;k<=n-1;k++){
                int addresult=cards[i]+cards[j]+cards[k];
                if (addresult<=m)
                    max=max>addresult ? max:addresult;
            }
        }
    }
    
    cout<<max;
}