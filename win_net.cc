#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
//#include <stdio.h>

#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

//mvoe
int wnet() {
  return 0;
}

using namespace std;

class wNet{

    WSADATA wsaData;

    int res;

    BOOL startup(){
        res = WSAStartup(MAKEWORD(2,2), &wsaData);
        if(res != 0){
            cout << "[!] wnet failed " << endl;
            return FALSE;
        }
    }

    wNet(){
            struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;

            ZeroMemory( &hints, sizeof(hints) );
            hints.ai_family   = AF_INET;
            hints.ai_socktype = SOCK_STREAM;
            hints.ai_protocol = IPPROTO_TCP;

            #define DEFAULT_PORT "27015"

            // Resolve the server address and port
            iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
            if (iResult != 0) {
                printf("getaddrinfo failed: %d\n", iResult);
                WSACleanup();
                return ;

                #define DEFAULT_PORT "27015"

            // Resolve the server address and port
            iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
            if (iResult != 0) {
                printf("getaddrinfo failed: %d\n", iResult);
                WSACleanup();
                return 1;
            }
            SOCKET ConnectSocket = INVALID_SOCKET;

            // Attempt to connect to the first address returned by
            // the call to getaddrinfo
            ptr=result;

            // Create a SOCKET for connecting to server
            ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);
            if (ConnectSocket == INVALID_SOCKET) {
                printf("Error at socket(): %ld\n", WSAGetLastError());
                freeaddrinfo(result);
                WSACleanup();
                return 1;
            }
        }
    }
    ~wNet(){ 
        // decomp here
    }

}