/*
  ==============================================================================

    Distortion.cpp
    Created: 5 Sep 2022 11:05:08am
    Author:  DarKeN

  ==============================================================================
*/

#include "Distortion.h"
template <typename SampleType>
void Distortion<SampleType>::PrepareToPlay(const juce::dsp::ProcessSpec& specs)
{

}

template <typename SampleType>
void Distortion<SampleType>::Reset()
{

}

template <typename SampleType>
void Distortion<SampleType>::SetDrive(float drive)
{
    m_Drive = drive;
}
template class Distortion<float>;
template class Distortion<double>;