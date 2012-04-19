
#include <stdio.h>
#include <string.h>  

#include "ndk_types.h"
#include "jnilogger.h"

// the C++ version
#ifdef __cplusplus
extern "C"
{
#endif

// declarations
void helloLog
(JNIEnv * env, jobject obj, jstring logThis);
jstring addIntReturnString
(JNIEnv * env, jobject obj, jint value1, jint value2);

// the class method mapping
static JNINativeMethod methods[] = {
{"helloLog", "(Ljava/lang/String;)V", (void *)helloLog},
{"addIntReturnString", "(I;I;)Ljava/lang/String", (void *)addIntReturnString},
};

// the target class name
static const char *className = "com/ethan/sample/ndk/firstndkActivity";

#define DEBUG_TAG "NDK_AndroidNDK1SampleActivity"  

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    jint result = JNI_OK;
    JNIEnv* env = NULL;
    jclass clazz;
    jint methodsLength;

    // cache the JNIEnv interface pointer in global variable
    if (result == JNI_OK)
    {
        result = vm->GetEnv((void**)&env, JNI_VERSION_1_2);
        if (result != JNI_OK)
        {
            LOGE("ERROR: GetEnv failed/n");
        }
    }

    // register local method.Load target class
    if (result == JNI_OK)
    {
        //assert(env != NULL);

        clazz = env->FindClass(className);
        if (clazz == NULL)
        {
            LOGE("Native registration unable to find class '%s'", className);
            result = JNI_ERR;
        }
    }

    // construct method mapping
    if (result == JNI_OK)
    {
        // get method length
        methodsLength = sizeof(methods)/sizeof(methods[0]);
        if ((env)->RegisterNatives(clazz, methods, methodsLength) < 0)
        {
            LOGE("RegisterNatives failed for '%s'", className);
            result = JNI_ERR;
        }
    }

    LOGI("JNI_OnLoad startup ~~!");
    return JNI_VERSION_1_2;
}

void JNI_OnUnload(JavaVM* vm, void* reserved)
{
    LOGI("call JNI_OnUnload ~~!");
}
  
//void Java_com_ethan_sample_ndk_firstndkActivity_helloLog
void helloLog
(JNIEnv * env, jobject obj, jstring logThis)  
{  
    jboolean isCopy;  
    const char * szLogThis = env->GetStringUTFChars(logThis, &isCopy);  
  
  	// Do something with the native String
    __android_log_print(ANDROID_LOG_DEBUG, DEBUG_TAG, "NDK:LC: [%s]", szLogThis);  
 
 	// DON'T FORGET THIS LINE!!!
    env->ReleaseStringUTFChars(logThis, szLogThis);  
} 

//jstring Java_com_ethan_sample_ndk_firstndkActivity_addIntReturnString
jstring addIntReturnString
(JNIEnv * env, jobject obj, jint value1, jint value2)
{
    char *szFormat = "The sum of the two numbers is: %i";
    char *szResult;
 
    // add the two values
    jlong sum = value1 + value2;
 
    // malloc room for the resulting string
    szResult = (char *)malloc(sizeof(szFormat) + 20);
    
    // standard sprintf
    sprintf(szResult, szFormat, sum);
 
    // get an object string
    jstring result = env->NewStringUTF(szResult);
    
    // cleanup
    free(szResult);
 
    return result;
}



#ifdef __cplusplus
}
#endif
