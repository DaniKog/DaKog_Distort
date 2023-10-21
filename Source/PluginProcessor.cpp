/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "util/Range.h"
#include "util/Parameters.h"

namespace
{
    static const int s_ButterWorthFilterPole = 4;
}

//==============================================================================
DaKog_DistortAudioProcessor::DaKog_DistortAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), m_ParametersTreeState(*this,nullptr,"Parameters",SetupParameters())
#endif
{
    m_ParametersTreeState.addParameterListener(InputID,this);
    //Filter 
    m_ParametersTreeState.addParameterListener(LoPassFilterCutOffID, this);
    m_ParametersTreeState.addParameterListener(HiPassFilterCutOffID, this);

    //SineWave
    m_ParametersTreeState.addParameterListener(SineFrequencyID, this);
    m_ParametersTreeState.addParameterListener(SineMixID, this);
    m_ParametersTreeState.addParameterListener(SineToggleID, this);

    //Distortion
    m_ParametersTreeState.addParameterListener(DriveID,this);
    m_ParametersTreeState.addParameterListener(ClipFactorID,this);

    //Output
    m_ParametersTreeState.addParameterListener(WetGainID,this);
    m_ParametersTreeState.addParameterListener(MixID,this);
    m_ParametersTreeState.addParameterListener(OutputGainID,this);
}

DaKog_DistortAudioProcessor::~DaKog_DistortAudioProcessor()
{
    m_ParametersTreeState.removeParameterListener(InputID, this);
    //Filter 
    m_ParametersTreeState.removeParameterListener(LoPassFilterCutOffID, this);

    //SineWave
    m_ParametersTreeState.removeParameterListener(SineFrequencyID, this);
    m_ParametersTreeState.removeParameterListener(SineMixID, this);
    m_ParametersTreeState.removeParameterListener(SineToggleID, this);

    //Distortion
    m_ParametersTreeState.removeParameterListener(DriveID, this);
    m_ParametersTreeState.removeParameterListener(ClipFactorID, this);

    //Output
    m_ParametersTreeState.removeParameterListener(WetGainID, this);
    m_ParametersTreeState.removeParameterListener(MixID, this);
    m_ParametersTreeState.removeParameterListener(OutputGainID, this);
}

void DaKog_DistortAudioProcessor::parameterChanged(const juce::String& parameterID, float /*newValue*/)
{

    //TODO find a better solution to remove this if/else madness
    if (parameterID == InputID)
        m_InputGain = m_ParametersTreeState.getRawParameterValue(InputID)->load();
    //Filters
    else if (parameterID == LoPassFilterCutOffID ||
        parameterID == HiPassFilterCutOffID)
        UpdateFilters(parameterID);
    //Distortion
    else if (parameterID == DriveID)
        m_DistortionDSP.SetDrive(m_ParametersTreeState.getRawParameterValue(DriveID)->load());
    else if (parameterID == ClipFactorID)
        m_DistortionDSP.SetFactor(m_ParametersTreeState.getRawParameterValue(ClipFactorID)->load());
    //SineWave
    else if (parameterID == SineFrequencyID 
        || parameterID == SineToggleID)
        UpdateSineWaves(parameterID);
    else if (parameterID == SineMixID)
        m_SineMix = m_ParametersTreeState.getRawParameterValue(SineMixID)->load();
    //Output
    else if (parameterID == WetGainID)
        m_WetGain = m_ParametersTreeState.getRawParameterValue(WetGainID)->load();
    else if (parameterID == MixID)
        m_Mix = m_ParametersTreeState.getRawParameterValue(MixID)->load();
    else if (parameterID == OutputGainID)
        m_OutputGain = m_ParametersTreeState.getRawParameterValue(OutputGainID)->load();
}

void DaKog_DistortAudioProcessor::UpdateSineWaves(const juce::String& parameterID)
{
    if (parameterID == SineFrequencyID)
    {
        for (int i = 0; i < getTotalNumOutputChannels(); ++i)
        {
            m_SineWaves[i].SetFrequency(m_ParametersTreeState.getRawParameterValue(SineFrequencyID)->load());
        }
    }
    else if (parameterID == SineToggleID)
    {
        m_ToggleSineWave = m_ParametersTreeState.getRawParameterValue(SineToggleID)->load();
    }
}

