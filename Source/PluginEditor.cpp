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
    frequencySlider.setRange(20, 20000, 1);
    frequencySlider.setValue(10000);
    frequencySlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    frequencySlider.addListener(this);
    
    addAndMakeVisible(&frequencySlider);
    
    frequencyLabel.attachToComponent(&frequencySlider, false);
    frequencyLabel.setText("Frequency", NotificationType::dontSendNotification);
    frequencyLabel.setJustificationType(Justification::centred);
    
    gainSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    gainSlider.setRange(0, 11, 1);
    gainSlider.setValue(5);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    gainSlider.addListener(this);
    
    addAndMakeVisible(&gainSlider);
    
    gainLabel.attachToComponent(&gainSlider, false);
    gainLabel.setText("Gain", NotificationType::dontSendNotification);
    gainLabel.setJustificationType(Justification::centred);
    
    qSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    qSlider.setRange(0.1, 20, 0.1);
    qSlider.setValue(10);
    qSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    qSlider.addListener(this);
    
    addAndMakeVisible(&qSlider);
    
    qLabel.attachToComponent(&qSlider, false);
    qLabel.setText("Q", NotificationType::dontSendNotification);
    qLabel.setJustificationType(Justification::centred);
    
    filterMenu.addItem("Peak", 1);
    filterMenu.addItem("Lowpass", 2);
    filterMenu.addItem("Highpass", 3);
    filterMenu.setSelectedId(0);
    filterMenu.addListener(this);
    
    addAndMakeVisible(&filterMenu);
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
    gainSlider.setBounds(40, 170, 100, 100);
    qSlider.setBounds(170, 40, 100, 100);
    filterMenu.setBounds(170, 170, 100, 100);
}

void _3bandEqAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    processor.freq = frequencySlider.getValue();
    processor.gain = gainSlider.getValue();
    processor.q = qSlider.getValue();
}

void _3bandEqAudioProcessorEditor::comboBoxChanged (ComboBox* comboBox)
{
    processor.control = filterMenu.getSelectedId() - 1;
}