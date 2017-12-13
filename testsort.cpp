#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <climits>

using namespace std;

int main(){
    int myints [] = {3,4,2,1};
    vector<int> datas (myints, myints+4);
    sort(datas.begin(), datas.end());
    copy(datas.begin(), datas.end(), ostream_iterator<int>(cout, " "));
    
    cout<<"hello"<<endl;
    cout<<INT_MAX<<endl;
    
}