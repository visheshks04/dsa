/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = head;
        int len = 0;
        while(temp != null){
            temp = temp.next;
            len++;
        }
        
        if(len == n)
            return head.next;
        
        n = len-n-1;
        temp = head;
        
        while(n-- > 0)
            temp = temp.next;
        
        temp.next = temp.next.next;
        
        return head;
    }
}
