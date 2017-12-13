#include<iostream>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int tmp_len = 0;
        int not_dup_len = 0;
        int j=0;
        for(int i=0; i<s.size(); i++){
            not_dup_len = 0;
            j = 0;
            while(j<tmp_len){
               if(s.at(i)==s.at(i-j-1)){
                   break;
               }else{
                   j += 1;
               }
           }
           tmp_len = j+1;
           if(tmp_len>max_len){
               max_len = tmp_len;
           }

        }

        // cout<<max_len<<endl;
        return max_len;
    }
};

int main(){
    Solution s;
    s.lengthOfLongestSubstring("");

    return 0;
}