# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libpixelboost
LOCAL_CFLAGS    := -Werror -DPIXELBOOST_PLATFORM_ANDROID
FILE_LIST := $(shell find $(LOCAL_PATH)/../../pixelboost/engine/src/common -type f -name "*.c*")
FILE_LIST += $(shell find $(LOCAL_PATH)/../../pixelboost/engine/src/external -type f -name "*.c*")
FILE_LIST += $(shell find $(LOCAL_PATH)/../../pixelboost/engine/src/platform/android -type f -name "*.c*")
FILE_LIST += $(shell find $(LOCAL_PATH)/../../source -type f -name "*.c*")
FILE_LIST += game.cpp
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := \
$(LOCAL_PATH)/../../pixelboost/engine/src/common/ \
$(LOCAL_PATH)/../../pixelboost/engine/src/external/ \
$(LOCAL_PATH)/../../pixelboost/engine/src/platform/android/ \
$(LOCAL_PATH)/../../source/

LOCAL_LDLIBS    := -llog -lGLESv2
LOCAL_CFLAGS += -ffast-math -O3 -funroll-loops
LOCAL_ARM_MODE := arm

include $(BUILD_SHARED_LIBRARY)
