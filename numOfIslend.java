import java.util.Scanner;

/*abstract



Example 1:

Input: grid = {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
}
Output: 1
Example 2:

Input: grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
}
Output: 3


*/

public class numOfIslend {

    
    public static void dfs(char [][] arr,int x,int y,boolean[][]visited)
    {
        if(visited[x][y] == true || arr[x][y]!='1' || x>=arr.length || y>=arr[0].length || x<0 || y<0 )
        {
            return;
        }
        visited[x][y] = true;
        if(x+1 <arr.length)
        	{
        		dfs(arr, x+1, y, visited);
        	}
        if(y+1 < arr[0].length)
        	{
        		dfs(arr, x, y+1, visited);
        	}
        if(x-1 >=0) 
        	{
        		dfs(arr, x-1, y, visited);
        	}
        if(y-1 >=0)
        	{
        		dfs(arr, x, y-1, visited);
        	}
    }
    public static void main(String[] args) {
    	
        char [][]arr = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
            
          };
          int n = arr.length;
          int m = arr[0].length;
          int ans = 0;
          boolean [][] visited = new boolean[n][m];
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                  if(arr[i][j]=='1')
                  {
                      dfs(arr, i, j, visited);
                      ans++;
                  }
              }
          }
          System.out.println(ans);
    }

}