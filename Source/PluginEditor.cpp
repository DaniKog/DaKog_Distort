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


    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(600, 600);

    //Setup attachements
    m_InputGainSliderValue = m_GUI->AttachAndSetupSlider(InputID, audioProcessor.m_ParametersTreeState);
    //Drive
    m_DriveSliderValue = m_GUI->AttachAndSetupSlider(DriveID, audioProcessor.m_ParametersTreeState);
    m_ClippingFactorValue = m_GUI->AttachAndSetupSlider(ClipFactorID, audioProcessor.m_ParametersTreeState);
    //SineWave
    m_SineMixValue = m_GUI->AttachAndSetupSlider(SineMixID, audioProcessor.m_ParametersTreeState);
    m_SineToggleValue = m_GUI->AttachAndSetupButton(SineToggleID, audioProcessor.m_ParametersTreeState);
    m_SineFrequencyValue = m_GUI->AttachAndSetupSlider(SineFrequencyID, audioProcessor.m_ParametersTreeState);
    //Filter
    m_LoCutFilterValue = m_GUI->AttachAndSetupSlider(LoPassFilterCutOffID, audioProcessor.m_ParametersTreeState);
    m_HiCutFilterValue = m_GUI->AttachAndSetupSlider(HiPassFilterCutOffID, audioProcessor.m_ParametersTreeState);
    //Mix
    m_WetGainValue = m_GUI->AttachAndSetupSlider(WetGainID, audioProcessor.m_ParametersTreeState);
    m_MixValue = m_GUI->AttachAndSetupSlider(MixID, audioProcessor.m_ParametersTreeState);
    m_OutputValue = m_GUI->AttachAndSetupSlider(OutputGainID, audioProcessor.m_ParametersTreeState);
    
}

DaKog_DistortAudioProcessorEditor::~DaKog_DistortAudioProcessorEditor()
{
    delete m_GUI;
}

void DaKog_DistortAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
