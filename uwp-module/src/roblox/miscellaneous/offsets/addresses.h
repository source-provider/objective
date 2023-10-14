#pragma once
#include <memory>
#include "offsets.h"

struct lua_State;
struct threadRef;
#define rebase(addy) ((addy - 0x400000) + reinterpret_cast<std::uintptr_t>(GetModuleHandle(NULL)))
#define unbase(addy) (addy - reinterpret_cast<std::uintptr_t>(GetModuleHandle(NULL)))

namespace module {
	namespace addresses {
		const uintptr_t nilObject = rebase(0x2CF8A98); x
		const uintptr_t dummyNode = rebase(0x2CF8A78); x 
		const uintptr_t taskScheduler = rebase(0xBC8020);
		const uintptr_t luauExecute = rebase(0x1C104A0);
		const uintptr_t fireProximityPrompt = rebase(0x159D600);
		const uintptr_t pushInstance = rebase(0x7E4D30);
		const uintptr_t stdOut = rebase(0x114FC10);
		const uintptr_t fireClickDetector = rebase(0x1646CD0);
		const uintptr_t vmLoad = rebase(0x000000);
		const uintptr_t scriptContextResume = rebase(0x000000);
		const uintptr_t getState = rebase(0x8774B0);
		const uintptr_t taskDefer = rebase(0x000000);
		const uintptr_t loadModuleFlag = rebase(0x3210498); x
	};

	namespace addressTypes {
		using taskScheduler = std::intptr_t(__cdecl*)();
		using luauExecute = void(__thiscall*)(lua_State* L);
		using fireProximityPrompt = void(__thiscall*)(std::intptr_t proximityPrompt);
		using pushInstance = std::intptr_t(__cdecl*)(lua_State* L, void* instance);
		using pushInstanceW = std::intptr_t(__cdecl*)(lua_State* L, std::weak_ptr<uintptr_t> instance);
		using stdOut = void(__cdecl*)(std::intptr_t color, const char* fmt, ...);
		using vmLoad = std::intptr_t(__fastcall*)(std::intptr_t L, std::string* source, const char* chunk, int env);
		using scriptContextResume = std::intptr_t(__thiscall*)(std::intptr_t scriptContext, threadRef threadRef, std::intptr_t results);
		using getState = lua_State * (__thiscall*)(std::intptr_t scriptContext, std::intptr_t* contextLevel, std::intptr_t* scriptPtr);
		using taskDefer = std::intptr_t(__cdecl*)(lua_State* L);
	};

	namespace roblox {
		const auto getTaskScheduler = reinterpret_cast<addressTypes::taskScheduler>(addresses::taskScheduler);
		const auto luauExecute = reinterpret_cast<addressTypes::luauExecute>(addresses::luauExecute);
		const auto fireProximityPrompt = reinterpret_cast<addressTypes::fireProximityPrompt>(addresses::fireProximityPrompt);
		const auto pushInstance = reinterpret_cast<addressTypes::pushInstance>(addresses::pushInstance);
		const auto pushInstanceW = reinterpret_cast<addressTypes::pushInstanceW>(addresses::pushInstance);
		const auto stdOut = reinterpret_cast<addressTypes::stdOut>(addresses::stdOut);
		const auto vmLoad = reinterpret_cast<addressTypes::vmLoad>(addresses::vmLoad);
		const auto scriptContextResume = reinterpret_cast<addressTypes::scriptContextResume>(addresses::scriptContextResume);
		const auto getState = reinterpret_cast<addressTypes::getState>(addresses::getState);
		const auto taskDefer = reinterpret_cast<addressTypes::taskDefer>(addresses::taskDefer);
		const auto _fireclickdetector = addresses::fireClickDetector;
		static __declspec(naked) void fireClickDetector(int a1, float a2, int a3) {
			__asm
			{
				push ebp
				mov ebp, esp
				push ebx
				push a3
				mov ecx, a2
				mov ecx, a1
				call[_fireclickdetector]
				pop ebx
				leave
				ret
			}
		};
	}
};