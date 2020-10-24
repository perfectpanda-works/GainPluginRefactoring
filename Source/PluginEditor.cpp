/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
//GainPluginAudioProcessorEditor::GainPluginAudioProcessorEditor (GainPluginAudioProcessor& p)
//   : AudioProcessorEditor (&p), audioProcessor (p)
//{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
//    setSize (400, 300);
//}

GainPluginAudioProcessorEditor::GainPluginAudioProcessorEditor(juce::AudioProcessor& parent, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(parent),
    valueTreeState(vts)
{
    gainLabel.setText("Gain", juce::dontSendNotification);
    addAndMakeVisible(gainLabel);

    addAndMakeVisible(gainSlider);
    gainAttachment.reset(new SliderAttachment(valueTreeState, "gain", gainSlider));

    invertButton.setButtonText("Invert Phase");
    addAndMakeVisible(invertButton);
    invertAttachment.reset(new ButtonAttachment(valueTreeState, "invertPhase", invertButton));

    //setSize(paramSliderWidth + paramLabelWidth, juce::jmax(100, paramControlHeight * 2));
    setSize(400, 300);
}

GainPluginAudioProcessorEditor::~GainPluginAudioProcessorEditor()
{
}

//==============================================================================
void GainPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void GainPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto r = getLocalBounds();

    auto gainRect = r.removeFromTop(paramControlHeight);
    gainLabel.setBounds(gainRect.removeFromLeft(paramLabelWidth));
    gainSlider.setBounds(gainRect);

    invertButton.setBounds(r.removeFromTop(paramControlHeight));
}
