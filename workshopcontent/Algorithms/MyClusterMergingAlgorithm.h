/**
 *  @file   WorkshopContent/workshopcontent/Algorithms/MyClusterMergingAlgorithm.h
 * 
 *  @brief  Header file for the myclustermerging algorithm class.
 * 
 *  $Log: $
 */
#ifndef WORKSHOP_MYCLUSTERMERGING_ALGORITHM_H
#define WORKSHOP_MYCLUSTERMERGING_ALGORITHM_H 1

#include "Pandora/Algorithm.h"
#include "larpandoracontent/LArHelpers/LArClusterHelper.h"

using namespace lar_content;

namespace workshop_content
{

/**
 *  @brief  MyClusterMergingAlgorithm class
 */
class MyClusterMergingAlgorithm : public pandora::Algorithm
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
    
    MyClusterMergingAlgorithm();

private:
    pandora::StatusCode Run();
    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);
    bool AreClustersAssociated(const pandora::Cluster *const pParentCluster, const pandora::Cluster *const pDaughterCluster) const;
    void GetSortedLongClusters(const pandora::ClusterList *const pClusterList, pandora::ClusterVector &sortedLongClusters);

    // Member variables here
    std::string  m_inputClusterListName;
    unsigned int m_minClusterCaloHits;
    float        m_maxClusterSeparation;
    float        m_maxImpactL;
    float        m_maxImpactT; 
    float        m_slidingFitWindow;

};

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::Algorithm *MyClusterMergingAlgorithm::Factory::CreateAlgorithm() const
{
    return new MyClusterMergingAlgorithm();
}

} // namespace workshop_content

#endif // #ifndef WORKSHOP_MYCLUSTERMERGING_ALGORITHM_H
