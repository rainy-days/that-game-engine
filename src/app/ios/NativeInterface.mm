#import "NativeInterface.h"
#include "GameLogicLoader.hpp"

@interface NativeInterface () 
{
}
@end

@implementation NativeInterface

-(instancetype)init
{
    NSString *libPath = [[NSBundle mainBundle] pathForResource:@"GameLogic" ofType:nil inDirectory:@"Frameworks/GameLogic.framework"];
    
    
    self = [super init];
    if (self) {
        LoadGameLogic([libPath UTF8String]);
    }
    return self;
}

@end
