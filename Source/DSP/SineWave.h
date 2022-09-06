/*
  ==============================================================================

    SineWave.h
    Created: 5 Sep 2022 6:44:44pm
    Author:  DarKeN

  ==============================================================================
*/

#include <JuceHeader.h>
#pragma once

template <typename SampleType>
class SineWave 
{
public:
    SineWave(double sampleRate);

    SampleType getNextSample() noexcept
    {
        if (m_CurrentTime > 1.0f)
        {
            m_CurrentTime = 0.0f;
        }

        SampleType sample = static_cast<SampleType>(std::sin(juce::MathConstants<float>::twoPi * m_Frequency.getCurrentValue() * m_CurrentTime));

        m_CurrentTime += m_Period;

        return sample * m_SinWaveGain.getNextValue();
    }

    void PreprareToPlay(double sampleRate);
    void SetFrequecncy(const float frequency);
    void SetSineGain(const float gain);
    void Reset();

private:

    juce::SmoothedValue<float> m_Frequency = 220;
    juce::SmoothedValue<float> m_SinWaveGain = 0.5f;

    double m_Period{0.0f};
    double m_CurrentTime{0.0f};
    double m_SampleRate{44100.0};

};