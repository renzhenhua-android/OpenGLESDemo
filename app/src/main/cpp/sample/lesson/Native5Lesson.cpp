#include "Native5Lesson.h"

Native5Lesson::Native5Lesson() :
        mModelMatrix(nullptr),mViewMatrix(nullptr),
        mProjectionMatrix(nullptr),mMVPMatrix(nullptr),
        mMVPMatrixHandle(0), mBending(true) {}

Native5Lesson::~Native5Lesson() = default;

void Native5Lesson::Init() {

    // Set the background clear color to black
    glClearColor(0, 0, 0, 0);

    // Use culling the remove back face
    glDisable(GL_CULL_FACE);

    // Enable depth testing
    glDisable(GL_DEPTH_TEST);

    // Enable blending
    glEnable(GL_BLEND);

    // Interpolative blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Main Program
    // 顶点着色器
    VERTEX_SHADER = GLUtils::openTextFile("vertex/vertex_shader_lesson_5.glsl");
    // 片段着色器
    FRAGMENT_SHADER = GLUtils::openTextFile("fragment/fragment_shader_lesson_5.glsl");

    // Set program handles
    m_ProgramObj = GLUtils::createProgram(&VERTEX_SHADER, &FRAGMENT_SHADER);
    if (!m_ProgramObj) {
        LOGD("Could not Create program")
        return;
    }

    // Create Cube data
    createCubeData();

    //
    mModelMatrix = new Matrix();
    mMVPMatrix = new Matrix();

    // Position the eye in front of the origin.
    float eyeX = 0.0f;
    float eyeY = 0.0f;
    float eyeZ = 1.5f;

    // We are looking at the origin
    float centerX = 0.0f;
    float centerY = 0.0f;
    float centerZ = -5.0f;

    // Set our up vector.
    float upX = 0.0f;
    float upY = 1.0f;
    float upZ = 0.0f;

    // Set the view matrix.
    mViewMatrix = Matrix::newLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
}

void Native5Lesson::Change(int width, int height) {

    m_Width = width;
    m_Height = height;

    glViewport(0, 0, m_Width, m_Height);

    // Create a new perspective projection matrix. The height will stay the same
    // while the width will vary as per aspect ratio.
    float ratio = (float) width / height;
    float left = -ratio;
    float right = ratio;
    float bottom = -1.0f;
    float top = 1.0f;
    float near = 1.0f;
    float far = 10.0f;

    mProjectionMatrix = Matrix::newFrustum(left, right, bottom, top, near, far);
}

void Native5Lesson::Draw(int width_, int height_) {

    if (mBending) {
        glClear(GL_COLOR_BUFFER_BIT);
    } else {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }


    // Do a compile rotation every 10 seconds;
    long time = TimeUtils::currentTimeMillis() % 10000L;
    float angleInDegrees = (360.0f / 10000.0f) * ((int) time);

    // Set out pre-vertex lighting program.
    glUseProgram(m_ProgramObj);

    // Set program handle for cube drawing.
    mMVPMatrixHandle = (GLuint) glGetUniformLocation(m_ProgramObj, "u_MVPMatrix");

    // Draw mCubes

    // right
    mModelMatrix->identity();
    mModelMatrix->translate(4.0f, 0.0f, -7.0f);
    mModelMatrix->rotate(angleInDegrees, 1.0f, 0.0f, 0.0f);
    drawCube();

    // left
    mModelMatrix->identity();
    mModelMatrix->translate(-4.0f, 0.0f, -7.0f);
    mModelMatrix->rotate(angleInDegrees, 0.0f, 1.0f, 0.0f);
    drawCube();

    // top
    mModelMatrix->identity();
    mModelMatrix->translate(0.0f, 4.0f, -7.0f);
    mModelMatrix->rotate(angleInDegrees, 0.0f, 1.0f, 0.0f);
    drawCube();

    // bottom
    mModelMatrix->identity();
    mModelMatrix->translate(0.0f, -4.0f, -7.0f);
    mModelMatrix->rotate(angleInDegrees, 0.0f, 1.0f, 0.0f);
    drawCube();

    // center
    mModelMatrix->identity();
    mModelMatrix->translate(0.0f, 0.0f, -5.0f);
    mModelMatrix->rotate(angleInDegrees, 1.0f, 1.0f, 1.0f);
    drawCube();
}

