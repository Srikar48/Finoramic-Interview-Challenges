/*
The input to the function is a vector that represents the current status of the sudoku.
*/

int Solution::isValidSudoku(const vector<string> &A) {
    
    unordered_map<char, int> row;
    unordered_map<char, int> col;
    unordered_map<char, int> grid[9];
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            
            if(A[i][j]!='.')                            //check if a no. is appearing more than once in a row
                if(row.find(A[i][j])==row.end())
                    row[A[i][j]]++;
                else
                    return 0;
            
            if(A[j][i]!='.')                            //check if a no. is appearing more than once in a column
                if(col.find(A[j][i])==col.end())
                    col[A[j][i]]++;
                else
                    return 0;
            
            if(A[i][j]!='.')                            //check if a no. is appearing more than once in a grid 
                if(grid[(i-i%3)+j/3].find(A[i][j])==grid[(i-i%3)+j/3].end())
                    grid[(i-i%3)+j/3].insert(make_pair(A[i][j],1));         //((i-i%3)+j/3) gives the grid no. that the elements belong to
                else
                    return 0;
            
        }
            
        row.clear();
        col.clear();
        
    }
            
    return 1;                                           //return 1 if it is a valid sudoku
    
}

