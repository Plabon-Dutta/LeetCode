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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector <int> v;
        ListNode *tmp = list1;
        while (tmp != NULL) {
            v.push_back(tmp -> val);
            tmp = tmp -> next;
        }

        ListNode *tmp2 = list2;
        while (tmp2 != NULL) {
            v.push_back(tmp2 -> val);
            tmp2 = tmp2 -> next;
        }
        
        sort(v.rbegin(), v.rend());
        ListNode *ans = new ListNode();
        ListNode *res = ans;
        for (int i = 0; i < v.size(); i++) {
            ans -> next = new ListNode(v[i], ans -> next);
        }
        res = res -> next;
        return res;
    }
};
