#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> ability(n);
    int tn = n;
    while(tn>0){
        int tb;
        cin>>tb;
        ability[n-tn] = tb;
        tn -= 1;
    }
    
    int k, d;
    cin >> k;
    cin >> d;
    
    vector<vector<long long> > dp_max(n+1, vector<long long>(k+1, 1));
    vector<vector<long long> > dp_min(n+1, vector<long long>(k+1, 1));
    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<k+1; j++){
    //         cout<<dp_max[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    dp_max[1][1] = ability[0];
    dp_min[1][1] = ability[0];
    int begin_j, end_j;
    long long max_product, min_product, max_t, min_t;
    for(int i=2; i<n+1; i++){
        for(int j=1; j<min(k+1, i+1); j++){
            begin_j = max(i-d, 1);
            begin_j = max(begin_j, j-1);
            end_j = i-1;
            min_product = LONG_MAX;
            max_product = LONG_MIN;
            // if(i==2 && j==1){
            //     cout<<"DDDDDDDDDDDDDDD"<<endl;
            //     cout<<begin_j;
            //     cout<<end_j;
            // }
            for(int t=begin_j; t<=end_j; t++){
                max_t = dp_max[t][j-1] * ability[i-1];
                min_t = dp_min[t][j-1] * ability[i-1];
                // if(i==2 && j==1){
                //     cout<<"DDDDDDDDDDDDDDD"<<endl;
                //     cout<<max_t<<endl;
                //     cout<<min_t<<endl;
                //     cout<<dp_max[t][j-1]<<endl;
                //     cout<<dp_min[t][j-1]<<endl;
                //     cout<<ability[i];

                // }
                if(max_t>min_t){
                    if(max_t>max_product){
                        max_product = max_t;
                    }
                    if(min_t<min_product){
                        min_product = min_t;
                    }
                }else{
                    if(max_t<min_product){
                        min_product = max_t;
                    }
                    if(min_t>max_product){
                        max_product = min_t;
                    }
                }
            }
            
            dp_max[i][j] = max_product;
            dp_min[i][j] = min_product;
            
        }
    }
    // cout<<"************"<<endl;
    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<k+1; j++){
    //         cout<<dp_max[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"************"<<endl;
    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<k+1; j++){
    //         cout<<dp_min[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    long long max_value = LONG_MIN;
    if(n<k){
        cout<< 0;
    }else{
        for(int i=k; i<n+1; i++){
            if(max_value<dp_max[i][k]){
                max_value = dp_max[i][k];
            }
        }
        cout<<max_value<<endl;
    }
    // cout<<LONG_MAX;
}