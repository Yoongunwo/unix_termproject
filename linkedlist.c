
#include "linkedlist.h"

#include <stddef.h>
#include "node.h"


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
        Node* p = _head;
        while(p != NULL){
                Node* nextNode = p->next;
                p->data = NULL;
                p->next = NULL;
                p = nextNode;
        }
        _head = NULL;
        _tail = NULL;
}

Node* append_left(size_t n, char new_data[n]){
        for(size_t i = n-1;i<=0;--i){
                Node* newNode;
                newNode->data = new_data[i];
                newNode->prev = NULL;
                newNode->next = _head;
        }
        return newNode;
}

Node* insert_after(Node* cur_node, Node* new_node){
        Node* curNode = cur_node;
        Node* newNode = new_node;

        newNode->next = curNode->next;
        newNode->prev = curNode;
        curNode->next = newNode;
        return newNode;
}

Node* append(size_t n, char new_data[n]){
        for(size_t i = 0;i<n;++i){
                Node* newNode;
                newNode->data = new_data[i];
                newNode->prev = _tail;
                newNode->next = NULL;
        }
        return _tail;
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
        return p;
}

Node* last(){
        Node* p = _tail;
        return p;
}

Node* next(){
        Node* p = _cur_node;
        return p;
}

Node* prev(){
        Node* p = _cur_node;
        return p;
}

int main(){
	int paly_num;
	int instruction_num:;
	scanf("%d",play_num);
	char* strArr[play_num];
	for(int i = 0; i< play_num; ++i){
		scanf("%s",strArr[i]);
	}
	//append(play_num, strArr[play_num]);	
	scanf("%d",instruction_num);
	char* str;
	for(int i = 0;i<intstruction_num;++i){
		scanf("%s",str);
		//file write
		//add - left_append
		//list - print list
		//play - print("%s is now playing!",cur_node);
		//next - cur_node = cur_node->next;
		//	 if(cur_node == NULL) cur_node = _head;
		//clear - print("LinkedList is cleared!");
		//quit - print("LinkedList is cleared!\nquit!");
	}
	//print_file
	return 0;
}
