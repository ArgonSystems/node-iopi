#include <node.h>
#include <v8.h>
#include <nan.h>

extern "C"{
  #include "ABE_IoPi.h"
}

using namespace v8;

void initIOPI(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  IOPi_init(address);
}

void setPortDirection(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char direction = args[2]->NumberValue();
  set_port_direction(address, port, direction);
}

void setPinDirection(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  char direction = args[2]->NumberValue();
  set_pin_direction(address, pin, direction);
}

void writePort(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  write_port(address, port, value);
}

void writePin(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  write_pin(address, pin, value);
}

void readPin(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  int value = read_pin(address,pin);
  Local<Number> num = Nan::New(value);
  args.GetReturnValue().Set(num);
}

void setup(Handle<Object> exports) {
  exports->Set(Nan::New("init").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(initIOPI)->GetFunction());
  exports->Set(Nan::New("setPortDirection").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPortDirection)->GetFunction());
  exports->Set(Nan::New("setPinDirection").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPinDirection)->GetFunction());
  exports->Set(Nan::New("writePort").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(writePort)->GetFunction());
  exports->Set(Nan::New("writePin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(writePin)->GetFunction());
  exports->Set(Nan::New("readPin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(readPin)->GetFunction());
}

NODE_MODULE(iopi, setup)
