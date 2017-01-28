/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class _3bandEqAudioProcessorEditor : public AudioProcessorEditor, private Slider::Listener, private ComboBox::Listener
{
public:
    _3bandEqAudioProcessorEditor (_3bandEqAudioProcessor&);
    ~_3bandEqAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    void sliderValueChanged (Slider* slider) override;
    void comboBoxChanged (ComboBox* comboBox) override;
    
    _3bandEqAudioProcessor& processor;
    
    Slider frequencySlider;
    Label frequencyLabel;
    
    Slider gainSlider;
    Label gainLabel;
    
    Slider qSlider;
    Label qLabel;
    
    ComboBox filterMenu;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_3bandEqAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
