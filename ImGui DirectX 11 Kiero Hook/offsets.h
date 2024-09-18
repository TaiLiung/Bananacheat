#pragma once
#include <Windows.h>
namespace offsets {
    constexpr uintptr_t RecoilFir = 0x630390; //  0x630390
    constexpr uintptr_t ChangeWeapon = 0x696820; // recoil 0x6A5AE0
    constexpr uintptr_t SetRecoil = 0x6A5AE0;

    constexpr uintptr_t SetPos = 0x804E80; // float float float

    constexpr uintptr_t set_MaxHealth = 0x17B690;
    constexpr uintptr_t set_Health = 0x804F20;
    // 0x4000CF0
    constexpr uintptr_t fireRate = 0x74 + 0x4000CF0; //float
    constexpr uintptr_t spread = 0x7C + 0x4000CF2;
    constexpr uintptr_t sens = 0x4000A16;
    constexpr uintptr_t maxjumps = 0x558BD0 + 0xD4;

}