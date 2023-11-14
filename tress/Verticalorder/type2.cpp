// int this one you need to be careful that the order in which things are printed

//eg:

/*
HL:

-2  -1      0                                                        1           2

ANS:

0   1       0 has 3 levels (0,2,2) so go level by level             
            0 : [3]
            2:[2]
            2:[2]
            [3,2,2]

*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // i want to make a map which has hd level values and the node values

        map<int,map<int,vector<int> > > nodes; //let first be horizontal distance

        queue<pair<TreeNode*,pair<int,int> > > q; //let second's first be level

        q.push({root,{0,0}});

        while(!q.empty()){

          pair<TreeNode*,pair<int,int> > p = q.front();
          q.pop();


          int level = p.second.first;
          int horizontaldistance = p.second.second;
          TreeNode* node = p.first;

          nodes[horizontaldistance][level].push_back(node->val);

          if(node->left != NULL){
            q.push({node->left,{level+1,horizontaldistance-1}});
          }
          if(node->right != NULL){
            q.push({node->right,{level+1,horizontaldistance+1}});
          }
           

}

// map<int,map<int,vector<int> > > nodes; //let first be horizontal distance

        vector<vector<int> > finalans;


    for(auto i:nodes){
       //now i have horizontaldistances
       vector<int> column;

       for(auto j:i.second){
           vector<int> values = j.second;
            sort(values.begin(), values.end());
            for(auto k:values){
                column.push_back(k);
            }
       }
          finalans.push_back(column);

     
    }

    return finalans;

    }
    
};
