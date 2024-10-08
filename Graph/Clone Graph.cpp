/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, vector<Node*>& visited) {
        if (visited[node->val] != nullptr) {
            return visited[node->val];
        }

        Node* clone = new Node(node->val);
        visited[node->val] = clone;

        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }

        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr)return nullptr;
        vector<Node*>v(101,nullptr);
        
        return dfs(node,v);
    }
};