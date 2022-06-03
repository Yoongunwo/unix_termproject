#include <stddef.h>
#include "linkedlist.h"

static Node* _head = NULL;

static Node* _tail = NULL;

static Node* _cur_node = NULL;

bool empty(){
        Node* p = _head;
        if(p->next == NULL) return True;
        else return False;
}

size_t size(){
        size_t result = 0;
        Node* p = _head;
        while(p->next != _tail){
                p = p->next;
                ++result;
        }
        return result;
}

void print(){
        Node* p = _head;
	printf("LinkedList [ ");
        while(p != NULL){
		p = p->next;
                printf("%s ",p->data);
        }
	printf("]\n");
}

void print_file(FILE* stream){
        int size;
        char* buffer;
        fseek(stream, 0, SEEK_END);
        size = ftell(stream);
        buffer = malloc(size + 1);
        memset(buffer, 0, size + 1);

        while(fgets(file_buff, size + 1, stream) != NULL){
                printf("%s", buffer);
                memset(buffer, 0, size + 1);
        }
        fclose(stream);
        free(buffer);
}

void clear(){
        Node* p = _head->next;
        while(p != NULL){
                Node* nextNode = p->next;
                p->data = NULL;
                p->next = NULL;
		p->prev = NULL;
                p = nextNode;
        }
        _head = NULL;
        _tail = NULL;
	printf("LinkedList is cleared!\n");
}

Node* append_left(size_t n, char new_data[n]){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = new_data;
	newNode->prev = _head;
	_head->next = newNode;

	if(size() == 0){
		newNode->next = _tail;
		_tail->prev = newNode;
	}
	else{
		Node* nextNode;
		nextNode = _head->next;
		nextNode->prev = newNode;
		newNode->next = nextNode;
	}
	_cur_node = newNode;
        return _cur_node;
}

Node* insert_after(Node* cur_node, Node* new_node){
        Node* curNode = cur_node;
        Node* newNode = new_node;

        newNode->next = curNode->next;
        newNode->prev = curNode;
        curNode->next = newNode;
        return new_node;
}

Node* append(size_t n, char new_data[n]){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = new_data;
	newNode->next = _tail;

        if(size() == 0){
                newNode->prev = _head;
		_head->next = newNode;
        }
        else{
		Node* prevNode;
		prevNode = _tail->prev;
                prevNode->next = newNode;
		newNode->prev = prevNode;
        }
        _cur_node = newNode;
        return _cur_node;
}

Node* delete_node(Node* cur_node){
        cur_node->prev->next = cur_node->next;
	cur_node->next->prev = cur_node->prev;
	free(cur_node->data);
	return _cur_node;
}

Node* delete(char* data){
        Node* p = first();
        while(p != _tail){
                if(strcmp(data, p->data) == 0){
                        delete_node(p);
                }
		else{
			p = p->next;
		}
        }
        return _cur_node;
}

Node* get_node(size_t index){
        Node* p = _head;
	Node* temp;
	size_t count = 0;
	while(count <= index){
		temp = p;
		p = p->next;
		if(p != _cur_node) ++count;
		else{
			temp->next = p->next;
			p->next->prev = temp;
		}
	}
	_cur_node->prev = temp;
	_cur_node->next = p;
        
        return p;
}

Node* first(){
        Node* p = _head;
	if(p->next != NULL) p = p->next;
        return p;
}

Node* last(){
        Node* p = _tail;
	if(p->prev != NULL) p = p->prev;
        return p;
}

Node* next(){
        Node* p = _cur_node;
	if(p->next != NULL) p = p->next;
        return p;
}

Node* prev(){
        Node* p = _cur_node;
	if(p->prev != NULL) p = p->prev;
        return p;
}
