#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool> > slens(s.size());
        for(int i=0; i<s.size(); i++){
            vector<bool> t (s.size(), false);
            t[i] = true;
            slens[i]=t;
        }

        for(int i=1; i<s.size(); i++){
            if(s[i]==s[i-1]){
                slens[i][i-1]=true;
            }
            for(int j=i-1; j>0; j--){
                if(slens[i-1][j]==true && s[i]==s[j-1]){
                    slens[i][j-1] = true;
                }
            }
        }
        
        // for(int i=0; i<s.size(); i++){
        //     for(int j =0; j<s.size(); j++){
        //         cout<<slens[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int max_len = 0;
        int t_len  = 0;
        int l_index =0;
        int r_index = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(slens[i][j]==true){
                    t_len = i-j+1;
                    if(t_len>max_len){
                        max_len = t_len;
                        l_index = j;
                        r_index = i;
                    }
                }
            }
        }
      
        // cout<<s.substr(l_index, max_len);
        // cout<<max_len<<endl;      
        return s.substr(l_index, max_len);  //没返回这个报错段错误核心已转存
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("dddddd");
}