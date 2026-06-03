class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int row = 0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(backtrack(board,word,row,col,0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int rows;
    int cols;

    vector<pair<int,int>> directions = {
        {1,0},{-1,0},{0,1},{0,-1}
    };

    bool backtrack(vector<vector<char>>& board,const string& word,int row,int col, int index){
        if(index==word.size()){
            return true;
        }

        if(row<0 || row>=rows || col<0 || col>=cols||board[row][col]!=word[index]){
            return false;
        }

        char original = board[row][col];
        board[row][col]='#';

        for(auto& [dr,dc]:directions){
            int nextRow = row+dr;
            int nextCol = col+dc;

            if(backtrack(board,word,nextRow,nextCol,index+1)){
                board[row][col]=original;
                return true;
            }
        }
        board[row][col]=original;
        return false;


    }
};
