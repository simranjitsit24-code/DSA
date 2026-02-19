#include <bits/stdc++.h>
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
   struct greater{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue <ListNode*,vector<ListNode*>,greater> pq; 
        int n = lists.size();
        if (lists.empty())
        {
            return nullptr;
        }
        if (n==1)
        {
            if(lists[0]==nullptr) return nullptr;
            else return lists[0];
        }
        for (auto &i : lists)
        {
            while(i!=nullptr)
            {
                ListNode* node = i->next;
                i->next = nullptr;
                pq.push(i);
                i = node;
            }
        }
        if (pq.empty()) return nullptr;
        ListNode* head = pq.top();
        pq.pop();
        ListNode* curr = head;
        while (!pq.empty())
        {
          curr->next = pq.top();
          pq.pop();
          curr = curr->next;  
        }
     return head;
    }
};
int main()
{
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(6);
    vector<ListNode*> lists = {head1,head2,head3};
    Solution s;
    ListNode* result = s.mergeKLists(lists);
    while (result!=nullptr)
    {
        cout<<result->val<<" ";
        result=result->next;
    }
}