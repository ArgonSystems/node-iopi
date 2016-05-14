#include <node.h>
#include <v8.h>
#include <uv.h>
#include <nan.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <time.h>

#include "ABE_IoPi.c"

using namespace v8;

void initIOPI(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

}

void setPortDirection(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

}

void setPinDirection(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

}

void writePort(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

}

void writePin(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

}

void setup(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "init", initIOPI);
  NODE_SET_METHOD(exports, "setPortDirection", set_port_direction);
  NODE_SET_METHOD(exports, "setPinDirection", set_pin_direction);
  NODE_SET_METHOD(exports, "writePort", writePort)
  NODE_SET_METHOD(exports, "writePin", writePin)
}

NODE_MODULE(iopi, setup)
