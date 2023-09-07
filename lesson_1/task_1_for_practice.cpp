#include <iostream>

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
            arr[i][j] = rand() % 10;
        }
    }
}

bool IsAllItemsInColumnDifferent(int** arr, int row, int col_number) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i][col_number] == arr[j][col_number]) {
                return false;
            }
        }
    }
    return true;
}

int NumberOfColumnsWithDifferentItems(int** arr, int row, int col) {
    int numberOfColumns = 0;
    for (int col_num = 0; col_num < col; col_num++) {
        if (IsAllItemsInColumnDifferent(arr, row, col_num) == true) {
            numberOfColumns++;
        }
    }
    return numberOfColumns;
}

void OutputArrayToConsole(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows, columns, result;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Etner number of columns: ";
    std::cin >> columns;
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
    }
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
    OutputArrayToConsole(array, rows, columns);
    result = NumberOfColumnsWithDifferentItems(array, rows, columns);
    std::cout << "Number of columns with different items: " << result;

    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}