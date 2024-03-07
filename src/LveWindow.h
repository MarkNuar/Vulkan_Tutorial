#pragma once 

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace lve
{
    class LveWindow
    {
    public:
        LveWindow(int w, int h, std::string name);
        ~LveWindow( );

        // Delete copy constructor and copy operator
        // We don't want to copy an LveWindow and have a shared LveWindow reference, may result in dangling pointers
        LveWindow(const LveWindow&) = delete;
        LveWindow &operator=(const LveWindow&) = delete;

        bool shouldClose() {return glfwWindowShouldClose(window);}

    private:
        void initWindow();

        const int width;
        const int height;

        std::string windowName;

        GLFWwindow *window;
    };
} // namespace lve