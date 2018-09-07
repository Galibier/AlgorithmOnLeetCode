public class WordSearch {
    public boolean exist(char[][] board, String word) {
        char[] w = word.toCharArray();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (exist(board, i, j, w, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean exist(char[][] board, int i, int j, char[] word, int idx) {
        if (idx == word.length) {
            return true;
        }
        if (i < 0 || j < 0 || i == board.length || j == board[i].length) {
            return false;
        }
        if (board[i][j] != word[idx]) {
            return false;
        }
        board[i][j] ^= 256;
        boolean exist = exist(board, i, j + 1, word, idx + 1)
                || exist(board, i, j - 1, word, idx + 1)
                || exist(board, i + 1, j, word, idx + 1)
                || exist(board, i - 1, j, word, idx + 1);
        board[i][j] ^= 256;
        return exist;
    }
}
