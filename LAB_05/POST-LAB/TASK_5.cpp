/*Implement a Sudoku solver using the backtracking technique. The program should take a
partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the puzzle.
Your algorithm should:
1. Find an empty cell.
2. Try placing a number from 1 to 9 in the empty cell.
3. Check if the number is valid in the current row, column, and 3x3 subgrid.
4. If valid, recursively call the function to solve the rest of the puzzle.
5. If the recursive call doesn't lead to a solution,
backtrack by resetting the cell to 0 and trying the next number.*/