// main.cpp : Defines the entry point for the console application.
//

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Implement.h"
#include "Engine/Platform/Win32/ImplementWin32.h"
#include "LeakChecker.h"

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width_screen, height_screen, "OpenGL Experiment", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* GLEW initialize */
	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		return -1;
	}

	/* Native initialize */
	setDataDir("../../../Assets");
	native_init();
	native_gl_init(width_screen,height_screen);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		native_gl_draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

  native_cleanup();
  glfwTerminate();
  LeakCheck();
  return 0;
}