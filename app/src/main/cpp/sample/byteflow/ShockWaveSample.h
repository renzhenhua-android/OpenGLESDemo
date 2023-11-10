//
// Created by OuyangPeng on 2021/12/21.
//

#ifndef OPENGLESDEMO_SHOCKWAVESAMPLE_H
#define OPENGLESDEMO_SHOCKWAVESAMPLE_H


#include <glm/gtc/matrix_transform.hpp>
#include <GLSampleBase.h>

using namespace glm;

class ShockWaveSample : public GLSampleBase {
public:
    ShockWaveSample();

    virtual ~ShockWaveSample();

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

    virtual void LoadImage(NativeImage *pImage);

    virtual void UpdateTransformMatrix(float rotateX, float rotateY, float scaleX, float scaleY);

    void UpdateMVPMatrix(mat4 &mvpMatrix, int angleX, int angleY, float ratio) const;

    virtual void SetTouchLocation(float x, float y);

private:
    GLuint m_TextureId;
    GLuint m_VaoId;
    GLuint m_VboIds[3];
    NativeImage m_RenderImage;
    glm::mat4 m_MVPMatrix;

    int m_AngleX;
    int m_AngleY;
    float m_ScaleX;
    float m_ScaleY;
    int m_FrameIndex;

    vec2 m_touchXY;
};


#endif //OPENGLESDEMO_SHOCKWAVESAMPLE_H
