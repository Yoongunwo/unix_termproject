
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
	if(_head != NULL){
		Node *p = first();
		Node *q = p->next;
		while(p!= _tail){
			free(p->data);
			p = q;
			q = q->next;
		}
		free(_head);
		free(_tail);
		free(_cur_node);
		_head = NULL;
		_tail = NULL;
		_cur_node = NULL;
	}
	printf("LinkedList is cleared!\n");
}

Node* append_left(size_t n, char new_data[n]){

    Node* newNode = (Node*)malloc(sizeof(Node));

    if(_tail == NULL){
        _tail = (Node*)malloc(sizeof(Node));
        _head = (Node*)malloc(sizeof(Node));
        _cur_node = (Node*)malloc(sizeof(Node));
        
	_tail->prev = newNode;
        newNode->next = _tail;
        _head->next = newNode;
        newNode->prev = _head;

    }
    else{
        newNode->next = _head->next;
        newNode->prev = _head;
        _head->next->prev = newNode;
        _head->next = newNode;
    }
    newNode->data = new_data;
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
	      while(find_node != index){
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
