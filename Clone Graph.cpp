class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
        return nullptr;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        Node* clonedNode = new Node(node -> val);
        mp[node] = clonedNode;
        q.push(node);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for(Node* neighbour : curr -> neighbors) {
                if(mp.find(neighbour) == mp.end()) {
                    Node* newNeighbour = new Node(neighbour -> val);
                    mp[neighbour] = newNeighbour;
                    q.push(neighbour);
                }
                mp[curr] -> neighbors.push_back(mp[neighbour]);
            }
        }
        return clonedNode;
    }
};