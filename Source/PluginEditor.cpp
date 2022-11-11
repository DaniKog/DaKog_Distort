/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "util/Parameters.h"

//==============================================================================
DaKog_DistortAudioProcessorEditor::DaKog_DistortAudioProcessorEditor (DaKog_DistortAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //Add Background 
    m_GUI = new GUI();
    addAndMakeVisible(m_GUI);

    //SetupRotors();

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(800, 600);

    //Setup attachements
    m_DriveSliderValue = m_GUI->AttachSlider(DriveID, audioProcessor.m_ParametersTreeState);
    
}

DaKog_DistortAudioProcessorEditor::~DaKog_DistortAudioProcessorEditor()
{
    delete m_GUI;
}

void DaKog_DistortAudioProcessorEditor::SetupRotors()
{
    //TODO Do all in GUI or Here 
    //SetupRotor(m_DriveSliderValue, DriveID);
}
void DaKog_DistortAudioProcessorEditor::SetupRotor(std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& sliderAttachment,const juce::String& parameterID, DaKog_RotorSlider& rotor)
{
    //TODO Store all UI Info per ParamterID in a mapped Struct
    juce::Slider& slider = rotor.GetSlider();
    juce::AudioProcessorValueTreeState& parametersTreeState = audioProcessor.m_ParametersTreeState;
    juce::RangedAudioParameter& rangedParameter = *parametersTreeState.getParameter(parameterID);

    slider.setTooltip(TRANS(GetToolTip(parameterID)));
    slider.setDoubleClickReturnValue(true, rangedParameter.getDefaultValue());
    slider.setValue(rangedParameter.getDefaultValue());

    sliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(parametersTreeState, parameterID, slider);
}
//==============================================================================

juce::String DaKog_DistortAudioProcessorEditor::GetToolTip(const juce::String& parameterID)
{
    if (parameterID == DriveID)
        return "Sets the Drive of the Distortion";

    return "";
        
}
void DaKog_DistortAudioProcessorEditor::paint (juce::Graphics& g)
{
}

void DaKog_DistortAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
