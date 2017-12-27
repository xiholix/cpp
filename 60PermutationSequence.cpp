#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

class Solution {
public:
    void permutated(vector<int>& elem, int n, int k, int offset){
        // cout<<"n is "<<n<<" k is "<<k<<" offset is "<<offset<<endl;
        if(n-1==offset){
            return;
        }
        
        int permutate_nums = n-offset-1;
        int product = 1;
        for(int i=1; i<=permutate_nums; i++){  //之前这里少了一个等于号，导致程序出现了bug
            product *= i;
        }
        
        int select_index = offset;
        while(k>product){
            select_index += 1;
            k -= product;
        }
        // cout<<"select_index "<<select_index<<" product is "<<product<<endl;
        int t = elem[select_index];
        for(int i=select_index; i>offset; i--){
            elem[i] = elem[i-1];
        }
        elem[offset] = t;
        
        return permutated(elem, n, k, offset+1);
    }
    
    string getPermutation(int n, int k) {
        vector<int> elems(n);
        for(int i=0; i<n; i++){
            elems[i] = i+1;
        }
        // copy(elems.begin(), elems.end(), ostream_iterator<int>(cout, " "));
        // cout<<"finish"<<endl;
        permutated(elems, n, k, 0);
        string s;
        for(int i=0; i<elems.size(); i++){
            // cout<<"s"<<endl;
            s += (elems[i]+'0');
        }
        // copy(elems.begin(), elems.end(), ostream_iterator<int>(cout, " "));
        // cout<<endl;
        // cout<<s<<endl;
        return s;
    }
};

int main(){
    Solution s;
    cout<<s.getPermutation(3, 6)<<endl;
    
}