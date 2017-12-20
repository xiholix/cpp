#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> max_right(nums.size(), 0);
        for(int i=nums.size()-1; i>=0; i--){
            max_right[i] = i+nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            cout<<max_right[i]<<" ";
        }
        cout<<endl;
        int begin=0;
        
        int step = 0;
        while(begin<nums.size()-1){
            int end = max_right[begin];
            
            step += 1;
            if(end>=nums.size()-1){
                break;
            }
            int max_v = 0;
            for(int i=begin+1; i<=end; i++){
                cout<<i<<endl;
                cout<<step<<endl;
                if(max_right[i]>max_v){
                    max_v = max_right[i];
                    begin = i;
                    // if(max_v >= nums.size()-1){
                    // //    step += 1;
                    //    cout<<"step is "<<step<<endl;
                    //    begin = nums.size();
                    //    break;
                    // }
                }
            }
        }
        
        return step;
    }
};

int main(){
    int a[] = {0};
    vector<int> t(a, a+1);

    Solution s;
    cout<<s.jump(t)<<endl;
}