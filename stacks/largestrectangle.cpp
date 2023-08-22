 int getPrevMax(vector<int> heights,int index){
        int value = heights[index];
        int index1 =INT_MIN;

        for(int i=index-1;i>=0;i--){
            if(heights[i] >= value){
                index1 = i;
            }
            else{
                break;
            }
        }

        return index1;

    }

    int getAfterMax(vector<int> heights,int index){
          int value = heights[index];
           int index1 =INT_MIN;

        for(int i=index+1;i<heights.size();i++){
            if(heights[i] >= value){
                index1 = i;
            }
            else{
                break;
            }
        }

        return index1;

    }


    int largestRectangleArea(vector<int>& heights) {

            int breadth =0;

            int area = 0;
            int ans = INT_MIN;

        for(int i=0;i<heights.size();i++){

            int length = heights[i];
               

            int prevGreaterElem = getPrevMax(heights,i);
            int afterGreaterElem = getAfterMax(heights,i);

            if(prevGreaterElem == INT_MIN){
                prevGreaterElem =i;
            }
            if(afterGreaterElem == INT_MIN){
                afterGreaterElem =i;
            }

            breadth = afterGreaterElem - prevGreaterElem +1;

            area = length* breadth;
            ans = max(ans,area);

           

            

        }
     return ans;

        
    }