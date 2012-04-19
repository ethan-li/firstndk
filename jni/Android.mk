
LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)

# We can specify the code extension.
LOCAL_CPP_EXTENSION	:= .cpp

# Here we give our module name and source file(s)
LOCAL_MODULE    := ndkfoo
LOCAL_SRC_FILES := ndkfoo.cpp

ifeq ($(HOST_OS),windows)
# NDK environment
LOCAL_LDLIBS	:= -llog	# android log
else
# entire source code environment
LOCAL_SHARED_LIBRARIES  := libutils
endif
#APP_STL			:= stlport_static	# STL support: stlport
 
include $(BUILD_SHARED_LIBRARY)
