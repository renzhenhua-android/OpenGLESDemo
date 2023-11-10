#pragma once

#include <GLSampleBase.h>

class NativeTriangle : public GLSampleBase {

#define VERTEX_POS_INDX       0

public:
    NativeTriangle() = default;

    virtual ~NativeTriangle() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();
};
