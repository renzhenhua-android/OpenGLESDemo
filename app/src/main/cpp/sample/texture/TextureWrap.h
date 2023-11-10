//
// Created by OuyangPeng on 2021/10/25.
//

#ifndef OPENGLESDEMO_TEXTUREWRAP_H
#define OPENGLESDEMO_TEXTUREWRAP_H

#include <GLSampleBase.h>

class TextureWrap : public GLSampleBase {
public:
    TextureWrap() = default;

    virtual ~TextureWrap() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    // Sampler location
    GLint samplerLoc;

    // Offset location
    GLint offsetLoc;

    // Texture handle
    GLuint textureId;

    static GLuint CreateTexture2D();

    static GLubyte *GenCheckImage(int width, int height, int checkSize);
};

#endif //OPENGLESDEMO_TEXTUREWRAP_H
