class Graph{

  unordered_map <char,list<pair<char,int> > adj;

  void addEdge(int u,int v,int weight,bool bidir = false){

        adj[u].push_back({v,weight});

        if(bidir){
            adj[v].push_back({u,weight});
        }
  }

  void print(){

        for(auto i:adj){

            cout<<i.first<<"-> ";
            for(auto nodes:i.second){
                cout<<"{ "<<nodes.first<<" , "<<nodes.second<<"}"<<" ";
            }
        }

  }

  

 

  int SSSP(T src){

    unordered_map<T,int> dist;
    unordered_map<T,T> parent;

    for(auto i:adj){
    dist[i.first] = INT_MAX;
    }

    dist[src] =0;
    parent[src] = src;

      set<pair<int,char> > s;
      s.insert({0,src});

      while(!s.empty()){
        auto f = s.begin();
        auto p = (*f).second;
        auto pD = (*f).first;

        for(auto i:adj[p]){

            int eD = i.second;
            int node = i.first;

            if(dist[node] > eD+ pD){
                auto x = s.find({dist[node],node});

                if(x != s.end()){
                    s.erase(x);
                }

            
                int newDistance = eD+ pD;

                dist[node] = newDistance;
                parent[node] = p;

                s.insert({newDistance,node})


            }

        }

      }


  }



};
