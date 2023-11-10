//
// Created by OuyangPeng on 2021/10/25.
//

#ifndef OPENGLESDEMO_MULTITEXTURE_H
#define OPENGLESDEMO_MULTITEXTURE_H

#include <GLSampleBase.h>

#define MULTI_TEXTURE_VERTEX_POS_INDX               0
#define MULTI_TEXTURE_VERTEX_TEXCOORD_INDX          1

class MultiTexture : public GLSampleBase {
public:
    MultiTexture() = default;

    virtual ~MultiTexture() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    // Sampler locations
    GLint baseMapLoc;
    GLint lightMapLoc;

    // Texture handle
    GLuint baseMapTexId;
    GLuint lightMapTexId;
};


#endif //OPENGLESDEMO_MULTITEXTURE_H
