#pragma once

#include <GLSampleBase.h>

class NativeRectangle : public GLSampleBase {

#define VERTEX_POS_INDX       0

public:
    NativeRectangle() = default;

    virtual ~NativeRectangle() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    // VertexBufferObject Ids
    GLuint vboIds[2];

    // VertexArrayObject Id
    GLuint vaoId;
};
