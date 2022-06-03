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
            if(title_of_song[strlen(title_of_song)-1] == '\n')
                title_of_song[strlen(title_of_song)-1] ='\0';
            strcpy(music,title_of_song);
			append_left(MAX_TITLE_SIZE, music);
		}
		return;
	}
}


void write_file(char* file_name) {
	FILE* fp = fopen(file_name, "w");
	if(fp == NULL){
		printf("Can't Find File!\n");
	}	
	else{
		print_file(fp);
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
		create_music_titles(fp);
		fclose(fp);
	}	
}