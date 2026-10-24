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
    ListNode* middle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge2(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            } else {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
        }
        temp->next = list1 ? list1 : list2;
        return dummy->next;
    }
    ListNode* ms(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* mid = middle(head);
        ListNode *lefthead = head, *righthead = mid->next;
        mid->next = nullptr;
        lefthead = ms(lefthead);
        righthead = ms(righthead);
        return merge2(lefthead, righthead);
    }
    ListNode* sortList(ListNode* head) { 
        return ms(head);
    }
};