import {
	glfwInit,
	glfwCreateWindow,
	GLFWWindowRef,
	glfwWindowShouldClose, 
	glfwPollEvents
} from "./C/glfwwrapper"

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

	while(!(await glfwWindowShouldClose(win)))
	{
		await glfwPollEvents();
	}
}


main();