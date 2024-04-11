#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 구조체 정의: 행렬 구조체
typedef struct {
    int rows;
    int cols;
    int **data; // 2차원 배열의 메모리를 동적으로 할당하기 위한 이중 포인터
} Matrix;

// 함수 프로토타입 선언
Matrix createMatrix(int rows, int cols);
void initializeMatrix(Matrix *mat);
void printMatrix(Matrix mat);
Matrix addMatrix(Matrix mat1, Matrix mat2);
Matrix subtractMatrix(Matrix mat1, Matrix mat2);
Matrix transposeMatrix(Matrix mat);
Matrix multiplyMatrix(Matrix mat1, Matrix mat2);
void freeMatrix(Matrix mat);

int main() {
    printf("[-----[josungjae] [2023078001]-----]\n");
    int rows, cols;

    // 행렬의 행(row)과 열(column)의 값을 입력 받음
    printf("행렬의 행(row)과 열(column)의 값을 입력하세요: ");
    scanf("%d %d", &rows, &cols);
    // 행렬 A와 B 생성 및 초기화
    Matrix A = createMatrix(rows, cols);
    Matrix B = createMatrix(rows, cols);
    initializeMatrix(&A);
    initializeMatrix(&B);

    // Print Matrix-A와 B 행렬 출력
    printf("Matrix A:\n");
    printMatrix(A);
    printf("\nMatrix B:\n");
    printMatrix(B);
    printf("\n");

    // Add Matrix-A+B 연산 및 출력
    printf("Addition (A + B):\n");
    Matrix addition = addMatrix(A, B);
    printMatrix(addition);
    printf("\n");

    // Subtract Matrix-A-B 연산 및 출력
    printf("Subtraction (A - B):\n");
    Matrix subtraction = subtractMatrix(A, B);
    printMatrix(subtraction);
    printf("\n");

    // Transpose Matrix-A의 전치행렬 T 구하고 출력
    printf("Transpose of A:\n");
    Matrix transpose = transposeMatrix(A);
    printMatrix(transpose);
    printf("\n");

    // Multiply Matrix-A X B 연산 및 출력
    printf("Multiplication (A * B):\n");
    Matrix multiplication = multiplyMatrix(A, B);
    printMatrix(multiplication);
    printf("\n");

    // 메모리 해제
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(addition);
    freeMatrix(subtraction);
    freeMatrix(transpose);
    freeMatrix(multiplication);

    return 0;
}

// 행렬 생성 함수
Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

// 행렬 초기화 함수: 랜덤 값으로 행렬 초기화
void initializeMatrix(Matrix *mat) {
    srand(time(NULL));
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mat->data[i][j] = rand() % 10; // 0부터 9 사이의 랜덤 값으로 초기화
        }
    }
}

// 행렬 출력 함수
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

// 행렬 덧셈 함수
Matrix addMatrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    return result;
}

// 행렬 뺄셈 함수
Matrix subtractMatrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }
    return result;
}

// 행렬 전치 함수
Matrix transposeMatrix(Matrix mat) {
    Matrix result = createMatrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            result.data[j][i] = mat.data[i][j];
        }
    }
    return result;
}

// 행렬 곱셈 함수
Matrix multiplyMatrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat2.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < mat1.cols; k++) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }
    return result;
}

// 행렬 메모리 해제 함수
void freeMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        free(mat.data[i]);
    }
    free(mat.data);
}
