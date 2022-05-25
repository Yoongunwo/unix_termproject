static Node* _head = NULL;

static Node* _tail = NULL;

static Node* _cur_node = NULL;

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
