class Solution {
public:
    int sz;
    bool prime(int num) {
        if(num <= 1) return false;
        if(num <= 3)  return true; 
        
        int range = sqrt(num);

        if(num % 2 == 0 || num % 3 == 0) 
            return false; 
        
        for(int i = 5; i <= range; i += 1) 
            if(num % i == 0 ) 
                return false; 
        
        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        
        if(mat.size()==0){
            return -1;
        }
        
        int n=mat.size();
        int m=mat[0].size();
        

        
        map<int,int> f;
    
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                
                string  x = to_string(mat[i][j]);
                string y=x;
                
                int r=j+1;
                
                while(r<mat[i].size()){
                    x += to_string(mat[i][r]);
                    if(prime(stoi(x))){
                        f[stoi(x)]++;
                    }
                    r++;
                }
                
                int l=j-1;
                x=y;
                
                while(l>=0){
                    x+=to_string(mat[i][l]);
                    if(prime(stoi(x))){
                        f[stoi(x)]++;
                    }
                    l--;
                }
                
                int nei=i-1;
                int nej=j+1;
                x=y;
                
                while(nei>=0 && nej<mat[i].size()){
                    x+=to_string(mat[nei][nej]);
                    if(prime(stoi(x))){
                        f[stoi(x)]++;
                    }
                    nei--;
                    nej++;
                }
                
                int sei=i+1;
                int sej=j+1;
                x=y;
                
                while(sei<mat.size() && sej<mat[i].size()){
                    x+=to_string(mat[sei][sej]);
                    if(prime(stoi(x))){
                        f[stoi(x)]++;
                    }
                    sei++;
                    sej++;
                }
                
                int u=i-1;
                x=y;
                
                while(u>=0){
                    x+=to_string(mat[u][j]);
                    if(prime(stoi(x))){
                        f[stoi(x)]++;
                    }
                    u--;
                }
                
                int d=i+1;
                x=y;
                
                while(d<mat.size()){
                    x+=to_string(mat[d][j]);
                    if(prime(stoi(x))){
                        f[stoi(x)]++;
                    }
                    d++;
                }
                
                int swi=i+1;
                int swj=j-1;
                x=y;
                
                while(swi<mat.size() && swj>=0){
                    x+=to_string(mat[swi][swj]);
                    if(prime(stoi(x))){
                        f[stoi(x)]++;
                    }
                    swi++;
                    swj--;
                }
                
                int nwi=i-1;
                int nwj=j-1;
                x=y;
                
                while(nwi>=0 && nwj>=0){
                    x+=to_string(mat[nwi][nwj]);
                    if(prime(stoi(x))){
                        f[stoi(x)]++;
                    }
                    nwi--;
                    nwj--;
                }
                
            }
        }
        
        int ansx=-1;
        int mxx=-1;
        
        for(auto it : f){
            int element = it.first;
            int freq = it.second;
            
            if(freq > mxx){
                ansx = element;
                mxx = freq;;
            }else if(freq == mxx){
                //if freq is equal for 2 elements return the number which is of higher frequency
                if(element > ansx){
                    ansx = element;
                }
            }
        }
        return ansx;
            
    }
};