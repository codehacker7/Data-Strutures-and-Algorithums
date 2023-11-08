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


    node* search(string key) {
		int hashIndex = hashFunction(key);
		node* head = a[hashIndex];
		while (head != NULL) {
			if (head->key == key) return head;

			head = head->next;
		}
		return head; 
	}

	int& operator[](string key) {
		node* x = search(key);
		if (x == NULL) {
			int g;
			insert(key, g); // g can be anything because yeh update // ho jaegi abhi jab hum bucket return krenge main ko
			x = search(key);
			return x->data;
		}
		return x->data;
	}

    void print() {
		for (int i = 0; i < ts; ++i)
		{
			cout << i << "-->";
			node* head = a[i];

			while (head != NULL) {
				cout << "(" << head->key << ", " << head->data << ") ";
				head = head->next;
			}
			cout << endl;
		}
	}
}

int main() {

	hashmap h;

	h.insert("Mango", 100);
	h.insert("Apple", 150);
	h.insert("Mausmi", 90);
	h.insert("Guava", 900);

	// ek hi function multiple kaam kr dega
	h["Pineapple"] = 20; // Insertion
	h["Pineapple"] = 200; // Updation
	cout << h["Pineapple"] << endl; // Search

	h.print();

	return 0;
}