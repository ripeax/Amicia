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
}#include <iostream>
#include <tchar.h>
#include <strsafe.h>
#include <conio.h>

#define BUFsz 256

using namespace std;

bool pwsh_p(){
    HANDLE stdinRd, stdinWr, stdoutRd, stdoutWr;
        DWORD readFromCmd();
        DWORD writeToCmd(CString command);
        int main(int argc,char* argv[])
        {
            SECURITY_ATTRIBUTES sa={sizeof(SECURITY_ATTRIBUTES), NULL, true};
            if(!CreatePipe(&stdinRd, &stdinWr, &sa, 1000000) || !CreatePipe(&stdoutRd,&stdoutWr, &sa, 1000000)) 
            {
                printf("CreatePipe()");
            }
            STARTUPINFO si;
            PROCESS_INFORMATION pi;
            GetStartupInfo(&si);
            si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
            si.wShowWindow = SW_HIDE;
            si.hStdOutput = stdoutWr;
            si.hStdError = stdoutWr;                  
            si.hStdInput = stdinRd; 

    // If powershell.exe is invoked, it does not work, however works for cmd.exe    
            //if(!CreateProcess(TEXT("C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"), NULL, NULL, NULL, TRUE,0, NULL, TEXT("C:\\Windows"), &si, &pi))
            if(!CreateProcess(NULL, TEXT("C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"), NULL, NULL, NULL, TRUE,0, NULL, TEXT("C:\\Windows"), &si, &pi))
            {
                printf("CreateProcess()");  
                printf("CreateProcess() failed in initiatecmd(CString,int) method",0);
                return -1;
            }

            writeToCmd(L"dir");
            Sleep(1000);
            readFromCmd();
            getchar();
            TerminateProcess(pi.hProcess,0);
            CloseHandle(pi.hProcess);
            return 0;

        }
        DWORD writeToCmd(CString command)
        {
            DWORD ret;
            DWORD numberofbyteswritten;
            command.AppendChar('\n');

            LPSTR command_ANSI;
            int size_needed = WideCharToMultiByte(CP_UTF8,0,command.GetString(),-1,NULL,0,NULL,NULL);
            command_ANSI = (LPSTR) calloc(1, ( size_needed + 1 )* sizeof(char));
            WideCharToMultiByte(CP_UTF8,0,command.GetString(),-1,command_ANSI,size_needed,NULL,NULL);

            ret = WriteFile(stdinWr, command_ANSI, size_needed-1, &numberofbyteswritten, NULL);
            if(ret==0)
            {
                printf("WriteFile()");
                printf("WriteFile() method failed in writeToCmd(CString) method",0);
                return 0;
            }

            CStringA temp;
            temp.Format("%d",numberofbyteswritten);
            temp += " bytes (Command:";
            temp+=command;
            temp+=") are successfully written to cmd";
            printf("%s",temp);
            return 1;
        }

        DWORD readFromCmd()
        {
            CString output_jsonstring;
            DWORD ret;
            DWORD dwRead;

            while(1)
            {
                DWORD totalbytesavailable;

                if(PeekNamedPipe(stdoutRd, NULL, 0, NULL, &totalbytesavailable, 0) == 0)
                {
                    printf("PeekNamedPipe()");
                    printf("PeekNamedPipe() method failed in responseHandler() method",0);
                    return 0;
                }
                if(totalbytesavailable != 0)
                {
                    char output_cmd[1000000];
                    if(ReadFile(stdoutRd, output_cmd, min(1000000,totalbytesavailable), &dwRead, NULL)==0)
                    {
                        printf("ReadFile()");
                        printf("ReadFile() method failed in responseHandler() method",0);
                        return 0;
                    }
                    int min = min(1000000,totalbytesavailable);
                    output_cmd[min]='\0';
                    printf("\n%s",output_cmd);
                }   
                if(totalbytesavailable == 0)
                    break;

                Sleep(100);
            }
            return 1;
        }
}
