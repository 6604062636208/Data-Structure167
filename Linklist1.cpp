 #include <iostream>
using namespace std;

class Node {
    public:
        Node* next;
        Node* prev;
        int value;

    Node(int v) {
        value=v;
        next=NULL;
        prev=NULL;
    }
};
class Linklist {
    public:
        Node* head;
        Node* tail;

    Linklist() {
        head=NULL;
        tail=NULL;
    }
	bool(contains(int id)){
   		Node * current=head;
    	while(current!=NULL){
        	if(current->value==id){
           		return true;
        	}
        	current=current->next;
    	}	
    	return false;
	}
    void insertAfter(int id, int value) {
        Node *current = head;
        if (contains(value)){
            return;
    }
        while (current != NULL) {
            if (current->value == id) {
                Node *newNode = new Node(value);
                newNode->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;  
                }
                current->next = newNode;
                newNode->prev = current;
                printList();
                return;
            }
            current = current->next;
        }
        append(value);
        printList();
    }
    void insertBefore(int id, int value) {
        Node *current = head;
        if (contains(value)){
        	return;
		}
        while (current != NULL) {
            if (current->value == id) {
                Node *newNode = new Node(value);
                newNode->prev = current->prev;
                newNode->next = current;
                if (current->prev != NULL) {
                    current->prev->next = newNode;
                } else {
                    head = newNode;  
                }
                current->prev = newNode;
                printList();
                return;
            }
            current = current->next;
        }
        append(value);
        printList();
    }
    void Delete(int id) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->value == id) {
                if (temp->prev != NULL) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                } else {
                    tail = temp->prev;
                }
                delete temp;
                printList();
                return;
            }
            temp = temp->next;
        }
    }
    void printList() const {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void append(int value) {
        Node *newNode = new Node(value);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
};
int main() {
    Linklist L;
    char ch;
    int id, value;
    while(true) {
        cin >> ch;
        if (ch == 'A') {
            cin >> id >> value;
            L.insertAfter(value,id);
        }
        else if (ch == 'I') {
            cin >> id >> value;
            L.insertBefore(value,id);
        }
        else if (ch == 'D') {
            cin >> id;
            L.Delete(id);
        }
        else if (ch == 'E') {
            break;
        }
    }
    return 0;
}