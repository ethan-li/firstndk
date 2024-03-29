/*
 * jnilogger.h
 *
 * Created on: 04/18/2012
 * Author:
 *
 */

#ifndef __JNILOGGER_H_
#define __JNILOGGER_H_

#include <android/log.h>

#ifdef _cplusplus
extern "C" {
#endif

#ifndef LOG_TAG
#define LOG_TAG "MY_LOG_TAG"
#endif

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL, LOG_TAG, __VA_ARGS__)

#ifdef _cplusplus
}
#endif

#endif /* __JNILOGGER_H_ */
