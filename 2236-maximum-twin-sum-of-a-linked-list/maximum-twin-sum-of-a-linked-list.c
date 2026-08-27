/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    int size = 0;

    // Find middle
    while (fast && fast->next) {
        size++;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* prev = NULL;
    struct ListNode* curr = slow;
    struct ListNode* front;

    while (curr) {
        front = curr->next;

        curr->next = prev;
        prev = curr;
        curr = front;
    }

    int maxi = INT_MIN;

    // Calculate twin sums
    for (int i = 0; i < size; i++) {
        int value = head->val + prev->val;

        if (value > maxi)
            maxi = value;

        head = head->next;
        prev = prev->next;
    }

    return maxi;
}