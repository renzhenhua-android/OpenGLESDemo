//
// Created by OuyangPeng on 2021/12/20.
//

#ifndef OPENGLESDEMO_ROTARYHEADSAMPLE_H
#define OPENGLESDEMO_ROTARYHEADSAMPLE_H

#include <glm/gtc/matrix_transform.hpp>
#include <GLSampleBase.h>

#define TRIANGLE_COUNT           32
#define KEY_POINTS_COUNT         9

// 因为要用到太多glm的东西，所以使用glm命名空间
using namespace glm;

class RotaryHeadSample : public GLSampleBase {
public:
    RotaryHeadSample();

    virtual ~RotaryHeadSample();

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

    virtual void LoadImage(NativeImage *pImage);

    virtual void UpdateTransformMatrix(float rotateX, float rotateY, float scaleX, float scaleY);

    void UpdateMVPMatrix(mat4 &mvpMatrix, int angleX, int angleY, float ratio) const;

    void CalculateMesh(float warpLevel);

    static vec2 CalculateIntersection(vec2 inputPoint, vec2 centerPoint);

    static vec2 RotaryKeyPoint(vec2 input, float rotaryAngle);

private:
    GLuint m_TextureId;
    GLint m_SamplerLoc;
    GLint m_MVPMatLoc;
    NativeImage m_RenderImage;
    mat4 m_MVPMatrix;

    int m_AngleX;
    int m_AngleY;
    float m_ScaleX;
    float m_ScaleY;

    int m_FrameIndex;

    vec3 m_Vertices[TRIANGLE_COUNT * 3]; //28个三角形
    vec2 m_TexCoords[TRIANGLE_COUNT * 3]; //28个三角形
    vec2 m_MeshPoints[24];
    vec2 m_KeyPointsInts[KEY_POINTS_COUNT]; //关键点对应的交点
    vec2 m_KeyPoints[KEY_POINTS_COUNT]; //关键点归一化
    GLuint m_VaoId;
    GLuint m_VboIds[2];
};


#endif //OPENGLESDEMO_ROTARYHEADSAMPLE_H
