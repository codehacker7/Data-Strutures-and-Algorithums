#include<iostream>
#include<queue>
#include<set>
#include<unordered_map>
#include<list>

#define pb push_back
using namespace std;

template<typename T>
class Graph{
public:
    unordered_map<T,list<pair<T,int> > > adj;

    void addEdge(T u,T v,int dist,bool bidir = true){
        adj[u].pb({v,dist});
        if(bidir){
            adj[v].pb({u,dist});
        }
    }

    void print(){
        
        for(auto p:adj){
            cout<<p.first<<" : ";
            for(auto x : p.second){
                cout<<"("<<x.first<<", "<<x.second<<") ";
            }
        }

    }

    //SSSP in weighted Graphs in Dijkstras Algo
    void SSSP(T src,T dest){

        unordered_map<T,T> parent;
        unordered_map<T,int> dist;

        //set the distances of all nodes to INT_MAX;

        for(auto p : adj){
            dist[p.first] = INT_MAX;
        }

        //Distance of src from itself is zero

        dist[src] =0;
        parent[src] = src;
        set<pair<int,char> > s;
        //src ko daldo zero distance ke saath
        s.insert({dist[src],src});

        while(!s.empty()){
            auto f = s.begin();
            auto p = (*f).second;
            auto pD = (*f).first;
            s.erase(f);
            
            for(auto n:adj[p]){
                if(dist[n.first] > pD + n.second){
                    int eD = n.second;
                    auto x = s.find({dist[n.first],n.first});

                    if(x != s.end()) s.erase(x);
                    
                    dist[n.first] = pD + eD;

                    parent[n.first] = p;

                    s.insert({dist[n.first,n.first]});

                }
            }
        }


        int ans = dist[des];

        cout<<"PATH: ";

        while(dest != parent[des]){
            cout<<dest<< "<-";
            dest = parent[des];
        }

        cout<<des<<endl;



    }

    




};

int main(){
    Graph<char> g;
    g.addEdge('A','B',1);
    g.addEdge('A','C',3);
    g.addEdge('A','D',2);
    g.addEdge('A','D',5);
    g.addEdge('A','D',4);

    g.print();

}