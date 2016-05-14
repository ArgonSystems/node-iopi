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
using namespace v8;
void init(const FunctionCallbackInfo<Value>& args){
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  
}

void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "init", init);
}

NODE_MODULE(iopi, init)
