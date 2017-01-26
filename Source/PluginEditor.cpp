/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
_3bandEqAudioProcessorEditor::_3bandEqAudioProcessorEditor (_3bandEqAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    frequencySlider.setSliderStyle(Slider::RotaryVerticalDrag);
    frequencySlider.setRange(20, 20000);
    
    addAndMakeVisible(&frequencySlider);
    
}

_3bandEqAudioProcessorEditor::~_3bandEqAudioProcessorEditor()
{
}

//==============================================================================
void _3bandEqAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void _3bandEqAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    frequencySlider.setBounds(40, 40, 100, 100);
}
