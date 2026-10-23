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
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *kth = head, *prev_last = nullptr, *front;
        while (temp != nullptr) {
            int count = 1;
            kth = temp;
            while ((count < k) && kth) {
                count++;
                kth = kth->next;
            }
            if (kth == nullptr) {
                if(prev_last) prev_last->next = temp;
                break;
            }
            front = kth->next;
            kth->next = nullptr;
            reverse(temp);
            if (temp == head)
                head = kth;
            else
                prev_last->next = kth;
            prev_last = temp;
            temp = front;
        }
        return head;
    }
};