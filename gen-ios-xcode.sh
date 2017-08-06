
cmake -H./src/app/ios -B./build/ios/sim64 -DCMAKE_TOOLCHAIN_FILE=../../../tools/toolchains/ios.cmake -DIOS_PLATFORM=SIMULATOR64 -GXcode
