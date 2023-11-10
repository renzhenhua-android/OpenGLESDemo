//
// Created by OuyangPeng on 2021/10/25.
//

#pragma once
#include "Noise3D.h"
#include <GLSampleBase.h>

// Attribute locations
#define ATTRIB_LOCATION_POS      0
#define ATTRIB_LOCATION_COLOR    1
#define ATTRIB_LOCATION_TEXCOORD 2

#define NOISE_TABLE_MASK   255


class Noise3DRender : public GLSampleBase{
public:
    Noise3DRender() = default;

    virtual ~Noise3DRender() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    // Uniform locations
    GLint  mvpLoc;
    GLint  mvLoc;
    GLint  fogMinDistLoc;
    GLint  fogMaxDistLoc;
    GLint  fogColorLoc;
    GLint  noiseTexLoc;
    GLint  timeLoc;

    // Vertex daata
    GLfloat  *vertices;
    GLfloat  *texCoords;
    GLuint   *indices;
    int       numIndices;

    // Rotation angle
    GLfloat   angle;

    // Matrices
    ESMatrix  mvMatrix;
    ESMatrix  mvpMatrix;

    long mLastTime = 0;

    // Time
    float curTime;

    // Texture handle
    GLuint textureId;

    void update(float deltaTime);

    float getDeltaTime();
};

