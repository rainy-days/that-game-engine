
#include "json.hpp"
#include "zmq.hpp"
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include "FileSystemWatcher.hpp"

using json = nlohmann::json;

std::string gFileToWatch;

void fileSystemCallback(ConstFSEventStreamRef /*streamRef*/, void *clientCallBackInfo, size_t numEvents, void *eventPaths, const FSEventStreamEventFlags eventFlags[], const FSEventStreamEventId eventIds[])
{
    char **paths = (char **)eventPaths;
    printf("FS callback. num events= %d\n", (int)numEvents);
    
    for (size_t i = 0; i < numEvents; ++i)
    {
        printf("event flags=0x%08x, path=%s\n", eventFlags[i], paths[i]);
        
        if ((eventFlags[i] & kFSEventStreamEventFlagItemIsFile) &&
            ((eventFlags[i] & kFSEventStreamEventFlagItemCreated) ||
             (eventFlags[i] & kFSEventStreamEventFlagItemModified)))
        {
            printf("File created or modified: %s\n", paths[i]);
        }
    }
}

int main(int argc, const char **argv)
{
    json config;
    {
        std::string conf(argv[0]);
        conf += ".json";
        
        std::ifstream t(conf);
        if (t.bad())
        {
            std::cerr << "Could not find " << conf << std::endl;
            return 1;
        }
        t >> config;
    }
    
    FileSystemWatcher watcher;
    
    // listen to the given directory
    auto directory = argv[1];
    auto latency = 1.0f;
    auto callback = &fileSystemCallback;
    
    watcher.Start(directory, latency, callback);
    
    // run this thread's IO loop (blocking)
    CFRunLoopRun();
	return 0;
}
