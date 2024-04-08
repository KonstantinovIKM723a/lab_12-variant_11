#include <iostream>;
#include "windows.h";
using namespace std;

const int n = 10;

int mainDiagSum(int a[][n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i][i];
    return sum;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    int a[n][n];

    //Створюємо масив n*n елементів
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) a[i][j] = rand() % 10;

    //Виводимо масив на екран
    cout << "Масив " << n << "*" << n << " елементів:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    //Знаходимо мінімальний і максимальний елементи
    int min = a[0][0], max = min, minI = 0, minJ = 0, maxI = 0, maxJ = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            if (min > a[i][j]) {
                min = a[i][j];
                minI = i;
                minJ = j;
            }
            if (max < a[i][j]) {
                max = a[i][j];
                maxI = i;
                maxJ = j;
            }
        }

    //Міняємо місцями перші зустріті мінімальний і максимальний елементи
    int temp = a[minI][minJ];
    a[minI][minJ] = a[maxI][maxJ];
    a[maxI][maxJ] = temp;

    //Виводимо масив на екран
    cout << "Масив з поміняними місцями першими зустрітими максимальним " << max << " (" << "i = " << minI << ", j = " << minJ << ") та мінімальним " << min << " (" << "i = " << maxI << ", j = " << maxJ << ") елементами: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    //Міняємо місцями всі елементи з мінімальним значенням на максимальне значення і навпаки
    temp = a[minI][minJ];
    a[minI][minJ] = a[maxI][maxJ];
    a[maxI][maxJ] = temp;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j] == min) {
                a[i][j] = max;
            } 
            else if (a[i][j] == max) {
                a[i][j] = min;
            }
        }

    cout << "Масив з поміняними місцями усіма максимальними (" << max << ") та мінімальними (" << min << ") елементами: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    //Обчислимо суму елементів, що знаходяться на головної діагоналі масиву
    cout << "сума елементів, що знаходяться на головної діагоналі масиву: " << mainDiagSum(a) << endl;

}
