#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& sudoku, int row, int col, int val) {
    
    for (int j = 0; j < 9; j++) {
        if (sudoku[row][j] == val) return false;
    }
    
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == val) return false;
    }
    
    int r = (row / 3) * 3, c = (col / 3) * 3;
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            if (sudoku[i][j] == val) return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == -1) { 
                for (int num = 1; num <= 9; num++) {
                    if (isValid(sudoku, i, j, num)) {
                        sudoku[i][j] = num;
                        if (solveSudoku(sudoku)) return true;
                        sudoku[i][j] = -1; 
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    vector<vector<int>> sudoku(9, vector<int>(9));
    cout << "give number if it exists else give input as -1" << endl;
	cout << "start input" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
    if (solveSudoku(sudoku)) {
        cout << "Solved Sudoku:" << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists!" << endl;
    }
    return 0;
}