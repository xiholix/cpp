#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k=nums1.size()+nums2.size();
        if(k%2==1){
            k = k/2+1;
            return findk(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), k);
        }else{
            k = k/2;
            double v1 = findk(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), k);
            double v2 = findk(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), k+1);
            return (v1+v2)/2;
        }
        
    }

    double findk(vector<int>::iterator nums1, int n, vector<int>::iterator nums2, int m, int k){
           if(n<m){
               return findk(nums2, m, nums1, n, k);
           }

           if(m==0){
               return nums1[k-1];
           }
           if(k==1){
               return min(nums1[0], nums2[0]);
           }

           int p2 = min(k/2, m);
           int p1 = k - p2;

           if(nums1[p1-1]<nums2[p2-1]){
               return findk(nums1+p1, n-p1, nums2, m, p2);
           }
           if(nums1[p1-1]>nums2[p2-1]){
               return findk(nums1, n, nums2+p2, m-p2, p1);
           }

           return nums1[p1-1];

    }
};
void test(){
    int b[] = {1,2,3,4};
    vector<int> a (b, b+4);
    vector<int>::iterator c = a.begin();
    c = c+1;
    cout<<c[1]<<endl;
}

int main(){
   test();
   return 0;
}