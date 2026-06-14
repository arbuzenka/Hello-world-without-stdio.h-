typedef unsigned long DWORD;
typedef void* HANDLE;
typedef int BOOL;

#define STD_OUTPUT_HANDLE (DWORD)-11

__attribute__((dllimport)) HANDLE __stdcall GetStdHandle(DWORD nStdHandle);
__attribute__((dllimport)) BOOL __stdcall WriteFile(
    HANDLE hFile, 
    const void* lpBuffer, 
    DWORD nNumberOfBytesToWrite, 
    DWORD* lpNumberOfBytesWritten, 
    void* lpOverlapped
);
__attribute__((dllimport)) void __stdcall ExitProcess(unsigned int uExitCode);

void nomain(void) {

    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    const char message[] = "Hello, World\n";
    DWORD bytesWritten = 0;

    WriteFile(hStdout, message, 13, &bytesWritten, 0);

ExitProcess(0);
}
