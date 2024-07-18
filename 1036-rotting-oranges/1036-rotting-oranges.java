class Solution {
    public static class Pair {
        int i = 0;
        int j = 0;
        Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
    
    public static int[] di = new int[]{0, 1, 0, -1};
    public static int[] dj = new int[]{1, 0, -1, 0};
    public final static int INF = 1000000007;
    
    public static void bfs(int[][] grid, int[][] dist, int n, int m) {
        Queue<Pair> queue = new LinkedList<>();
        for (int is = 0; is < n; is++) {
            for (int js = 0; js < m; js++) {
                dist[is][js] = INF;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new Pair(i, j));
                    dist[i][j] = 0;
                }
            }
        }
        
        while (!queue.isEmpty()) {
            Pair cur = queue.remove();
            for (int h = 0; h < 4; h++) {
                int toi = cur.i + di[h];
                int toj = cur.j + dj[h];
                if (toi >= 0 && toi < n && toj >= 0 && toj < m &&
                    dist[toi][toj] > dist[cur.i][cur.j] + 1 &&
                    grid[toi][toj] == 1) {
                    dist[toi][toj] = dist[cur.i][cur.j] + 1;
                    queue.add(new Pair(toi, toj));
                }
            }
        }
    }
    
    public int orangesRotting(int[][] grid) {
        final int n = grid.length;
        final int m = grid[0].length;
        int[][] dist = new int[n][m];
        bfs(grid, dist, n, m);
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && dist[i][j] > result) {
                    result = dist[i][j];
                }
            }
        }
        
        return result != INF ? result : -1;
    }
}