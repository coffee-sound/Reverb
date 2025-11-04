#pragma once

#include <JuceHeader.h>

const juce::ParameterID delayParamID{ "delay", 1 };

class Parameters
{
public:
	Parameters(juce::AudioProcessorValueTreeState& apvts);

	static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

	void update() noexcept;

	float delayTime = 0.2f;

private:
	juce::AudioParameterFloat* delayParam;
};