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
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    bool isPalindrome(ListNode* head) { 
        ListNode* middle = middleNode(head);
        ListNode *ptr2 = reverseList(middle->next);
        ListNode *ptr1 = head;
        while(ptr2 != nullptr){
            if(ptr1->val != ptr2->val) return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true; 
    }
};