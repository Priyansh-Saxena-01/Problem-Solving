class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> newneighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())
                {
                    newneighbour.push_back(mp[it]); 
                }
                else
                    newneighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=newneighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==nullptr)
            return nullptr;
        if(node->neighbors.size()==0)
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};