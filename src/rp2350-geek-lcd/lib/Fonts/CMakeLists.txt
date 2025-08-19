project(Fonts)

add_library(${PROJECT_NAME} 
    font8.c
    font12.c
    font16.c
    font20.c
    font24.c
    )

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
