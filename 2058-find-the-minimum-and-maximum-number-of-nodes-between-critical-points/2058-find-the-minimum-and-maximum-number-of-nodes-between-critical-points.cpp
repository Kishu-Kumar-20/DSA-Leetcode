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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *temp = head->next, *prev = head, *nex;
        int cnt = 1, count = 0;
        int l= INT_MAX, r = INT_MIN;
        int _min = INT_MAX;
        int _max;
        int _prev = INT_MAX;
        while(temp->next != nullptr){
            nex = temp->next;
            cnt++;
            if(temp->val < prev->val && temp->val < nex->val){
                l = min(l, cnt);
                r = max(r,cnt);
                if (_prev != INT_MAX) {
                    int diff = cnt - _prev;
                    _min = min(_min, diff);
                }
                _prev = cnt;
                count++; 
            }else if(temp->val > prev->val && temp->val > nex->val){
                l = min(l, cnt);
                r = max(r,cnt);
                if (_prev != INT_MAX) {
                    int diff = cnt - _prev;
                    _min = min(_min, diff);
                }
                _prev = cnt;
                count++; 
            }
            prev = temp;
            temp = nex;
        }
        vector<int> ans;
        if(count<2){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        _max = r - l;
        ans.push_back(_min);
        ans.push_back(_max);
        return ans;

    }
};