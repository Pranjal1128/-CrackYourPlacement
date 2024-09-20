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
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        slow = reve(slow);
        while(slow != NULL && head != NULL) {
            if(head -> val != slow -> val) return false;
            head = head -> next;
            slow = slow -> next;
        }

        return true;
    }
};
