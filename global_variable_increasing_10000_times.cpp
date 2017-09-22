// global_variable_increasing_10000_times.cpp 

#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int data = 0;
void func();

DWORD WINAPI MyThreadFunc(LPVOID lpParameter)
{
	for (int i = 0; i < 10000; i++)
		data++;

	printf(" now data is : %d\n", data);
	printf("thread finished!\n");
	return 0;
}

int main()
{
	func();
	
	_getch(); // the wait
	printf("\nthe Global Data is : %d\n", data);
	
	_getch();
	return 0;           
}

void func()
{
	CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
}
