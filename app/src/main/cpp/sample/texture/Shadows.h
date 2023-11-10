//
// Created by OuyangPeng on 2021/10/25.
//
#pragma once

#include <GLSampleBase.h>

#define POSITION_LOC    0
#define COLOR_LOC       1

class Shadows : public GLSampleBase {
public:
    Shadows() = default;

    virtual ~Shadows() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    // Handle to a program object
    GLuint sceneProgramObject;
    GLuint shadowMapProgramObject;

    // Uniform locations
    GLint sceneMvpLoc;
    GLint shadowMapMvpLoc;
    GLint sceneMvpLightLoc;
    GLint shadowMapMvpLightLoc;

    // Sampler location
    GLint shadowMapSamplerLoc;

    // shadow map Texture handle
    GLuint shadowMapTextureId;
    GLuint shadowMapBufferId;
    GLuint shadowMapTextureWidth;
    GLuint shadowMapTextureHeight;

    // VBOs of the model
    GLuint groundPositionVBO;
    GLuint groundIndicesIBO;
    GLuint cubePositionVBO;
    GLuint cubeIndicesIBO;

    // Number of indices
    int groundNumIndices;
    int cubeNumIndices;

    // dimension of grid
    int groundGridSize;

    // MVP matrices
    ESMatrix groundMvpMatrix;
    ESMatrix groundMvpLightMatrix;
    ESMatrix cubeMvpMatrix;
    ESMatrix cubeMvpLightMatrix;

    float eyePosition[3];
    float lightPosition[3];

    void initMVP();

    int initShadowMap();

    void drawScene(GLint mvpLoc, GLint mvpLightLoc);
};
