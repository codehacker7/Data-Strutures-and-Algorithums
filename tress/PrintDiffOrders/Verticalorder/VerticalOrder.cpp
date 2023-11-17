class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // i want to make a map which has hd level values and the node values

        map<int,vector<int> > nodes;

        queue<pair<TreeNode*,int> > q;

        q.push({root,0});

        while(!q.empty()){

           pair<TreeNode*,int> p = q.front();
           q.pop();

           int Hlevel = p.second;
           TreeNode* front = p.first;

          nodes[Hlevel].push_back(front->val);

          if(front->left != NULL){
              q.push({front->left,Hlevel -1});
          }
          if(front->right != NULL){
              q.push({front->right,Hlevel + 1});
          } 
}

        int minLevel = INT_MAX;
        int maxLevel = INT_MIN;

        for(auto i:nodes){
            int level = i.first;
            minLevel = min(minLevel,level);
            maxLevel = max(maxLevel,level);
        }

        vector<vector<int> > finalans;

        for(int i=minLevel;i<=maxLevel;i++){

          vector<int> vec = nodes[i];
    finalans.push_back(vec);

        }




       }
    
    
    
}
