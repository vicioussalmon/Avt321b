#include <iostream>

// Функція для вводу матриці
void inputMatrix(double** matrix, int rows, int cols) {
    std::cout << "Введіть матрицю " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

// Функція для виводу матриці
void printMatrix(double** matrix, int rows, int cols) {
    std::cout << "Матриця " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Функція для виділення пам'яті під матрицю
double** allocateMatrix(int rows, int cols) {
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
    }
    return matrix;
}

// Функція для звільнення пам'яті, видалення матриці
void deallocateMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Функція для розв'язання задачі лінійного програмування симплекс-методом
void solveLinearProgrammingProblem(double** matrix, int rows, int cols) {
    // Додайте код для симплекс-методу тут
}

int main() {
    int numVariables; // Кількість змінних
    int numConstraints; // Кількість обмежень

    std::cout << "Введіть кількість змінних: ";
    std::cin >> numVariables;

    std::cout << "Введіть кількість обмежень: ";
    std::cin >> numConstraints;

    // Виділення пам'яті під матрицю коефіцієнтів
    double** coefficientMatrix = allocateMatrix(numConstraints + 1, numVariables + numConstraints + 1);

    // Введення коефіцієнтів цільової функції
    std::cout << "Введіть коефіцієнти цільової функції:\n";
    for (int j = 0; j < numVariables; j++) {
        std::cin >> coefficientMatrix[0][j];
    }

    // Введення коефіцієнтів обмежень
    for (int i = 1; i <= numConstraints; i++) {
        std::cout << "Введіть коефіцієнти обмеження " << i << ":\n";
        for (int j = 0; j < numVariables; j++) {
            std::cin >> coefficientMatrix[i][j];
        }
    }

    // Введення значень вектора обмежень
    std::cout << "Введіть вектор обмежень:\n";
    for (int i = 1; i <= numConstraints; i++) {
        std::cin >> coefficientMatrix[i][numVariables + i];
    }

    // Виведення проміжних симплекс таблиць
    bool printTables;
    std::cout << "Вивести проміжні симплекс таблиці? (0 - ні, 1 - так): ";
    std::cin >> printTables;

    // Розв'язання задачі лінійного програмування симплекс-методом
    solveLinearProgrammingProblem(coefficientMatrix, numConstraints + 1, numVariables + numConstraints + 1);

    // Звільнення пам'яті, видалення матриці
    deallocateMatrix(coefficientMatrix, numConstraints + 1);

    return 0;
}
