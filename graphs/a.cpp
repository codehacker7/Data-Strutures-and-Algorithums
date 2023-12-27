#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class Graph{
public:
        unordered_map<T,list<T>> adj;
        
     void addEdge(T u,T v,bool bidir = false){
        adj[u].push_back(v);
        
        if(bidir){
            adj[v].push_back(u);
        }
    
    }


    void print(){
        for(auto p:adj){
            cout<<p.first<<" ";

            for(auto n:p.second){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(T src,T dest){
        unordered_map<T,int> distance;
         unordered_map<T,bool> visited;
          unordered_map<T,T> parent;

        distance[src] = 0;
        parent[src] = src;
        distance[src] = 0;

        queue<T> q;
        q.push(src);

        while(!q.empty()){

            T node = q.front();

            q.pop();
            
            cout<<node<<" ";

            for(auto neighbour : adj[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    distance[neighbour] = distance[node]+1;
                    parent[neighbour] = node;
                    visited[neighbour] = true;
                }
            }

            cout<<endl;
            cout<"PATH:  ";

            cout<<"PRINTING ALL DISTANCES:\n";

            for(auto p:distance){
                cout<<"Distance of "<<p.first<<"from "<<src<<" is "<<p.second<<endl;
            }

            while(dest != parent[dest]){
                cout<< dest << "<-";
                des = parent[des];
            }   

            //to print 0 as well print
            cout<<dest<<endl;

            cout<<endl;

        }


    }
};