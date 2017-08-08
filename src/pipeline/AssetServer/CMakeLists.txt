cmake_minimum_required (VERSION 3.9)

set(DEVELOPMENT_PROJECT_NAME "AssetServer")
set(APP_NAME "AssetServer")
set(APP_BUNDLE_IDENTIFIER "com.rainydays.assetserver")

project(${DEVELOPMENT_PROJECT_NAME})
include(BundleUtilities)

set(PRODUCT_NAME ${APP_NAME})
set(EXECUTABLE_NAME ${APP_NAME})
set(MACOSX_BUNDLE_EXECUTABLE_NAME ${APP_NAME})
set(MACOSX_BUNDLE_INFO_STRING ${APP_BUNDLE_IDENTIFIER})
set(MACOSX_BUNDLE_GUI_IDENTIFIER ${APP_BUNDLE_IDENTIFIER})
set(MACOSX_BUNDLE_BUNDLE_NAME ${APP_BUNDLE_IDENTIFIER})
set(MACOSX_BUNDLE_ICON_FILE "")
set(MACOSX_BUNDLE_LONG_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_BUNDLE_VERSION "1.0")
set(MACOSX_BUNDLE_COPYRIGHT "Copyright Rainy Days")

set (CMAKE_CXX_STANDARD 11)

set(APP_SOURCE_FILES
  ./main.cpp
  ./FileSystemWatcher.hpp
  ./FileSystemWatcher.cpp
)

add_executable(
    ${APP_NAME}
    MACOSX_BUNDLE
    ${APP_SOURCE_FILES}
)

configure_file(${APP_NAME}.json ${APP_NAME}.json COPYONLY)

find_library(FOUNDATION Foundation)
find_library(CORESERVICES CoreServices)

target_link_libraries(${APP_NAME} ${FOUNDATION})
target_link_libraries(${APP_NAME} ${CORESERVICES})

# filesystem is part of C++17, but is not supported by XCode at the moment
find_package(Boost 1.64 REQUIRED COMPONENTS filesystem)
target_include_directories(${APP_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} ${Boost_LIBRARIES})

set(TOOLS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../tools")

target_include_directories(${APP_NAME} PUBLIC ${TOOLS_ROOT}/json)
target_include_directories(${APP_NAME} PUBLIC ${TOOLS_ROOT}/libzmq/include)
target_link_libraries(${APP_NAME} ${TOOLS_ROOT}/libzmq/lib/libzmq.a)
