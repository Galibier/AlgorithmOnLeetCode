import java.util.ArrayList;
import java.util.List;

public class SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix.length == 0) {
            return res;
        }

        int rowBegin = 0;
        int rowEnd = matrix.length - 1;
        int colBegin = 0;
        int colEnd = matrix[0].length - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int j = colBegin; j <= colEnd; j++) {
                res.add(matrix[rowBegin][j]);
            }
            rowBegin++;
            for (int j = rowBegin; j <= rowEnd; j++) {
                res.add(matrix[j][colEnd]);
            }
            colEnd--;

            for (int j = colEnd; j >= colBegin && rowBegin <= rowEnd; j--) {
                res.add(matrix[rowEnd][j]);
            }
            rowEnd--;

            for (int j = rowEnd; j >= rowBegin && colBegin <= colEnd; j--) {
                res.add(matrix[j][colBegin]);
            }
            colBegin++;
        }
        return res;
    }
}
