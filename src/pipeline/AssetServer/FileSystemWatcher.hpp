
#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>

class FileSystemWatcher
{
public:
    typedef FSEventStreamCallback Callback;
    
    FileSystemWatcher();
    virtual ~FileSystemWatcher();
    
    void Start(const char* directoryToWatch, float latencyInSeconds, Callback callback);
    void Stop();
    
private:
    FSEventStreamRef stream;
};
