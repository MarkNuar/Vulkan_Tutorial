/*
 * Generates a hilly terrain using perlin noise
 *
 * Copyright (C) 2020 by Blurrypiano - https://github.com/blurrypiano/littleVulkanEngine
 *
 * This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT)
 */

#pragma once

#include "lattice.hpp"

// core
#include <littleVulkanEngine/core/lve_model.hpp>

// std
#include <memory>

namespace lve {

class Terrain {
 public:
  Terrain(LveDevice& device);

  static std::unique_ptr<Terrain> makeIsland(LveDevice& device);

  float sampleHeight(glm::vec2 s);
  glm::vec2 sampleGradient(glm::vec2 point);
  float nearestHeight(glm::vec2 p);
  glm::vec3 nearestNormal(glm::vec2 p);

  std::unique_ptr<LveModel> model{};
  std::unique_ptr<generate::GridLattice2D> heights;

 private:
  void generateTerrainModel(int vertexCount, float size, float textureScaleFactor);

  void generateHeightMap(int vertexCount, float size, float minHeight, float maxHeight);
  void transformHeightMapIsland(int vertexCount, float oceanDepth, float peakHeight);

  static glm::vec3 calculateNormal(
      const generate::GridLattice2D& heightMap, float delta, int i, int k);
  static glm::vec4 calculateTangent(const generate::GridLattice2D& heightMap, int i, int k);

  static constexpr float SIZE = 400.0f;
  static constexpr int VERTEX_COUNT = 800;

  static constexpr float PEAK_HEIGHT = -50.0f;
  static constexpr float OCEAN_HEIGHT = 30.0f;

  float x;
  float z;
  float size_;
  LveDevice& device_;
};

}  // namespace lve
