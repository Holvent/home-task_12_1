#include <iostream>
using namespace std;

//Задание 1.
bool IsLeapYear(int year) {
    return (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0)) ?
        true : false;
}
int CountDay(int m, int y) {
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        return IsLeapYear(y) ? 29 : 28;
        break;
    default:
        break;
    }
}
int DaysOfMonth(int month, int year) {
    int sum = 0;
    for (int i = 1; i < month; i++) {
        sum += CountDay(i, year);
    }
    return sum;
}
void DiffOfDays(int fDay, int sDay, int fMonth, int sMonth, int fYear, int sYear) {

    int fSum = 0, sSum = 0;
    for (int i = fYear; i < sYear; i++) {
        if (IsLeapYear(i)) sSum += 366;
        else sSum += 365;
    }
    fSum += IsLeapYear(fYear) ? DaysOfMonth(fMonth, fYear) :
        DaysOfMonth(fMonth, fYear);
    sSum += DaysOfMonth(sMonth, sYear);
    fSum += fDay;
    sSum += sDay;
    cout << sSum - fSum<<endl;
}
//Задание 2.
const int SIZE = 5;
void createArray(int array[]){
    cout << "Array" << endl;
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
        cout << array[i] << " ";
    }
    cout << endl;
}
double averege(int array[]){
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
            sum += array[i];
    return sum / (SIZE);
}
//Задание 3.
void sumNum(int array[]) {
    int sumpos = 0;
    int sumneg = 0;
    int sumzero = 0;
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > 0)sumpos++;
        if (array[i] < 0)sumneg++;
        if (array[i] == 0)sumzero++;
    }
    cout << endl;
    cout << "Sum pos el = " << sumpos << endl;
    cout << "Sum neg el = " << sumneg << endl;
    cout << "Sum zero el = " << sumzero << endl;
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    //Задание 1.
    //Написать функцию, которая принимает две даты
    //(т.е.функция принимает шесть параметров) и вычисляет
    //разность в днях между этими датами.Для решения этой
    //задачи необходимо также написать функцию, которая
    //определяет, является ли год високосным.
    
    cout << "Home task #12.1.1\n\n";
    DiffOfDays(6, 21, 5, 3, 2016, 2022);
    system("pause");
    system("cls");

    //Задание 2.
    //Написать функцию, определяющую среднее
    //арифметическое элементов передаваемого ей массива.
    
    cout << "Home task #12.1.2\n\n";
    int arr[SIZE];
    createArray(arr);
    cout << "Average = " << averege(arr) << endl;
    system("pause");
    system("cls");

    //Задание 3.
    //Написать функцию, определяющую количество
    //положительных, отрицательных и нулевых элементов
    //передаваемого ей массива.

    cout << "Home task #12.1.3\n\n";
    int arr2[SIZE];
    createArray(arr2);
    sumNum(arr2);
}