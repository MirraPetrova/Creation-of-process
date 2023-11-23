#include <iostream>
#include <windows.h>
#include<string>
using namespace std;

int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    long* arr = new long[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int X;
    cout << "Enter X(width): ";
    cin >> X;

    string cmdLine = "Child.exe ";
    cmdLine += to_string(size) + " ";
    for (int i = 0; i < size; i++)
        cmdLine += to_string(arr[i]) + " ";
    //cmdLine += to_string(X) + " ";
   
    int len = cmdLine.length();
    char* cmdLineChar = new char[len + 1];
    strcpy_s(cmdLineChar, len + 1, cmdLine.c_str());

    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USEPOSITION;
    si.dwX = X;

    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));
    if (!CreateProcess(NULL, cmdLineChar, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        cout << "Error creating child process: " << GetLastError() << endl;
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    delete[] arr;
    delete[] cmdLineChar;

    return 0;
}
