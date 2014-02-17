#include <node.h>
#include "myobject.h"

v8::Handle<v8::Value> CreateObject(const v8::Arguments& args) {
  v8::HandleScope scope;
  return scope.Close(MyObject::NewInstance(args));
}

v8::Handle<v8::Value> Add(const v8::Arguments& args) {
  v8::HandleScope scope;

  MyObject* obj1 = node::ObjectWrap::Unwrap<MyObject>(args[0]->ToObject());
  MyObject* obj2 = node::ObjectWrap::Unwrap<MyObject>(args[1]->ToObject());

  double sum = obj1->Value() + obj2->Value();
  return scope.Close(v8::Number::New(sum));
}

void InitAll(v8::Handle<v8::Object> exports) {
  MyObject::Init();

  exports->Set(v8::String::NewSymbol("createObject"),
      v8::FunctionTemplate::New(CreateObject)->GetFunction());

  exports->Set(v8::String::NewSymbol("add"),
      v8::FunctionTemplate::New(Add)->GetFunction());
}

NODE_MODULE(addon, InitAll)
