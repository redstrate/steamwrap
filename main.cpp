#include <iostream>
#include <steam/steam_api.h>
#include <cstdlib>

int main(int argc, char *argv[]) {
    putenv("SteamAppId=39210");
    putenv("SteamGameId=39210");

    std::cout << "Previous LD_LIBRARY_PATH:" << getenv("LD_LIBRARY_PATH") << std::endl;

    std::string newEnv = std::string("PREVIOUS_LD_LIBRARY_PATH=") + getenv("LD_LIBRARY_PATH");

    putenv(const_cast<char*>(newEnv.c_str()));

    putenv("LD_LIBRARY_PATH=");

    if (!SteamAPI_Init()) {
        throw std::runtime_error("Failed to initialize steam api!");
    }

    std::cout << "Initialized Steam API..." << std::endl;

    std::string args;
    for (int i = 1; i < argc; i++) {
        args += std::string(argv[i]) + " ";
    }

    std::cout << args.c_str() << std::endl;
    system(args.c_str());

    SteamAPI_Shutdown();

    std::cout << "Shutdown!" << std::endl;

    return 0;
}
