/*
  ==============================================================================

    SineWave.h
    Created: 5 Sep 2022 6:44:44pm
    Author:  DarKeN

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

template <typename SampleType>
class SineWave 
{
public:
    SineWave();

    SineWave(double sampleRate); //Set Sample rate on constracting

    SampleType getNextSample() noexcept
    {
        if (m_CurrentTime > 1.0f)
        {
            m_CurrentTime = 0.0f;
        }

        SampleType sample = static_cast<SampleType>(std::sin(juce::MathConstants<float>::twoPi * m_Frequency.getCurrentValue() * m_CurrentTime));

        m_CurrentTime += m_Period;

        return sample;
    }

    void PreprareToPlay(double sampleRate);
    void SetFrequency(const float frequency);
    void SetSineGain(const float gain);
    void Reset();

private:

    juce::SmoothedValue<float> m_Frequency = 2200.f;
    juce::SmoothedValue<float> m_SinWaveGain = 1.0f; //Unsued at the moment as moved to a Dry Wet approach for the SineWave

    double m_Period = 0.0f;
    double m_CurrentTime = 0.0f;
    double m_SampleRate = 44100.0;

};