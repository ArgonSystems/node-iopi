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

// #include "ABE_IoPi.c"

using namespace v8;

void initIOPI(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  char address = args[0]->NumberValue();
  Local<Number> num = Nan::New(address);
  args.GetReturnValue().Set(num);
  // IOPi_init((char)address);
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
  exports->Set(Nan::New("init").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(initIOPI)->GetFunction());
  // NODE_SET_METHOD(exports, "setPortDirection", setPortDirection);
  // NODE_SET_METHOD(exports, "setPinDirection", setPinDirection);
  // NODE_SET_METHOD(exports, "writePort", writePort);
  // NODE_SET_METHOD(exports, "writePin", writePin);
}

NODE_MODULE(iopi, setup)
