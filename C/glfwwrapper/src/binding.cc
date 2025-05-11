#include <node.h>

#include <GLFW/glfw3.h>
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

void glfwInitWrapper(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	
	int res = glfwInit();
	
	args.GetReturnValue().Set(Number::New(isolate, (double)res));
}

void glfwCreateWindowWrapper(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();

	uint16_t* windowTitleUTF16 = new uint16_t[101];
	int len = args[2].As<String>()->Write(isolate, windowTitleUTF16, 0, 100, 0);

	char* windowTitle = new char[51];
	for(int i = 0; i < len; i++)
	{
		uint16_t c = windowTitleUTF16[i] & 0x7FFF;
		windowTitle[i] = ((uint8_t*)(&c))[0];
	}

	windowTitle[len] = 0;

	GLFWwindow* win = glfwCreateWindow(
		args[0].As<Number>()->Value(),
		args[1].As<Number>()->Value(),
		windowTitle,
		(GLFWmonitor*)((uint64_t)args[3].As<Number>()->Value()),
		(GLFWwindow*)((uint64_t)args[4].As<Number>()->Value())
	);

	delete windowTitleUTF16;
	delete windowTitle;

	args.GetReturnValue().Set(Number::New(isolate, (double)((uint64_t)win)));
}

void glfwWindowShouldCloseWrapper(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();

	GLFWwindow* win = (GLFWwindow*)((uint64_t)(args[0].As<Number>()->Value()));

	bool res = glfwWindowShouldClose(win);

	args.GetReturnValue().Set(Boolean::New(isolate, res));
}

void glfwPollEventsWrapper(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();

	glfwPollEvents();
}

void glfwTerminateWrapper(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();

	glfwTerminate();
}

void glfwMakeContextCurrentWrapper(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();

	glfwMakeContextCurrent((GLFWwindow*)((uint64_t)(args[0].As<Number>()->Value())));
}

void glfwSwapBuffersWrapper(const FunctionCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();

	glfwSwapBuffers((GLFWwindow*)((uint64_t)(args[0].As<Number>()->Value())));
}

void Initialize(Local<Object> exports) {
	NODE_SET_METHOD(exports, "glfwInitWrapper", glfwInitWrapper);
	NODE_SET_METHOD(exports, "glfwCreateWindowWrapper", glfwCreateWindowWrapper);
	NODE_SET_METHOD(exports, "glfwWindowShouldCloseWrapper", glfwWindowShouldCloseWrapper);
	NODE_SET_METHOD(exports, "glfwPollEventsWrapper", glfwPollEventsWrapper);
	NODE_SET_METHOD(exports, "glfwTerminateWrapper", glfwTerminateWrapper);
	NODE_SET_METHOD(exports, "glfwMakeContextCurrentWrapper", glfwMakeContextCurrentWrapper);
	NODE_SET_METHOD(exports, "glfwSwapBuffersWrapper", glfwSwapBuffersWrapper);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)