project(GD32E231K_EVAL LANGUAGES C CXX ASM)

add_library(GD32E231K_EVAL OBJECT
    ${DRIVERS_DIR}/BSP/GD32E231K_EVAL/gd32e231k_eval.c
    )

target_include_directories(GD32E231K_EVAL PUBLIC
    ${DRIVERS_DIR}/BSP/GD32E231K_EVAL
    ${DRIVERS_DIR}/BSP/GD32E231K_EVAL/LCD_Common
    )

target_link_libraries(GD32E231K_EVAL PUBLIC GD32E23x_standard_peripheral)
