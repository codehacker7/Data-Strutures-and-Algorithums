#include<iostream>
using namespace std;

class node{
public:
     int data;
     node* next;
     string key;
    
    node(string key,int data){
        this->key = key;
        this->data = data;
    }
    
};


class hashmap{
     int ts;
     node** a;
     int cs;
    int hashFunction(string key){

        int ans =0;
        int mul =1;
        for(int i=0;i<key.length();i++){
            ans += ((s[i] %ts)*(mul%ts))%ts;
            mul = ((mul%ts)*(37%ts))%ts;

        }
        return ans%ts;
    }

    hashmap(int t = 7){
        a = new node*[7];
        ts = t;
        cs = 0;
        for(int i=0;i<ts;i++){
            a[i] = NULL;
         }

    }
   

    void insert(string key, int value) {
       int index = hashFunction(key);
       node* n = new node(key,value);
       n->next = a[index];
       a[index] = n;
       cs++;

      float loadfactor = cs/ts;

      if(loadfactor > 0.5){
        rehashing();
      }
    
    }


     void rehashing(){
        node** olda = a;
        int oldts = ts;

        ts = ts*2;
        a = new node*[ts];

        cs =0;
        for(int i=0;i<oldts;i++){
            node* head = olda[i];

            while(head != NULL){
                insert(head->key,head->value);
                head = head->next;
                
            } 
        }
    }
}