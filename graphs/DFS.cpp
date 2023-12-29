#include<iostream>
using namespace std;

class Graph{
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool bidir = false){
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

    void BreadthFirstSearch(int src,int dest){
        unordered_map<T,T> parent; //stores parent of a node
        unordered_map<T,int> distance;//distance of 1 node from src node
        unordered_map<T,bool> visited;

        queue<T> q;
        q.push(src);

        parent[src] = src;
        distance[src] = 0;
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();

            cout<<node<<" ";

            for(T neighbour:adj[node]){
                if(visited[neighbour] == false){
                    q.push(neighbour);
                    parent[neighbour] = node;
                    distance[neighbour] = distance[node] +1;
                    visited[src] = true;
                }
            }

        }


        while(dest != parent[des]){
            cout<<dest<< " ";
            dest = parent[des];
        }

        cout<<des<<" ";

    }


    void DFSHelper(T src,unordered_map<T,bool> &visited){
        cout<<src<<" ";
        visited[src] = true;
        for(auto neighbour:adj[src]){

            if(visited[neighbour] == false){

                DFSHelper(neighbour,visited);
            }
        }
    }   

    void DFS(T src){
        unordered_map<T,bool> visited;
        DFSHelper(src,visited);

        int component = 1;

        for(auto p:adj){
            if(!visited[p.first]){
                DFSHelper(p.first,visited);
                component++;
            }
        }
    }

};