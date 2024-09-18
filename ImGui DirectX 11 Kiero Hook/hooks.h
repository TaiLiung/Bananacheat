#pragma once
#include <windows.h>
#include <MinHook.h>
#include <offsets.h>
typedef void(__cdecl* RecoilFN)(void*, float, float, float);
typedef void(__cdecl* FirerateFN)(void*, float);
typedef void(__cdecl* SpreadFN)(void*, float);
typedef void(__cdecl* sensFN)(void*, float);
typedef void(__cdecl* maxjumpFN)(void*, int);
namespace hooks
{
    void Setup();
    void antirecoil();
    void firerate();
    void Nospreasd();
    void sens();
    void maxjump();
    RecoilFN oRecoil = nullptr;
    FirerateFN oFirerate = nullptr;
    SpreadFN oSpread = nullptr;
    sensFN oSens = nullptr;
    maxjumpFN oMaxJump = nullptr;
    void _cdecl hRecoil(void* self, float x, float y, float z);
    void _cdecl hFirerate(void* self, float firerate);
    void _cdecl hSpread(void* self, float spread);
    void _cdecl hSens(void* self, float sensivity);
    void _cdecl hMaxjump(void* self, int val);
}

void hooks::Setup()
{
    uintptr_t Assembly = reinterpret_cast<uintptr_t>(GetModuleHandleA("GameAssembly.dll"));
    MH_Initialize();
    MH_CreateHook(reinterpret_cast<LPVOID>(Assembly + offsets::RecoilFir), hRecoil, reinterpret_cast<void**>(&oRecoil));
    MH_EnableHook(MH_ALL_HOOKS);
}

// Атяреколил
void hooks::antirecoil()
{
    uintptr_t Assembly = reinterpret_cast<uintptr_t>(GetModuleHandleA("GameAssembly.dll"));
    MH_Initialize();
    MH_CreateHook(reinterpret_cast<LPVOID>(Assembly + offsets::RecoilFir), hRecoil, reinterpret_cast<void**>(&oRecoil));
    MH_EnableHook(MH_ALL_HOOKS);
}


// Рапидафер
void hooks::firerate()
{
    uintptr_t Assembly = reinterpret_cast<uintptr_t>(GetModuleHandleA("GameAssembly.dll"));
    MH_Initialize();
    MH_CreateHook(reinterpret_cast<LPVOID>(Assembly + offsets::fireRate), hFirerate, reinterpret_cast<void**>(&oFirerate));
    MH_EnableHook(MH_ALL_HOOKS);
}


// Насрал на сприд
void hooks::Nospreasd()
{
    uintptr_t Assembly = reinterpret_cast<uintptr_t>(GetModuleHandleA("GameAssembly.dll"));
    MH_Initialize();
    MH_CreateHook(reinterpret_cast<LPVOID>(Assembly + offsets::spread), hSpread, reinterpret_cast<void**>(&oSpread));
    MH_EnableHook(MH_ALL_HOOKS);
}

// сенса
void hooks::sens()
{
    uintptr_t Assembly = reinterpret_cast<uintptr_t>(GetModuleHandleA("GameAssembly.dll"));
    MH_Initialize();
    MH_CreateHook(reinterpret_cast<LPVOID>(Assembly + offsets::sens), hSens, reinterpret_cast<void**>(&oSens));
    MH_EnableHook(MH_ALL_HOOKS);
}
void hooks::maxjump()
{
    uintptr_t Assembly = reinterpret_cast<uintptr_t>(GetModuleHandleA("GameAssembly.dll"));
    MH_Initialize();
    MH_CreateHook(reinterpret_cast<LPVOID>(Assembly + offsets::maxjumps), hMaxjump, reinterpret_cast<void**>(&oMaxJump));
    MH_EnableHook(MH_ALL_HOOKS);
}


//void __cdecl hooks::hSetPos(void* self, int val, int max) {
//    return oSetPos(self, 20, 1000);
//}
//void __cdecl hooks::hSetHealth(void* self, int value) {
//    return oSetHealth(self, 1000);
//}

void __cdecl hooks::hRecoil(void* self, float x, float y, float) {
    return oRecoil(self, 0.0, 0.0, 0.0);
}

void __cdecl hooks::hFirerate(void* self, float Firerate) {
    return oFirerate(self, 100.0);
}

void __cdecl hooks::hSpread(void* self, float spread) {
    return oSpread(self, 0.0);
}

void __cdecl hooks::hSens(void* self, float sensivity) {
    return oSens(self, 3000.0);
}


void __cdecl hooks::hMaxjump(void* self, int x) {
    return oSens(self, 3);
}

