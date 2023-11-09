class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
     bool valid(Node* root,double leftvalue,double rightvalue){

        if(root == NULL){
            return true;
        }
        if(!(root->data > leftvalue && root->data < rightvalue)){
                return false;
        }

        return valid(root->left,leftvalue,root->data) && valid(root->right,root->data,rightvalue);

    }
    bool isValidBST(Node* root) {

        
        double negative_infinity = -std::numeric_limits<double>::infinity();
        double positive_infinity = std::numeric_limits<double>::infinity();


        return valid(root,negative_infinity,positive_infinity);
        
    }
    
    int countnodes(Node* front){
        if(front == NULL){
            return 0;
        }
        
        return 1+ countnodes(front->left) + countnodes(front->right);
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	int maxi = INT_MIN;
    	
    	while(!q.empty()){
    	   int levelSize = q.size();
    	    
    	    for(int i=0;i<levelSize;i++){
    	        Node* front = q.front();
    	        q.pop();
    	        
    	      bool check =  isValidBST(front);
    	       
    	       if(check == true){
    	           int temp = countnodes(front);
    	           
    	           maxi = max(maxi,temp);
    	           
    	       }
    	       
    	       if(front->left != NULL){
    	           q.push(front->left);
    	       }
    	       if(front->right != NULL){
    	           q.push(front->right);
    	       }
    	        
    	    }
    	    
    	}
    	
    	return maxi;
    }
}