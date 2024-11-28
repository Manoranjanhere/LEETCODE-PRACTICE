class Solution:
    def minimumObstacles(self,grid):
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        # Initialize the priority queue with the starting cell
        pq = [(grid[0][0], 0, 0)]
        dist = [[float('inf')] * n for _ in range(m)]
        dist[0][0] = grid[0][0]
        
        while pq:
            cost, x, y = heapq.heappop(pq)
            
            # If we have reached the target cell, return the cost
            if (x, y) == (m-1, n-1):
                return cost

            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    new_cost = cost + grid[nx][ny]
                    if new_cost < dist[nx][ny]:
                        dist[nx][ny] = new_cost
                        heapq.heappush(pq, (new_cost, nx, ny))
        
        return -1  
