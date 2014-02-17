#include <node.h>
#include "myobject.h"

v8::Persistent<v8::Function> MyObject::constructor;

MyObject::MyObject(double value) : value_(value) {
}

MyObject::~MyObject() {
}

void MyObject::Init() {
  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);
  tpl->SetClassName(v8::String::NewSymbol("MyObject"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
}

v8::Handle<v8::Value> MyObject::New(const v8::Arguments& args) {
  v8::HandleScope scope;

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new MyObject(...)`
    double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
    MyObject* obj = new MyObject(value);
    obj->Wrap(args.This());
    return args.This();
  } else {
    // Invoked as plain function: `MyObject(...)`, turn into construct call
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { args[0] };
    return scope.Close(constructor->NewInstance(argc, argv));
  }
}

v8::Handle<v8::Value> MyObject::NewInstance(const v8::Arguments& args) {
  v8::HandleScope scope;

  const unsigned argc = 1;
  v8::Handle<v8::Value> argv[argc] = { args[0] };
  v8::Local<v8::Object> instance = constructor->NewInstance(argc, argv);

  return scope.Close(instance);
}
