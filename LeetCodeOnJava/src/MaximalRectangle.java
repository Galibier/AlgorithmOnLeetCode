import java.util.Stack;

public class MaximalRectangle {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) {
            return 0;
        }

        int n = matrix[0].length, max = 0;
        int[] heights = new int[n];

        for (char[] row : matrix) {
            for (int i = 0; i < n; i++) {
                if (row[i] == '1') {
                    heights[i] += 1;
                } else {
                    heights[i] = 0;
                }
            }
            max = Math.max(max, maxArea(heights));
        }
        return max;
    }

    private int maxArea(int[] heights) {
        int n = heights.length, max = 0;
        int[] left = new int[n], right = new int[n];
        left[0] = -1;
        right[n - 1] = n;

        for (int i = 1; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && heights[j] >= heights[i]) {
                j = left[j];
            }
            left[i] = j;
        }
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && heights[j] >= heights[i]) {
                j = right[j];
            }
            right[i] = j;
        }
        for (int i = 0; i < n; i++) {
            max = Math.max(max, heights[i] * (right[i] - left[i] - 1));
        }
        return max;
    }
}
