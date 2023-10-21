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

#include "DaKog_VerticalSlider.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DaKog_VerticalSlider::DaKog_VerticalSlider ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_BottomLabel.reset (new juce::Label ("new label",
                                          TRANS ("Text")));
    addAndMakeVisible (m_BottomLabel.get());
    m_BottomLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    m_BottomLabel->setJustificationType (juce::Justification::centred);
    m_BottomLabel->setEditable (false, false, false);
    m_BottomLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_BottomLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_BottomLabel->setBounds (0, 0, 64, 24);

    m_DaKogVerticalSlider.reset (new juce::Slider ("m_DaKogRotorSilder"));
    addAndMakeVisible (m_DaKogVerticalSlider.get());
    m_DaKogVerticalSlider->setRange (0, 1, 1);
    m_DaKogVerticalSlider->setSliderStyle (juce::Slider::LinearVertical);
    m_DaKogVerticalSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 92, 20);
    m_DaKogVerticalSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff5b5b5b));
    m_DaKogVerticalSlider->setColour (juce::Slider::thumbColourId, juce::Colours::white);
    m_DaKogVerticalSlider->setColour (juce::Slider::trackColourId, juce::Colour (0xffc1c1c1));
    m_DaKogVerticalSlider->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::white);
    m_DaKogVerticalSlider->setColour (juce::Slider::rotarySliderOutlineColourId, juce::Colours::white);
    m_DaKogVerticalSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x66c6c6c6));

    m_DaKogVerticalSlider->setBounds (8, 24, 48, 448);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DaKog_VerticalSlider::~DaKog_VerticalSlider()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_BottomLabel = nullptr;
    m_DaKogVerticalSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DaKog_VerticalSlider::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DaKog_VerticalSlider::resized()
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

<JUCER_COMPONENT documentType="Component" className="DaKog_VerticalSlider" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="1b62d27a1e93c3fc" memberName="m_BottomLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="m_DaKogRotorSilder" id="fb640ad76e405aa9" memberName="m_DaKogVerticalSlider"
          virtualName="" explicitFocusOrder="0" pos="8 24 48 448" bkgcol="ff5b5b5b"
          thumbcol="ffffffff" trackcol="ffc1c1c1" rotarysliderfill="ffffffff"
          rotaryslideroutline="ffffffff" textboxhighlight="66c6c6c6" min="0.0"
          max="1.0" int="1.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="92" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

