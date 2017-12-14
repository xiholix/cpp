#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> slens(s.size(), -1);
        slens[0] = 0;
        int t = 0;
        for(int i=1; i<s.size(); i++){
            t = slens[i-1];
        }

        return "h";  //没返回这个报错段错误核心已转存
    }
};

int main(){
    Solution s;
    s.longestPalindrome("dddddd");
}