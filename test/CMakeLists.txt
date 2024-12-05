set(policy CMP0135)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  osl_test
  test_main.cpp
)
target_link_libraries(
  osl_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(osl_test)
