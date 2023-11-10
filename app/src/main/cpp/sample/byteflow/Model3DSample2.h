//
// Created by OuyangPeng on 2021/12/28.
//

#ifndef OPENGLESDEMO_MODEL3DSAMPLE2_H
#define OPENGLESDEMO_MODEL3DSAMPLE2_H

#include <GLSampleBase.h>
#include <shader.h>
#include <model.h>

class Model3DSample2 : public GLSampleBase {
public:
    Model3DSample2();

    virtual ~Model3DSample2() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

    virtual void UpdateTransformMatrix(float rotateX, float rotateY, float scaleX, float scaleY);

    void UpdateMVPMatrix(glm::mat4 &mvpMatrix, int angleX, int angleY, float ratio);

private:
    glm::mat4 m_MVPMatrix;
    glm::mat4 m_ModelMatrix;
    Shader *m_pShader;
    Model *m_pModel;

    int m_AngleX;
    int m_AngleY;
    float m_ScaleX;
    float m_ScaleY;
};


#endif //OPENGLESDEMO_MODEL3DSAMPLE2_H
