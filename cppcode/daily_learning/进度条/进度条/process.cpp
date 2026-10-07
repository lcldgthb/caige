#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"process.h"
//#include<unistd.h>
#include<windows.h>
#define SIZE 101
#define STEY '#'
void processv1()
{
	char buffer[SIZE];
	memset(buffer, 0, SIZE);
	const char* tmp = "|\\/-";
	int cnt = 0;
	double total = 100;
	while (cnt <=total)
	{
		double rate = cnt * 100 / total;
		for (int i = 0; i < cnt; i++)
			buffer[i] = STEY;
		printf("[%-100s][%.1f][%c]\r", buffer,rate,tmp[cnt%4]);
		fflush(stdout);
		cnt++;
		Sleep(100);
	}
	printf("\n");
}
void process(double total,double current)
{
	if (current >= total)current = total;
	static int a = 0;
	char buffer[SIZE];
	memset(buffer, 0, SIZE);
	const char* tmp = "|\\/-";
	int fill = (int)(current*100 / total);
		double rate = current * 100 / total;
		for (int i = 0; i < fill; i++)
			buffer[i] = STEY;
		printf("[%-100s][%.1f%%][%c]\r", buffer, rate, tmp[a % 4]);
		fflush(stdout);
		a++;
		Sleep(100);
}
void downloadv1()
{
	double cur = 0;
	double tatol = 1024.0;
	while (cur <= tatol)
	{
		cur += 20;
		process( tatol, cur);
		
	}
	printf("\n");
}
typedef void (*fucptr)(double total, double current);
void download(fucptr bf)
{
	double cur = 0;
	double tatol = 1024.0;
	while (cur <= tatol)
	{
		cur += 80;
		bf(tatol, cur);

	}
	printf("\n");
	printf("download:%.1f,sucessfully!\n",tatol);
}
void Upload(fucptr bf)
{
	double cur = 0;
	double tatol = 1024.0;
	while (cur <= tatol)
	{
		cur += 80;
		bf(tatol, cur);

	}
	printf("\n");
	printf("Upload:%.1fkB,sucessfully!\n", tatol);
}
int main()
{
	//process();
	download(process);
	Upload(process);
	return 0;
}
//#include <stdio.h>
//#include <string.h>
////#include <unistd.h>
//#include<Windows.h>
//int main(void)
//{
//    char buffer[101];
//    int spinner_index = 0;
//    const char spinner[] = "|/-\\";
//
//    memset(buffer, ' ', 100);
//    buffer[100] = '\0';
//
//    for (int i = 0; i <= 100; i++) {
//        if (i > 0) {
//            buffer[i - 1] = '#';
//        }
//
//        printf("\r[%s][%3d%%][%c]",
//            buffer,
//            i,
//            spinner[spinner_index]);
//
//        fflush(stdout);
//
//        spinner_index = (spinner_index + 1) % 4;
//        Sleep(100);
//    }
//
//    printf("\n");
//
//    return 0;
//}