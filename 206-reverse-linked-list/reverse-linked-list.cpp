/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* head, ListNode* P) {
        if(head == NULL) return P;
        ListNode* N = head -> next;
        head -> next = P;
        P = head;
        head = N;
        return rev(head, P);
    }

    ListNode* reverseList(ListNode* head) {
        return rev(head, NULL);
    }
};