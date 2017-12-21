#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        double current = x;
        if(x==0){
            return 0;
        }
        if(n<0){   // -2147483648取负数还是-2147483648，应该是溢出
            current = 1/x;
        }

        while(n){
            if(n%2==1||n%2==-1){
                result = result * current;
            }
            
            current =  current*current;
            n /= 2;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.myPow(2, -2147483648);
}