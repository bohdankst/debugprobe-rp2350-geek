set(DEBUG_ON_PICO ON CACHE BOOL "Compile firmware for the Pico instead of Debug Probe" FORCE)
set(LCD_DISPLAY ON CACHE BOOL "Enable LCD Display" FORCE)

if (LCD_DISPLAY)
    add_compile_definitions(LCD_DISPLAY=1)
else()
    add_compile_definitions(LCD_DISPLAY=0)
endif()
