//
// Created by OuyangPeng on 2021/12/10.
//

#ifndef OPENGLESDEMO_ROTATETEXTURE_H
#define OPENGLESDEMO_ROTATETEXTURE_H

#include <GLSampleBase.h>
#include <glm/detail/type_mat4x4.hpp>

#define CS_VERTEX_POS_INDX  0
#define CS_TEXTURE_POS_INDX 1

class RotateTexture : public GLSampleBase {
public:
    RotateTexture();

    virtual ~RotateTexture();

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

    virtual void LoadImage(NativeImage *pImage);

private:
    GLuint m_TextureId;
    GLint m_SamplerLoc;
    GLint m_MVPMatLoc;
    NativeImage m_RenderImage;

    long mLastTime;
    // 旋转 angle
    GLfloat angle;

    void update(float deltaTime);

    float getDeltaTime();

    float translateToRadianAngle(int rotateAngle);

    void updateVertexCoordinates();
};
#endif //OPENGLESDEMO_RotateTexture_H
