// global_variable_increasing_10000_times.cpp 

#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int data = 0;
int increment = 1;
void func();
DWORD WINAPI MyThreadFunc(LPVOID lpParameter);

int main()
{
	func();
	
	printf("\n* Global Data is : %d *\n\n", data);
	
	_getch();
	return 0;           
}

void func()
{
	HANDLE h1 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE h2 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE h3 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE h4 = CreateThread(NULL, 0, &MyThreadFunc, 0, 0, NULL);
	HANDLE handles[] = {h1,h2,h3,h4};
	WaitForMultipleObjects(4,handles,TRUE,INFINITE); // is '&handles' right?
}

DWORD WINAPI MyThreadFunc(LPVOID lpParameter)
{
	for (int i = 0; i < 10000000; i++)
		data = data + increment;
		//++data;

	printf("now data is: %d\t end of thread!\n\n", data);
	return 0;
}
