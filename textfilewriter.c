#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_SIZE 50 
// We assume TOTAL_NUM_OF_MUSIC is less than 50

void create_music_titles(FILE* stream) {
	return;
}

void write_file(char* file_name) {
	FILE* fp = fopen(file_name, "w");

	if(fp == NULL){
		printf("Can't Find File!\n");
	}	
	else{
		long num_of_song = 0;
		char* arr[MAX_TITLE_SIZE] = {0}; 

		printf("How many songs?: ");
		scanf("%ld\n", &num_of_song);

		for(int i=0; i<num_of_song; i++){
			*(arr + i) = (char*)malloc(sizeof(char*));
			fgets(arr[i], MAX_TITLE_SIZE, stdin);
		}
		
		fprintf(fp, "%ld\n", num_of_song);

		for (int i=0; i<num_of_song; i++){
			fprintf(fp,"%s", arr[i]);
			free(arr[i]);
		}
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
		if(num_of_song == -1){
			printf("Empty File!\n");
			return;
		}

		for(int i=0; i<num_of_song; i++){
			*(title_of_song + i) = (char*)malloc(sizeof(char*));
			fgets(title_of_song[i], MAX_TITLE_SIZE, fp); 
		}

		for (int i=0; i<num_of_song; i++){
			printf("%s", title_of_song[i]);
			free(*(title_of_song+i));
		}

		fclose(fp);
		return;
	}
	return;

}
int main() {
	char* file_name = "./Text.txt";

	read_file(file_name);
	read_file("sexy.txt");
	write_file(file_name);
}
