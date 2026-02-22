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
    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << "->";
            for (auto node : l[i]) {    
                cout << node << ",";
            }
            cout << endl;
        }
    }
    void dfs(int source) {
        stack<int>s;
        vector<bool> visited(V, false);
        s.push(source);
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (!visited[node]) {
                cout << node << " ";
                visited[node] = true;
                for (auto nbr : l[node]) {
                    if (!visited[nbr]) {
                        s.push(nbr);
                    }
                }
            }
    }
}
};
int main()
{    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);        
    g.addEdge(1, 3);
    g.printAdjList();
    cout << "\nDFS traversal starting from node 0: ";
    g.dfs(0);
    return 0;
}