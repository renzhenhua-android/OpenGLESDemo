#ifndef OPENGLESDEMO_BEZIERCURVESAMPLE_H
#define OPENGLESDEMO_BEZIERCURVESAMPLE_H


#include <glm/gtc/matrix_transform.hpp>
#include <GLSampleBase.h>
//#include "CoordSystemSample.h"

class BezierCurveSample : public GLSampleBase
{
public:
	BezierCurveSample();

	virtual ~BezierCurveSample();

	virtual void Init();

	virtual void Draw(int width_, int height_);

	virtual void Destroy();

	virtual void UpdateTransformMatrix(float rotateX, float rotateY, float scaleX, float scaleY);

	void UpdateMVPMatrix(glm::mat4 &mvpMatrix, int angleX, int angleY, float ratio) const;

private:
    static void DrawArray();

	GLuint m_TextureId;
	GLint m_SamplerLoc;
	GLint m_MVPMatLoc;
	GLuint m_VaoId;
	GLuint m_VboId;
	NativeImage m_RenderImage;
	glm::mat4 m_MVPMatrix;

	int m_AngleX;
	int m_AngleY;
	float m_ScaleX;
	float m_ScaleY;

	int m_FrameIndex;
};


#endif //OPENGLESDEMO_BEZIERCURVESAMPLE_H
