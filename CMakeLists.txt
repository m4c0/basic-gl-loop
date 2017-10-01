cmake_minimum_required(VERSION 3.9)
project(basic-gl-loop VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PROJECT_NAME}.hpp")
target_link_libraries(${PROJECT_NAME} PUBLIC "-framework OpenGL")
target_link_libraries(${PROJECT_NAME} PUBLIC "-framework GLUT")
install(
    TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include)

add_executable(example example.cpp)
target_link_libraries(example PUBLIC ${PROJECT_NAME})

