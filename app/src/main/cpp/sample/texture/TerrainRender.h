//
// Created by OuyangPeng on 2021/10/25.
//
#pragma once

#include <GLSampleBase.h>

#define POSITION_LOC  0

class TerrainRender : public GLSampleBase {
public:
    TerrainRender() = default;

    virtual ~TerrainRender() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:

    // Uniform locations
    GLint mvpLoc;
    GLint lightDirectionLoc;

    // Sampler location
    GLint samplerLoc;

    // Texture handle
    GLuint textureId;

    // VBOs
    GLuint positionVBO;
    GLuint indicesIBO;

    // Number of indices
    int numIndices;

    // dimension of grid
    int gridSize;

    // MVP matrix
    ESMatrix mvpMatrix;

    void initMVP();
};
