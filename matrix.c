#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ����ü ����: ��� ����ü
typedef struct {
    int rows;
    int cols;
    int **data; // 2���� �迭�� �޸𸮸� �������� �Ҵ��ϱ� ���� ���� ������
} Matrix;

// �Լ� ������Ÿ�� ����
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

    // ����� ��(row)�� ��(column)�� ���� �Է� ����
    printf("����� ��(row)�� ��(column)�� ���� �Է��ϼ���: ");
    scanf("%d %d", &rows, &cols);
    // ��� A�� B ���� �� �ʱ�ȭ
    Matrix A = createMatrix(rows, cols);
    Matrix B = createMatrix(rows, cols);
    initializeMatrix(&A);
    initializeMatrix(&B);

    // Print Matrix-A�� B ��� ���
    printf("Matrix A:\n");
    printMatrix(A);
    printf("\nMatrix B:\n");
    printMatrix(B);
    printf("\n");

    // Add Matrix-A+B ���� �� ���
    printf("Addition (A + B):\n");
    Matrix addition = addMatrix(A, B);
    printMatrix(addition);
    printf("\n");

    // Subtract Matrix-A-B ���� �� ���
    printf("Subtraction (A - B):\n");
    Matrix subtraction = subtractMatrix(A, B);
    printMatrix(subtraction);
    printf("\n");

    // Transpose Matrix-A�� ��ġ��� T ���ϰ� ���
    printf("Transpose of A:\n");
    Matrix transpose = transposeMatrix(A);
    printMatrix(transpose);
    printf("\n");

    // Multiply Matrix-A X B ���� �� ���
    printf("Multiplication (A * B):\n");
    Matrix multiplication = multiplyMatrix(A, B);
    printMatrix(multiplication);
    printf("\n");

    // �޸� ����
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(addition);
    freeMatrix(subtraction);
    freeMatrix(transpose);
    freeMatrix(multiplication);

    return 0;
}

// ��� ���� �Լ�
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

// ��� �ʱ�ȭ �Լ�: ���� ������ ��� �ʱ�ȭ
void initializeMatrix(Matrix *mat) {
    srand(time(NULL));
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mat->data[i][j] = rand() % 10; // 0���� 9 ������ ���� ������ �ʱ�ȭ
        }
    }
}

// ��� ��� �Լ�
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

// ��� ���� �Լ�
Matrix addMatrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    return result;
}

// ��� ���� �Լ�
Matrix subtractMatrix(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }
    return result;
}

// ��� ��ġ �Լ�
Matrix transposeMatrix(Matrix mat) {
    Matrix result = createMatrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            result.data[j][i] = mat.data[i][j];
        }
    }
    return result;
}

// ��� ���� �Լ�
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

// ��� �޸� ���� �Լ�
void freeMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        free(mat.data[i]);
    }
    free(mat.data);
}
