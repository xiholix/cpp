#include<cstdio>
#include<climits>
using namespace std;

int main(){
    int n = 0;
    int tl = 0;
    int big3[3] = {INT_MAX, INT_MAX, INT_MAX};
    scanf("%d", &n);
    tl = n;
    int t=0;
    int i=2;
    while(n--){
        scanf("%d", &t);

        if(big3[2]<t){
            continue;
        }
        i = 2;
        while(i>0){
            if(big3[i-1]==INT_MAX || big3[i-1]<t){
                big3[i] = big3[i-1];
                if(i==1)
                   break;
            }else{
                break;
            }
            i -= 1;
        }
        printf("%d\n", t);
        printf("%d\n", i);
        big3[i-1] = t;
        for(int i=0; i<3; i++){
            printf("%d\n", big3[i]);
        }
    }
    
    printf("%d", big3[2]);
   
    return 0;
}