import java.util.PriorityQueue;

public class TrappingRainWaterII {
    public int trapRainWater(int[][] heightMap) {
        if (heightMap == null || heightMap.length <= 1 || heightMap[0].length <= 1) {
            return 0;
        }

        int m = heightMap.length;
        int n = heightMap[0].length;

        boolean[][] visited = new boolean[m][n];
        PriorityQueue<int[]> q = new PriorityQueue<>((c1, c2) -> c1[2] - c2[2]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    visited[i][j] = true;
                    q.offer(new int[]{i, j, heightMap[i][j]});
                }
            }
        }

        int res = 0;
        int[][] dirs = new int[][]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            for (int[] dir : dirs) {
                int x = cell[0] + dir[0];
                int y = cell[1] + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    visited[x][y] = true;
                    res += Math.max(0, cell[2] - heightMap[x][y]);
                    q.offer(new int[]{x, y, Math.max(cell[2], heightMap[x][y])});
                }
            }
        }
        return res;
    }
}
