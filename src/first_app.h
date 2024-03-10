#pragma once

#include "lve_window.h"
#include "lve_pipeline.h"

namespace lve {
    class FirstApp {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 800;

        void run();

    private:
        LveWindow lveWindow {WIDTH, HEIGHT, "Hello Vulkan!"};
        // The executable runs in cmake-build-debug folder, we need to go out and then enter src...
        LvePipeline lvePipeline {"../src/shaders/simple_shader.vert.spv", "../src/shaders/simple_shader.frag.spv"};
    };
}