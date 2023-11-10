#pragma once

#include <GLSampleBase.h>

class NativeTriangle2 : public GLSampleBase {

#define VERTEX_POS_INDX       0
#define VERTEX_COLOR_INDX     1

#define VERTEX_POS_SIZE       3 // x, y and z
#define VERTEX_COLOR_SIZE     4 // r, g, b, and a

public:
    NativeTriangle2() = default;

    virtual ~NativeTriangle2() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();
};
