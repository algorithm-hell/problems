import static java.lang.Integer.MAX_VALUE;
import static java.lang.Integer.parseInt;
import static java.lang.System.in;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(in));

    int N = parseInt(br.readLine());
    String[] input = br.readLine().split(" ");

    int[] nums = new int[N];
    for (int i = 0; i < N; i++) {
      nums[i] = Integer.parseInt(input[i]);
    }

    Arrays.sort(nums);

    int s = 0, e = N - 1;

    if (nums[s] >= 0) {
      System.out.println(nums[0] + " " + nums[1]);
    } else if (nums[e] <= 0) {
      System.out.println(nums[N - 2] + " " + nums[N - 1]);
    } else {
      int MIN_VALUE = MAX_VALUE;
      int a1 = nums[s], a2 = nums[e];

      while (s < e) {
        int tmp = nums[s] + nums[e];
        if (tmp > 0) {
          if (Math.abs(tmp) < MIN_VALUE) {
            MIN_VALUE = Math.abs(tmp);
            a1 = nums[s];
            a2 = nums[e];
          }
          e--;
        } else if (tmp <= 0) {
          if (Math.abs(tmp) < MIN_VALUE) {
            MIN_VALUE = Math.abs(tmp);
            a1 = nums[s];
            a2 = nums[e];
          }
          s++;
        }
      }

      System.out.println(a1 + " " + a2);
    }
  }
}
