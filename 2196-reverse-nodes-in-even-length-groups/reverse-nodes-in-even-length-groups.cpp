class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prevGroupTail = nullptr;
        ListNode* curr = head;
        int groupSize = 1;

        while (curr) {
            // Find actual group size
            ListNode* groupHead = curr;
            int count = 0;

            while (curr && count < groupSize) {
                curr = curr->next;
                count++;
            }

            // curr = first node of next group

            if (count % 2 == 0) {
                ListNode* prev = curr;
                ListNode* node = groupHead;

                // Reverse current group
                while (node != curr) {
                    ListNode* next = node->next;
                    node->next = prev;
                    prev = node;
                    node = next;
                }

                // Connect previous group
                if (prevGroupTail)
                    prevGroupTail->next = prev;
                else
                    head = prev;

                // Original first node is now the tail
                prevGroupTail = groupHead;
            }
            else {
                // Odd group: find its last node
                prevGroupTail = groupHead;

                while (prevGroupTail->next != curr)
                    prevGroupTail = prevGroupTail->next;
            }

            groupSize++;
        }

        return head;
    }
};