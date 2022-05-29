#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_SIZE 50 
// We assume TOTAL_NUM_OF_MUSIC is less than 50
// "print_file" will be used in read_file.
void print_file(FILE* stream);


void create_music_titles(FILE* stream) {
	char music_name[10];
	scanf("%s", music_name);
	fprintf(stream, "%s", music_name);
	
	return;
}

void write_file(char* file_name) {
	FILE* fp = fopen(file_name, "a");

	if(fp == NULL){
		printf("Can't Find File!\n");
	}	
	else{
		create_music_titles(fp);
		fclose(fp);
	}
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

