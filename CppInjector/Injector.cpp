#include "Injector.h"

Injector::Injector(){
}


Injector::~Injector(){
}

Injector::Injector(std::string processName, std::string dllPath){
	this->processName = processName;
	this->dllPath = dllPath;
}

void Injector::setDllPath(std::string dllPath) {
	this->dllPath = dllPath;
}

void Injector::setProcessName(std::string processName) {
	this->processName = processName;
}

DWORD Injector::getProcessId() {
	return this->processID;
}

HANDLE Injector::getProcessHandle() {
	return this->hProcess;
}

std::list<std::string> Injector::getAllProcessNames() {
	std::list<std::string> processList;
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE systemSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	if (Process32First(systemSnapshot, &pEntry)) {
		do {
			processList.push_front(pEntry.szExeFile);
		} while (Process32Next(systemSnapshot, &pEntry));
	}
	processList.sort();
	return processList;
}

bool Injector::findProcessID() {
	PROCESSENTRY32 pEntry;
	BOOL valid;
	std::string lastProcess;
	pEntry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE systemSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	if (Process32First(systemSnapshot, &pEntry)) {
		do {
			this->processID = pEntry.th32ProcessID;
			lastProcess = pEntry.szExeFile;
			valid = Process32Next(systemSnapshot, &pEntry);
		} while (valid && (lastProcess != this->processName));
		if (!valid) {
			this->processID = NULL;
			return false;
		}
	}
	return true;
}

BOOL Injector::deleteProcessHandle() {
	return CloseHandle(this->hProcess);
}

bool Injector::createProcessHandle() {
	this->hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, processID);
	if (this->hProcess != NULL) {
		return true;
	}
	else {
		return false;
	}
}


