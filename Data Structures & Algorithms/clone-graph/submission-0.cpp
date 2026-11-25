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
private:
    unordered_map<Node*, Node*> nodes; 
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        if(nodes.find(node) != nodes.end()) return nodes[node];
        
        Node* clone = new Node(node->val);
        nodes[node] = clone;

        for(Node* nei: node->neighbors){
            clone->neighbors.push_back(cloneGraph(nei));
        }
        return clone;
    }
};
