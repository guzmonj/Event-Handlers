package com.company.activity;
class EventHandler implements java.lang.reflect.InvocationHandler {
    long f;
    EventHandler(long f) { this.f = f; }
    @Override public native Object invoke(Object proxy, java.lang.reflect.Method method, Object[] args);
}
