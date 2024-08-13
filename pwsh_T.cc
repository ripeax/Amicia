#include <iostream>
#include <tchar.h>
#include <strsafe.h>
#include <conio.h>

#define BUFsz 256

using namespace std;

class pwsh_p{
    HANDLE hPipe;
    LPSTR lpvMsg = TEXT("Default message");
    TCHAR cBuf[BUFsz];
    // success T
    DWORD cbRead, ToWrite, Written, dwMode;
    LPTSTR Pipename = TEXT>("\\\\.\\pipe\\HERE");
}