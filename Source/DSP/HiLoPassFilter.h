/*
  ==============================================================================

    HiLoPassFilter.h
    Created: 30 Sep 2022 8:40:37pm
    Author:  DarKeN

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <math.h>

template <typename SampleType>
class HiLoPassFilter
{
public:
    HiLoPassFilter(bool lowPass);
    void PrepareToPlay(const juce::dsp::ProcessSpec& specs);

    void CalculateCoefficients()
    {
        m_Tan = static_cast<SampleType>(std::tan(juce::MathConstants<SampleType>::pi * m_Cutoff / m_SampleRate));
        m_A1 = (m_Tan - 1.f) / (m_Tan + 1.f);
    }

    SampleType ProcessSample(SampleType& inSample, int channel) noexcept
    {
        SampleType filteredSample = m_A1 * inSample + m_StoredBuffer[channel];
        m_StoredBuffer[channel] = inSample - m_A1 * filteredSample;
        return (inSample + m_Sign * filteredSample);
    }

    void Reset();
    void SetCutoff(SampleType cutoff);
private:
    int m_Sign = 1;
    SampleType m_Tan = SampleType(0);
    SampleType m_A1 = SampleType(0);
    SampleType m_Cutoff = SampleType(600);
    double m_SampleRate = 44100;
    std::vector<SampleType> m_StoredBuffer;
};