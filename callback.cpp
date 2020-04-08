#include <node.h>

using namespace v8;

void CallThis(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  Local<Context> context = isolate->GetCurrentContext();
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = {
      String::NewFromUtf8(isolate, "Called me...", NewStringType::kNormal).ToLocalChecked()};

  cb->Call(context, Null(isolate), argc, argv).ToLocalChecked();
}

void Init(Local<Object> exports, Local<Object> module)
{
  NODE_SET_METHOD(module, "exports", CallThis);
}

NODE_MODULE(callback, Init);
