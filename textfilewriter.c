#include <stdio.h>

#define MAX_TITLE_SIZE 50

void create_music_titles(FILE* stream) {
	return;
}

void read_file(char* file_name) {
	return;
}

void write_file(char* file_name) {
	return;
}


void read_file(char* file_name) {
	FILE* fp = fopen(file_name, "r");

	if (fp == NULL) {
		printf("Can't Read File!\n");
		return;
	}

	else {
		// 첫 줄에는 곡의 개수가 입력된다.
		int song_num;
		char* arr[MAX_TITLE_SIZE] = NULL;
		fscanf(fp, "%d\n", &song_num);

		for (int i = 0; i < song_num; i++) {
			fscanf(fp, "%s\n", arr[i]);
		}

		// test

		for (int j = 0; j < song_num; j++) {
			printf("%s\n", arr[j]);
		}
	}

}
int main() {
	char* file_name = "Text.txt";

	read_file(file_name);
}

// 현재 컴파일이 안된다 왜이럼..?
