#include <iostream>
using namespace std;


void arrayInput(int array[], int);
void arrayOutput(int array[], int);
void arrayBubbleSort(int array[], int);


/////
int main() {
	int lenarr;
	cout << "Введите длину массива: ";
	cin >> lenarr;

	int array[lenarr];
	
	arrayInput(array, lenarr);
	arrayBubbleSort(array, lenarr);
	arrayOutput(array, lenarr);
	
	return 0;
}
/////



void arrayInput(int array[], int len) {
	cout << "Введите элементы массива: ";
	for (int i = 0; i < len; i++) {
		cin >> array[i];
	}
}


void arrayOutput(int array[], int len) {
	cout << "Отсортированный массив: ";
	for (int i = 0; i < len; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}


void arrayBubbleSort(int array[], int len) {
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


