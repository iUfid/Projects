#include <stdio.h>


void arrayInput(int array[], int);
void arrayOutput(int array[], int);
void bubbleSort(int array[], int);


int main() {

    int len;
	printf("Введите длину массива: ");
	scanf("%d", &len);
	int array[len];

    arrayInput(array, len);
    bubbleSort(array, len);

	printf("Отсортированный массив: ");
    arrayOutput(array, len);


    return 0;
}


void arrayInput(int array[], int len) {
	printf("Введите элементы массива: ");
	for (int i = 0; i < len; i++) {
		scanf("%d", &array[i]);
	}
}


void arrayOutput(int array[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}


void bubbleSort(int array[], int len) {
	int tmp;
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len-1-i; j++) {
			if (array[j] > array[j+1]) {
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}
}


