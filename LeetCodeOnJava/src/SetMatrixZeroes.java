import java.util.Stack;

public class SetMatrixZeroes {
    public void setZeroes(int[][] matrix) {
        Stack<Integer> rows = new Stack<>();
        Stack<Integer> cols = new Stack<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    rows.push(i);
                    cols.push(j);
                }
            }
        }

        while (!rows.empty()) {
            int row = rows.pop();
            int col = cols.pop();
            for (int i = 0; i < matrix[0].length; i++) {
                matrix[row][i] = 0;
            }
            for (int j = 0; j < matrix.length; j++) {
                matrix[j][col] = 0;
            }
        }
    }
}
