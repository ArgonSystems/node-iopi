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
  IOPi_init(address);
  // Local<Number> num = Nan::New(address);
  // args.GetReturnValue().Set(num);
}

void setPortDirection(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char direction = args[2]->NumberValue();
  set_port_direction(address, port, direction);
}

void setPinDirection(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  char direction = args[2]->NumberValue();
  set_pin_direction(address, pin, direction);
}

void writePort(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  write_port(address, port, value);
}

void writePin(const Nan::FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  write_pin(address, pin, value);
}

void setup(Handle<Object> exports) {
  exports->Set(Nan::New("init").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(initIOPI)->GetFunction());
  exports->Set(Nan::New("setPortDirection").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPortDirection)->GetFunction());
  exports->Set(Nan::New("setPinDirection").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPinDirection)->GetFunction());
  exports->Set(Nan::New("writePort").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(writePort)->GetFunction());
  exports->Set(Nan::New("writePin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(writePin)->GetFunction());
}

NODE_MODULE(iopi, setup)
