#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
     class Node
     {
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node (int k=0,int v=0):key(k),val(v)
        {
            prev = next = nullptr;
        }

     };
    int limit;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map <int,Node* >m;
    void addNode(Node* newn)
    {
       Node* oldnext = head->next;
       newn->prev = head;
       head->next = newn;
       newn->next = oldnext;
       oldnext->prev = newn;
    }
    void delNode(Node* oldn)
    {
        oldn->prev->next = oldn->next;
        oldn->next->prev = oldn->prev;
      
    }
    LRUCache(int capacity) 
    {
       limit = capacity;
       head->next = tail;
       tail->prev = head;
    }
    int get(int key)
    {
        if (m.find(key)==m.end())
        {
            return -1;
        }
        int ans = m[key]->val;
        Node* newn = new Node(key,ans);
        addNode(newn);
        delNode(m[key]);
        m[key] = newn;
        return ans;
    }
    void put(int key, int value) 
    {
        Node* newn = new Node(key, value);
        if (m.find(key)!=m.end())
        {
            delNode(m[key]);
            m.erase(key);
        }
        if (m.size()==limit) 
        {
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(newn);
        m[key] = newn;
    }
};

int main()
{
    LRUCache l1(2);
    l1.put(1,1);
    l1.put(2,2);
    cout << "get(1): " << l1.get(1) << endl;
    l1.put(3,3);
    cout << "get(2): " << l1.get(2) << endl;
    l1.put(4,4);
    cout << "get(1): " << l1.get(1) << endl;
    cout << "get(3): " << l1.get(3) << endl;
    cout << "get(4): " << l1.get(4) << endl;
    return 0;
}