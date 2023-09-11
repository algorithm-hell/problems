import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) throws Exception {
    Scanner scan = new Scanner(System.in);

    int n = scan.nextInt();

    ArrayList<Integer>[] list = new ArrayList[n + 1]; // 연결된 노드 저장소
    int[] indegree = new int[n + 1]; // 진입차수
    int[] times = new int[n + 1]; // 시간
    for (int i = 1; i <= n; i++) {
      list[i] = new ArrayList<>();
      times[i] = scan.nextInt();
      indegree[i] = scan.nextInt();

      for (int j = 0; j < indegree[i]; j++) {
        list[scan.nextInt()].add(i);
      }
    }

    int[] cost = new int[n + 1];
    Queue<Integer> queue = new LinkedList<>();
    for (int i = 1; i <= n; i++) {
      if (indegree[i] == 0) { // 진입차수가 0인 것들을 넣음.
        queue.offer(i);
        cost[i] = times[i];
      }
    }

    while (!queue.isEmpty()) {
      int current = queue.poll();

      for (int i = 0; i < list[current].size(); i++) {
        int next = list[current].get(i);
        cost[next] = Math.max(cost[current] + times[next], cost[next]);
        // 사전의 작업이 모두 수행되어야 하므로 max 값을 구함.
        indegree[next]--;
        if (indegree[next] == 0) {
          queue.offer(next);
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = Math.max(ans, cost[i]);
    }
    System.out.println(ans);
  }
}
