#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool is_valid(vector<vector<int> >& sign, int index){
        bool result=true;
        for(int i=index; i<sign.size(); i++){
            result = false;
            for(int j=0; j<sign.size(); j++){
                if(sign[j][i]==0){
                    result = true;
                }
            }
            if(result==false){
                return false;
            }
        }
        
        return true;
    }
    
    void place_queue(vector<vector<int> >& sign, int row, int column, int gap){
        for(int i=0; i<sign.size(); i++){
            sign[row][i] += gap;
            sign[i][column] += gap;
        }
        sign[row][column] -= gap;
        
        int r=row-1, c=column-1;
        while(r>=0 && c>=0){
            sign[r][c] += gap;
            r-=1;
            c-=1;
        }
        
        r=row+1;
        c=column+1;
        while(c<sign.size() && r<sign.size()){
            sign[r][c] += gap;
            c+=1;
            r+=1;
        }
        
        r=row-1;
        c=column+1;
        while(r>=0 && c<sign.size()){
            sign[r][c]+=gap;
            r -= 1;
            c += 1;
        }
        
        r=row+1;
        c=column-1;
        while(c>=0 && r<sign.size()){
            sign[r][c] += gap;
            r -= 1;
            c += 1;
        }
        
    }
    
    
    void feed_board(int index, vector<string> &board, vector<vector<int> >& sign, vector<vector<string> >&results){
        for(int i=index; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                if(sign[j][i]==0){
                    place_queue(sign, j, i, 1);
                    bool valid = is_valid(sign, i+1);
                    if(valid==true){
                        board[j][i] = 'Q';
                        if(index+1<sign.size()){
                           feed_board(index+1, board, sign, results);
                        }else{
                            vector<string> t(board.begin(), board.end());
                            results.push_back(t);
                        }
                        board[j][i] = '.';
                       
                    }
                    place_queue(sign, j, i, -1);
                }
            }
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > results;
        vector<string> board(n, string(n, '.'));
        vector<vector<int> > sign(n, vector<int>(n, 0));
        feed_board(0, board, sign, results);
        return results;
    }
};

int main(){
    Solution s;
    vector<vector<string> > result;
    result = s.solveNQueens(9);
    cout<<result.size();
}