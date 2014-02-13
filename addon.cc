#include <node.h>

using namespace v8;

Handle<Value> RunCallback(const Arguments& args) {
  HandleScope scope;

  Local<Function> cb = Local<Function>::Cast(args[0]);
  Local<Value> argv[1] = { Local<Value>::New(String::New("hello world")) };
  cb->Call(Context::GetCurrent()->Global(), 1, argv);

  return scope.Close(Undefined());
}

void Init(Handle<Object> exports, Handle<Object> module) {
  module->Set(String::NewSymbol("exports"), 
      FunctionTemplate::New(RunCallback)->GetFunction());
}

NODE_MODULE(addon, Init)
