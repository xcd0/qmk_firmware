# MCU name
MCU = atmega32u4

# Bootloader selection
#BOOTLOADER = atmel-dfu
BOOTLOADER = catarina

# Build Options
#   change yes to no to disable
#
#BOOTMAGIC_ENABLE = lite     # Virtual DIP switch configuration
BOOTMAGIC_ENABLE = no
#MOUSEKEY_ENABLE = yes       # Mouse keys
MOUSEKEY_ENABLE = no
#EXTRAKEY_ENABLE = yes       # Audio control and System control
EXTRAKEY_ENABLE = no
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output

# Add trackball support
SPLIT_KEYBOARD = yes
POINTING_DEVICE_ENABLE = yes
SRC += pmw3360/pmw3360.c

SRC += spi_master.c
#SRC += adns/adns.c
SRC += pmw/pmw.c
