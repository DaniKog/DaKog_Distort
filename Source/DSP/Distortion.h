/*
  ==============================================================================

    Distortion.h
    Created: 5 Sep 2022 11:05:08am
    Author:  DarKeN

  ==============================================================================
*/

#include <JuceHeader.h>
#pragma once

template <typename SampleType>
class Distortion : juce::Component
{
public:
    Distortion() {};
    ~Distortion() {};
    void PrepareToPlay(const juce::dsp::ProcessSpec& specs);
    void Reset();
    SampleType PrcoessSample(SampleType& inSample) noexcept
    {
        inSample = inSample * m_Drive.getNextValue();
        inSample = inSample > 1.0f ? 1.0f : inSample < -1.0f ? -1.0f : inSample;
        return inSample;
    }

    void SetDrive(float drive);
private:
    juce::SmoothedValue<float> m_Drive;
    float m_Factor;
};