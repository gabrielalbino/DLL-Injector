#pragma once
#include <string>
#include <Windows.h>
#include <tlhelp32.h>
#include <list>

class Injector
{
public:
	Injector();
	Injector(std::string processName, std::string dllName);
	DWORD getProcessId();
	HANDLE getProcessHandle();
	void setProcessName(std::string processName);
	void setDllPath(std::string dllName);
	bool createProcessHandle();
	BOOL deleteProcessHandle();
	std::list<std::string> getAllProcessNames();
	bool findProcessID();
	bool Inject();
	~Injector();
private:
	std::string dllPath, processName;
	HANDLE hProcess;
	DWORD processID;
};

