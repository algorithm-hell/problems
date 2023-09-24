import java.util.*;

class Solution {
    
    static Map<String,String> m = new HashMap<>();
    static Map<String,Integer> result = new HashMap<>();
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        
        for (int i = 0; i < enroll.length; i++){
            m.put(enroll[i], referral[i]);
            result.put(enroll[i], 0);
        }
        
        for (int i = 0; i < seller.length; i++){
            search(seller[i], amount[i] * 100);
        }
        
        for (int i = 0; i < enroll.length; i++){
            answer[i] = result.get(enroll[i]);
        }
        
        return answer;
    }
    
    public void search(String str, int a){
        if (str.equals("-")) {
            return;
        }
        int value = result.get(str);
        result.put(str, value + a - (a / 10));
        String r = m.get(str);
        if(a / 10 != 0) search(r, a / 10);
    }
}
