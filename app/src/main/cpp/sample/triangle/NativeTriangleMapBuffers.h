#pragma once

#include <GLSampleBase.h>

#define VERTEX_POS_SIZE       3 // x, y and z
#define VERTEX_COLOR_SIZE     4 // r, g, b, and a

#define VERTEX_POS_INDX       0
#define VERTEX_COLOR_INDX     1

class NativeTriangleMapBuffers : public GLSampleBase {
public:
    NativeTriangleMapBuffers() = default;

    virtual ~NativeTriangleMapBuffers() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    GLuint vboIds[2];

    void DrawPrimitiveWithVBOsMapBuffers(GLint numVertices, GLfloat *vtxBuf,
                                         GLint vtxStride, GLint numIndices,
                                         GLushort *indices);
};


