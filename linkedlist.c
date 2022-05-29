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
        free(buffet);
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
	Node* newNode = (Node*)malloc(sizeof(Node));\
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
        return cur_node;
}

Node* append(size_t n, char new_data[n]){
        Node* newNode = (Node*)malloc(sizeof(Node));\
        newNode->data = new_data;
	newNode->next = _tail;

        if(size() == 0){
                _head->next = newNode;
                newNode->prev = _head;
        }
        else{
                newNode->prev = _tail->prev;
        }
	_tail->prev = newNode;
        _cur_node = newNode;
        return _cur_node;

}

Node* delete_node(Node* cur_node){
        Node* prevNode;
        Node* nextNode;

        prevNode = cur_node->prev;
        nextNode = cur_node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        cur_node->data = NULL;
        cur_node->next = NULL;
        cur_node->prev = NULL;
	return prevNode;
}

Node* delete(char* data){
        Node* p = _head;
        while(p != NULL){
		p = p->next;
                if(p->data == data){
                        break;
                }
        }
        delete_node(p);
}

Node* get_node(size_t index){
        Node* p = _head;
        for(size_t i = 0;i<=index;++i) p = p->next;
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
