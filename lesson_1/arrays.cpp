#include <iostream>

// func to set array manually
void ManualDataInitialization(int** arr, int size);

// func to set array randomly
void RandomDataInitialization(int** arr, int size);

//func to print entire array to console
void DefaultPrint(int** arr, int size);

// func to print top left triangle
void PrintTopLeftTriangle(int** arr, int size);

// func to print bottom left triangle
void PrintBottomLeftTriangle(int** arr, int size);

// func to print top right triangle
void PrintTopRightTriangle(int** arr, int size);

// func to print bottom right triangle
void PrintBottomRightTriangle(int** arr, int size);


void ManualDataInitialization(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "Enter array[" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }
}

void RandomDataInitialization(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int random = rand() % 10;
            arr[i][j] = random;
        }
    }
}

void DefaultPrint(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void PrintTopLeftTriangle(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; i + j < size; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void PrintBottomLeftTriangle(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void PrintTopRightTriangle(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int space = 0; space < i; space++) {
            std::cout << "  ";
        }
        
        for (int j = size - 1; j >= i; j--) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void PrintBottomRightTriangle(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int space = 0; space < size - 1 - i; space++) {
            std::cout << "  ";
        }
        
        for (int j = size - 1; j >= size - i - 1; j--) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main(){
    int size;
    std::cout << "Enter number of rows (square matrix): ";
    std::cin >> size;
    int** array = new int*[size];
    for (int i = 0; i < size; i++) {
        array[i] = new int[size];
    }
    std::cout << "Do you want to initialize array manualy?\n\t1 - Yes\n\t2 - No\n";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            ManualDataInitialization(array, size);
            break;
        case 2:
            RandomDataInitialization(array, size);
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
    }

    std::cout << "Array:" << std::endl;
    DefaultPrint(array, size);
    std::cout << "Top Left Triangle: " << std::endl;
    PrintTopLeftTriangle(array, size);
    std::cout << "Bottom Left Triangle: " << std::endl;
    PrintBottomLeftTriangle(array, size);
    std::cout << "Top Right Triangle: " << std::endl;
    PrintTopRightTriangle(array, size);
    std::cout << "Bottom Right Triangle: " << std::endl;
    PrintBottomRightTriangle(array, size);

    for (int i = 0; i < size; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}