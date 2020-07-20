/**
 *  @file   WorkshopContent/workshopcontent/Algorithms/MyParticleCreationAlgorithm.h
 * 
 *  @brief  Header file for the myparticlecreation algorithm class.
 * 
 *  $Log: $
 */
#ifndef WORKSHOP_MYPARTICLECREATION_ALGORITHM_H
#define WORKSHOP_MYPARTICLECREATION_ALGORITHM_H 1

#include "Pandora/Algorithm.h"

namespace workshop_content
{

/**
 *  @brief  MyParticleCreationAlgorithm class
 */
class MyParticleCreationAlgorithm : public pandora::Algorithm
{
public:
    /**
     *  @brief  Factory class for instantiating algorithm
     */
    class Factory : public pandora::AlgorithmFactory
    {
    public:
        pandora::Algorithm *CreateAlgorithm() const;
    };

private:
    pandora::StatusCode Run();
    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

    // Member variables here
};

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::Algorithm *MyParticleCreationAlgorithm::Factory::CreateAlgorithm() const
{
    return new MyParticleCreationAlgorithm();
}

} // namespace workshop_content

#endif // #ifndef WORKSHOP_MYPARTICLECREATION_ALGORITHM_H
