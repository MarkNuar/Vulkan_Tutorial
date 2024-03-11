#pragma once

#include "lve_device.h"

#include <string>

namespace lve {
    // Pipeline configuration settings
    struct PipelineConfigInfo {};

    class LvePipeline {
    public:
        LvePipeline(
                LveDevice& device,
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);

        ~LvePipeline() {}

        // No copy constructor and copy operator
        LvePipeline(const LvePipeline&) = delete;
        void operator=(const LvePipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        // A pipeline needs a device -> we use a reference (&) which cannot become a dangling pointer
        LveDevice& lveDevice;
        // Handle to the Vulkan pipeline object
        VkPipeline graphicsPipeline;
        // Handle for vertex shader object
        VkShaderModule vertShaderModule;
        // Handle for fragment shader object
        VkShaderModule fragShaderModule;
    };
}