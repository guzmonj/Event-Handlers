std::string jstring2string(jstring jStr) {
    if (!jStr)
        return "";

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);
    return ret;
}

jobject seekbar_Listener (JNIEnv *env, jobject obj, jobject proxy, jobject method, jobjectArray args) {
    jobject seekbar = env->GetObjectArrayElement(args, 0);

    jclass klass = env->FindClass("java/lang/reflect/Method");
    jmethodID method_ = env->GetMethodID(klass, "getName", "()Ljava/lang/String;");
    std::string string = jstring2string((jstring)env->CallObjectMethod(method, method_));

    if (string == "onProgressChanged") {
        //TODO: CODE
    }
}

void createSeekbar () { //Wherever you need. Just my example.
     jobject seekbar = new SeekBar()->_this;
     jclass klass = env->FindClass("android/widget/SeekBar");
     jmethodID method = env->GetMethodID(klass, "setOnSeekBarChangeListener", "(Landroid/widget/SeekBar$OnSeekBarChangeListener;)V");
     klass = env->FindClass("android/widget/SeekBar$OnSeekBarChangeListener");
     env->CallVoidMethod(seekbar, method, createProxyInstance(env, klass, &seekbar_Listener));
     env->DeleteLocalRef(klass);
     env->DeleteLocalRef(seekbar);
}
