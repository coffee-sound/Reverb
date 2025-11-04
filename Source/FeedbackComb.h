#pragma once
#include <JuceHeader.h>

class FeedbackComb
{
public:
	void prepare(double sampleRate, int maxDelayInSamples);
	float processSample(float x);

	void setDelaySamples(int D);
	void setBeta(float beta);

	int getMaxDelayInSamples() { return maxDelayInSamples; }

private:
	double fs = 44100.0f;
	float delayTime = 0.2f;
	std::vector<float> buffer;
	int bufferLength = 0;
	int maxDelayInSamples = 0;
	int writeIndex = 0;
	int delayInSamples = 0;
	float beta = 0.8f;
};