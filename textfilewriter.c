#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

#define MAX_TITLE_SIZE 50 


void create_music_titles(FILE* stream) {
	char* num_of_song;
	fgets(num_of_song, MAX_TITLE_SIZE, stream);
	
	if(feof(stream)!=0) return;
	else{
		char title_of_song[MAX_TITLE_SIZE];
		
		for(int i=0; i<atoi(num_of_song); i++){
			char* music = (char*)malloc(sizeof(char));
			fgets(title_of_song, MAX_TITLE_SIZE, stream);
			if(i == atoi(num_of_song)-1) strcpy(music, title_of_song);
			else strncpy(music, title_of_song, strlen(title_of_song)-1);
			append_left(MAX_TITLE_SIZE, music);
		}
	}
	return;
}


void write_file(char* file_name) {
	FILE* fp = fopen(file_name, "w");
	if(fp == NULL){
		printf("Can't Find File!\n");
	}	
	else{
		print_file(fp);
	}
	fclose(fp);
	return;
}


void read_file(char* file_name) {
	FILE* fp = fopen(file_name, "r");

	if(fp == NULL){
		printf("Can't Find File!\n");
		return;
	}

	else{
		int num_of_song = -1;
		char* title_of_song[MAX_TITLE_SIZE] = {0};
		fscanf(fp, "%d\n", &num_of_song);

		// If file is empty
		if(num_of_song == -1){
			printf("Empty File!\n");
			return;
		}

		for(int i=0; i<num_of_song; i++){
			*(title_of_song + i) = (char*)malloc(sizeof(char*));
			fgets(title_of_song[i], MAX_TITLE_SIZE, fp); 
		}

		// if I have to control the command(player),
		int command_num = -1;
		char* command[MAX_TITLE_SIZE] = {0};
		fscanf(fp, "%d\n", &command_num);

		if(command_num == -1){
			printf("command is empty!\n");
		}
		
		for(int i=0; i<command_num; i++){
			*(command + i) = (char*)malloc(sizeof(char*));
			fgets(command[i], MAX_TITLE_SIZE, fp);
		}

		for (int i=0; i<num_of_song; i++){
			printf("%s", title_of_song[i]);
			free(*(title_of_song+i));
		}

		for (int i=0; i<command_num; i++){
			printf("%s", command[i]);
			free(*(command + i));
		}

		fclose(fp);
		return;

	}

}

/*
int main(){
	FILE* fp = fopen("Text.txt", "r");
	create_music_titles(fp);
}
*/
