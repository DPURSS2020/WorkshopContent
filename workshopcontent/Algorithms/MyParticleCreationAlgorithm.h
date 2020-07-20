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
#include "larpandoracontent/LArHelpers/LArClusterHelper.h"
#include "larpandoracontent/LArHelpers/LArGeometryHelper.h"
#include "larpandoracontent/LArObjects/LArTwoDSlidingFitResult.h"

using namespace lar_content;
using namespace pandora;

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
    
    MyParticleCreationAlgorithm();

private:
    pandora::StatusCode Run();
    pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

    void GetSortedLongClusters(pandora::ClusterVector &sortedLongClustersU, pandora::ClusterVector &sortedLongClustersV,
pandora::ClusterVector &sortedLongClustersW) const;

    void GetSortedLongClusters(const std::string &inputClusterListName, pandora::ClusterVector &sortedLongClusters) const;
    
    bool GetBestParticle(const pandora::ClusterVector &sortedLongClustersU, const pandora::ClusterVector &sortedLongClustersV,
const pandora::ClusterVector &sortedLongClustersW, const pandora::Cluster *&pBestClusterU, const pandora::Cluster *&pBestClusterV,
const pandora::Cluster *&pBestClusterW) const;

    float GetOverlapFigureOfMerit(const pandora::Cluster *const pClusterU, const pandora::Cluster *const pClusterV,
const pandora::Cluster *const pClusterW) const;

    void CreateParticle(const pandora::Cluster *const pClusterU, const pandora::Cluster *const pClusterV,
const pandora::Cluster *const pClusterW) const;

    // Member variables here
    
    std::string m_outputPfoListName;
    std::string m_inputClusterListNameU;
    std::string m_inputClusterListNameV;
    std::string m_inputClusterListNameW;
    int         m_slidingFitWindow;
    int         m_minClusterCaloHits;
    
};

//------------------------------------------------------------------------------------------------------------------------------------------
inline pandora::Algorithm *MyParticleCreationAlgorithm::Factory::CreateAlgorithm() const
{
    return new MyParticleCreationAlgorithm();
}
} // namespace workshop_content



#endif // #ifndef WORKSHOP_MYPARTICLECREATION_ALGORITHM_H
