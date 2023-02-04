cmake_minimum_required(VERSION 3.2)
project (lab4s3)
add_subdirectory(
"${CMAKE_CURRENT_SOURCE_DIR}/googletest"
"googletest"

)
add_executable(
    main
    "${PROJECT_SOURCE_DIR}/main.cpp"
  
)

add_executable(
    test_lab4
    "${PROJECT_SOURCE_DIR}/test_lab4.cpp"
)

target_include_directories(
test_lab4 PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/lab4s3"

)

target_link_libraries(
test_lab4 PRIVATE
gtest gtest_main
)


if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(
        main PRIVATE
        /W4
    )
    target_compile_options(
        test_lab4 PRIVATE
        /W4
    )
else ()
    target_compile_options(
        main PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_lab4 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()