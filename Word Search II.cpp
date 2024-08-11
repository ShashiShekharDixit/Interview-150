class Node{
private:
    Node * links[26];
    bool wordEnd = false;
public:
    bool isNull(int ind){
        return links[ind] == NULL;
    }
    void put(int ind,Node * node){
        links[ind] = node;
    }
    Node* get(int ind){
        return links[ind];
    }
    void setEnd(){
        wordEnd = true;
    }
    void unSetEnd(){
        wordEnd = false;
    }
    bool isEnd(){
        return wordEnd;
    }
};
class Solution {
private:
    vector<int> Y = {-1,0,1,0};
    vector<int> X = {0,-1,0,1};
    void insert(string &word,Node * node){
        for(const char & ch : word){
            int ind = ch-'a';
            if(node->isNull(ind)){
                node->put(ind,new Node());
            }
            node = node->get(ind);
        }
        node->setEnd();
    }
    void checkWord(int i,int j,vector<vector<char>> & board,vector<vector<bool>> & vis,vector<string> & res,Node * node,string s){
        if(node->isEnd()){
            res.push_back(s);
            node->unSetEnd();
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if(vis[i][j] == true) return;
        vis[i][j] = true;
        int ind = board[i][j]-'a';
        if(node->isNull(ind) == false){
            for(int k=0; k<4; k++){
                int ii = i+X[k];
                int jj = j+Y[k];
                checkWord(ii,jj,board,vis,res,node->get(ind),s+board[i][j]);
            }
        }
        vis[i][j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size(),cols=board[0].size();
        vector<string> res;
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));
        Node * root = new Node();
        for(auto & word : words ){
            insert(word,root);
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(root->isNull(board[i][j] - 'a') == false){
                    checkWord(i,j,board,vis,res,root,"");
                }
            }
        }
        return res;
    }
};