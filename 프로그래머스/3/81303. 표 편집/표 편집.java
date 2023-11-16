import java.util.*;

class Solution {
    static class Node {
        Node prev, next;
        int value;
        boolean removed = false;
        
        public Node(int value) {
            this.value = value;
        }
        
        public boolean getRemoved() {
            return this.removed;
        }
        
        public Node getPrev() {
            return this.prev;
        }
        
        public Node getNext() {
            return this.next;
        }
        
        public int getValue() {
            return this.value;
        }
        
        public void setPrev(Node prev) {
            this.prev = prev;
        }
        
        public void setNext(Node next) {
            this.next = next;
        }
        
        public void setRemoved(boolean removed) {
            this.removed = removed;
        }
    }
    
    public Node up(Node curr, int count) {
        while(count > 0) {
            curr = curr.getPrev();
            count--;
        }
        
        return curr;
    }
    
    public Node down(Node curr, int count) {
        while(count > 0) {
            curr = curr.getNext();
            count--;
        }
        
        return curr;
    }
    
    public String solution(int n, int k, String[] cmd) {
        StringBuilder answer = new StringBuilder("");
        
        
        Node[] nodes = new Node[n];
        
        for(int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }
        
        for(int i = 1; i < n; i++) {
            nodes[i - 1].setNext(nodes[i]);
            nodes[i].setPrev(nodes[i - 1]);
        }
        
        Stack<Node> trash = new Stack<>();
        Node curr = nodes[k];
        for(int i = 0; i < cmd.length; i++) {
            String op = cmd[i];
            
            if(op.charAt(0) == 'U') {
                curr = up(curr, Integer.parseInt(op.substring(2)));
            } else if(op.charAt(0) == 'D') {
                curr = down(curr, Integer.parseInt(op.substring(2)));
            } else if(op.charAt(0) == 'C') {
                curr.setRemoved(true);
                trash.add(curr);
                
                Node up = curr.getPrev();
                Node down = curr.getNext();
                
                if(up != null)
                    up.setNext(down);
                
                if(down != null) {
                    down.setPrev(up);
                    curr = down;
                } else {
                    curr = up;
                }
                
            } else {
                Node top = trash.pop();
                top.setRemoved(false);
                
                Node up = top.getPrev();
                Node down = top.getNext();
                
                if(up != null)
                    up.setNext(top);
                if(down != null)
                    down.setPrev(top);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(nodes[i].getRemoved()) {
                answer.append("X");
            } else {
                answer.append("O");
            }
        }
        
        return answer.toString();
    }
}