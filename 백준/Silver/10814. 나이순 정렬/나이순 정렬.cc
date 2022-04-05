#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person{
    int age;
    string name;
    int number;
};

bool compare(person &a, person &b){
    if (a.age != b.age)
        return a.age<b.age;
    else
        return a.number<b.number;
}

int main(){
    int n;
    cin>>n;
    vector<person> v;
    for (int i=0;i<n;i++){
        person x; cin>>x.age>>x.name;
        x.number=i;
        v.push_back(x);
    }
    
    sort(v.begin(),v.end(),compare);
    
    for (int i=0;i<n;i++)
        cout<<v[i].age<<' '<<v[i].name<<'\n';
    
    return 0;
}