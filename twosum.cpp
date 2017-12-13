#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> t(nums);
        sort(nums.begin(), nums.end());
        copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
        copy(t.begin(), t.end(), ostream_iterator<int>(cout, " "));
        int i=0;
        int j= nums.size()-1;       
        vector<int> result(2);
        while(i<j){
           if(nums[i]+nums[j]==target){
               result[0] = nums[i];
               result[1] = nums[j];
               for(int i=0; i<nums.size(); i++){
                   if(t[i]==result[0]){
                       result[0]=i;
                       break;
                   }
               }
               for(int i=0; i<nums.size(); i++){
                if(t[i]==result[1]){
                    result[1]=i;
                    break;
                }
            }
               return result;
           }else{
               if(nums[i]+nums[j]<target){
                  i += 1;
               }else{
                  j -= 1;
               }
           }
        }
        
        return result;
    }
};

int main(){
    Solution a;
    int datas[] = {2,1,3,4};
    vector<int> t (datas, datas+4);
    t = a.twoSum(t, 5);
    copy(t.begin(), t.end(), ostream_iterator<int>(cout, " "));
    return 0;
}