void Native5Lesson::drawCube() {

    // Pass in the position info
    glVertexAttribPointer(
            NATIVE_LESSON_FIVE_ATTRIB_LOCATION_POS,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            mCubePositionData
    );
    glEnableVertexAttribArray(NATIVE_LESSON_FIVE_ATTRIB_LOCATION_POS);

    // Pass in the color info
    glVertexAttribPointer(
            NATIVE_LESSON_FIVE_ATTRIB_LOCATION_COLOR,
            4,
            GL_FLOAT,
            GL_FALSE,
            0,
            mCubeColorData
    );
    glEnableVertexAttribArray(NATIVE_LESSON_FIVE_ATTRIB_LOCATION_COLOR);

    // This multiplies the view by the model matrix
    // and stores the result the MVP matrix.
    // which currently contains model * view
    mMVPMatrix->multiply(*mViewMatrix, *mModelMatrix);

    // This multiplies the model view matrix by the projection matrix
    // and stores the result in the MVP matrix.
    // which no contains model * view * projection
    mMVPMatrix->multiply(*mProjectionMatrix, *mMVPMatrix);

    // Pass in the model view projection matrix
    glUniformMatrix4fv(
            mMVPMatrixHandle,
            1,
            GL_FALSE,
            mMVPMatrix->mData
    );

    // Draw the cube
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Native5Lesson::createCubeData() {

    // Define points for a cube.
    // X, Y, Z
    float p1p[] = {-1.0f, 1.0f, 1.0f};
    float p2p[] = {1.0f, 1.0f, 1.0f};
    float p3p[] = {-1.0f, -1.0f, 1.0f};
    float p4p[] = {1.0f, -1.0f, 1.0f};
    float p5p[] = {-1.0f, 1.0f, -1.0f};
    float p6p[] = {1.0f, 1.0f, -1.0f};
    float p7p[] = {-1.0f, -1.0f, -1.0f};
    float p8p[] = {1.0f, -1.0f, -1.0f};

    mCubePositionData = esGenerateCubeData(p1p, p2p, p3p, p4p, p5p, p6p, p7p, p8p,
                                           (sizeof(p1p) / sizeof(*p1p)));

    // Points of the cube: color information
    // R, G, B, A
    float p1c[] = {1.0f, 0.0f, 0.0f, 1.0f};        // red
    float p2c[] = {1.0f, 0.0f, 1.0f, 1.0f};        // magenta
    float p3c[] = {0.0f, 0.0f, 0.0f, 1.0f};        // black
    float p4c[] = {0.0f, 0.0f, 1.0f, 1.0f};        // blue
    float p5c[] = {1.0f, 1.0f, 0.0f, 1.0f};        // yellow
    float p6c[] = {1.0f, 1.0f, 1.0f, 1.0f};        // white
    float p7c[] = {0.0f, 1.0f, 0.0f, 1.0f};        // green
    float p8c[] = {0.0f, 1.0f, 1.0f, 1.0f};        // cyan

    mCubeColorData = esGenerateCubeData(p1c, p2c, p3c, p4c, p5c, p6c, p7c, p8c,
                                        (sizeof(p1c) / sizeof(*p1c)));
}

void Native5Lesson::SwitchBlendingMode() {
    mBending = !mBending;

    if (mBending) {
        // No culling of back faces
        glDisable(GL_CULL_FACE);

        // No depth testing
        glDisable(GL_DEPTH_TEST);

        // Enable blending
        glEnable(GL_BLEND);

        glBlendFunc(GL_ONE, GL_ONE);
    } else {
        // Culling back faces.
        glEnable(GL_CULL_FACE);

        // Enable depth testing
        glEnable(GL_DEPTH_TEST);

        // Disable blending
        glDisable(GL_BLEND);
    }
}

void Native5Lesson::Destroy() {
    GLSampleBase::Destroy();
    delete mCubePositionData;
    mCubePositionData = nullptr;

    delete mCubeColorData;
    mCubeColorData = nullptr;

    delete mModelMatrix;
    mModelMatrix = nullptr;

    delete mViewMatrix;
    mViewMatrix = nullptr;

    delete mProjectionMatrix;
    mProjectionMatrix = nullptr;

    delete mMVPMatrix;
    mMVPMatrix = nullptr;

    // Delete program object
    GLUtils::DeleteProgram(m_ProgramObj);
}