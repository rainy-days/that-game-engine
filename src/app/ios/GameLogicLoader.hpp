#ifndef _GAME_LOGIC_LOADER_HPP_
#define _GAME_LOGIC_LOADER_HPP_

void LoadGameLogic(const char *libPath);

typedef void (*RunFrameFunction)();
static RunFrameFunction cbRunFrame = nullptr;

#endif // _GAME_LOGIC_LOADER_HPP_
