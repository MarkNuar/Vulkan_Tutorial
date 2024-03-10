#include "lve_pipeline.h"

//std
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace lve {
    LvePipeline::LvePipeline(const std::string& vertFilepath, const std::string& fragFilepath) {
        createGraphicsPipeline(vertFilepath, fragFilepath);
    }

    void LvePipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath) {
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex Shader code size: " << vertCode.size() << std::endl;
        std::cout << "Fragment Shader code size: " << fragCode.size() << std::endl;
    }

    std::vector<char> LvePipeline::readFile(const std::string& filepath) {
        std::ifstream file {filepath, std::ios::ate | std::ios::binary};

        std::cout << std::filesystem::current_path() << std::endl;

        if(!file.is_open()) {
            throw std::runtime_error("failed to open file: " + filepath);
        }

        size_t filesize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer (filesize);

        file.seekg(0);
        file.read(buffer.data(), filesize);

        file.close();
        return buffer;
    }
}
