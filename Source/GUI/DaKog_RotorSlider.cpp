/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.8

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "DaKog_RotorSlider.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DaKog_RotorSlider::DaKog_RotorSlider ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_RotorLabel.reset (new juce::Label ("RotorLabel",
                                         TRANS ("label text")));
    addAndMakeVisible (m_RotorLabel.get());
    m_RotorLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    m_RotorLabel->setJustificationType (juce::Justification::centred);
    m_RotorLabel->setEditable (false, false, false);
    m_RotorLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_RotorLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_RotorLabel->setBounds (16, 0, 104, 24);

    m_DaKogRotorSilder.reset (new juce::Slider ("DaKog_RotorSilder"));
    addAndMakeVisible (m_DaKogRotorSilder.get());
    m_DaKogRotorSilder->setExplicitFocusOrder (1);
    m_DaKogRotorSilder->setRange (0, 10, 1);
    m_DaKogRotorSilder->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_DaKogRotorSilder->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 72, 20);
    m_DaKogRotorSilder->setColour (juce::Slider::thumbColourId, juce::Colours::white);
    m_DaKogRotorSilder->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xffd7d7d7));
    m_DaKogRotorSilder->setColour (juce::Slider::rotarySliderOutlineColourId, juce::Colour (0xff6b6b6b));
    m_DaKogRotorSilder->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x668b8b8b));

    m_DaKogRotorSilder->setBounds (16, 24, 104, 112);

    m_LeftLabel.reset (new juce::Label ("LeftLabel",
                                        TRANS ("0")));
    addAndMakeVisible (m_LeftLabel.get());
    m_LeftLabel->setFont (juce::Font ("Calibri", 19.20f, juce::Font::plain).withTypefaceStyle ("Regular"));
    m_LeftLabel->setJustificationType (juce::Justification::centredRight);
    m_LeftLabel->setEditable (false, false, false);
    m_LeftLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_LeftLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_LeftLabel->setBounds (-8, 96, 48, 16);

    m_RightLabel.reset (new juce::Label ("RightLabel",
                                         TRANS ("11000")));
    addAndMakeVisible (m_RightLabel.get());
    m_RightLabel->setFont (juce::Font ("Calibri", 19.20f, juce::Font::plain).withTypefaceStyle ("Regular"));
    m_RightLabel->setJustificationType (juce::Justification::centredLeft);
    m_RightLabel->setEditable (false, false, false);
    m_RightLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_RightLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_RightLabel->setBounds (88, 96, 64, 16);


    //[UserPreSize]
    m_DaKogRotorSilder->setLookAndFeel(&m_LookAndFeel);
    //[/UserPreSize]

    setSize (144, 144);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DaKog_RotorSlider::~DaKog_RotorSlider()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_RotorLabel = nullptr;
    m_DaKogRotorSilder = nullptr;
    m_LeftLabel = nullptr;
    m_RightLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DaKog_RotorSlider::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DaKog_RotorSlider::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DaKog_RotorSlider" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="144" initialHeight="144">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="RotorLabel" id="ce165a1f18d9fc20" memberName="m_RotorLabel"
         virtualName="" explicitFocusOrder="0" pos="16 0 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DaKog_RotorSilder" id="4c17abbf426b9f3" memberName="m_DaKogRotorSilder"
          virtualName="" explicitFocusOrder="1" pos="16 24 104 112" thumbcol="ffffffff"
          rotarysliderfill="ffd7d7d7" rotaryslideroutline="ff6b6b6b" textboxhighlight="668b8b8b"
          min="0.0" max="10.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="72"
          textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <LABEL name="LeftLabel" id="65e4b92ab4a78c89" memberName="m_LeftLabel"
         virtualName="" explicitFocusOrder="0" pos="-8 96 48 16" edTextCol="ff000000"
         edBkgCol="0" labelText="0" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Calibri" fontsize="19.2" kerning="0.0"
         bold="0" italic="0" justification="34"/>
  <LABEL name="RightLabel" id="dd847a6f3f0520e8" memberName="m_RightLabel"
         virtualName="" explicitFocusOrder="0" pos="88 96 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="11000" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Calibri" fontsize="19.2" kerning="0.0"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

