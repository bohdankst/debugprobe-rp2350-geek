# cmake_minimum_required(VERSION 3.12)
# include(pico_sdk_import.cmake)
# project(Pico_ePaper_Code)
# pico_sdk_init()

# #添加编译子目录
# add_subdirectory(lib/Config)
# add_subdirectory(lib/Infrared)
# add_subdirectory(lib/LCD)
# add_subdirectory(lib/Fonts)
# add_subdirectory(lib/GUI)
# add_subdirectory(examples)



add_subdirectory(lib)

project(gui)

add_library(${PROJECT_NAME}
    gui/gui.c
    examples/ImageData.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/examples
    ${CMAKE_CURRENT_SOURCE_DIR}/gui
    )

target_link_libraries(${PROJECT_NAME} LCD GUI Fonts Config )

# #添加头文件目录
# include_directories(examples)
# include_directories(./lib/Config)
# include_directories(./lib/GUI)

# include_directories(./lib/LCD)
# include_directories(./lib/Infrared)


# # 生成可执行文件
# add_executable(main 
# main.c
# )


# target_link_libraries(main examples LCD Infrared GUI Fonts Config pico_stdlib hardware_spi)