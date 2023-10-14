#include <roblox/exploit/environment/environment.h>
#include <dependencies/luau/vm/src/lstate.h>
#include <thread>


auto alreadyDone = false;
auto mainThread(HMODULE hModule) -> void {
    auto storage{ module::storage::getSingleton() };
    auto console{ module::console::getSingleton() };
    auto taskScheduler{ module::scheduler::getSingleton() };
    auto execution{ module::execution::getSingleton() };
    auto environment{ module::environment::getSingleton() };
    auto render{ module::render::getSingleton() };
    

    storage->store<HMODULE>(obfuscate_str("moduleHandle"), hModule);
    storage->store<HWND>(obfuscate_str("windowHandle"), FindWindowW(0, L"Roblox"));

    execution->load();
    console->writeMode(obfuscate_str("Execution Loaded!"), module::console::info);

    execution->send(
        [environment, console](lua_State* L) -> void {
            setIdentity(L, 8);
            environment->createEnvironment(L);
            console->writeMode(obfuscate_str("Environment Created!"), module::console::info);
        }
    );

    if (!alreadyDone) {
        render->load();
        console->writeMode(obfuscate_str("Render Loaded!"), module::console::info);

        execution->send(
            [execution, render, console](lua_State* L) -> void {
                execution->createPipe();
                console->writeMode(obfuscate_str("Pipe Launched!"), module::console::info);
            }
        );
    }

    alreadyDone = true;
}

auto APIENTRY DllMain(HMODULE hModule, DWORD callReason, LPVOID lpReserved) -> BOOL {
    if (callReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        std::thread(mainThread, hModule).detach();
    }

    return TRUE;
}

