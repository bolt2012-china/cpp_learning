#include <iostream>
#include <vector>
#include <set>

using namespace::std;
int main(){
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
        v.push_back(i);
    }
    set<int> s(v.begin(),v.end());
    multiset<int> ms(v.begin(),v.end());
    cout<<s.size() << " " <<ms.size()<<endl;
    return 0;
}
