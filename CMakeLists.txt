cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 17)

project(ball-on-plate
  LANGUAGES CXX
  VERSION 1.0.0
)


add_subdirectory(tests)
add_subdirectory(serialComm)
add_subdirectory(websocket)
add_subdirectory(systemIdentification)
add_subdirectory(scripts)

find_package (Threads REQUIRED)

add_executable(controller1 scripts/controller1.cpp)

target_link_libraries(controller1 PUBLIC ${CMAKE_THREAD_LIBS_INIT}
)

target_link_libraries(controller1 PUBLIC Serial)
target_link_libraries(controller1 PUBLIC serialib)
target_link_libraries(controller1 PUBLIC Websocket)
target_link_libraries(controller1 PUBLIC mimoIdentification)

target_include_directories(controller1 PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/tests"
                            "${PROJECT_SOURCE_DIR}/serialComm"
                            "${PROJECT_SOURCE_DIR}/websocket"
                            "${PROJECT_SOURCE_DIR}/systemIdentification"
                            "${PROJECT_SOURCE_DIR}/scripts"
                            )
