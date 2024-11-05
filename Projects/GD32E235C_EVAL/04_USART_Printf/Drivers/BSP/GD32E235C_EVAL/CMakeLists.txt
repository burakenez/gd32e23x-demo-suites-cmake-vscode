project(GD32E235C_EVAL LANGUAGES C CXX ASM)

add_library(GD32E235C_EVAL OBJECT
    ${DRIVERS_DIR}/BSP/GD32E235C_EVAL/gd32e235c_eval.c
    )

target_include_directories(GD32E235C_EVAL PUBLIC
    ${DRIVERS_DIR}/BSP/GD32E235C_EVAL
    )

target_link_libraries(GD32E235C_EVAL PUBLIC GD32E23x_standard_peripheral)
