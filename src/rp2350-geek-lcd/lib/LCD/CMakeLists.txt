
project(LCD)

add_library(${PROJECT_NAME} LCD_1in14_V2.c)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC Config)