void DaKog_DistortAudioProcessor::UpdateFilters(const juce::String& parameterID)
{
    if (parameterID == LoPassFilterCutOffID)
    {
        for (int i = 0; i < getTotalNumOutputChannels(); ++i)
        {
            m_LoPassFilter[i].coefficients = juce::dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(m_ParametersTreeState.getRawParameterValue(LoPassFilterCutOffID)->load(), getSampleRate(), s_ButterWorthFilterPole)[0];
        }
    }

    if (parameterID == HiPassFilterCutOffID)
    {
        for (int i = 0; i < getTotalNumOutputChannels(); ++i)
        {
            m_HiPassFilter[i].coefficients = juce::dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(m_ParametersTreeState.getRawParameterValue(HiPassFilterCutOffID)->load(), getSampleRate(), s_ButterWorthFilterPole)[0];
        }
    }
}


void DaKog_DistortAudioProcessor::UpdateParameters()
{
    for (int i = 0; i < getTotalNumOutputChannels(); ++i)
    {
        m_LoPassFilter[i].coefficients = juce::dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(m_ParametersTreeState.getRawParameterValue(LoPassFilterCutOffID)->load(), getSampleRate(), s_ButterWorthFilterPole)[0];
    }

    for (int i = 0; i < getTotalNumOutputChannels(); ++i)
    {
        m_HiPassFilter[i].coefficients = juce::dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(m_ParametersTreeState.getRawParameterValue(HiPassFilterCutOffID)->load(), getSampleRate(), s_ButterWorthFilterPole)[0];
    }

    m_DistortionDSP.SetDrive(m_ParametersTreeState.getRawParameterValue(DriveID)->load());
    m_DistortionDSP.SetFactor(m_ParametersTreeState.getRawParameterValue(ClipFactorID)->load());

    m_DistortionDSP.SetFactor(m_ParametersTreeState.getRawParameterValue(ClipFactorID)->load());
    m_InputGain = m_ParametersTreeState.getRawParameterValue(InputID)->load();
}

//==============================================================================
const juce::String DaKog_DistortAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DaKog_DistortAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DaKog_DistortAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DaKog_DistortAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DaKog_DistortAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DaKog_DistortAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DaKog_DistortAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DaKog_DistortAudioProcessor::setCurrentProgram (int /*index*/)
{
}

const juce::String DaKog_DistortAudioProcessor::getProgramName (int /*index*/)
{
    return {};
}

void DaKog_DistortAudioProcessor::changeProgramName (int /*index*/, const juce::String& /*newName*/)
{
}

//==============================================================================
void DaKog_DistortAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    int numberOfChannels = getTotalNumOutputChannels();
    juce::dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = numberOfChannels;

    //Setup Filter

    for (int i = 0; i < numberOfChannels; ++i)
    {
        m_LoPassFilter[i] = juce::dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(20000, sampleRate, s_ButterWorthFilterPole)[0];
    }


    for (int i = 0; i < numberOfChannels; ++i)
    {
        m_HiPassFilter[i] = juce::dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(20, sampleRate, s_ButterWorthFilterPole)[0];
    }

    //Setup Distortion
    m_DistortionDSP.PrepareToPlay(spec);
    
    //Setup Sinewaves 
    for (int i = 0; i < numberOfChannels; ++i)
    {
        m_SineWaves[i].PreprareToPlay(sampleRate);
    }

    //Reset Parameters
    m_InputGain.reset(sampleRate, 0.02f);
    m_InputGain.setTargetValue(0.0f);
    UpdateParameters();

    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void DaKog_DistortAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DaKog_DistortAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DaKog_DistortAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& /*midiMessages*/)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float inSample = buffer.getSample(channel, sample) * juce::Decibels::decibelsToGain(m_InputGain.getNextValue());
            float drySample = inSample;

            //Filters 
            inSample = m_LoPassFilter[channel].processSample(inSample);
            inSample = m_HiPassFilter[channel].processSample(inSample);
            

            //Distortion
            inSample = m_DistortionDSP.ProcessSample(inSample);

            //Sine Wave Generator
            if (m_ToggleSineWave)
            {
                float sineDrySample = inSample;
                inSample = inSample * m_SineWaves[channel].getNextSample();
                float sineMixVlaue = m_SineMix.getNextValue() * 0.01f;
                inSample = (sineDrySample * (1.0f - sineMixVlaue)) + (inSample * sineMixVlaue);
            }

            //Safety Hardclip
            inSample = inSample > 1.0f ? 1.0f : inSample < -1.0f ? -1.0f : inSample;

            //Output
            inSample = inSample * juce::Decibels::decibelsToGain(m_WetGain.getNextValue());
            float mixVlaue = m_Mix.getNextValue() * 0.01f;
            inSample = (drySample * (1.0f - mixVlaue)) + (inSample * mixVlaue);
            channelData[sample] = inSample * juce::Decibels::decibelsToGain(m_OutputGain.getNextValue());
        }
    }
}

