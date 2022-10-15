/*QUES :

 Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

*/

/***********************************************************************************************************************/


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

/************************************************************CODE******************************************************/
class Solution {
public:
    void dfs(Node* node,Node* start, vector<Node*>&vis){
        vis[start->val] = start;                                    //MARKING THE VISITED INDEX WITH NODE ITSELF
        for(auto &e:(node->neighbors)){
            if(vis[e->val]==NULL){
                Node* temp = new Node(e->val);
                (start->neighbors).push_back(temp);               //PUSHING ADJACENT NODES AS NEIGHBOURS BY CREATING THAT ADJACENT NODE
                dfs(e,temp,vis);
            }
            else{
                (start->neighbors).push_back(vis[e->val]);        //IF ALREADY VIVITED THEN PLACING THEIR VALUE 
            }
        }
    }
    Node* cloneGraph(Node* node) {
        
        if(node==NULL){
            return NULL;
        }
        vector<Node*> vis(101,NULL);
        Node * clone = new Node(node->val);  // CREATING ROOT NODE FOR NEW GRAPH
        
        dfs(node,clone,vis);                 //DFS CALL ON NEW ROOT
        return clone;
    }
};