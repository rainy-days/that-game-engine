#include "FileSystemWatcher.hpp"

FileSystemWatcher::FileSystemWatcher()
: stream(nullptr)
{
}

FileSystemWatcher::~FileSystemWatcher()
{
    Stop();
}

void FileSystemWatcher::Start(const char *directory, float latencyInSeconds, Callback callback)
{
    CFStringRef pathToWatchCF = CFStringCreateWithCString(NULL, directory, kCFStringEncodingUTF8);
    CFArrayRef pathsToWatch = CFArrayCreate(NULL, (const void **)&pathToWatchCF, 1, NULL);
    
    FSEventStreamContext context;
    context.version = 0;
    context.info = this;
    context.retain = NULL;
    context.release = NULL;
    context.copyDescription = NULL;
    
    stream = FSEventStreamCreate(NULL, callback, &context, pathsToWatch, kFSEventStreamEventIdSinceNow, latencyInSeconds, kFSEventStreamCreateFlagFileEvents);
    FSEventStreamScheduleWithRunLoop(stream, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode);
    FSEventStreamStart(stream);
    
    CFRelease(pathToWatchCF);
}


void FileSystemWatcher::Stop()
{
    FSEventStreamStop(stream);
    FSEventStreamInvalidate(stream);
    FSEventStreamRelease(stream);
}
