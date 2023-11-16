#pragma once

#include <GLSampleBase.h>

class NativeTriangle : public GLSampleBase {


public:
    NativeTriangle() = default;

    virtual ~NativeTriangle() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();
};
