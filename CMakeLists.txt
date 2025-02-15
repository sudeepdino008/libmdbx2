cmake_minimum_required(VERSION 3.14)
project(libmdbx2)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# Add MDBX options before including the submodule
set(MDBX_BUILD_SHARED_LIBRARY OFF CACHE BOOL "Build shared library" FORCE)
set(MDBX_INSTALL_STATIC OFF CACHE BOOL "Install static library" FORCE)
set(MDBX_BUILD_TOOLS OFF CACHE BOOL "Build tools" FORCE)
add_subdirectory(libmdbx)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
  hello_test
  hello_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
  mdbx-static
)

target_include_directories(hello_test PRIVATE ${CMAKE_SOURCE_DIR}/libmdbx)

include(GoogleTest)
gtest_discover_tests(hello_test)