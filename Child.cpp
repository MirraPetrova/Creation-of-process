#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[])
{
    int size = atoi(argv[1]);
    long* arr = new long[size];
    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 2]);
    }
    
    //int X = atoi(argv[size + 4]);

    long sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i] * arr[i];

    cout << "Sum of squares: " << sum << endl;
    Sleep(120);
    cin >> sum;
    delete[] arr;
    return 0;
}