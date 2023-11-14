class Solution {
  public:
    
    Node* createParentMapping(Node* root,int target, map<Node*,Node*>& nodeToParent){
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        
       nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            
            if(front->left){
                nodeToParent[front->left]= front;
                q.push(front->left);
            }
             if(front->right){
                nodeToParent[front->right]= front;
                q.push(front->right);
            }
        }
        
        return res;
        
    }
    
    int burnTree(Node* root,map<Node*,Node*> &nodeToParent){
        
        map<Node*,bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root] = true;
        
        int ans =0;
        
        while(!q.empty()){
            bool flag =0;
            int size = q.size();
            
            for(int i=0;i<size;i++){
                Node* front = q.front();
                q.pop();
                
                if(front->left != NULL && visited[front->left] == false){
                    flag =1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                  if(front->right != NULL && visited[front->right] == false){
                      flag =1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag =1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            
            if(flag){
                ans++;
            }
            
        }
        return ans;
    }
  
  
  
    int minTime(Node* root, int target) 
    {
      int ans =0;
      map<Node*,Node*> nodeToParent;
      Node* targetNode = createParentMapping(root,target,nodeToParent);
        
        ans =burnTree(targetNode,nodeToParent);
        return ans;
    }
};