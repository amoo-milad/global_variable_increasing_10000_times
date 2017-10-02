// global_variable_increasing_10000_times.cpp 

#include "stdafx.h"
#include <conio.h>
#include <windows.h>

#define NUM_INC  1000000

int data = 0;
void func();

DWORD WINAPI MyThreadFunc(LPVOID lpParameter);

HANDLE mutex = NULL;
HANDLE hConnectionIsOpen = NULL;

int main()
{
	//mutex = CreateMutex(NULL, FALSE, L"cafe_bazaar__file_is_open");
	mutex = CreateMutex(NULL, FALSE, NULL);

	//hConnectionIsOpen = CreateEvent(NULL, TRUE, TRUE/FALSE, NULL);
	//
	//SetEvent(hConnectionIsOpen);
	//ResetEvent(hConnectionIsOpen);
	//
	//WaitForSingleObject(hConnectionIsOpen, INFINITE);
	//CloseHandle(hConnectionIsOpen);

	func();
	
	printf("\n* Global Data is : %d *\n\n", data);
	
	_getch();
	CloseHandle(mutex);
	return 0;           
}

void func()
{
	HANDLE h1 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE h2 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE h3 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE h4 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE handles[] = {h1, h2, h3, h4};
	
	WaitForMultipleObjects(4,handles,TRUE,INFINITE);

	CloseHandle(h1);
	CloseHandle(h2);
	CloseHandle(h3);
	CloseHandle(h4);
}

DWORD WINAPI MyThreadFunc(LPVOID lpParameter)
{
	for (int i = 0; i < NUM_INC; i++)
	{
		WaitForSingleObject(mutex, INFINITE);
		++data;
		ReleaseMutex(mutex);
	}

	//	WaitForSingleObject(mutex, INFINITE);
	printf("now data is: %d\t end of thread!\n\n", data);
	//	ReleaseMutex(mutex);
	return 0;
}
