/*
  ==============================================================================

    SineWave.cpp
    Created: 5 Sep 2022 6:44:45pm
    Author:  DarKeN

  ==============================================================================
*/

#include "SineWave.h"

template <typename SampleType>
SineWave<SampleType>::SineWave()
{
    PreprareToPlay(m_SampleRate);
}

template <typename SampleType>
SineWave<SampleType>::SineWave(double sampleRate)
{
    PreprareToPlay(sampleRate);
}

template <typename SampleType>
void SineWave<SampleType>::PreprareToPlay(double sampleRate)
{
    Reset();
    m_SampleRate = sampleRate;
    m_Period = 1.0f / sampleRate;
}

template <typename SampleType>
void SineWave<SampleType>::SetFrequency(const float frequency)
{
    m_CurrentTime = 0.0f;
    m_Frequency = frequency;
}

template <typename SampleType>
void SineWave<SampleType>::SetSineGain(const float gain)
{
    m_SinWaveGain = gain;
}

template <typename SampleType>
void SineWave<SampleType>::Reset()
{
    m_Frequency.reset(m_SampleRate, 0.02f);
    m_Frequency.setTargetValue(220.0f);

    m_SinWaveGain.reset(m_SampleRate, 0.02f);
    m_SinWaveGain.setTargetValue(1.0f);

    m_Period =  0.0f;
    m_CurrentTime = 0.0f;
}

template class SineWave<float>;
template class SineWave<double>;