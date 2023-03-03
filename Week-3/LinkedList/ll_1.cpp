//Leetcode 23: Merge k Sorted Lists
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        while(lists.size()>1)
        {
            lists.push_back(merge2lists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode* merge2lists(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val <= l2 -> val){
            l1->next = merge2lists(l1->next, l2);
            return l1;
        }
        else{
            l2-> next = merge2lists(l1,l2->next);
            return l2;
        }

    }
};

int main(){
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(5);
    ListNode *l4 = new ListNode(1);
    ListNode *l5 = new ListNode(3);
    ListNode *l6 = new ListNode(4);
    ListNode *l7 = new ListNode(2);
    ListNode *l8 = new ListNode(6);
    l1->next = l2;
    l2->next = l3;
    l4->next = l5;
    l5->next = l6;
    l7->next = l8;
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l4);
    lists.push_back(l7);
    ListNode *ans = s.mergeKLists(lists);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    return 0;
}