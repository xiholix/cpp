#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int ilen = s.size()+1;
        int jlen = p.size()+1;
        
        // if(jlen==0){
        //     return ilen!=0;
        // }
        

        vector<vector<bool> > dp(ilen, vector<bool>(jlen, false));
        // if(p[0]=='.' || s[0]==p[0]){
        //     dp[0][0] = true;
        // }
        dp[0][0] = true;
        for(int i=1; i<jlen; i+=2){
            if(p[i]!='*'){
                break;
            }else{
                dp[0][i+1] = true;
            }
        }
        if(ilen==1){
            // int i=1;
            // for(i=1; i<jlen; i+=2){
            //     if(p[i]!='*'){
            //         break;
            //     }else{
            //         dp[0][i+1] = true;
            //     }
            // }
            
            // if(i>=jlen && jlen%2==1){
            //     return true;
            // }else{
            //     return false;
            // }
            return dp[0][jlen-1];
        }
        for(int i=1; i<ilen; i++){
            for(int j=1; j<jlen; j++){
                if(dp[i-1][j-1]==true && (s[i-1]==p[j-1] || p[j-1]=='.')){
                    dp[i][j] = true;
                    continue;
                }
                
                if(j-2>=0 && dp[i-1][j]==true && (p[j-1]=='*'&&(p[j-2]==s[i-1]||p[j-2]=='.'))){ //因为j>1
                    dp[i][j] = true;
                    continue;
                }

                if(j-2>=0 && dp[i][j-2]==true && (p[j-1]=='*')){
                    dp[i][j] = true;
                    continue;
                }
            }
        }

        for(int i=0; i<ilen; i++){
            for(int j=0; j<jlen; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return dp[ilen-1][jlen-1];
    }
};

int main(){
    Solution s;
    cout<<s.isMatch("", "a*a");
    return 0;
}