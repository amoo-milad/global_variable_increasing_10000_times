// global_variable_increasing_10000_times.cpp 

#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int data = 0;
int increment = 1;
HANDLE* func();
DWORD WINAPI MyThreadFunc(LPVOID lpParameter);

int main()
{
	HANDLE handles = func();
	
	WaitForMultipleObjects(4,&handles,TRUE,INFINITE); // is '&handles' right?
	printf("\n* Global Data is : %d *\n\n", data);
	
	_getch();
	return 0;           
}

HANDLE* func()
{
	HANDLE h1 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE h2 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE h3 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE h4 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE handles[] = {h1,h2,h3,h4};
	return handles;
}

DWORD WINAPI MyThreadFunc(LPVOID lpParameter)
{
	for (int i = 0; i < 10000; i++)
		data++;
	//	data = data + increment;

	printf("now data is: %d\t end of thread!\n\n", data);
	return 0;
}
