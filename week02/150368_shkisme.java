import java.util.*;
import javafx.util.*;

class Solution {
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = {0, 0};
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(new Comparator<Pair<Integer, Integer>>() {
				    @Override
				    public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
				        if (p1.getKey().equals(p2.getKey())) {
				            return p2.getValue().compareTo(p1.getValue());
				        }
				        return p2.getKey().compareTo(p1.getKey());
				    }
				});
        
        int userCnt = users.length;
        int n = emoticons.length;
        int[] elements = {10, 20, 30, 40};
        
        List<List<Integer>> permutations = generatePermutations(elements, n);
       
        for (List<Integer> permutation : permutations) { // 퍼센트 순회
            int cnt = 0;
            int value =0;
            for (int i = 0; i < userCnt; i++){ // users 순회
                int tmpValue = 0;
                for (int j = 0; j < permutation.size(); j++){
                    if (users[i][0] <= permutation.get(j)){
                        tmpValue += (emoticons[j] - (emoticons[j] * (permutation.get(j) / 100.0)));
                        if (tmpValue >= users[i][1]){
                            cnt++;
                            tmpValue = 0;
                            break;
                        }
                    }
                }
                value += tmpValue; 
            }
            pq.add(new Pair<>(cnt, value));
        }
        answer[0] = pq.peek().getKey();
        answer[1] = pq.peek().getValue();
        return answer;
    }
    
    public List<List<Integer>> generatePermutations(int[] elements, int n) {
        List<List<Integer>> result = new ArrayList<>();
        generatePermutationsHelper(elements, n, new ArrayList<>(), result);
        return result;
    }

    private void generatePermutationsHelper(int[] elements, int n, List<Integer> current, List<List<Integer>> result) {
        if (current.size() == n) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = 0; i < elements.length; i++) {
            current.add(elements[i]);
            generatePermutationsHelper(elements, n, current, result);
            current.remove(current.size() - 1);
        }
    }
}
