#include <stdio.h>

#define MAX_TITLE_SIZE 50

void create_music_titles(FILE* stream) {
	return;
}

void write_file(char* file_name) {
	
	return;
}


void read_file(char* file_name) {
	FILE* fp = fopen(file_name, "r");

	if(fp == NULL){
		printf("Can't Find File!\n");
		return;
	}

	else{
		int num_of_song;
		int max = 100;
		char line[max];
		char *pLine;
		int counter = 1;
		fscanf(fp, "%d", &num_of_song);

		printf("Total number of songs is %d\n", num_of_song);
		pLine = fgets(line, max, fp); // delete trash value
		while(!feof(fp) && (counter <= num_of_song)){
			pLine = fgets(line, max, fp);
			printf("%d: %s", counter,pLine);
			counter++;
		}
		fclose(fp);
	}

}
int main() {
	char* file_name = "./Text.txt";

	read_file(file_name);
	read_file("sexy.txt");
}
