#include <stdio.h>

#include <stdbool.h>

#include <stddef.h>

#include "node.h"

bool empty(){
	Node* p = _head;
	if(p->next == NULL) return True;
	else return False;
}


size_t size(){
	size_t result = 0;
	Node* p = _head;
	while(p != _tail){
		p = p->next;
		++result;
	}
	return result;
}

void print(){
	Node* p = _head;
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}

void print_file(FILE* stream);

void clear(); // linked list clear 

Node* append_left(size_t n, char new_data[n]){
	for(size_t i = n-1;i<=0;--i){
		Node* newNode;
        	newNode->data = new_data[i];
		newNode->prev = NULL;
		newNode->next = _head;
	}
}

Node* insert_after(Node* cur_node, Node* new_node){ // cur node right append
        Node* curNode = _cur_node;
	Node* nextNode = curNode->next;
	for(size_t i = 0;i<n;++i){
                Node* newNode;
                newNode->data = new_data[i];
                newNode->prev = curNode;
                newNode->next = NULL;
        }
}

Node* append(size_t n, char new_data[n]){ //tail
	for(size_t i = 0;i<n;++i){
                Node* newNode;
                newNode->data = new_data[i];
                newNode->prev = _tail;
                newNode->next = NULL;
        }
}

Node* delete_node(Node* cur_node){
	Node* prevNode;
	Node* nextNode;
	prevNode = cur_node->prev;
	nextNode = cur_node->next;
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
}

Node* delete(char* data){
	Node* p = _head;
	while(p != NULL){
		if(p->data == data){
			break;
		}
		p = p->next;
	}
	delete_node(p);
}

Node* get_node(size_t index){
	Node* p = _head->next;
	for(size_t i = 0;i<index;++i) p = p->next;
	return p;
}

Node* first(){
	Node* p = _head;
	return p->data;
}

Node* last(){
	Node* p = _tail;
        return p->data;
}

Node* next(){
	Node* p = _cur_node;
        return p->next->data;
}

Node* prev(){
	Node* p = _cur_node;
        return p->prev->data;
}
