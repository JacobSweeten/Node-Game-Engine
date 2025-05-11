const { 
	glClearColorWrapper,
	glClearWrapper,
	glewInitWrapper
} = require("./build/Release/binding");

const GLConstants = {
	GL_COLOR_BUFFER_BIT: 16384,
	GL_DEPTH_BUFFER_BIT: 256,
	GL_STENCIL_BUFFER_BIT: 1024,
	GLEW_OK: 0
};

export async function glClearColor(
	r: number,
	g: number,
	b: number,
	a: number
) : Promise<void>
{
	glClearColorWrapper(r, g, b, a);
}

export async function glClear(
	GL_COLOR_BUFFER_BIT: boolean,
	GL_DEPTH_BUFFER_BIT: boolean,
	GL_STENCIL_BUFFER_BIT: boolean
) : Promise<void>
{
	var bitmask = 0;

	if(GL_COLOR_BUFFER_BIT)
	{
		bitmask |= GLConstants.GL_COLOR_BUFFER_BIT;
	}

	if(GL_DEPTH_BUFFER_BIT)
	{
		bitmask |= GLConstants.GL_DEPTH_BUFFER_BIT;
	}

	if(GL_STENCIL_BUFFER_BIT)
	{
		bitmask |= GLConstants.GL_STENCIL_BUFFER_BIT;
	}

	glClearWrapper(bitmask);
}

export async function glewInit() : Promise<void>
{
	var res : number = glewInitWrapper();

	if(res != GLConstants.GLEW_OK)
	{
		throw new Error("Failed to initialize GLEW.");
	}
}