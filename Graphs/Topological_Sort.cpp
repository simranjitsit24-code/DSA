#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int i, int j, bool undir = true) {
        l[i].push_back(j);
        if (undir) {
            l[j].push_back(i);
        }
    }
    void topologicalsort(vector<bool> &vis,stack<int> &st,int node)
    {
        vis[node] = true;
        for (auto nbr : l[node])
        {
            if (!vis[nbr])
            {
                topologicalsort(vis,st,nbr);
            }
        }
        st.push(node);
    }
    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << "->";
            for (auto node : l[i]) {    
                cout << node << ",";
            }
            cout << endl;
        }
    }
};
int main()
{    Graph g(6);
    g.addEdge(5, 2,false);
    g.addEdge(5, 0,false);
    g.addEdge(4, 0,false);        
    g.addEdge(4, 1,false);
    g.addEdge(2, 3,false);
    g.addEdge(3, 1,false);
    g.printAdjList();
    stack<int> st;
    vector<bool> vis(6,false);
    for (int i=0;i<6;i++)
    {
        if (!vis[i])
        {
            g.topologicalsort(vis,st,i);
        }
    }
    cout << "\nTopological Sort: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}