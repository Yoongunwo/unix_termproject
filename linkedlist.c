
#include <stddef.h>
#include "linkedlist.h"

static Node* _head = NULL;

static Node* _tail = NULL;

static Node* _cur_node = NULL;

bool empty(){
        Node* p = _head;

        if(p->next == NULL) return true;
        else return false;
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
        while(p -> next != _tail){
                printf("%s ",p->next->data);
        	p = p->next;
	}
	printf("]\n");

}

void play_music(){
	printf("%s is now playing!\n", _cur_node->data);
}

void print_file(FILE* stream){
        int size;
        char* buffer;
        fseek(stream, 0, SEEK_END);
        size = ftell(stream);
        buffer = malloc(size + 1);
        memset(buffer, 0, size + 1);


//        while(fgets(file_buff, size + 1, stream) != NULL){
//                printf("%s", buffer);
//                memset(buffer, 0, size + 1);
//        }

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

    if(_tail == NULL){
        _tail = (Node*)malloc(sizeof(Node));
        _head = (Node*)malloc(sizeof(Node));
        _cur_node = (Node*)malloc(sizeof(Node));
        _cur_node = newNode;
        _tail->prev = newNode;
        newNode->next = _tail;
        _head->next = newNode;
        _head->next->prev = _head;

    }
    else{
        newNode->next = _head->next;
        _head->next->prev = newNode;
        newNode->prev = _head;
        newNode->prev->next = newNode;
    }
    newNode->data = new_data;
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
        Node* newNode = (Node*)malloc(sizeof(Node));
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
        Node* p = _head->next;
	Node* temp;
        while(p != NULL){
                if(strcmp(data, p->data) == 0){
                        temp->next = p->next;
			temp->prev = p->prev;
			free(p);
			p = temp->next;
                }
		else{
			temp = p;
			p = p->next;
		}
        }
        return _cur_node;
}

Node* get_node(size_t index){ //move
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
	if(_cur_node->next == _tail){
		return _cur_node;
	}
	else _cur_node = _cur_node -> next;
	return _cur_node;
}

Node* prev(){
	if(_cur_node->prev == _head){
		return _cur_node;
	}
	else _cur_node = _cur_node->prev;
	return _cur_node;
}