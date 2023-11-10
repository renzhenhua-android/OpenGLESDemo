//
// Created by OuyangPeng on 2021/10/25.
//

#ifndef OPENGLESDEMO_PARTICLESYSTEM_H
#define OPENGLESDEMO_PARTICLESYSTEM_H

#include <GLSampleBase.h>

#define PARTICLE_SYSTEM_NUM_PARTICLES   1000
#define PARTICLE_SIZE   7

#define PARTICLE_SYSTEM_ATTRIBUTE_LIFETIME_LOCATION       0
#define PARTICLE_SYSTEM_ATTRIBUTE_START_POSITION_LOCATION  1
#define PARTICLE_SYSTEM_ATTRIBUTE_END_POSITION_LOCATION    2

class ParticleSystem : public GLSampleBase{
public:
    ParticleSystem() = default;

    virtual ~ParticleSystem() = default;

    virtual void Init();

    virtual void Draw(int width_, int height_);

    virtual void Destroy();

private:
    // Uniform location
    GLint mTimeLoc;
    GLint mCenterPositionLoc;
    GLint mColorLoc;
    GLint mSamplerLoc;

    // Texture handle
    GLuint mTextureId;

    // Particle vertex data
    float mParticleData[PARTICLE_SYSTEM_NUM_PARTICLES * PARTICLE_SIZE ];

    long mLastTime = 0;

    // Current time
    float mTime;

    float getDeltaTime();

    void update(float deltaTime);
};


#endif //OPENGLESDEMO_PARTICLESYSTEM_H
