//
// Created by OuyangPeng on 2021/12/23.
//

#ifndef OPENGLESDEMO_RGB2YUVSAMPLE_H
#define OPENGLESDEMO_RGB2YUVSAMPLE_H

#include <glm/gtc/matrix_transform.hpp>
#include <GLSampleBase.h>

class RGB2YUVSample  : public GLSampleBase {
public:
    RGB2YUVSample();

    virtual ~RGB2YUVSample();

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

    virtual void LoadImage(NativeImage *pImage);

    bool CreateFrameBufferObj();

private:
    GLuint m_ImageTextureId;
    GLuint m_FboTextureId;
    GLuint m_FboId;
    GLuint m_VaoIds[2] = {GL_NONE};
    GLuint m_VboIds[4] = {GL_NONE};
    GLint m_SamplerLoc;
    NativeImage m_RenderImage;
    GLuint m_FboProgramObj;
    GLuint m_FboVertexShader;
    GLuint m_FboFragmentShader;
    GLint m_FboSamplerLoc;
};

#endif //OPENGLESDEMO_RGB2YUVSAMPLE_H
