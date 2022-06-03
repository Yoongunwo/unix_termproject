#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "textfilewriter.h"
#include "linkedlist.h"

extern Node* _cur_node;

int main(){
	char* file_name = "text.txt";

	int start_music_num;
	scanf("%d", &start_music_num);

	for(int i=0; i<start_music_num; i++){ //초기 음악 추가 append_left
		char* music_name = (char*)malloc(sizeof(char));
		scanf("%s", music_name);
		append_left(20, music_name);
	}	

	int command_num; // 명령어 개수
	scanf("%d", &command_num);

	for(int i=0; i<command_num; i++){ // 명령어 실행문
		char command[10];
		scanf("%s", command);

		if(strcmp(command, "add") ==0){
			char music_name[20];
			scanf("%s", music_name);
			append_left(20, music_name);
		}
		else if(strcmp(command, "del") ==0){
			char del_music[10];
			scanf("%s", del_music);
			delete(del_music);
		}
		else if(strcmp(command, "list") ==0){
	
		}
		else if(strcmp(command, "next") ==0){
			next();
		}
		else if(strcmp(command, "prev") ==0){
			prev();
		}
		else if(strcmp(command, "move") ==0){
			int location;
			scanf("%d", &location);
			get_node(location);
		}
		else if(strcmp(command, "play") ==0){
			print();
		}
		else if(strcmp(command, "clear") ==0){
			clear();
		}
		else if(strcmp(command, "quit") ==0){
			clear();
			printf("quit!");
			exit(1);
		}
		else if(strcmp(command, "load") ==0){
			FILE* fp = fopen(file_name, "r");
			if(fp == NULL){
				printf("Can't Find File!\n");
			}
			else {
				create_music_titles(fp);
				fclose(fp);
			}
		}
		else if(strcmp(command, "save") ==0)
		{
			write_file(file_name);
		}
		else printf("존재하지 않는 명령어");
		
	}
	return 0;
}
