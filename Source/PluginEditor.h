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
    void paint (juce::Graphics&) override;
    void resized() override;
private:
    void SetupRotors();
    void SetupRotor(std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& sliderAttachment, const juce::String& parameterID, DaKog_RotorSlider& rotor);
    juce::String GetToolTip(const juce::String& parameterID);
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
     //Filter
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_LoCutFilterValue;
     std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_HiCutFilterValue;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DaKog_DistortAudioProcessorEditor)
};
