/*
  ==============================================================================

    Distortion.cpp
    Created: 5 Sep 2022 11:05:08am
    Author:  DarKeN

  ==============================================================================
*/

#include "Distortion.h"

template <typename SampleType>
Distortion<SampleType>::Distortion()
{
    Reset();
}

template <typename SampleType>
void Distortion<SampleType>::PrepareToPlay(const juce::dsp::ProcessSpec& specs)
{
    m_SampleRate = specs.sampleRate;
    Reset();
}

template <typename SampleType>
void Distortion<SampleType>::Reset()
{
    m_Drive.reset(m_SampleRate, 0.02f);
    m_Drive.setTargetValue(0.0f);

    m_Factor.reset(m_SampleRate, 0.02f);
    m_Factor.setTargetValue(0.0f);
}

template <typename SampleType>
void Distortion<SampleType>::SetDrive(float drive)
{
    m_Drive = drive;
}

template <typename SampleType>
void Distortion<SampleType>::SetFactor(float factor)
{
    m_Factor = factor;
}

template class Distortion<float>;
template class Distortion<double>;