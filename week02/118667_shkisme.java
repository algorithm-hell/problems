import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int len = queue1.length;
        int[] arr1 = new int[2 * len + 1];
        int[] arr2 = new int[2 * len + 1];
        
        for (int i= 0; i < len; i++){
            arr1[i] = queue1[i];
            arr2[i] = queue2[i];
        }
        for (int i= 0; i < len; i++){
            arr1[i + len] = queue2[i];
            arr2[i + len] = queue1[i];
        }
        
        int s1 = 0, s2 = 0, e1 = len - 1, e2 = len - 1;
        
        long sum1 = Arrays.stream(queue1).sum();
        long sum2 = Arrays.stream(queue2).sum();
        
        int cnt = 0;
        int last = 2 * len - 1;
        
        while(sum1 != sum2){
            if (cnt > (Math.abs(s1 - e1) + Math.abs(s2 - e2)) * 3) {
                return -1;
            }
            if (sum1 > sum2){
                sum1 -= arr1[s1];
                s1 = (s1 == last) ? 0 : s1 + 1;
                e2 = (e2 == last) ? 0 : e2 + 1;
                sum2 += arr2[e2];
                cnt++;
            }
            else if (sum1 < sum2){
                sum2 -= arr2[s2];
                s2 = (s2 == last) ? 0 : s2 + 1;
                e1 = (e1 == last) ? 0 : e1 + 1;
                sum1 += arr1[e1];
                cnt++;
            }
        }
        if (sum1 == sum2){
            return cnt;
        }
        return -1;
    }
}
