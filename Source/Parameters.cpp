#include "Parameters.h"

Parameters::Parameters(juce::AudioProcessorValueTreeState& apvts)
{
	auto* param = apvts.getParameter(delayParamID.getParamID());
	delayParam = dynamic_cast<juce::AudioParameterFloat*>(param);
}

void Parameters::update() noexcept
{
	delayTime = delayParam->get();
}

juce::AudioProcessorValueTreeState::ParameterLayout Parameters::createParameterLayout()
{
	juce::AudioProcessorValueTreeState::ParameterLayout layout;

	layout.add(std::make_unique<juce::AudioParameterFloat>(
		delayParamID,
		"Delay",
		juce::NormalisableRange<float> {0.05f, 2.0f},
		0.2f)
	);

	return layout;
}