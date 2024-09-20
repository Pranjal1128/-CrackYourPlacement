class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = NULL, *even = NULL;
        ListNode *a = NULL, *b = NULL;
        int cnt = 1;
        while(head != NULL) {
            if(cnt % 2) {
                if(odd == NULL) {
                    odd = new ListNode(head -> val);
                    a = odd;
                }
                else {
                    odd -> next = new ListNode(head -> val);
                    odd = odd -> next;
                }
            }
            else {
                if(even == NULL) {
                    even = new ListNode(head -> val);
                    b = even;
                }
                else {
                    even -> next = new ListNode(head -> val);
                    even = even -> next;
                }
            }
            cnt++;
            head = head -> next;
        }

        if(odd) odd -> next = b;
        return a;
    }
};