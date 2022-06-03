#include <stddef.h>
#include "linkedlist.h"

static Node* _head = NULL;

static Node* _tail = NULL;

static Node* _cur_node = NULL;

bool empty(){
        if(size() > 0) return false;
        return true;
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
        if(!empty()){
		size_t num_of_song = size();
		fprintf(stream, "%d\n", num_of_song);
		Node* p = last();
		while(p != first()->prev){
			fprintf(stream, "%s\n", p->data);
			p = p->prev;
		}
	}
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
        cur_node->prev = new_node;
	cur_node->next = new_node->next;
	cur_node->prev->next = cur_node;
        cur_node->next->prev = cur_node;
        return cur_node;
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
        Node* p = first();
	int find_node = 1;
	while(finde_node != index){
		p = p->next;
		++find_node;
	}
	Node* cu = first();
	int cur = 1;
	while(cu != _cur_node){
		cu = cu->next;
		++cur;
	}
	_cur_node->prev->next = _cur_node->next;
	_cur_node->next->prev = _cur_node->prev;
        if(find_node > cur){
		insert_after(_cur_node, p);
	}
	else if(find_node < cur){
		insert_after(_cur_node, p->prev);
	}
	else return _cur_node;
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
