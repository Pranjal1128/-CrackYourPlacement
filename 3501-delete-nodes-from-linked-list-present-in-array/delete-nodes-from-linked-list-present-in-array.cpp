class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> us(nums.begin(), nums.end());
        ListNode* temp = new ListNode(0, head);
        ListNode* current = temp;

        while (current -> next != nullptr) {
            if (us.find(current -> next -> val) != us.end()) {
                ListNode* temp = current -> next;
                current -> next = current -> next -> next;
                delete temp;  
            } else {
                current = current -> next;
            }
        }

        ListNode* ans = temp -> next;
        delete temp; 
        return ans;
    }
};
