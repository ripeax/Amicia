/*
HANDLE CreateFileMappingA(
  [in]           HANDLE                hFile,
  [in, optional] LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
  [in]           DWORD                 flProtect,
  [in]           DWORD                 dwMaximumSizeHigh,
  [in]           DWORD                 dwMaximumSizeLow,
  [in, optional] LPCSTR                lpName
);

HANDLE CreateFileMappingNumaA(
  [in]           HANDLE                hFile,
  [in, optional] LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
  [in]           DWORD                 flProtect,
  [in]           DWORD                 dwMaximumSizeHigh,
  [in]           DWORD                 dwMaximumSizeLow,
  [in, optional] LPCSTR                lpName,
  [in]           DWORD                 nndPreferred
);
*/

// #include "winapi.h"
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#include <iostream>
#include <string_view>

#include <vector>

#define BUF_SIZE 65536

void privExt(const wchar_t* priv, BOOL bEnable)
{
    HANDLE           hToken;
    TOKEN_PRIVILEGES tp;
    BOOL             status;
    DWORD            error;

    // open process token
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
        DisplayError(TEXT("OpenProcessToken"), GetLastError());

    // get the luid
    if (!LookupPrivilegeValue(NULL, pszPrivilege, &tp.Privileges[0].Luid))
        DisplayError(TEXT("LookupPrivilegeValue"), GetLastError());

    tp.PrivilegeCount = 1;

    // enable or disable privilege
    if (bEnable)
        tp.priv[0].Attributes = SE_PRIVILEGE_ENABLED;
    else
        tp.priv[0].Attributes = 0;

    // enable or disable privilege
    status = AdjustTokenPrivileges(hToken, FALSE, &tp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

    // It is possible for AdjustTokenPrivileges to return TRUE and still not succeed.
    // So always check for the last error value.
    error = GetLastError();
    if (!status || (error != ERROR_SUCCESS))
        DisplayError(TEXT("AdjustTokenPrivileges"), GetLastError());

    // close the handle
    if (!CloseHandle(hToken))
        DisplayError(TEXT("CloseHandle"), GetLastError());
}

int fMap(){
  // req
  HANDLE  file = NULL;
  LPSECURITY_ATTRIBUTES map_attr = FILE_MAP_ALL_ACCESS;
  DWORD priv = PAGE_EXECUTE_WRITECOPY | SEC_WRITECOMBINE; // 0x80, 0x40000000
  DWORD mxSzH = ...; DWORD mxSzL = ...; LPCSTR name = "mapped object"

  hMap = CreateFileMappingA(file, map_attr, protect, mxSzH, mxSzL, name);
  if(hMap == NULL){
    std::cout << "[!] fmap error: " << GetLastError() << std::endl;
  } else std::cout << "[.] fmap created..." << endl;

  priv(TEXT("SeLockMemoryPrivilege"), FALSE);
  pbuf = (LPTSTR) MapViewOfFile(hMap,          
         FILE_MAP_ALL_ACCESS | FILE_MAP_LARGE_PAGES, 
         0,
         0,
         BUF_SIZE);

  UnmapViewOfFile(pBuf);
  CloseHandle(hMap);
}
