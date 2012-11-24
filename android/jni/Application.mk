# APP_ABI := all # release
APP_ABI := armeabi-v7a #debug

APP_CPPFLAGS += -frtti -fexceptions -Wno-multichar
APP_STL := gnustl_static

NDK_TOOLCHAIN_VERSION=4.4.3