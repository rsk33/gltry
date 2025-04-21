#include <iostream>
#include <thread>
#include <chrono>

#include <glad/gl.h>
// GLFW (include after glad)
#include <GLFW/glfw3.h>


constexpr GLuint WIDTH = 800;
constexpr GLuint HEIGHT = 600;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << "key pressed - " << key << '\n';
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        std::cout << "glfw esc key pressed\n";
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    std::cout << "Start gltry\n";

    if (!glfwInit())
    {
        // Initialization failed
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    std::cout << "GLFW initialization - success\n";
    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "gltry", NULL, NULL);
    if(!window)
    {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }

    std::cout << "GLFW create window - success\n";
    glfwMakeContextCurrent(window);

    int version = gladLoadGL(glfwGetProcAddress);
    if(version == 0)
    {
        std::cerr << "Failed to initialize OpenGL context\n";
        glfwTerminate();
        return -1;
    }

    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << '.' << GLAD_VERSION_MINOR(version) << '\n';

    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.7f, 0.9f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
