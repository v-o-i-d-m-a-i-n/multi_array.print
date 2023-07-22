# super build mode
cmake_minimum_required (VERSION 3.20 FATAL_ERROR)

project("algs" LANGUAGES CXX)

get_filename_component(SECOND_FOLDER_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

INCLUDE_DIRECTORIES(
	${SECOND_FOLDER_DIR}
    ${CMAKE_INCLUDE_PATH}
)

message(STATUS "include ${CMAKE_INCLUDE_PATH}")

# finding dependencies
# find_package(Threads)
find_package(Boost ${Boost_MINIMUM_REQUIRED})

# building
add_executable(${PROJECT_NAME} run.cpp)

# install step
set(CMAKE_INSTALL_PREFIX ${STAGED_INSTALL_PREFIX})
install(TARGETS ${PROJECT_NAME}
    RUNTIME
)
