/*
 *Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        typedef UndirectedGraphNode Node;
        typedef pair<Node*,Node*> Pair;
        if(node==NULL) return NULL;                 

        queue<Node*> q;
        Node *res = new Node(node->label);
        q.push(node);

        unordered_map<Node*,Node*> m;
        m[node] = res;
        
        while(!q.empty())
        {
            Node *cur = q.front(); 
            Node *copy = m[cur];
            q.pop();
            for(Node* nb: cur->neighbors)
            {
                if(m.find(nb)!=m.end())     
                {
                    copy->neighbors.push_back(m[nb]);     
                }
                else
                {
                    Node *nb_copy = new Node(nb->label); 
                    m[nb] = nb_copy;
                    q.push(nb);
                    copy->neighbors.push_back(nb_copy);
                }
            }
        }

        return res;

    }
};
