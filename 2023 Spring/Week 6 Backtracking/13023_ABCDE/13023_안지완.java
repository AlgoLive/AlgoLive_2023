import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main{
    static int n,m;
    static boolean[] visited;
    static ArrayList<ArrayList<Integer>> friend = new ArrayList<>();

    public static boolean sol(int depth, int personNum){
        if (depth == 5){
            System.out.println(1);
            System.exit(0);
        }

        for (int i =0; i< friend.get(personNum).size(); i++){
            int newFriend = friend.get(personNum).get(i);
            if(!visited[newFriend]){
                visited[newFriend] = true;
                sol(depth+1, friend.get(personNum).get(i));
                visited[newFriend] = false;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a,b;

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        visited = new boolean[n];

        for (int i =0 ; i < n ;i++){
            friend.add(new ArrayList<Integer>());
        }


        for (int i =0 ;i < m; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            friend.get(a).add(b);
            friend.get(b).add(a);
        }

        for(int i = 0; i < n ;i++){
            if(sol(0,i)){
                System.out.println(1);
                System.exit(0);
            }
        }
        System.out.println(0);
        System.exit(0);
    }
}