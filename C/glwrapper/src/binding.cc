#include <node.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <stdint.h>

#include <iostream>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;
using v8::Boolean;

void glClearColorWrapper(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	
	glClearColor(
		args[0].As<Number>()->Value(),
		args[1].As<Number>()->Value(),
		args[2].As<Number>()->Value(),
		args[3].As<Number>()->Value()
	);
}

void glClearWrapper(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	
	glClear((unsigned int)(args[0].As<Number>()->Value()));
}

void glewInitWrapper(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	
	int res = glewInit();

	args.GetReturnValue().Set(Number::New(isolate, (double)res));
}

void Initialize(Local<Object> exports) {
	std::cout << "Initializing C" << std::endl;
	NODE_SET_METHOD(exports, "glClearColorWrapper", glClearColorWrapper);
	NODE_SET_METHOD(exports, "glClearWrapper", glClearWrapper);
	NODE_SET_METHOD(exports, "glewInitWrapper", glewInitWrapper);
}



NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)