import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static int a, b;
    static int ret = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int[] arr = new int[50002];

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            arr[i] = b;
        }

        Stack<Integer> st = new Stack<>();
        for(int i = 0; i <= N; i++){
            while(!st.empty() && st.peek() > arr[i]){
                ret += 1;
                st.pop();
            }

            if(!st.empty() && st.peek() == arr[i])
                continue;

            st.push(arr[i]);
        }
        System.out.println(ret);
    }
}
