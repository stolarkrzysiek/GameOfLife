cmake_minimum_required(VERSION 3.12)
project(ChangeMyName CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

# Put Your .cpp files in line below
add_executable(gol src/main.cpp src/field.cpp src/board.cpp src/CommandSource.cpp src/UserCommand.cpp src/AlwaysNextTurn.cpp src/board_surface.cpp src/board_roller.cpp src/board_torus.cpp)
target_include_directories(gol PUBLIC include)

# If You want to write some tests...
option(USE_GTEST "Download compile and provide gtest/gmock" OFF)

if(USE_GTEST)
        include(FetchContent)
        FetchContent_Declare(
                googletest
                GIT_REPOSITORY https://github.com/google/googletest.git
                GIT_TAG main
        )

        FetchContent_MakeAvailable(googletest)

        add_executable(sample_test src/testZero.cpp src/sampleTests.cpp)
        target_include_directories(sample_test PUBLIC include)
        target_link_libraries(sample_test gmock_main gtest gmock)

        add_custom_target(run_tests
                        COMMAND sample_test
                        DEPENDS sample_test)

        enable_testing()
        add_test(tests sample_test)
endif(USE_GTEST)
