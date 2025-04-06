#include <iostream>
using namespace std;

class Node {
	public:
		int value; 
		Node *next;
		Node(int v){
			value = v;
			next = NULL;
		}
};

void insert_Front(Node **head, int value){
	Node *new_node = new Node(value);
	new_node->next = *head;
	*head = new_node;
}

Node* insert_Front_2(Node* head, int value){
	Node *new_node = new Node(value);
	new_node->next = head;
	return new_node;
}

void insert_Last(Node **head, Node **tail, int value){
	Node*new_node = new Node(value);
	if (*tail != NULL){
		(*tail)->next = new_node;
	} else {
		*head = new_node;
	}
	*tail = new_node; 
}

Node* delete_Front(Node **head){
	Node* deleted_node = *head;
	*head = (*head)->next;
	return deleted_node;
}

int main(){
	Node *list_head = NULL;
	Node *tail = NULL;
	list_head = insert_Front_2(list_head, 10);
	list_head = insert_Front_2(list_head, 20);
	list_head = insert_Front_2(list_head, 30);
	insert_Last(&list_head, &tail, 10);
	insert_Last(&list_head, &tail, 20);
	insert_Last(&list_head, &tail, 30);
	Node *a = delete_Front(&list_head);
	for(Node *h = list_head; h!=NULL;h=h->next){	
		cout<<h->value<<" ";
	}
	cout << "\nDeleted node is " << a->value << endl;
	return 0;
}