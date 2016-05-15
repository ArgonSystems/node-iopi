#include <node.h>
#include <v8.h>
#include <nan.h>

extern "C"{
  #include "ABE_IoPi.h"
}

using namespace v8;


void setPinDirection(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  char direction = args[2]->NumberValue();
  set_pin_direction(address, pin, direction);
}

void setPortDirection(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char direction = args[2]->NumberValue();
  set_port_direction(address, port, direction);
}

void setPinPullup(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char pinval = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  set_pin_pullup(address, pinval, value);
}

void setPortPullups(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  set_port_pullups(address, port, value);
}

void writePin(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  write_pin(address, pin, value);
}

void writePort(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  write_port(address, port, value);
}

void readPin(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  int value = read_pin(address,pin);
  Local<Number> num = Nan::New(value);
  args.GetReturnValue().Set(num);
}

void readPort(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  int value = read_port(address, port);
  Local<Number> num = Nan::New(value);
  args.GetReturnValue().Set(num);
}

void invertPin(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  char polarity = args[2]->NumberValue();
  invert_pin(address, pin, polarity);
}

void invertPort(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char polarity = args[2]->NumberValue();
  invert_port(address, port, polarity);
}

void mirrorInterrupts(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char value = args[1]->NumberValue();
  mirror_interrupts(address, value);
}

void setInterruptPolarity(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char value = args[1]->NumberValue();
  set_interrupt_polarity(address, value);
}

void setInterruptType(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  set_interrupt_type(address, port, value);
}

void setInterruptDefaults(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  set_interrupt_defaults(address, port, value);
}

void setInterruptOnPin(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char pin = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  set_interrupt_on_pin(address, pin, value);
}

void setInterruptOnPort(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  char value = args[2]->NumberValue();
  set_interrupt_on_port(address, port, value);
}

void readInterruptStatus(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  int value = read_interrupt_status(address, port);
  Local<Number> num = Nan::New(value);
  args.GetReturnValue().Set(num);
}

void readInterruptCapture(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  char port = args[1]->NumberValue();
  int value = read_interrupt_capture(address, port);
  Local<Number> num = Nan::New(value);
  args.GetReturnValue().Set(num);
}

void resetInterrupts(const Nan::FunctionCallbackInfo<Value>& args){
  //TODO Figure out what to do here
  char address = args[0]->NumberValue();
  reset_interrupts();
}

void init(const Nan::FunctionCallbackInfo<Value>& args){
  char address = args[0]->NumberValue();
  IOPi_init(address);
}

void setup(Handle<Object> exports) {
  exports->Set(Nan::New("init").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(init)->GetFunction());
  exports->Set(Nan::New("IOPi_init").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(init)->GetFunction());
  exports->Set(Nan::New("setPinDirection").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPinDirection)->GetFunction());
  exports->Set(Nan::New("set_pin_direction").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPinDirection)->GetFunction());
  exports->Set(Nan::New("setPortDirection").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPortDirection)->GetFunction());
  exports->Set(Nan::New("set_port_direction").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPortDirection)->GetFunction());
  exports->Set(Nan::New("setPinPullup").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPinPullup)->GetFunction());
  exports->Set(Nan::New("set_pin_pullup").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPinPullup)->GetFunction());
  exports->Set(Nan::New("setPortPullups").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPortPullups)->GetFunction());
  exports->Set(Nan::New("set_port_pullups").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setPortPullups)->GetFunction());
  exports->Set(Nan::New("writePin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(writePin)->GetFunction());
  exports->Set(Nan::New("write_pin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(writePin)->GetFunction());
  exports->Set(Nan::New("writePort").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(writePort)->GetFunction());
  exports->Set(Nan::New("write_port").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(writePort)->GetFunction());
  exports->Set(Nan::New("readPin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(readPin)->GetFunction());
  exports->Set(Nan::New("read_pin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(readPin)->GetFunction());
  exports->Set(Nan::New("readPort").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(readPort)->GetFunction());
  exports->Set(Nan::New("read_port").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(readPort)->GetFunction());
  exports->Set(Nan::New("invertPin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(invertPin)->GetFunction());
  exports->Set(Nan::New("invert_pin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(invertPin)->GetFunction());
  exports->Set(Nan::New("invertPort").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(invertPort)->GetFunction());
  exports->Set(Nan::New("invert_port").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(invertPort)->GetFunction());
  exports->Set(Nan::New("mirrorInterrupts").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(mirrorInterrupts)->GetFunction());
  exports->Set(Nan::New("mirror_interrupts").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(mirrorInterrupts)->GetFunction());
  exports->Set(Nan::New("setInterruptPolarity").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptPolarity)->GetFunction());
  exports->Set(Nan::New("set_interrupt_polarity").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptPolarity)->GetFunction());
  exports->Set(Nan::New("setInterruptType").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptType)->GetFunction());
  exports->Set(Nan::New("set_interrupt_type").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptType)->GetFunction());
  exports->Set(Nan::New("setInterruptDefaults").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptDefaults)->GetFunction());
  exports->Set(Nan::New("set_interrupt_defaults").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptDefaults)->GetFunction());
  exports->Set(Nan::New("setInterruptOnPin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptOnPin)->GetFunction());
  exports->Set(Nan::New("set_interrupt_on_pin").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptOnPin)->GetFunction());
  exports->Set(Nan::New("setInterruptOnPort").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptOnPort)->GetFunction());
  exports->Set(Nan::New("set_interrupt_on_port").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(setInterruptOnPort)->GetFunction());
  exports->Set(Nan::New("readInterruptStatus").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(readInterruptStatus)->GetFunction());
  exports->Set(Nan::New("read_interrupt_status").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(readInterruptStatus)->GetFunction());
  exports->Set(Nan::New("readInterruptCapture").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(readInterruptCapture)->GetFunction());
  exports->Set(Nan::New("read_interrupt_capture").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(readInterruptCapture)->GetFunction());
  exports->Set(Nan::New("resetInterrupts").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(resetInterrupts)->GetFunction());
  exports->Set(Nan::New("reset_interrupts").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(resetInterrupts)->GetFunction());
}

NODE_MODULE(iopi, setup)
