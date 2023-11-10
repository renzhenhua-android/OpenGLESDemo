#ifndef OPENGLLESSON_NATIVE5LESSON_H
#define OPENGLLESSON_NATIVE5LESSON_H

#include <GLSampleBase.h>

#define NATIVE_LESSON_FIVE_ATTRIB_LOCATION_POS        0
#define NATIVE_LESSON_FIVE_ATTRIB_LOCATION_COLOR      1

class Native5Lesson : public GLSampleBase{

public:

    Native5Lesson();

    virtual ~Native5Lesson();
    virtual void Init();

    virtual void Change(int width, int height);

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

    virtual void SwitchBlendingMode();

private:
    float *mCubePositionData;
    float *mCubeColorData;

    // Matrix
    Matrix *mModelMatrix;
    Matrix *mViewMatrix;
    Matrix *mProjectionMatrix;
    Matrix *mMVPMatrix;

    // Handle
    GLuint mMVPMatrixHandle;

    bool mBending;

    void drawCube();

    void createCubeData();
};


#endif //OPENGLLESSON_NATIVE5LESSON_H
