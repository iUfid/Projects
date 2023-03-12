#include <iostream>


void arrayInput(int arr[], int);
void arrayOutput(int arr[], int, std::string outputString = "Массив: ");
void arraySort(int arr[], int);
void arrayReverse(int arr[], int);
int findMaxInArray(int arr[], int);
int findMinInArray(int arr[], int);


int main() {
    int length;
    std::cout << "Введите длину массива: ";
    std::cin >> length;

    int arr[length];
    arrayInput(arr, length);

    std::string keyword;
    std::cout << "Выбор действия: ";
    std::cin >> keyword;

    if (keyword == "Output" || keyword == "output") {
        arrayOutput(arr, length);
    } else

    if (keyword == "Sort" || keyword == "sort") {
        arraySort(arr, length);
        std::string outputString = "Отсортированный массив: ";
        arrayOutput(arr, length, outputString);
    } else

    if (keyword == "Max" || keyword == "max") {
        int maxelem = findMaxInArray(arr, length);
        std::cout << "Максимальный элемент массива: " << maxelem << std::endl;
    } else

    if (keyword == "Min" || keyword == "min") {
        int minelem = findMinInArray(arr, length);
        std::cout << "Минимальный элемент массива: " << minelem << std::endl;
    } else 
    
    if (keyword == "Reverse" || keyword == "reverse") {
        arrayReverse(arr, length);
        std::string outputString = "Развернутый массив: ";
        arrayOutput(arr, length, outputString);
    } else
    
    if (keyword == "Revsort" || keyword == "revsort") {
        arraySort(arr, length);
        arrayReverse(arr, length);
        std::string outputString = "Отсортированный массив: ";
        arrayOutput(arr, length, outputString);
    } else {
        std::cout << "Такого действия нет" << std::endl;
    }



    return 0;
}


void arrayInput(int arr[], int length) {
    std::cout << "Введите элементы: ";
    for (int i = 0; i < length; i++) {
        std::cin >> arr[i];
    }
}


void arrayOutput(int arr[], int length, std::string outputString) {
    std::cout << outputString;
    for (int i = 0; i < length-1; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << arr[length-1] << std::endl;
}


void arraySort(int arr[], int length) {
    int tmp;
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void arrayReverse(int arr[], int length) {
    int tmp;
    for (int i = 0; i < length / 2; i++) {
        tmp = arr[i];
        arr[i] = arr[length-1-i];
        arr[length-1-i] = tmp;
    }
}

int findMaxInArray(int arr[], int length) {
    int max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } 
    }
    
    return max;
}

int findMinInArray(int arr[], int length) {
    int min = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } 
    }
    
    return min;
}

