cmake_minimum_required(VERSION 3.5)
set (PROJECT_NAME runUnitTests)

find_package(Qt5Test REQUIRED)

enable_testing()
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES
    main.cpp
    Foo.cpp
    BechmarkedFoo.cpp
    DataDrivenFoo.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} AutoTest.h)
#add_test(Foo Foo)
#add_test(Foo BechmarkedFoo)

#qt5_use_modules(${PROJECT_NAME} Widgets)
#qt5_use_modules(${PROJECT_NAME} Test)
target_link_libraries(${PROJECT_NAME} Qt5::Test)
