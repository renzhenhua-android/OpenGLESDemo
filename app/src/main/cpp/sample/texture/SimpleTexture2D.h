//
// Created by OuyangPeng on 2021/10/24.
//

#ifndef OPENGLESDEMO_SIMPLETEXTURE2D_H
#define OPENGLESDEMO_SIMPLETEXTURE2D_H

#include <GLSampleBase.h>

#define SIMPLE_TEXTURE_2D_VERTEX_POS_INDEX              0
#define SIMPLE_TEXTURE_2D_VERTEX_TEXTCOORD_INDEX        1

class SimpleTexture2D : public GLSampleBase {

public:
    SimpleTexture2D() = default;

    virtual ~SimpleTexture2D() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    // Sampler location
    GLint samplerLoc;

    // Texture handle
    GLuint textureId;

    static GLuint CreateSimpleTexture2D();
};

#endif //OPENGLESDEMO_SIMPLETEXTURE2D_H
