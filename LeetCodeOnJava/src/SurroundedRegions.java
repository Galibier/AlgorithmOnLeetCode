import java.util.LinkedList;
import java.util.Queue;

public class SurroundedRegions {
    public void solve(char[][] board) {
        if (board.length == 0) {
            return;
        }
        int m = board.length, n = board[0].length;
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.add(new int[]{i, 0});
            }
            if (board[i][n - 1] == 'O') {
                q.add(new int[]{i, n - 1});
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.add(new int[]{0, j});
            }
            if (board[m - 1][j] == 'O') {
                q.add(new int[]{m - 1, j});
            }
        }
        int[] d = new int[]{0, 1, 0, -1, 0};
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            board[cur[0]][cur[1]] = 'C';
            for (int k = 0; k < 4; k++) {
                int x = cur[0] + d[k], y = cur[1] + d[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
                    continue;
                }
                q.add(new int[]{x, y});
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'C') {
                    board[i][j] = 'O';
                }
            }
        }
    }
}
