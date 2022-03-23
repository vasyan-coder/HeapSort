#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void heapify(int *arr, int n, int i, long long int& C, long long int& M)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    //Левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    //Правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    //Если самый большой элемент не корень
    if (largest != i)
    {
        C++;
        swap(arr[i], arr[largest]);
        M++;

        //Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest, C, M);
    }
}

void heapSort(int* arr, int n, long long int &C, long long int &M)
{
    //Построение кучи
    int i = 0;
    for (i = 0; i < n; i++)
    {
        C++;
        heapify(arr, n, i, C, M);
    }



    //Извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        C++;
        //Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);
        M++;

        //Вызываем heapify на уменьшенной кучи
        heapify(arr, i, 0, C, M);
    }
}

//Вывод массива
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int n = 6;

    int* arr = new int[n];
    arr[0] = 12;
    arr[1] = 11;
    arr[2] = 13;
    arr[3] = 5;
    arr[4] = 6;
    arr[5] = 7;

    cout << "Массив до сортировки:\n";
    printArray(arr, n);

    auto start = high_resolution_clock::now(); //Время
    //Инициализация счётчиков 
    long long int C = 0;
    long long int M = 0;

    heapSort(arr, n, C, M);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Время выполнения алгоритма: "
        << (double)duration.count() / 100.0 << " мс" << endl;
    cout << "C = " << C << endl;
    cout << "M = " << M << endl;
    cout << "C + M = " << C + M << endl;

    cout << "Массив после сортировки:\n";
    printArray(arr, n);
    return 0;
}