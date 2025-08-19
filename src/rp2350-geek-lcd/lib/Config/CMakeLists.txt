project(Config)

add_library(${PROJECT_NAME} DEV_Config.c)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC pico_stdlib hardware_spi hardware_i2c hardware_pwm hardware_adc)