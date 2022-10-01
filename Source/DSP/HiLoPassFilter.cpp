/*
  ==============================================================================

    HiLoPassFilter.cpp
    Created: 30 Sep 2022 8:40:37pm
    Author:  DarKeN

  ==============================================================================
*/

#include "HiLoPassFilter.h"

template <typename SampleType>
HiLoPassFilter<SampleType>::HiLoPassFilter(bool lowPass)
{
    m_Sign = lowPass ? 1 : -1;
    Reset();
}

template <typename SampleType>
void HiLoPassFilter<SampleType>::PrepareToPlay(const juce::dsp::ProcessSpec& specs)
{
    m_SampleRate = specs.sampleRate;
    m_StoredBuffer.resize(specs.numChannels, 0);
    Reset();
}

template <typename SampleType>
void HiLoPassFilter<SampleType>::Reset()
{
    SetCutoff(600);
}

template <typename SampleType>
void HiLoPassFilter<SampleType>::SetCutoff(SampleType cutoff)
{
    m_Cutoff = cutoff;
    CalculateCoefficients();
}


template class HiLoPassFilter<float>;
template class HiLoPassFilter<double>;