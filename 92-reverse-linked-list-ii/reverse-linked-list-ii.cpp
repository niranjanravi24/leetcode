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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* leftBack = head;
        for(int i=1; i<left-1; i++){
            leftBack = leftBack->next;
        }
        ListNode* leftNode;
        if(left == 1){
            leftNode = head;
        }
        else{
            leftNode = leftBack->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = leftNode;
        for(int i=0; i<right-left+1; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(left==1){
            head = prev;
        }
        else{
            leftBack->next = prev;
        }

        leftNode->next = curr;
        return head;
    }
};