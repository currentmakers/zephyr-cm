board_set_flasher_ifnset(stlink_gdbserver)
board_set_debugger_ifnset(stlink_gdbserver)

set(OPENOCD_INTERFACE stlink)
set(OPENOCD_TARGET stm32f4x)

board_runner_args(jlink "--device=STM32F407VE" "--speed=4000")

board_runner_args(stm32cubeprogrammer "--port=swd" "--reset-mode=hw")

include(${ZEPHYR_BASE}/boards/common/stm32cubeprogrammer.board.cmake)
include(${ZEPHYR_BASE}/boards/common/openocd-stm32.board.cmake)
include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/stlink_gdbserver.board.cmake)


