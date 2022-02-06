#include "featureExtractor.h"
#include <cmath>

//Constructor using sampling rate and window length in seconds
FeatureExtractor::FeatureExtractor(std::vector<Filter> &filters, float samplingRate, float windowLength)
{
		this->filters=filters;
		this->windowSamples=int (samplingRate*windowLength);
		this->sampleCount=0;
		this->energy.resize(filters.size());
		std::fill(this->energy.begin(), this->energy.end(), 0);
		this->totalEnergy=0;
		this->ready=false;
}

//Constructor using window length in samples directly
FeatureExtractor::FeatureExtractor(std::vector<Filter> &filters, int windowSamples)
{
		this->filters=filters;
		this->windowSamples=windowSamples;
		this->sampleCount=0;
		this->energy.resize(filters.size());
		std::fill(this->energy.begin(), this->energy.end(), 0);
		this->totalEnergy=0;
		this->ready=false;
}
	
//Update feature extractor with new sample

void FeatureExtractor::update (float value)
{
	float energy_local;
	for (int i=0; i<filters.size(); i++)
	{
		energy_local=filters[i].filter(value);
		energy[i]+=pow(energy_local,2);
	}
  	
  	totalEnergy+=pow(value,2);
	sampleCount=sampleCount+1;
  
	//If sample count has reached window length, normalize, set flag as ready and reset sample count
	if(sampleCount>=windowSamples)
	{
		for (int i=0; i<filters.size(); i++)
		{
			energy[i]=energy[i]/totalEnergy;
		}
		ready=true;
		sampleCount=0;
	}
  
}

//Return ready state
bool FeatureExtractor::isReady()
{
	return ready;
}

//Return energy
std::vector<float> FeatureExtractor::getEnergy()
{
	ready=false;
	return energy;
}

//Return totalEnergy
float FeatureExtractor::getTotalEnergy()
{
	return totalEnergy;
}

//Clear energy
void FeatureExtractor::clearEnergy()
{
	std::fill(energy.begin(), energy.end(), 0);
	totalEnergy=0;
}

