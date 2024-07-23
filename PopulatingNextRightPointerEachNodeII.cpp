class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        std::queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()) {
            std::queue<Node*> newQueue;
            int size = queue.size();
            for(int i = 0; i < size; ++i){
                Node* node = queue.front();
                queue.pop();
                if(node) {
                    if(node -> left) newQueue.push(node -> left);
                    if(node -> right) newQueue.push(node -> right);
                    node -> next = (i < size - 1) ? queue.front() : nullptr;
                }
            }
            queue = newQueue;
        }
        return root;
    }
};