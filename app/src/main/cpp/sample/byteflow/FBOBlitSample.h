//
// Created by OuyangPeng on 2021/12/22.
//

#ifndef OPENGLESDEMO_FBOBLITSAMPLE_H
#define OPENGLESDEMO_FBOBLITSAMPLE_H

#include <glm/gtc/matrix_transform.hpp>
#include <GLSampleBase.h>

#define ATTACHMENT_NUM 4

class FBOBlitSample : public GLSampleBase {
public:
    FBOBlitSample();

    virtual ~FBOBlitSample();

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

    virtual void LoadImage(NativeImage *pImage);

    virtual void UpdateTransformMatrix(float rotateX, float rotateY, float scaleX, float scaleY);

    void UpdateMVPMatrix(glm::mat4 &mvpMatrix, int angleX, int angleY, float ratio) const;

    bool InitFBO();

    void BlitTextures();

private:
    GLuint m_TextureId;
    GLuint m_AttachTexIds[ATTACHMENT_NUM];
    GLuint m_FBO;
    GLint m_SamplerLoc;
    GLint m_MVPMatLoc;
    GLuint m_VaoId;
    GLuint m_VboIds[3];
    NativeImage m_RenderImage;
    glm::mat4 m_MVPMatrix;

    int m_AngleX;
    int m_AngleY;
    float m_ScaleX;
    float m_ScaleY;
};


#endif //OPENGLESDEMO_FBOBLITSAMPLE_H