//==============================================================================
bool DaKog_DistortAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* DaKog_DistortAudioProcessor::createEditor()
{
   return new DaKog_DistortAudioProcessorEditor(*this);
}

//==============================================================================
void DaKog_DistortAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    auto state = m_ParametersTreeState.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void DaKog_DistortAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(m_ParametersTreeState.state.getType()))
            m_ParametersTreeState.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessorValueTreeState::ParameterLayout DaKog_DistortAudioProcessor::SetupParameters()
{
    juce::AudioProcessorValueTreeState::ParameterLayout parameters;
    juce::NormalisableRange<float> inputdbGainRange = makeRange::withCentre(-96, 6, -9, false);
    juce::NormalisableRange<float> outputdbGainRange = makeRange::withCentre(-96, 0, -15, false);
    juce::NormalisableRange<float> driveRange = makeRange::withCentre(1, 150, 20, false);
    juce::NormalisableRange<float> frequencyRange = makeRange::withCentre(20.f, 20000.f, 1000.f, true);

    auto gainAtributes = juce::AudioParameterFloatAttributes()
        .withStringFromValueFunction([](float value, int) { return juce::String(value, 1); })
        .withValueFromStringFunction([](const juce::String& text) { return text.getFloatValue(); });

    auto frequencyAtributes = juce::AudioParameterFloatAttributes()
        .withStringFromValueFunction([](float value, int) { return juce::String(value, 0); })
        .withValueFromStringFunction([](const juce::String& text) { return text.getFloatValue(); });

    parameters.add(std::make_unique<juce::AudioParameterFloat>(InputID, InputName, inputdbGainRange, 0.0f, gainAtributes));
    //Distortion
    parameters.add(std::make_unique<juce::AudioParameterFloat>(DriveID, DriveName, driveRange, 1.0f, gainAtributes));
    parameters.add(std::make_unique<juce::AudioParameterFloat>(ClipFactorID, ClipFactorName,0.1f,30.f,1.f));
    //SineWave
    parameters.add(std::make_unique<juce::AudioParameterBool>(SineToggleID, SineToggleName,false));
    parameters.add(std::make_unique<juce::AudioParameterFloat>(SineFrequencyID, SineFrequencyName, frequencyRange, 432.f, frequencyAtributes));
    parameters.add(std::make_unique<juce::AudioParameterInt>(SineMixID, SineMixName, 0, 100, 50));
    //Filters
    parameters.add(std::make_unique<juce::AudioParameterFloat>(LoPassFilterCutOffID, LoPassFilterCutOffName, frequencyRange, 20000.f, frequencyAtributes));
    parameters.add(std::make_unique<juce::AudioParameterFloat>(HiPassFilterCutOffID, HiPassFilterCutOffName, frequencyRange, 20.f, frequencyAtributes));
    //Output
    parameters.add(std::make_unique<juce::AudioParameterFloat>(WetGainID, WetGainName, outputdbGainRange, 0.0f, gainAtributes));
    parameters.add(std::make_unique<juce::AudioParameterInt>(MixID, MixName, 0, 100, 50));
    parameters.add(std::make_unique<juce::AudioParameterFloat>(OutputGainID, OutputGainName, outputdbGainRange, 0.0f, gainAtributes));

    return parameters;
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DaKog_DistortAudioProcessor();
}

