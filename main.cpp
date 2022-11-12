#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace chrono;

const int N = 100;

void coutarr(int arr[], int N) {
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
}

void bubblesort(int *arr, int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
}

void shakersort(int *arr, int N) {
    for (int j = 0; j < N / 2; j++) {
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
        for (int i = N - 2; i > 0; i--) {
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
    }
}

void insertsort(int *arr, int N) {
    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--)
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
                i -= 1;
            }
    }
}

int binarysearch(int arr[], int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "ru_RU");
    int arr[N] = {};
    int commander;
    cout << "Запустить программу?\nда - 1\nнет - 0" << endl;
    cin >> commander;
    switch (commander) {
        case 1: {
            // 1. Целочисленный массив из 100 элементов
            cout << "1 - Создать массив; 0 - Закончить цикл" << endl;
            int firststart;
            cin >> firststart;
            while (firststart) {
                cout << "[ ";
                for (int i = 0; i < N; i++) {
                    arr[i] = -99 + rand() % (199);
                    cout << arr[i] << " ";
                }
                cout << "]" << endl;
                break;
            }
        }
        case 2: {
            // 2. Сортировка массива
            int sortname, cycleone, bubble[N] = {}, shaker[N] = {}, insert[N] = {};
            cout << "1 - Отсортировать массив; 0 - Закончить цикл" << endl;
            cin >> cycleone;
            while (cycleone) {
                cout << "1 - Bubble sort; 2 - Shaker sort; 3 - Insert sort" << endl;
                cin >> sortname;
                switch (sortname) {
                    case 1: {
                        auto start = steady_clock::now();
                        for (int i = 0; i < N; i++) {
                            bubble[i] = arr[i];
                        }
                        bubblesort(bubble, N);
                        auto end = steady_clock::now();
                        auto elapsed = duration_cast<nanoseconds>(end - start);
                        coutarr(bubble, N);
                        cout << endl;
                        cout << "Сортировка заняла " << elapsed.count() << " наносекунд\n";
                        cout << endl;
                        break;
                    }
                    case 2: {
                        auto start = steady_clock::now();
                        for (int i = 0; i < N; i++) {
                            shaker[i] = arr[i];
                        }
                        shakersort(shaker, N);
                        auto end = steady_clock::now();
                        auto elapsed = duration_cast<nanoseconds>(end - start);
                        coutarr(shaker, N);
                        cout << endl;
                        cout << "Сортировка заняла " << elapsed.count() << " наносекунд\n";
                        cout << endl;
                        break;
                    }
                    case 3: {
                        auto start = steady_clock::now();
                        for (int i = 0; i < N; i++) {
                            insert[i] = arr[i];
                        }
                        insertsort(insert, N);
                        auto end = steady_clock::now();
                        auto elapsed = duration_cast<nanoseconds>(end - start);
                        coutarr(insert, N);
                        cout << endl;
                        cout << "Сортировка заняла " << elapsed.count() << " наносекунд";
                        cout << endl;
                        break;
                    }
                    default:
                        cout << endl;
                }
                cout << "\nВыбрать другую сортировку? да - 1; нет - 0" << endl;
                cin >> cycleone;
            }
        }
        case 3: {
            // Поиск минимального и максимального в неотсротированом массиве
            int arrMaxMin[N] = {};
            for (int i = 0; i < N; i++)
                arrMaxMin[i] = arr[i];
            auto startFind = steady_clock::now();
            for (int i = 0; i < N - 1; i++)
                if (arrMaxMin[i] > arrMaxMin[i + 1])
                    swap(arrMaxMin[i], arrMaxMin[i + 1]);
            for (int i = N - 1; i > 0; i--)
                if (arrMaxMin[i] < arrMaxMin[i - 1])
                    swap(arrMaxMin[i], arrMaxMin[i - 1]);
            auto endFind = steady_clock::now();
            auto resultFind = duration_cast<nanoseconds>(endFind - startFind);
            // 3. Поиск максмимального и минимального элемента.
            cout << "Поиск максмимального и минимального элемента. " << "Введите sorted или unsorted:" << endl;
            string array;
            int j = 0, shaker[N] = {};
            while (j != 2) {
                cin >> array;
                if (array == "unsorted") {
                    cout << "Min и max элемент массива: " << arrMaxMin[0] << ", " << arrMaxMin[N - 1] << endl;
                    j += 1;
                    cout << "Поиск элементов занял: " << resultFind.count() << " наносекунд\n";
                } else if (array == "sorted") {
                    for (int i = 0; i < N; i++) {
                        shaker[i] = arr[i];
                    }
                    shakersort(arr, N);
                    auto startFindS = steady_clock::now();
                    auto endFindS = steady_clock::now();
                    auto resultFindS = duration_cast<nanoseconds>(endFindS - startFindS);
                    cout << "Min и max элемент массива: " << arr[0] << ", " << arr[N - 1] << endl;
                    cout << "Поиск элементов занял: " << resultFindS.count() << " наносекунд\n\n";
                    j += 1;
                }
            }
        }
        case 4: {
            // 4. Среднее значение минимального и максимального элемента. Индексы равные этому значению и их кол-во.
            int avg = (arr[N - 1] + arr[0]) / 2, k = 0;
            cout << endl << "Среднее значение: " << avg << endl;
            for (int i = 0; i < N; i++)
                if (arr[i] == avg) {
                    k += 1;
                    cout << "arr[" << i << "] = ";
                }
            if (k != 0) cout << avg << " ";
            cout << "Количество равных значений: " << k << endl;
        }
        case 5: {
            shakersort(arr, N);
            int a, cnt(0);
            cout << "\nВведите число а:\n";
            cin >> a;
            for (int i = 0; i < N; i++) {
                if (arr[i] < a) {
                    cnt++;
                } else
                    break;
            }
            if (cnt > 0)
                cout << "Количество элементов, которые меньше числа а: " << cnt << "\n";
            else
                cout << "\nНет таких элементов";
        }
        case 6: {
            shakersort(arr, N);
            int b, cnt(0);
            cout << "\nВведите число b:\n";
            cin >> b;
            for (int i = N - 1; i >= 0; i--) {
                if (arr[i] > b) {
                    cnt++;
                } else
                    break;
            }
            if (cnt > 0)
                cout << "Количество элементов, которые больше числа а: " << cnt << "\n";
            else
                cout << "\nНет таких элементов";
        }
        case 7: {
            cout << "\nБинарный поиск: 1 - запустить цикл; 0 - закончить цикл" << endl;
            int cycleseven;
            cin >> cycleseven;
            while (cycleseven) {
                cout << "\nВведите число в диапазоне [-99,99]\n";
                int x;
                cin >> x;
                {
                    auto start = steady_clock::now();
                    int result = binarysearch(arr, x, 0, N - 1);
                    auto end1 = steady_clock::now();
                    auto elapsed = duration_cast<nanoseconds>(end1 - start);
                    if (result == -1)
                        cout << "Число не найдено";
                    else
                        cout << "Элемент найден по индексу: " << result;
                    cout << endl;
                    cout << "Бинарный поиск занял " << elapsed.count() << " наносекунд\n";
                }
                cout << endl;
                //------------------------------------------------------------------------------------------------------
                auto start = steady_clock::now();
                for (int i = 0, k = 0; i < N; i++) {
                    if (arr[i] == x) {
                        cout << "Введенное число находится в массиве с номером " << i << endl;
                        k += 1;
                    }
                    if (k == 0 && i == 99) cout << "Введенное число не входит в массив\n";
                }
                auto endTime = steady_clock::now();
                auto elapsed = duration_cast<nanoseconds>(endTime - start);
                cout << "Перечисление элементов заняло  " << elapsed.count() << " наносекунд\n";
                cout << "\nПродолжить цикл? 1 - да; 0 - нет\n";
                cin >> cycleseven;
            }
        }
        case 8: {
            int a, b;
            cout << "\nВведите индексы элементов, которые вы хотите поменять: \n";
            cin >> a >> b;
            swap(arr[a], arr[b]);
            for (int i = 0; i < N; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        default:
            cout << endl;
    }
}