import java.util.*;

class Solution {
    static int endPoint;
    static int[][] arr;
    static int curr = 1;
    static int x = 0, y = 0;
    
    public int[] solution(int n) {
        List<Integer> list = new ArrayList<>();
        endPoint = n * (n + 1) / 2;
        arr = new int[n][n];
        int depth = n;
        
        while(true){
            if (fill(depth) == true){
                break;
            }
            x += 1;
            y += 2;
            depth -= 3;
        }
        
        for (int[] a : arr){
            for (int i : a){
                if (i != 0){
                    list.add(i);
                }
            }
        }
        
        int[] answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
    
    public boolean fill(int depth){
        int currX = 0, currY = 0;
        
        for (int i = y; i < depth + y; i++){
            arr[i][x] = curr++;
            if (curr > endPoint) return true;
            currY = i; // 변경된 Y값 저장
        }
        for (int i = x + 1; i < depth + x; i++){
            arr[currY][i] = curr++;
            if (curr > endPoint) return true;
            currX = i; // 변경된 X값 저장
        }
        for (int i = currY - 1; i > y; i--){
            arr[i][currX] = curr++;
            if (curr > endPoint) return true;
        }
        return false;
    }
}
