#include <stdio.h>

#define max_title_size 50

void create_music_titles(FILE* stream) {
	return;
}

void write_file(char* file_name) {
	FILE* fp = fopen(file_name, "w");

	if(fp == NULL){
		printf("can't find file!\n");
	}	
	else{
		long num_of_song = 0;
		const char* arr[50];
		char str[100];

		printf("how many songs?: ");
		scanf("%ld", &num_of_song);
		gets(str); // delete trash value;

		for(int i=0; i<num_of_song; i++){
			gets(str);			
			arr[i] = str;
		}
		
		fprintf(fp, "%ld", num_of_song);
		for (int i=0; i<num_of_song; i++){
			fprintf(fp,"%s\n", arr[i]);
		}
			
	}
	return;
}


void read_file(char* file_name) {
	FILE* fp = fopen(file_name, "r");

	if(fp == NULL){
		printf("can't find file!\n");
		return;
	}

	else{
		int num_of_song;
		int max = 100;
		char line[max];
		char *pline;
		int counter = 1;
		fscanf(fp, "%d", &num_of_song);

		printf("total number of songs is %d\n", num_of_song);
		pline = fgets(line, max, fp); // delete trash value
		while(!feof(fp) && (counter <= num_of_song)){
			pline = fgets(line, max, fp);
			printf("%d: %s", counter,pline);
			counter++;
		}
		fclose(fp);
	}

}
