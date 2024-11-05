project(GD32E230C_EVAL LANGUAGES C CXX ASM)

add_library(GD32E230C_EVAL OBJECT
    ${DRIVERS_DIR}/BSP/GD32E230C_EVAL/gd32e230c_eval.c
    )

target_include_directories(GD32E230C_EVAL PUBLIC
    ${DRIVERS_DIR}/BSP/GD32E230C_EVAL
    )

target_link_libraries(GD32E230C_EVAL PUBLIC GD32E23x_standard_peripheral)
