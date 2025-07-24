#include "pch.h"
DWORD WINAPI InitializeAndLoad(LPVOID) {
    while (*reinterpret_cast<unsigned char*>(0xC8D4C0) != 9) {
        Sleep(100);
    }
    while (1) {
        *reinterpret_cast<BYTE*>(0xB7CEE4) = 1;
        Sleep(10000);
    }
    return 0;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, &InitializeAndLoad, 0, 0, 0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}