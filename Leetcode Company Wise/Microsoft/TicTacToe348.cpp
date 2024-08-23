// Intuition and approach -

// Here first count the number of x and o and if cntx != cnto + 1 , then its not valid as x moves first hence it should be one more than o. 
// Now check for win condition , both cant win simultaneously and return true for rest of the cases.



class Solution {
  public:
    
    vector<vector<int>>win =  { {0,1,2} , {3,4,5} , {6,7,8} , {0 , 3 , 6} , {1,4,7} , { 2,5,8}, {0,4,8}, {2,4,6}};
    
    int isWin(char board[] , char c){
        int cnt = 0; 
        for(int i = 0; i<8; i++){
            if(board[win[i][0]] == c && board[win[i][1]] == c && board[win[i][2]] == c) cnt++;
        }
        return cnt;
    }
    
    bool isValid(char board[9]) {
        int cntx = 0; int cnto = 0;
        for(int i = 0; i<9; i++){
            if(board[i] == 'X') cntx++;
            else if(board[i] == 'O') cnto++;
        }
        
        if(cntx != cnto+1) return false;
        
        int xwin = isWin(board , 'X');
        int owin = isWin(board , 'O');
        
        if(!xwin && owin == 1) return true;
        if(!owin && xwin == 1) return true;
        if(!owin && !xwin) return true;
        return false;
    }
};