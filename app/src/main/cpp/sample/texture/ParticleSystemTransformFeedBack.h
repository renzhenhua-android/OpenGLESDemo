//
// Created by OuyangPeng on 2021/10/25.
//

#pragma once
#include <cstdlib>
#include <GLSampleBase.h>
#include "Noise3D.h"

#define NUM_PARTICLES   200
#define EMISSION_RATE   0.3f
#define ACCELERATION   -1.0f

#define ATTRIBUTE_POSITION      0
#define ATTRIBUTE_VELOCITY      1
#define ATTRIBUTE_SIZE          2
#define ATTRIBUTE_CURTIME       3
#define ATTRIBUTE_LIFETIME      4


class ParticleSystemTransformFeedBack : public GLSampleBase{
public:
    ParticleSystemTransformFeedBack() = default;

    virtual ~ParticleSystemTransformFeedBack() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    // 定义粒子的顶点结构
    // 这个结构定义与glTransformFeedbackVaryings的可变变量的顺序和类型相符
    // 每个粒子包含如下信息： 位置、速度、大小、当前时间和寿命
    typedef struct
    {
        float position[2];
        float velocity[2];
        float size;
        float curtime;
        float lifetime;
    } Particle;

    // Handle to a program object
    GLuint emitProgramObject;
    GLuint drawProgramObject;

    // Emit shader uniform locations
    GLint emitTimeLoc;
    GLint emitEmissionRateLoc;
    GLint emitNoiseSamplerLoc;

    // Draw shader uniform location
    GLint drawTimeLoc;
    GLint drawColorLoc;
    GLint drawAccelerationLoc;
    GLint samplerLoc;

    // Texture handles
    GLuint textureId;
    GLuint noiseTextureId;

    // Particle vertex data
    Particle particleData[ NUM_PARTICLES ];

    // Particle VBOs
    GLuint particleVBOs[2];

    // Index into particleVBOs (0 or 1) as to which is the source.
    // Ping-pong between the two VBOs
    GLuint curSrcIndex;

    long mLastTime = 0;

    // Current time
    float time;

    // synch object to synchronize the transform feedback results and the Draw
    GLsync emitSync;

    // 获取时间
    float getDeltaTime();

    // 每次绘制之前更新
    void update(float deltaTime);

    // 初始化发射粒子
    void initEmitParticles();

    // 用变化反馈发射粒子
    void emitParticles();

    // 初始化顶点属性
    static void setupVertexAttributes(GLuint vboID);
};
