#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

char** read_mas(int count) {
	char buffer[1024];
	char **mas=0;
	mas = malloc(sizeof(char *)*count);
	for (int i = 0; i < count; i++) {
		printf("String %d: ", i+1);
		fgets(buffer, 1024, stdin);
		mas[i] = (char *)malloc(sizeof(char)*(strlen(buffer) - 1));
		strncpy(mas[i], buffer, strlen(buffer) - 1);
	}
	return mas;
}

int number_count(char *str) {
	int numbers = 0;
	for (int i = 0; str[i] != NULL; i++) {
		if (str[i]>='0' && str[i]<='9') {
			numbers++;
		}
	}
	return numbers;
}
char number_two(char *str) {
	int numbers = 0;
	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			numbers++;
			if (numbers == 2)
				return str[i];
		}
	}
	return ' ';
}

void print_mas(char **mas, int count) {
	printf("\nSorted strings:\n");
	for (int i = 0; i < count; i++) {
		printf("%s, numbers in this string=%d", mas[i], number_count(mas[i]));
		if (number_count(mas[i]) >= 2)
			printf(", second digit in this string=%c", number_two(mas[i]));
		printf("\n");
	}
	
}
static int cmp(const void *p1, const void *p2){
    char * s1 = *(char**)p1;
    char * s2 = *(char**)p2;
    return number_count(s1) - number_count(s2);
};
void free_mas(char **mas, int count) {
	for (int i = 0; i < count; i++) {
		free(mas[i]);
	}
	free(mas);
}
int main() {
	char **strings = NULL;
	int count;
	printf("Enter quantity of strings\n");
	scanf("%d", &count);
	getchar();//eating '\n'
	if (count > 0) {
		strings = read_mas(count);
		//strings = sort(strings, count);
        qsort(strings, count, sizeof(char*), cmp);
		print_mas(strings, count);
		free_mas(strings, count);
	}
	else {
		printf("Quantity of strings must be greater than zero\n");
	}
	return 0;
}
