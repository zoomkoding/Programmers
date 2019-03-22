import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> hm = new HashMap<>();   
        for(int i = 0; i< completion.length; i++){
            if(hm.get(completion[i]) == null){
                hm.put(completion[i], 1);
            }
            else{
                int num = hm.get(completion[i]) + 1;
                hm.put(completion[i], num);
            }
        }
        
        for(int i = 0; i< participant.length; i++){
            if(hm.get(participant[i]) == null) return participant[i]; 
            int num = hm.get(participant[i]);
            if(num > 0){
                
                hm.put(participant[i], --num);
            }
            else{
                return participant[i];
            }
        }
        return answer;
    }
}
