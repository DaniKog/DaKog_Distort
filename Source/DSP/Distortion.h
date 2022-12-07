/*
  ==============================================================================

    Distortion.h
    Created: 5 Sep 2022 11:05:08am
    Author:  DarKeN

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

constexpr float diode_Divisor = 1.0f / (1.68f * 0.0253f);

template <typename SampleType>
class Distortion
{
public:
    Distortion();
    void PrepareToPlay(const juce::dsp::ProcessSpec& specs);
    void Reset();
    SampleType ProcessSample(SampleType& inSample) noexcept
    {
        inSample = inSample * m_Drive.getNextValue();
        
        //Diode Distortion
        inSample = inSample + 0.5f * (0.105f * (std::exp(0.1f * inSample * diode_Divisor) - 1.0f));
        
        //SoftClipping
        inSample = m_PiDivisor * std::atan(m_Factor.getNextValue() * inSample);

        return inSample;
    }

    void SetDrive(float drive);
    void SetFactor(float factor);
private:
    juce::SmoothedValue<float> m_Drive;
    juce::SmoothedValue<float> m_Factor;

    const float m_PiDivisor = 2.0f / juce::MathConstants<float>::pi;
    double m_SampleRate = 44100.0;
};