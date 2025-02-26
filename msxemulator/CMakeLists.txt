add_executable(msxemulator)

# by default the header is generated into the build dir
pico_generate_pio_header(msxemulator ${CMAKE_CURRENT_LIST_DIR}/hsync.pio)
pico_generate_pio_header(msxemulator ${CMAKE_CURRENT_LIST_DIR}/vsync.pio)
pico_generate_pio_header(msxemulator ${CMAKE_CURRENT_LIST_DIR}/rgb.pio)
pico_generate_pio_header(msxemulator ${CMAKE_CURRENT_LIST_DIR}/hsync2.pio)
pico_generate_pio_header(msxemulator ${CMAKE_CURRENT_LIST_DIR}/vsync2.pio)
pico_generate_pio_header(msxemulator ${CMAKE_CURRENT_LIST_DIR}/rgb2.pio)
# however, alternatively you can choose to generate it somewhere else (in this case in the source tree for check in)
#pico_generate_pio_header(pio_blink ${CMAKE_CURRENT_LIST_DIR}/blink.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR})

# Make sure TinyUSB can find tusb_config.h
target_include_directories(msxemulator PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_sources(msxemulator PRIVATE msxemulator.c Z80.c hid_app.c joystick.c hidparser/hidparser.c vga16_graphics.c lfs.c lfs_util.c tms9918/vrEmuTms9918.c tms9918/vrEmuTms9918Util.c emu2149/emu2149.c emu2413/emu2413.c emu2212/emu2212.c fdc.c)
#target_sources(msxemulator PRIVATE msxemulator.c Z80.c hid_app.c joystick.c hidparser/hidparser.c vga16_graphics.c lfs.c lfs_util.c tms9918/vrEmuTms9918.c tms9918/vrEmuTms9918Util.c emu2149/emu2149.c emu2212/emu2212.c fdc.c)

pico_enable_stdio_usb(msxemulator 0)
pico_enable_stdio_uart(msxemulator 1)

target_compile_definitions(msxemulator PRIVATE Z80_STATIC Z80_WITH_LOCAL_HEADER Z80_WITH_Q Z80_WITH_ZILOG_NMOS_LD_A_IR_BUG)
target_link_libraries(msxemulator PRIVATE pico_stdlib hardware_pio hardware_timer hardware_dma hardware_uart hardware_flash pico_multicore hardware_pwm hardware_vreg tinyusb_host tinyusb_board)
pico_add_extra_outputs(msxemulator)
