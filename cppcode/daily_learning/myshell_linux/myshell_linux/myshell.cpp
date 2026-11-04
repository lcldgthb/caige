#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#define COMMAND_SIZE 1024

#define MAXARGC 128
char* a_argv[MAXARGC];
int a_argc = 0;
const char*  GetUseName()
{
	const char* name = getenv("USER");
	return name == NULL ? "None" : name;
}
const char* GetHostName()
{
	const char* name = getenv("HOSTNAME");
	return name == NULL ? "None" : name;
}
const char* GetPwd()
{
	const char* name = getenv("PWD");
	return name == NULL ? "None" : name;
}
bool GetCommandLine(char* out, int size)
{

}
bool CommandParse(char* commandline)
{
#define SEP " "
	a_argc = 0;
	
	a_argv[a_argc++] = strtok(commandline, SEP);
	while ((bool)(a_argv[a_argc++] = strtok(nullptr, SEP)));
	a_argc--;
	return true;
}

int main()
{
	printf("%s@%s: %s ",GetUseName(),GetHostName(),GetPwd());
	char commandline[COMMAND_SIZE];
	char *c = fgets(commandline,sizeof(commandline), stdin);
	if (c == NULL)return 1;
	commandline[strlen(commandline) - 1] = 0;
	//Ω‚Œˆ√¸¡Ó
	std::string command = commandline;
	CommandParse(commandline);
	//÷¥––√¸¡Ó
	
	printf("echo %s", commandline);
	return 0;
}