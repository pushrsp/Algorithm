import java.util.*;

class Solution {
    
    private final List<Word> words = new ArrayList<>();
    private final int[] prefix = new int[200_001];
    private final boolean[] isSpoiler = new boolean[200_001];
    
    static class Word {
        String word;
        int start, end;
        
        Word(String word, int start, int end) {
            this.word = word;
            this.start = start;
            this.end = end;
        }
        
        boolean inRange(int start, int end) {
            for(int i = start; i <= end; i++) {
                if(i == this.start || i == this.end) {
                    return true;
                }
            }
            return false;
        }
    }
    
    public int solution(String message, int[][] spoiler_ranges) {
        Arrays.fill(prefix, -1);
        int i = 0;
        for(i = 0; i < message.length(); i++) {
            int start = i;
            String s = "";
            for(int j = i; j < message.length(); j++) {
                if(message.charAt(j) == ' ') {
                    i = j;
                    break;
                } else if(j == message.length() - 1) {
                    i = message.length();
                    s += message.charAt(j);
                    break;
                } else {
                    s += message.charAt(j);
                }
            }
            
            words.add(new Word(s, start, i - 1));
        }
        
        for(i = 0; i < words.size(); i++) {
            for(int j = words.get(i).start; j <=  words.get(i).end; j++) {
                prefix[j] = i;
            }
        }
        
        List<String> spoilers = new ArrayList<>();
        for(int[] range: spoiler_ranges) {
            for(i = range[0]; i <= range[1]; i++) {
                if(prefix[i] != -1) {
                    isSpoiler[prefix[i]] = true;
                    spoilers.add(words.get(prefix[i]).word);
                }
            }
        }
        
        Set<String> nonSpoilers = new HashSet<>();
        for(int k = 0; k < words.size(); k++) {
            if(!isSpoiler[k]) {
                nonSpoilers.add(words.get(k).word);
            }
        }
        
        int answer = 0;
        for(String spoiler: spoilers) {
            if(!nonSpoilers.contains(spoiler)) {
                answer++;
            }
            nonSpoilers.add(spoiler);
        }
        
        
        return answer;
    }
}