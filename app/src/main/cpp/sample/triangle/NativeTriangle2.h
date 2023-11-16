#pragma once

#include <GLSampleBase.h>

class NativeTriangle2 : public GLSampleBase {


public:
    NativeTriangle2() = default;

    virtual ~NativeTriangle2() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();
};
