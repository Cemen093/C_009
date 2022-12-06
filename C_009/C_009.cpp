#include <iostream>
using namespace std;

void view(int** array, int x, int y)
{
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

//Задание 1. Написать функцию, добавляющую строку двумерному массиву в конец.
void task01(int**& array, int& x, int& y)
{
    int** arr = new int* [x+1];
    for (size_t i = 0; i < x + 1; i++)
        arr[i] = new int[y];
    arr[x] = new int[y];

    for (size_t i = 0; i < y; i++)
        arr[x][i] = 0;

    for (size_t i = 0; i < x; i++)
        arr[i] = array[i];
    array = arr;
    x++;
}
//Задание 2. Написать функцию, добавляющую строку двумерному массиву в начало.
void task02(int**& array, int& x, int& y)
{
    int** arr = new int* [x + 1];
    for (size_t i = 0; i < x + 1; i++)
        arr[i] = new int[y];
    arr[0] = new int[y];

    for (size_t i = 0; i < y; i++)
        arr[0][i] = 0;

    for (size_t i = 0; i < x; i++)
        arr[i + 1] = array[i];
    array = arr;
    x++;
}

//Задание 3. Написать программу, которая поэлементно суммирует два динамических двумерных массива, заполненных случайными числами, и сохраняет результат в третьем массиве.Размеры исходных массивов задаются пользователем.
void task03()
{
    int x1, y1;
    cout << "input x arr 1 >> ";
    cin >> x1;
    cout << "input y arr 1 >> ";
    cin >> y1;
    int x2, y2;
    cout << "input x arr 2 >> ";
    cin >> x2;
    cout << "input y arr 2 >> ";
    cin >> y2;
    int** arr1 = new int* [x1];
    for (size_t i = 0; i < x1; i++)
        arr1[i] = new int[y1];
    for (size_t i = 0; i < x1; i++)
        for (size_t j = 0; j < y1; j++)
            arr1[i][j] = rand() % 30;
    int** arr2 = new int* [x2];
    for (size_t i = 0; i < x2; i++)
        arr2[i] = new int[y2];
    for (size_t i = 0; i < x2; i++)
        for (size_t j = 0; j < y2; j++)
            arr2[i][j] = rand() % 30;


    int x3 = x1 > x2 ? x1 : x2, y3 = y1 > y2 ? y1 : y2;
    int** arr3 = new int* [x3];
    for (size_t i = 0; i < x3; i++)
        arr3[i] = new int[y3];
    for (size_t i = 0; i < x3; i++)
        for (size_t j = 0; j < y3; j++)
            arr3[i][j] = 0;

    for (size_t i = 0; i < x1; i++)
        for (size_t j = 0; j < y1; j++)
            arr3[i][j] += arr1[i][j];
    for (size_t i = 0; i < x2; i++)
        for (size_t j = 0; j < y2; j++)
            arr3[i][j] += arr2[i][j];

    cout << "arr1" << endl;
    view(arr1, x1, y1);
    cout << "arr2" << endl;
    view(arr2, x2, y2);
    cout << "arr3" << endl;
    view(arr3, x3, y3);
}

//Задание 4. 
// Напишите функцию умножения матриц.Матрица представляет собой таблицу чисел.
// Произведением матрицы A размером M x N(M строк, N столбцов) на матрицу B размером N x K является матрица C размером M x K такова, 
// что cij = ai1b1j + ai2b2j + … + aiNbNj, для 1 <= i <= M и 1 <= j <= K, 
// где axy — элемент, находящийся на пересечении строки x и столбца y матрицы A;
//■ bxy – элемент, находящийся на пересечении строки x и столбца y матрицы B;
//■ cxy – элемент, находящийся на пересечении строки x и столбца y матрицы C.

void task03(int** mA, int** mB, int m, int n, int k, int**& mC)
{
    mC = new int* [m];
    for (size_t i = 0; i < m; i++)
        mC[i] = new int[k];

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < k; j++)
            mC[i][j] = 0;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            for (size_t z = 0; z < n; z++)
            {
                mC[i][j] += mA[i][z] * mB[z][j];
            }
        }
    }
}

int main()
{
    srand(time(NULL));

    cout << "task 01" << endl;
    int x = 3, y = 10;
    int** arr = new int* [x];
    for (size_t i = 0; i < x; i++) 
        arr[i] = new int[y];
    for (size_t i = 0; i < x; i++)
        for (size_t j = 0; j < y; j++)
            arr[i][j] = i + j;

    view(arr, x, y);
    task01(arr, x, y);
    view(arr, x, y);

    for (size_t i = 0; i < x; i++)
        delete[] arr[i];
    delete[] arr;


    cout << "task 02" << endl;
    int x2 = 3, y2 = 10;
    int** arr2 = new int* [x2];
    for (size_t i = 0; i < x2; i++)
        arr2[i] = new int[y2];
    for (size_t i = 0; i < x2; i++)
        for (size_t j = 0; j < y2; j++)
            arr2[i][j] = i + j;

    view(arr2, x2, y2);
    task01(arr2, x2, y2);
    view(arr2, x2, y2);

    for (size_t i = 0; i < x2; i++)
        delete[] arr2[i];
    delete[] arr2;


    cout << "task 03" << endl;
    int m = 3, n = 4, k = 5;

    int** mA = new int* [m];
    for (size_t i = 0; i < m; i++)
        mA[i] = new int[n];
    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            mA[i][j] = rand() % 30;

    int** mB = new int* [n];
    for (size_t i = 0; i < n; i++)
        mB[i] = new int[k];
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < k; j++)
            mB[i][j] = rand() % 30;
    int** mC;

    task03(mA, mB, m,n,k,mC);
    view(mA, m, n);
    view(mB, n, k);
    view(mC, m, k);
}