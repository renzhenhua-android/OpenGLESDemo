//
// Created by OuyangPeng on 2021/10/25.
//

#ifndef OPENGLESDEMO_MIPMAP2D_H
#define OPENGLESDEMO_MIPMAP2D_H

#include <GLSampleBase.h>

class MipMap2D : public GLSampleBase {
public:
    MipMap2D() = default;

    virtual ~MipMap2D() = default;

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

    static GLuint CreateMipMappedTexture2D();

    static GLboolean
    GenMipMap2D(const GLubyte *src, GLubyte **dst, int srcWidth, int srcHeight, int *dstWidth,
                int *dstHeight);

    static GLubyte *GenCheckImage(int width, int height, int checkSize);
};


#endif //OPENGLESDEMO_MIPMAP2D_H
