#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>


void task1() {
	float sum = 0;
	float sr = 0;
	float d = 0;
	int count = 0;
	FILE* inf;
	inf = fopen("D:/проги/lab19/lab19/temp.txt", "r");
	if (inf == NULL) {
		printf("ERROR");
		return 0;
	}
	while (!feof(inf)) {
		fscanf(inf, "%f", &d);
		printf("%f\n", d);
		sum += d;
		printf("%f\n", sum);
		count += 1;
		printf("%d\n\n\n", count);
	}
	sr = sum / count;
	printf("%f", sr);
	fclose(inf);

}
void task2() {
	FILE* file;
	FILE* file2;
	int d;
	char fname[50];
	char fname2[50];
	char txt[5] = ".txt";
	char chang[8] = "parity2";
	printf("Введите имя файла\n");
	scanf("%s", &fname);
	for (int i = 0; i < 50; i++) {
		fname2[i] = fname[i];
	}
	strcat(fname2, chang);
	strcat(fname2, txt);
	strcat(fname, txt);
	printf("%s\n", fname);
	file = fopen(fname, "r");
	if (file == NULL) {
		printf("ERRr");
		return 0;
	}
	printf("%s\n", fname2);
	file2 = fopen(fname2, "w");
	if (file2 == NULL) {
		printf("ERR");
		return 0;
	}
	printf("\naaaaaaaaaaaaa\n");
	while (!feof(file)) {
		fscanf(file, "%d", &d);
		if (d > 100) {
			fprintf(file2, "%d\n", d / 2);
		}
		else
		{
			fprintf(file2, "%d\n", d);
		}
	}
	fclose(file);
	fclose(file2);
}

void task3() {
	FILE* file;
	FILE* file2;
	char wrd[50];
	char txt[5] = ".txt";
	char fname2[30];
	char help = 'h';
	file = fopen("winter.txt", "r");
	if (file == NULL) {
		printf("ERR");
		return 0;
	}
	puts("Введите имя файла");
	scanf("%s", fname2);
	strcat(fname2, txt);
	file2 = fopen(fname2, "w");
	int j = 0;
	while (!feof(file)) {
		int i = 1;
		char d, d1;
		fgets(wrd, 50, file);
		for (j = 0; j < strlen(wrd) - 1; j++) {
			if ((wrd[j] == ' ') || (wrd[j] == "\n")) {
				i++;
				j++;
				break;
			}
		}
		if (i % 2 == 0) {
			for (int k = strlen(wrd); k > j; k--) {
				wrd[k + 1] = wrd[k];
				wrd[k] = wrd[k - 1];
			}
			wrd[j] = '!';

		}
		fprintf(file2, "%s", wrd);
	}
	fclose(file);
	fclose(file2);
}

void main() {
	setlocale(LC_ALL, "ru_RU");
	task3();
}