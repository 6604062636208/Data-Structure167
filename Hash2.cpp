#include <iostream>
using namespace std;

class node{
	public:
		int key;
		string data;
		node *next;
		node()
		{
			key = -1;
			data = "-";
			next = NULL;
		}
		node(string s, int k)
		{
			key = k;
			data = s;
			next = NULL;
		}
};
class seperate_chaining{
	public:
		int n;
		node hash_table[100];
		seperate_chaining(int p_n)
		{
			n = p_n;
		}
		void add(int key, string data)
		{
			int j = key%n;
			if(hash_table[j].next == NULL)
			{
				hash_table[j].data = data;
				hash_table[j].key = key;
				hash_table[j].next = new node();
			}
			else 
			{
				node *t_node = hash_table[j].next;
				while(t_node->next != NULL)
				{
					t_node = t_node->next;
				}
				t_node->data = data;
				t_node->key = key;
				t_node->next = new node();
			}
		}
		string search(int key){
			int j = key%n;
			if(hash_table[j].key == key)
			{
				return hash_table[j].data;
			}
			else
			{
				node *t_node = hash_table[j].next;
				while(t_node->next != NULL)
				{
					if(key == t_node->key)
					{
						return t_node->data;
					}
					t_node = t_node->next;
				}
			}
			return "-";
		}
		void print()
		{
			for(int i=0; i<n; i++)
			{
				cout<<"("<<hash_table[i].key<<","<<hash_table[i].data<<") ";
				if(hash_table[i].next != NULL)
				{
					node *t_node = hash_table[i].next;
					while(t_node->next != NULL)
					{
						cout<<"("<<t_node->key<<","<<t_node->data<<") ";
						t_node = t_node->next;
					}
				}
				cout<<endl;
			}
		}
};
int main(){
	seperate_chaining H(17);
    char character;
    int key;
    string data;

    while (true) {
        cin >> character;
        if (character == 'e') {
            break;
        } else if (character == 'a') {
            cin >> key >> data;
            H.add(key, data);
        } else if (character == 'p') {
            H.print();
        } else if (character == 's') {
            cin >> key;
            cout << H.search(key) << endl;
        }
    }
    return 0;
}