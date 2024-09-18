#include <iostream>
#include <vector>

using namespace std;

int board[8][8];
int result = 0;

vector<bool> column(8, false);              
vector<bool> primaryDiagonal(15, false);    
vector<bool> secondaryDiagonal(15, false);

void placeQueens(int row) {
    if (row == 8) {
        result++;
        return;
    }

    
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == 0 && !column[col] && !primaryDiagonal[row - col + 7] && !secondaryDiagonal[row + col]) {
            
            column[col] = primaryDiagonal[row - col + 7] = secondaryDiagonal[row + col] = true;
            placeQueens(row + 1);

            
            column[col] = primaryDiagonal[row - col + 7] = secondaryDiagonal[row + col] = false;
        }
    }
}

int main() {
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char cell;
            cin >> cell;
            if (cell == '*') {
                board[i][j] = 1; 
            } else {
                board[i][j] = 0;
            }
        }
    }

    
    placeQueens(0);
    cout << result << endl;

    return 0;
}
