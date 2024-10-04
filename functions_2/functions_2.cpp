#include <iostream>
#include <algorithm>
#include <iomanip>
#define SIZE 10
#define ROWS 10
#define COLS 10

using namespace std;



int isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);   
}

int DasyInMonth(int year, int month)
{
    int day = 0;
    for (int i = 1; i < month; i++)
    {
        switch (i)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            day += 31;
            break;
        case 4: case 6: case 9: case 11:
            day += 30;
            break;
        case 2:
            if (isLeap(year) == true) {
                day += 29;
            }
            else {
                day += 28;
            }
            break;
        default:
            break;
        }
    }
    return day;
}


void FindDifference(int year1, int month1, int day1, int year2, int month2, int day2)
{
    int day_from_start1 = 0, day_from_start2 = 0,result;
    for (int i = 0; i < year1; i++)
    {
        if (isLeap(i) == true) {
            day_from_start1 += 366;
        }
        else {
            day_from_start1 += 365;
        }
    }
    for (int i = 0; i < year2; i++)
    {
        if (isLeap(i) == true) {
            day_from_start2 += 366;
        }
        else {
            day_from_start2 += 365;
        }
    }

    day_from_start1 += DasyInMonth(year1,month1) + day1;
    day_from_start2 += DasyInMonth(year2, month2) + day2;
    if (day_from_start1 > day_from_start2) {
        result = day_from_start1 - day_from_start2;
    }
    else {
        result = day_from_start2 - day_from_start1;
    }
    cout << "Difference between this dates is " << result << endl;
}

int CalculateArOfArray(int arr[SIZE])
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }
    return sum / SIZE;
}

void CountTypes(int arr[SIZE])
{
    int count_plus = 0, count_minus = 0, count_zero = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] < 0) {
            count_minus++;
        }
        else if (arr[i] > 0)
        {
            count_plus++;
        }
        else {
            count_zero++;
        }
    }
    cout << "Count of nums higher than 0: " << count_plus << endl;
    cout << "Count of nums equal 0: " << count_zero << endl;
    cout << "Count of nums less than 0: " << count_minus << endl;
}

template<typename T>
int swap(T num1, T num2)
{
    T temp = num1;
    num1 = num2;
    num2 = temp;
}

template<typename T>
T TasksWithArr(T arr[ROWS][COLS])
{
    T max, min;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << setw(2)<< arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
    max = arr[0][0];
    min = arr[0][0];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == j) {
                if (arr[i][j] < min) {
                    min = arr[i][j];
                }
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
            }
        }
    }
    cout << "Max num on general diagonal: " << max << endl;
    cout << "Min num on general diagonal: " << min << endl;
    cout << endl;

    for (int j = 0; j < COLS; j++)
    {
        for (int i = 0; i < ROWS; i++)
        {           
            sort(arr[i],arr[i] + COLS);
        }
    }

    cout << "Arr after sort:" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << setw(2) <<arr[i][j];
        }
        cout << endl;
    }
    return 0;
}

int MaxDividerOfTwoNums(int num1, int num2)
{
    if (num2 == 0) {
        return num1;
    }
    return MaxDividerOfTwoNums(num2, num1 % num2);
}


int main()
{
    srand(time(NULL));
    int arr_1[ROWS][COLS];
    int arr[SIZE];
    
    FindDifference(2004, 2, 2, 2005, 2, 2);
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 10;
    }
    cout << CalculateArOfArray(arr) << endl;
    int arr1[SIZE] = {0,-1,-3,-4,0,0,1,3,54,10};
    CountTypes(arr1);
    
    TasksWithArr(arr_1);
    int result = MaxDividerOfTwoNums(50, 90);
    cout << result;
}



