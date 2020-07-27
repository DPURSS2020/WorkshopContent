/**
 *  @file   WorkshopContent/workshopcontent/Algorithms/MyTestAlgorithm.h
 * 
 *  @brief  Header file for the mytest algorithm class.
 * 
 *  $Log: $
 */
#ifndef WORKSHOP_MYTEST_ALGORITHM_H
#define WORKSHOP_MYTEST_ALGORITHM_H 1

#include "Pandora/Algorithm.h"

namespace workshop_content
{

/**
 *  @brief  MyTestAlgorithm class
 */
class MyTestAlgorithm : public pandora::Algorithm
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
    
    /*Default Constructor*/
    MyTestAlgorithm();

private:
    pandora::StatusCode Run();
    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

    // Member variables here
    std::string            m_myMandatoryString;
    bool                   m_myOptionalBool;
    unsigned int           m_myOptionalUnsignedInt;
    pandora::FloatVector   m_myMandatoryFloatVector;

    std::string 		   m_outputClusterListName;
	unsigned int 		   m_nHitsPerCluster;
	
	std::string            m_inputCaloHitListName;
};

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::Algorithm *MyTestAlgorithm::Factory::CreateAlgorithm() const
{
    return new MyTestAlgorithm();
}

} // namespace workshop_content

#endif // #ifndef WORKSHOP_MYTEST_ALGORITHM_H
