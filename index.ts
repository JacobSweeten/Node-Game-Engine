import {
	glfwInit,
	glfwCreateWindow,
	GLFWWindowRef,
	glfwWindowShouldClose, 
	glfwPollEvents,
	glfwTerminate,
	glfwMakeContextCurrent,
	glfwSwapBuffers
} from "./C/glfwwrapper"
import { glClear, glClearColor, glewInit } from "./C/glwrapper";

async function main()
{
	try
	{
		await glfwInit({});
	}
	catch(e)
	{
		console.log(e);
		process.exit(1);
	}

	var win : GLFWWindowRef;

	try
	{
		win = await glfwCreateWindow(600, 400, "Test Window", null, null);
	}
	catch(e)
	{
		console.log(e);
		process.exit(1);
	}

	await glfwMakeContextCurrent(win);

	try
	{
		await glewInit();
	}
	catch(e)
	{
		console.log(e);
		process.exit(1);
	}

	await glClearColor(1, 0, 0, 1);

	while(!(await glfwWindowShouldClose(win)))
	{
		await glClear(true, false, false);
		await glfwSwapBuffers(win);
		await glfwPollEvents();
	}

	await glfwTerminate();
}


main();