#include <iostream>
#include <thread>
#include <chrono>

#include <glad/gl.h>
// GLFW (include after glad)
#include <GLFW/glfw3.h>

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

int main()
{
    std::cout << "Start gltry\n";

    if (!glfwInit())
    {
        // Initialization failed
        std::cout << "glfw initialization - failed\n";
        return -1;
    }
    else
    {
        std::cout << "glfw initialization - success\n";
        glfwSetErrorCallback(error_callback);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(640, 480, "gltry", NULL, NULL);
        if(!window)
        {
            std::cerr << "glfw create window - failed\n";
            glfwTerminate();
            return -1;
        }
        else
        {
            std::cout << "glfw create window - success\n";
            glfwMakeContextCurrent(window);

            int version = gladLoadGL(glfwGetProcAddress);
            if(version == 0)
            {
                std::cerr << "failed to initialize OpenGL context\n";
                glfwTerminate();
                return -1;
            }
            else
            {
                std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << '.' << GLAD_VERSION_MINOR(version) << '\n';
            }

            glfwSetKeyCallback(window, key_callback);

            while(!glfwWindowShouldClose(window))
            {
//                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//                std::cout << "glfw window up\n";
            }
            glfwDestroyWindow(window);
        }
        glfwTerminate();
    }
}
