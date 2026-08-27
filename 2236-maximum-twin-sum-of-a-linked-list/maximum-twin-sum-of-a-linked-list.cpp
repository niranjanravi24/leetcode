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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int size=0;
        while(fast){
            size++;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* front;
        while(curr){
            size++;
            front = curr->next;

            curr->next = prev;
            prev = curr;
            curr = front;
        }
        int maxi =INT_MIN;
        for(int i=0; i<size/2; i++){
            int value = head->val + prev->val;
            head = head->next;
            prev = prev->next;
            maxi = max(maxi, value);
        }
        return maxi;
    }
};