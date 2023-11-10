#ifndef OPENGLLESSON_NATIVE6LESSON_H
#define OPENGLLESSON_NATIVE6LESSON_H

#include <GLSampleBase.h>
#include "lesson_cube_data.h"

#define NATIVE_LESSON_SIX_ATTRIB_LOCATION_POS                       0
#define NATIVE_LESSON_SIX_ATTRIB_LOCATION_NORMAL                    1
#define NATIVE_LESSON_SIX_ATTRIB_LOCATION_TEX_COORDINATE            2

class Native6Lesson : public GLSampleBase{

public:
    Native6Lesson() = default;

    ~Native6Lesson() = default;

    virtual void Init();

    virtual void Change(int width, int height);

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

    virtual void SetDelta(float x, float y);

    virtual void SetMinFilter(int filter);

    virtual void SetMagFilter(int filter);

private:

    //
    const int BYTES_PER_FLOAT = 4;
    const int POSITION_DATA_SIZE = 3;
    const int NORMAL_DATA_SIZE = 3;
    const int TEXTURE_COORDINATE_DATA_SIZE = 2;


    // model/view/projection matrix
    Matrix *mModelMatrix;
    Matrix *mViewMatrix;
    Matrix *mProjectionMatrix;
    Matrix *mMVPMatrix;

    //
    Matrix *mAccumulatedRotationMatrix;
    Matrix *mCurrentRotationMatrix;

    //
    Matrix *mLightModelMatrix;

    //
    GLuint mMVPMatrixHandle;
    GLuint mMVMatrixHandle;
    GLuint mLightPosHandle;
    GLuint mTextureUniformHandle;

    GLuint mPointProgramHandle;

    GLuint mBrickDataHandle;
    GLuint mGrassDataHandle;

    GLint mQueuedMinFilter;
    GLint mQueuedMagFilter;

    float mLightPosInModelSpace[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    float mLightPosInWorldSpace[4];
    float mLightPosInEyeSpace[4];

    float mDeltaX;
    float mDeltaY;

    void drawCube();

    void drawLight();
};


#endif //OPENGLLESSON_NATIVE6LESSON_H
