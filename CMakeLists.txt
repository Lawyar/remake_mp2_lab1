cmake_minimum_required(VERSION 3.16)

project(remake_mp2)

include_directories(inc)

set(SOURCES
        main.cpp
        src/tbitfield.cpp
        src/tset.cpp
        test/test_tset.cpp
        test/test_tbitfield.cpp)

set(HEADERS
        inc)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
FetchContent_MakeAvailable(googletest)

add_executable(main ${SOURCES} ${HEADERS})

target_link_libraries(main gtest_main)

set_target_properties(
        main PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
