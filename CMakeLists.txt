cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o0 -g -Wall -Wextra -Werror")

set(EXECUTABLE_NAME string)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${EXECUTABLE_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/String.cpp
)