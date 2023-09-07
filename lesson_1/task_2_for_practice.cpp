#include <iostream>

/*
Знайти і вивести строчки, які схожі на першу строку матриці.
Строки схожі - коли в них повністю співпадають множини елементів, з яких кожна з них складається.
*/

// func to manual initialization
void ManualDataInitialization(int** arr, int row, int col);

// func to automatic (random) initialization
void RandomDataInitialization(int** arr, int row, int col);

// func to output
void OutputArrayToConsole(int** arr, int row, int col);

// func to check is to sets are similar
bool IsSimilar(int** arr, int* first_row_items, int set_size, int row_number, int size);

// func to print similar rows to first row to console 
void SimilarRowsToConsole (int** arr, int row, int col);


void ManualDataInitialization(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << "Enter element " << j + 1 << " from row " << i + 1 << ": ";
            std::cin >> arr[i][j];
        }
    }
}

void RandomDataInitialization(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = rand() % 2;
        }
    }
}

void OutputArrayToConsole(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool IsSimilar(int** arr, int* first_row_items, int set_size, int row_number, int size) {
    int* cur_row = new int[size];
    for (int i = 0; i < size; i++) {
        cur_row[i] = arr[row_number][i];
    }
    // creating set from cur_row
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (cur_row[i] < cur_row[j]) {
                int buf = cur_row[i];
                cur_row[i] = cur_row[j];
                cur_row[j] = buf;
            }
        }
    }
    int new_set_size = 1;
    for (int i = 1; i < size; i++) {
        if (cur_row[i] != cur_row[i - 1]) {
            new_set_size += 1;
        }
    }
    int* set = new int[new_set_size];
    int index = 1;
    set[0] = cur_row[0];
    for (int i = 1; i < size; i++) {
        if (cur_row[i] != cur_row[i - 1]) {
            set[index] = cur_row[i];
            index++;
        }
    }
    // comparison block
    if (new_set_size != set_size) {
        // clearing memory
        delete[] set;
        delete[] cur_row;
        return false;
    }
    for (int i = 0; i < set_size; i++) {
        if (first_row_items[i] != set[i]) {
            // clearing memory
            delete[] set;
            delete[] cur_row;
            return false;
        }
    }
    // clearing memory
    delete[] set;
    delete[] cur_row;
    return true;
}

void SimilarRowsToConsole (int** arr, int row, int col) {
    int* first_row = new int[col];
    std::cout << "First row: " << std::endl;
    for (int i = 0; i < col; i++) {
        first_row[i] = arr[0][i];
        std::cout << arr[0][i] << ' ';
    }
    std::cout << std:: endl;
    // make set from array
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            if (first_row[i] < first_row[j]) {
                int buf = first_row[i];
                first_row[i] = first_row[j];
                first_row[j] = buf;
            }
        }
    }
    int new_set_size = 1;
    for (int i = 1; i < col; i++) {
        if (first_row[i] != first_row[i - 1]) {
            new_set_size += 1;
        }
    }
    int* set = new int[new_set_size];
    int index = 1;
    set[0] = first_row[0];
    for (int i = 1; i < col; i++) {
        if (first_row[i] != first_row[i - 1]) {
            set[index] = first_row[i];
            index++;
        }
    }

    for (int i = 1; i < row; i++) {
        // calling func to check is it similar
        if (IsSimilar(arr, set, new_set_size, i, col) == true) {
            std::cout << "Similar row (" << i + 1 << "): " << std::endl;
            for (int j = 0; j < col; j++) {
                std::cout << arr[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
    delete[] set;
    delete[] first_row;
}

int main() {
    int rows, columns;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> columns;

    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
    }
    // menu for choosing type of initialization
    std::cout << "Do you want to initialize array manualy?\n\t1 - Yes\n\t2 - No\n";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            ManualDataInitialization(array, rows, columns);
            break;
        case 2:
            RandomDataInitialization(array, rows, columns);
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
    }
    // output array
    OutputArrayToConsole(array, rows, columns);
    // output first row and similar rows to it
    SimilarRowsToConsole(array, rows, columns);

    // clearing memory
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}