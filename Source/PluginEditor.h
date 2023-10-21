/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUI/GUI.h"
#include "GUI/DaKog_RotorSlider.h"

//==============================================================================
/**
*/
class DaKog_DistortAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DaKog_DistortAudioProcessorEditor (DaKog_DistortAudioProcessor&);
    ~DaKog_DistortAudioProcessorEditor() override;

    //==============================================================================
    //void paint (juce::Graphics&) override;
    void resized() override;
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DaKog_DistortAudioProcessor& audioProcessor;
    GUI* m_GUI;
public:
     //Input
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_InputGainSliderValue;
     //Distortion
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_DriveSliderValue;
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_ClippingFactorValue;
     //SineWave
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_SineMixValue;
     std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> m_SineToggleValue;
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_SineFrequencyValue;
     //Filter
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_LoCutFilterValue;
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_HiCutFilterValue;
     //Mix
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_WetGainValue;
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_MixValue;
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_OutputValue;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DaKog_DistortAudioProcessorEditor)
};
