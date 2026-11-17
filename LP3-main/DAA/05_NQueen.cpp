#include <iostream>
#include <vector>
using namespace std;

//TC = O(n!)
//SC = O(1) but stack O(n)

vector<vector<string>> result;
int N;

bool isValid(vector<string> &board, int row, int col) {
    //upward check
    for(int i = row-1; i >= 0; i--) {
        if(board[i][col] == 'Q') return false;
    }

    //diagonal check
    for(int i = row-1, j = col+1; i >= 0 && j < N; i--, j++) {
        if(board[i][j] == 'Q') return false;
    }

    //antidiagonal check
    for(int i = row-1, j = col-1; i>=0 && j>=0; i--,j--) {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void solve(vector<string> board, int row) {
    if(row >= N) {
        result.push_back(board);
        return;
    }

    for(int col = 0; col < N; col++) {
        if(isValid(board, row, col)) {
            board[row][col] = 'Q';
            solve(board, row+1);
            //backtracking
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveQueens(int n) {
    result.clear();
    N = n;
    vector<string> board(n, string(n,'.'));
    solve(board, 0);
    return result;
}

int main() {
    int n = 4;
    vector<vector<string>> ans = solveQueens(n);
    for(int i = 0; i < ans.size(); i++) {
        cout<<"\nSolution : "<<i+1<<endl;
        for(int j = 0; j < n; j++) {
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
}