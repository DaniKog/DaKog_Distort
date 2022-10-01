/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "DSP/Distortion.h"
#include "DSP/SineWave.h"
#include "DSP/HiLoPassFilter.h"

//==============================================================================
/**
*/
class DaKog_DistortAudioProcessor  : public juce::AudioProcessor , public juce::AudioProcessorValueTreeState::Listener
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif 
{
public:
    //==============================================================================
    DaKog_DistortAudioProcessor();
    ~DaKog_DistortAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState m_ParametersTreeState;

private:
    juce::AudioProcessorValueTreeState::ParameterLayout SetupParameters();
    void parameterChanged(const juce::String& parameterID, float newValue) override;
    void UpdateParameters();
    void UpdateSineWaves(const juce::String& parameterID);

    //DSP
    Distortion<float> m_DistortionDSP;
    std::vector<SineWave<float>> m_SineWaves;
    HiLoPassFilter<float> m_Filter;

    //Internal Parameters
    juce::SmoothedValue<float> m_InputGain = 1.0f;
    juce::SmoothedValue<float> m_WetGain = 1.0f;
    juce::SmoothedValue<float> m_Mix = 1.f;
    juce::SmoothedValue<float> m_OutputGain = 1.0f;
    bool m_ToggleSineWave = false;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DaKog_DistortAudioProcessor)
};
