#include <iostream>
#include <adder.h>
#include <subtracter.h>
#include <GLFW/glfw3.h>

int main() {
    std::cout << "Hello from CMAKE ! " << std::endl;
    std::cout << add(43.1, 56.54) << std::endl;
    std::cout << subtract(43.1, 56.54) << std::endl;

     GLFWwindow* window;
    int width, height;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    glfwWindowHint(GLFW_DEPTH_BITS, 16);

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Set callback functions

    glfwMakeContextCurrent(window);
    glfwSwapInterval( 1 );

    glfwGetFramebufferSize(window, &width, &height);


    // Main loop
    while( !glfwWindowShouldClose(window) )
    {

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    // Exit program
    exit( EXIT_SUCCESS );
}