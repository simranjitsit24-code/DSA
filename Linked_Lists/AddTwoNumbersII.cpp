#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
class ListNode
{
    public:
    int val;
    ListNode* next;
    ListNode(int a):val(a){next = nullptr;}
};
ListNode* reverse(ListNode* &head)
    {
      ListNode* curr = head;
      ListNode* prev = nullptr;
      ListNode* next = nullptr;
      while (curr)
      {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
         l1= reverse(l1);
         l2 = reverse(l2);
        while (l1 || l2 || carry)
        {
            long long int sum = carry;

            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return reverse(dummy->next);
    }
}; 
