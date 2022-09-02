/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

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
}

DaKog_DistortAudioProcessor::~DaKog_DistortAudioProcessor()
{
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

void DaKog_DistortAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String DaKog_DistortAudioProcessor::getProgramName (int index)
{
    return {};
}

void DaKog_DistortAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void DaKog_DistortAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
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

void DaKog_DistortAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    //Get Parameters
    const float inputGain = m_ParametersTreeState.getRawParameterValue("INPUTGAIN")->load();
    const float drive = m_ParametersTreeState.getRawParameterValue("DRIVE")->load();
    const float clipFactor = m_ParametersTreeState.getRawParameterValue("CLIPFACTOR")->load();
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float inSample = buffer.getSample(channel, sample) * inputGain;
            const float drySignal = inSample;

            //Distortion
            inSample = inSample  * drive;

            //Output
            channelData[sample] = inSample

        }
    }
}

//==============================================================================
bool DaKog_DistortAudioProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* DaKog_DistortAudioProcessor::createEditor()
{
    return new DaKog_DistortAudioProcessorEditor (*this);
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
    parameters.add(std::make_unique<juce::AudioParameterFloat>("INPUTGAIN","InputGain",0.f,1.f,0.5f));
    //Distortion
    parameters.add(std::make_unique<juce::AudioParameterFloat>("DRIVE","Drive",0.f,1.f,0.5f));
    parameters.add(std::make_unique<juce::AudioParameterFloat>("CLIPFACTOR","ClipFactor",0.f,1.f,0.5f));
    //SineWave
    parameters.add(std::make_unique<juce::AudioParameterBool>("SINE_TOGGLE","SineWave",false));
    parameters.add(std::make_unique<juce::AudioParameterFloat>("SINE_FREQ","SineFrequency",0.f, 1.f, 0.5f));
    //Filters
    parameters.add(std::make_unique<juce::AudioParameterBool>("LOWPASS_TOGGLE","LowPass",false));
    parameters.add(std::make_unique<juce::AudioParameterFloat>("LOWPASS_CUTOFF","LowPassCutoff", 20.f, 20000.f, 20000.f));
    parameters.add(std::make_unique<juce::AudioParameterBool>("HIPASS_TOGGLE", "HighPass", true));
    parameters.add(std::make_unique<juce::AudioParameterFloat>("HIPASS_CUTOFF", "HighPassCutoff", 20.f, 20000.f, 20.f));
    //Output
    parameters.add(std::make_unique<juce::AudioParameterBool>("WETGAIN", "WetGain", 0.f, 1.f, 0.5f));
    parameters.add(std::make_unique<juce::AudioParameterBool>("DRYWET", "DryWet", 0.f, 1.f, 0.5f));
    parameters.add(std::make_unique<juce::AudioParameterBool>("OUTPUTGAIN", "OutputGain", 0.f, 1.f, 0.5f));
    

    return parameters;
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DaKog_DistortAudioProcessor();
}

