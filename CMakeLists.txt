project(krita-erf LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(Vc 1.3 REQUIRED)
find_package(xsimd 8.0.5 REQUIRED)
find_package(boost 1.7.0 REQUIRED COMPONENTS System)

add_executable(
    krita-erf
    main.cpp
)

target_include_directories(krita-erf PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> ${Boost_INCLUDE_DIRS})
target_link_libraries(krita-erf PUBLIC ${Vc_LIBRARIES} xsimd ${Boost_SYSTEM_LIBRARY})
