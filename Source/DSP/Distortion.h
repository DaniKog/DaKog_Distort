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
class Distortion
{
public:
    Distortion();
    void PrepareToPlay(const juce::dsp::ProcessSpec& specs);
    void Reset();
    SampleType PrcoessSample(SampleType& inSample) noexcept
    {
        inSample = inSample * m_Drive.getNextValue();
        
        //Diode Distortion
        inSample = inSample + 0.5f * (0.105f * (std::exp(0.1f * inSample / (1.68f * 0.0253f)) - 1));
        
        //SoftClipping
        inSample = m_PiDivisor * std::atan(m_Factor.getNextValue() * inSample);

        return inSample;
    }

    void SetDrive(float drive);
    void SetFactor(float factor);
private:
    juce::SmoothedValue<float> m_Drive;
    juce::SmoothedValue<float> m_Factor;

    const float m_PiDivisor = 2/ juce::MathConstants<float>::pi;
    double m_SampleRate = 44100;
};