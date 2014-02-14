#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <node.h>

class MyObject : public node::ObjectWrap {
  public:
    static void Init();
    static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
    double Val() const { return value_; }

  private:
    explicit MyObject(double value = 0);
    ~MyObject();

    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Persistent<v8::Function> constructor;
    double value_;
};

#endif
