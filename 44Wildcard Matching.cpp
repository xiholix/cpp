#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
         int ilen = s.size()+1;
         int jlen = p.size()+1;

         vector<vector<bool> > dp(ilen, vector<bool>(jlen, false));
         dp[0][0] = true;
         
         if(jlen>1){
             for(int j=0; j<jlen; j++){
                 if(p[j]=='*'){
                    for(int i=0;i<ilen; i++){
                        dp[i][j+1] = true;
                    }
                 }else{
                     break;
                 }
             }
            //  if(p[0]=='*'){
            //     for(int i=0; i<ilen; i++){
            //         dp[i][1] = true;
            //     }
            //  }
         }

         for(int i=1; i<ilen; i++){
             for(int j=1; j<jlen; j++){
                 if(dp[i-1][j-1]==true &&(s[i-1]==p[j-1] || p[j-1]=='*' || p[j-1]=='?')){
                     dp[i][j] = true;
                 }
                 if(dp[i][j]==true && p[j-1]=='*'){
                    for(int t=i+1; t<ilen; t++){
                        dp[t][j] = true;
                    }
                 }
                //  if(dp[i-1][j-1]==true && p[j-1]=='*'){
                //     for(int t=i; t<ilen; t++){
                //         dp[t][j] = true;
                //     }
                //  }

                 if(dp[i][j-1]==true && p[j-1]=='*'){
                     dp[i][j] = true;
                 }

             }
         }

        //  for(int i=0; i<ilen; i++){
        //      for(int j=0; j<jlen; j++){
        //          cout<<dp[i][j]<<" ";
        //      }
        //      cout<<endl;
        //  }

         return dp[ilen-1][jlen-1];
    }
};

int main(){
    Solution s;
    cout<<s.isMatch("zacabz", "*a?b*")<<endl;
    cout<<s.isMatch("aa", "*")<<endl;
    cout<<s.isMatch("aa", "aa*")<<endl;
    cout<<s.isMatch("", "*");
    cout<<s.isMatch("ho", "**ho");
}