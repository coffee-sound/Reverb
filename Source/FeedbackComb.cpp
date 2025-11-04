#include "FeedbackComb.h"

void FeedbackComb::prepare(double sampleRate, int maxDelayInSamples)
{
	fs = sampleRate;
	this->maxDelayInSamples = std::max(1, maxDelayInSamples);
	buffer.assign((size_t)maxDelayInSamples, 0.0f);
	bufferLength = (int)buffer.size();
	writeIndex = 0;

	delayInSamples = std::min(100, bufferLength - 1);
	beta = 0.9f;
}

float FeedbackComb::processSample(float x)
{
	int readIndex = writeIndex - delayInSamples;

	if (readIndex < 0) {
		readIndex += bufferLength;
	}

	const float y = buffer[(size_t)readIndex];

	buffer[(size_t)writeIndex] = x + beta * y;

	writeIndex += 1;

	if (writeIndex >= bufferLength) {
		writeIndex = 0;
	}

	return y;

}

void FeedbackComb::setDelaySamples(int D)
{
	delayInSamples = juce::jlimit(1, bufferLength, D);
}

void FeedbackComb::setBeta(float beta)
{
	this->beta = juce::jlimit(0.0f, 0.9999f, beta);
}