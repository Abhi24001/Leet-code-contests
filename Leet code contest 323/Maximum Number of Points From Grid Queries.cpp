class Solution { 
    public int[] maxPoints(int[][] grid, int[] queries) { 
  int max = 0; 
  int count = 0; 
  int m = grid.length; 
  int n = grid[0].length; 
  boolean[][] marked = new boolean[m][n]; 
  int[] arr = new int[1000001]; 
  PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> grid[a[0]][a[1]] - grid[b[0]][b[1]]); 
  pq.add(new int[] { 0, 0 }); 
  while (!pq.isEmpty()) { 
   int[] del = pq.remove(); 
   int i = del[0]; 
   int j = del[1]; 
   if (marked[i][j]) 
    continue; 
   marked[i][j] = true; 
   max = Math.max(max, grid[i][j]); 
   if (grid[i][j] == max) { 
    count++; 
    arr[grid[i][j]]++; 
   }else { 
    arr[max]++; 
   } 
   if (i - 1 >= 0) 
    pq.add(new int[] { i - 1, j }); 
   if (j - 1 >= 0) 
    pq.add(new int[] { i, j - 1 }); 
   if (i + 1 < m) 
    pq.add(new int[] { i + 1, j }); 
   if (j + 1 < n) 
    pq.add(new int[] { i, j + 1 }); 
  } 
  for (int i = 1; i < arr.length; i++) { 
   arr[i] += arr[i - 1]; 
  } 
  int[] ans = new int[queries.length]; 
  for (int i = 0; i < queries.length; i++) { 
   ans[i] = arr[queries[i] - 1]; 
  } 
  return ans; 
} 
}
