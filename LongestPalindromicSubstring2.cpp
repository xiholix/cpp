#include<iostream>

using namespace std;

class Solution {
public:
    string padStr(string s){
        string pad_s = "#";
        for(int i=0; i<s.size(); i++){
            pad_s += s.substr(i, 1)+"#";
        }
        return pad_s;
    }

    string longestPalindrome(string s) {
        string pad_s = padStr(s);
        int *p = new int[pad_s.size()];
        p[0] = 0;
        
        int i=0;
        int t=0;
        int L=0;
        int R=0;
        int C=0;
        int mirror_i = 0;
        // cout<<pad_s<<endl;
        for(i=1; i<pad_s.size(); i++){
            mirror_i = 2*C - i;
            if(mirror_i<=L+1 || p[mirror_i]+i>R){
               t = 0;
               C = i;
               while(C-t>=0 && pad_s[C-t]==pad_s[C+t]){
                   t += 1;
               }
               p[C] = t-1;
               L = C - p[C];
               R = C + p[C];
            }else{
                p[i] = p[mirror_i];
            }
        }
        int max_len = 0;
        int index = 0; 
        for(i=0; i<pad_s.size(); i++){
            cout<<p[i]<<" ";
            if(p[i]>max_len){
                max_len = p[i];
                index = i;
            }
        }
        string result = pad_s.substr(index-max_len, 2*max_len+1);
        string r = "";
        for(int i=1; i<result.size()-1; i+=2){
              r += result.substr(i, 1);
        }
        return r;
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("dddddd");
}