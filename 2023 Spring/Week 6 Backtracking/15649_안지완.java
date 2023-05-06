import java.io.*;
import java.util.StringTokenizer;

public class Main{

    static boolean[] visited;
    static int[] arr;
    static int n;
    static int m;

    public static void sol(int depth){
        if (depth == m){
            for (int i =0 ; i < m ; i++){
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }

        for(int i =0; i < n; i ++){
            if (!visited[i]){
                visited[i] = true;
                arr[depth] = i+1;
                sol(depth+1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        visited = new boolean[n];
        arr = new int[n];

        sol(0);

    }
}