#include "Game.hpp"

#define EXPORT __attribute__((visibility("default")))

extern "C"
{
    void __attribute__ ((constructor)) dl_initialize(void)
    {
        printf("hello from dl_initialize\n");
    }
    
    void __attribute__ ((destructor)) dl_finalize(void)
    {
        printf("hello from dl_finalize\n");
    }
    
    EXPORT void RunFrame()
    {
        std::cout << "RunFrame called." << std::endl;
    }
}
