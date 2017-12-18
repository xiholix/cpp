#include<iostream>
#include<cstdio>
#include<set>
#include<string>
using namespace std;

int main(){
   
    set<string> t;
    string s;
    while(cin>>s){
        string s2 = s;
        t.insert(s2);
    }
    cout<<"hell"<<endl;
    cout<<t.size()<<endl;
    return 0;
}