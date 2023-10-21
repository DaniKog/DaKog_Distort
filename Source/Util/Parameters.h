/*
  ==============================================================================

    Parameters.h
    Created: 4 Nov 2022 3:25:27pm
    Author:  Dani

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

//Parameters Def
const juce::String InputID = "INPUTGAIN";
const juce::String InputName = "InputGain";

//Filter
const juce::String LoPassFilterCutOffID = "LOWPASSCUTOFF";
const juce::String LoPassFilterCutOffName = "LowPassCutOff";

const juce::String HiPassFilterCutOffID = "HIPASSCUTOFF";
const juce::String HiPassFilterCutOffName = "HiPassCutOff";

//SineWave
const juce::String SineFrequencyID = "SINEFREQ";
const juce::String SineFrequencyName = "Frequency";

const juce::String SineMixID = "SINEMIX";
const juce::String SineMixName = "SineMix";

const juce::String SineToggleID = "SINETOGGLE";
const juce::String SineToggleName = "SineToggle";

//Distortion
const juce::String DriveID = "DRIVE";
const juce::String DriveName = "Drive";

const juce::String ClipFactorID = "CLIPFACTOR";
const juce::String ClipFactorName = "ClipFactor";

//Output
const juce::String WetGainID = "WETGAIN";
const juce::String WetGainName = "WetGain";

const juce::String MixID = "MIX";
const juce::String MixName = "Mix";

const juce::String OutputGainID = "OUTPUTGAIN";
const juce::String OutputGainName = "OutputGain";