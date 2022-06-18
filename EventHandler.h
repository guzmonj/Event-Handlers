//
// Created by Jasmur on 12/9/2021.
//

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

jobject invoke(JNIEnv *env, jobject obj, jobject proxy, jobject method, jobjectArray args) {
    jclass klass = env->FindClass("java/lang/reflect/Method");
    jmethodID method2 = env->GetMethodID(klass, "getName", "()Ljava/lang/String;");
    jstring string = (jstring) env->CallObjectMethod(method, method2);
    std::string string2 = jstring2string(string);

    klass = env->GetObjectClass(obj);
    jfieldID field = env->GetFieldID(klass, "f", "J");
    Func func = (Func)env->GetLongField(obj, field);
    func(env, obj, proxy, method, args);

    return nullptr;
}

void registerInvocationHandler(const char* text) {
    JNINativeMethod native[1];
    jclass klass = env->FindClass(text);
    native[0] = {"invoke", "(Ljava/lang/Object;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", (void *)invoke};
    env->RegisterNatives(klass, native, 1);
    for (uint64_t i = 0; i < 1; i++) native[i] = {""""};
}

#endif //EVENTHANDLER_H
