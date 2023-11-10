//
// Created by OuyangPeng on 2021/10/25.
//

#ifndef OPENGLESDEMO_MRT_H
#define OPENGLESDEMO_MRT_H

#include <GLSampleBase.h>

class MRT : public GLSampleBase {
public:
    MRT() = default;

    virtual ~MRT() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    // Handle to a framebuffer object
    GLuint fbo;

    // Texture handle
    GLuint colorTexId[4];

    // Texture size
    GLsizei textureWidth;
    GLsizei textureHeight;

    void initFBO();

    void drawGeometry();

    void blitTextures();
};


#endif //OPENGLESDEMO_MRT_H
