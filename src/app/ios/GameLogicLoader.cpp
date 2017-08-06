#include "GameLogicLoader.hpp"
#include <dlfcn.h>
#include <stdio.h>

void LoadGameLogic(const char* libPath)
{
	void *handle = dlopen(libPath, RTLD_LAZY);
	if (handle == nullptr)
	{
		printf("Failed to open library, error = %s\n", dlerror());
		return;
	}
    
    printf("Loaded library: %s\n", libPath);
    
    cbRunFrame = (RunFrameFunction)dlsym(handle, "RunFrame");
    if (cbRunFrame == nullptr)
    {
        printf("Failed to find RunFrame symbol, error = %s\n", dlerror());
    }
    cbRunFrame();
    
    int result = dlclose(handle);
    if (result != 0)
    {
        printf("Failed to close library, error = (%i) %s\n", result, dlerror());
    }
}
