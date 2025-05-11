const { 
	glfwInitWrapper,
	glfwCreateWindowWrapper,
	glfwWindowShouldCloseWrapper,
	glfwPollEventsWrapper
} = require("./build/Release/binding");

var GLFWInitialized = false;

const GLFWConstants = {
	GLFW_TRUE: 1,
	GLFW_FALSE: 0
};

export interface GLFWWindowRef {
	ptr: number
};

export interface GLFWmonitorRef {
	ptr: number
};

export interface GLFWOptions {
};

function initCheck() : void {
	if(!GLFWInitialized)
	{
		throw new Error("GLFW has not been initialized.");
	}
}

export async function glfwInit(GLFWOptionsData: GLFWOptions): Promise<void> {
	var res = glfwInitWrapper();

	if(res != GLFWConstants.GLFW_TRUE)
	{
		throw new Error("GLFW failed to initialize.");
	}
	else
	{
		GLFWInitialized = true;
	}
};

export async function glfwTerminate() : Promise<void> {
	initCheck();
	GLFWInitialized = false;
}

export async function glfwCreateWindow(
	w: number,
	h: number,
	title: string,
	GLFWmonitor: GLFWmonitorRef | null,
	GLFWwindow: GLFWWindowRef | null
) : Promise<GLFWWindowRef> {
	initCheck();
	
	var windowRef : GLFWWindowRef = {
		ptr: glfwCreateWindowWrapper(
			w,
			h,
			title,
			GLFWmonitor == null ? 0 : GLFWmonitor.ptr,
			GLFWwindow == null ? 0 : GLFWwindow.ptr
		)
	};

	if(windowRef.ptr === null)
	{
		throw new Error("Failed to create window.");
	}

	return windowRef;
};

export async function glfwWindowShouldClose(GLFWWindow: GLFWWindowRef) : Promise<Boolean>
{
	return glfwWindowShouldCloseWrapper(GLFWWindow.ptr); 
}

export async function glfwPollEvents() : Promise<void>
{
	glfwPollEventsWrapper();
}