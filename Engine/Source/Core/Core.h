// Core file to the engine

#ifdef CE_PLATFORM_WIN32
#ifdef CE_BUILD_DLL
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif
#endif