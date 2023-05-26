cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)

project(ball-on-plate
  LANGUAGES CXX
  VERSION 1.0.0
)


add_subdirectory(tests)
add_subdirectory(serialComm)
add_subdirectory(websocket)

find_package (Threads REQUIRED)

add_executable(test tests/serialWithWebsocket.cpp)

target_link_libraries(test PUBLIC ${CMAKE_THREAD_LIBS_INIT}
)

target_link_libraries(test PUBLIC Serial)
target_link_libraries(test PUBLIC serialib)
target_link_libraries(test PUBLIC Websocket)

target_include_directories(test PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/tests"
                            "${PROJECT_SOURCE_DIR}/serialComm"
                            "${PROJECT_SOURCE_DIR}/websocket"
                            )
