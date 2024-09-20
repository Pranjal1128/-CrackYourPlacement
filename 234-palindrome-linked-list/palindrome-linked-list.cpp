/**
 * Definition for singly-linked list.
 struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reve(ListNode* head) { 
        ListNode* N = NULL;
        ListNode* P = NULL;
        ListNode* C = head;

        while(C != NULL) {
            N = C -> next;
            C -> next = P;
            P = C;
            C = N;
        }

        return P;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* rev = NULL, *newll;
        while(curr != NULL) {
            if(rev == NULL) {
                rev = new ListNode(curr -> val);
                newll = rev;
            }
            else {
                rev -> next = new ListNode(curr -> val);
                rev = rev -> next;
            }
            curr = curr -> next;
        }

        head = reve(head);

        while(head != NULL) {
            if(head -> val != newll -> val) return false;
            head = head -> next;
            newll = newll -> next;
        }

        return true;
    }
};
