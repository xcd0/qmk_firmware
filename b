QMK Firmware 0.9.21
make: *** No rule to make target 'quantum/serial_link/tests/testlist.mk'. Stop.
|
|  QMK's make format recently changed to use folder locations and colons:
|     make project_folder:keymap[:target]
|  Examples:
|     make dz60:default
|     make planck/rev6:default:flash
|
make: *** No rule to make target 'testlist.mk'. Stop.
|
|  QMK's make format recently changed to use folder locations and colons:
|     make project_folder:keymap[:target]
|  Examples:
|     make dz60:default
|     make planck/rev6:default:flash
|
make: *** No rule to make target 'message.mk'. Stop.
|
|  QMK's make format recently changed to use folder locations and colons:
|     make project_folder:keymap[:target]
|  Examples:
|     make dz60:default
|     make planck/rev6:default:flash
|
make: *** No rule to make target 'Makefile'. Stop.
|
|  QMK's make format recently changed to use folder locations and colons:
|     make project_folder:keymap[:target]
|  Examples:
|     make dz60:default
|     make planck/rev6:default:flash
|
Making [1mhelix/rev2/sc[0m with keymap [1mdefault[0m

avr-gcc (GCC) 5.4.0
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Compiling: keyboards/helix/helix.c                                                                  [32;01m[OK][0m
Compiling: keyboards/helix/rev2/rev2.c                                                              [32;01m[OK][0m
Compiling: keyboards/helix/rev2/keymaps/default/keymap.c                                            [32;01m[OK][0m
Compiling: quantum/quantum.c                                                                        [32;01m[OK][0m
Compiling: quantum/keymap_common.c                                                                  [32;01m[OK][0m
Compiling: quantum/keycode_config.c                                                                 [32;01m[OK][0m
Compiling: quantum/matrix_common.c                                                                  [32;01m[OK][0m
Compiling: quantum/split_common/matrix.c                                                            [32;01m[OK][0m
Compiling: quantum/debounce/sym_g.c                                                                 [32;01m[OK][0m
Compiling: quantum/split_common/split_util.c                                                        [32;01m[OK][0m
Compiling: quantum/split_common/transport.c                                                         [32;01m[OK][0m
Compiling: quantum/process_keycode/process_space_cadet.c                                            [32;01m[OK][0m
Compiling: quantum/process_keycode/process_magic.c                                                  [32;01m[OK][0m
Compiling: quantum/process_keycode/process_grave_esc.c                                              [32;01m[OK][0m
Compiling: drivers/avr/i2c_master.c                                                                 [32;01m[OK][0m
Archiving: .build/obj_helix_rev2_sc_default/i2c_master.o                                            [32;01m[OK][0m
Compiling: drivers/avr/i2c_slave.c                                                                  [32;01m[OK][0m
Archiving: .build/obj_helix_rev2_sc_default/i2c_slave.o                                             [32;01m[OK][0m
Compiling: drivers/avr/serial.c                                                                     [32;01m[OK][0m
Archiving: .build/obj_helix_rev2_sc_default/serial.o                                                [32;01m[OK][0m
Compiling: tmk_core/common/host.c                                                                   [32;01m[OK][0m
Compiling: tmk_core/common/keyboard.c                                                               [32;01m[OK][0m
Compiling: tmk_core/common/action.c                                                                 [32;01m[OK][0m
Compiling: tmk_core/common/action_tapping.c                                                         [32;01m[OK][0m
Compiling: tmk_core/common/action_macro.c                                                           [32;01m[OK][0m
Compiling: tmk_core/common/action_layer.c                                                           [32;01m[OK][0m
Compiling: tmk_core/common/action_util.c                                                            [32;01m[OK][0m
Compiling: tmk_core/common/print.c                                                                  [32;01m[OK][0m
Compiling: tmk_core/common/debug.c                                                                  [32;01m[OK][0m
Compiling: tmk_core/common/sendchar_null.c                                                          [32;01m[OK][0m
Compiling: tmk_core/common/util.c                                                                   [32;01m[OK][0m
Compiling: tmk_core/common/eeconfig.c                                                               [32;01m[OK][0m
Compiling: tmk_core/common/report.c                                                                 [32;01m[OK][0m
Compiling: tmk_core/common/avr/suspend.c                                                            [32;01m[OK][0m
Compiling: tmk_core/common/avr/timer.c                                                              [32;01m[OK][0m
Compiling: tmk_core/common/avr/bootloader.c                                                         [32;01m[OK][0m
Assembling: tmk_core/common/avr/xprintf.S                                                           [32;01m[OK][0m
Compiling: tmk_core/common/magic.c                                                                  [32;01m[OK][0m
Compiling: tmk_core/protocol/lufa/lufa.c                                                            [32;01m[OK][0m
Compiling: tmk_core/protocol/usb_descriptor.c                                                       [32;01m[OK][0m
Compiling: tmk_core/protocol/lufa/outputselect.c                                                    [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Class/Common/HIDParser.c                                       [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/Device_AVR8.c                                        [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/EndpointStream_AVR8.c                                [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/Endpoint_AVR8.c                                      [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/Host_AVR8.c                                          [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/PipeStream_AVR8.c                                    [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/Pipe_AVR8.c                                          [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/USBController_AVR8.c                                 [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/USBInterrupt_AVR8.c                                  [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/ConfigDescriptors.c                                       [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/DeviceStandardReq.c                                       [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/Events.c                                                  [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/HostStandardReq.c                                         [32;01m[OK][0m
Compiling: lib/lufa/LUFA/Drivers/USB/Core/USBTask.c                                                 [32;01m[OK][0m
Linking: .build/helix_rev2_sc_default.elf                                                           [32;01m[OK][0m
Creating load file for flashing: .build/helix_rev2_sc_default.hex                                   [32;01m[OK][0m
Copying helix_rev2_sc_default.hex to qmk_firmware folder                                            [32;01m[OK][0m
Checking file size of helix_rev2_sc_default.hex                                                     [32;01m[OK][0m
 * The firmware size is fine - 16458/28672 (57%, 12214 bytes free)
