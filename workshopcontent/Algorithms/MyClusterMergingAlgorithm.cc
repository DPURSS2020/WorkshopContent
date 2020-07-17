/**
 *  @file   WorkshopContent/workshopcontent/Algorithms/MyClusterMergingAlgorithm.cc
 * 
 *  @brief  Implementation of the myclustermerging algorithm class.
 * 
 *  $Log: $
 */

#include "Pandora/AlgorithmHeaders.h"

#include "workshopcontent/Algorithms/MyClusterMergingAlgorithm.h"

#include "larpandoracontent/LArHelpers/LArPointingClusterHelper.h"
#include "larpandoracontent/LArObjects/LArPointingCluster.h"

#include "larpandoracontent/LArMonitoring/NeutrinoEventValidationAlgorithm.h"


#include "larpandoracontent/LArHelpers/LArGeometryHelper.h"
#include "larpandoracontent/LArObjects/LArTwoDSlidingFitResult.h"

using namespace pandora;

namespace workshop_content
{

	MyClusterMergingAlgorithm::MyClusterMergingAlgorithm() :
		m_inputClusterListName(),
		m_minClusterCaloHits(5),
		m_maxClusterSeparation(5.f),
		m_maxImpactL(3.f),
		m_maxImpactT(3.f)
	{
	}

StatusCode MyClusterMergingAlgorithm::Run()
{

    // Algorithm code here
	const ClusterList *pClusterList(nullptr);
	PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, PandoraContentApi::GetList(*this, m_inputClusterListName, pClusterList));
	
	ClusterVector sortedLongClusters;
	this->GetSortedLongClusters(pClusterList, sortedLongClusters);
	
	
	ClusterList defunctClusters;
    
    PandoraMonitoringApi::VisualizeClusters(this->GetPandora(), pClusterList, "pClusterList", RED);
	
	for (const Cluster *const pParentCluster : sortedLongClusters)
	{
		const bool isParentDefunct = std::find(defunctClusters.begin(), defunctClusters.end(), pParentCluster) != defunctClusters.end();
		
		if (isParentDefunct)
			continue;
		for (const Cluster *const pDaughterCluster : sortedLongClusters)
		{
            
            const bool isDaughterDefunct = std::find(defunctClusters.begin(), defunctClusters.end(), pDaughterCluster) != defunctClusters.end();
            
			if ( (pParentCluster == pDaughterCluster) || isDaughterDefunct)
				continue;
				
			if (!this->AreClustersAssociated(pParentCluster, pDaughterCluster))
				continue;
				
			PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, PandoraContentApi::MergeAndDeleteClusters(*this, pParentCluster, pDaughterCluster));
			defunctClusters.push_back(pDaughterCluster);
		}
	}

    return STATUS_CODE_SUCCESS;
}

//------------------------------------------------------------------------------------------------------------------------------------------



StatusCode MyClusterMergingAlgorithm::ReadSettings(const TiXmlHandle xmlHandle)
{
    // Read settings from xml file here
	PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, XmlHelper::ReadValue(xmlHandle, "InputClusterListName", m_inputClusterListName));
	PANDORA_RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, XmlHelper::ReadValue(xmlHandle, "MinClusterCaloHits", m_minClusterCaloHits));
	PANDORA_RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, XmlHelper::ReadValue(xmlHandle, "MaxClusterSeparation", m_maxClusterSeparation));
    return STATUS_CODE_SUCCESS;
}

/*
bool MyClusterMergingAlgorithm::AreClustersAssociated(const Cluster *const pParentCluster, const Cluster *const pDaughterCluster) const
{
	try
	{
		// Useful constructs for evaluating topological information
		const float slidingFitPitch(LArGeometryHelper::GetWireZPitch(this->GetPandora()));
		const TwoDSlidingFitResult parentFitResult(pParentCluster, m_slidingFitWindow, slidingFitPitch);
		const TwoDSlidingFitResult daughterFitResult(pDaughterCluster, m_slidingFitWindow, slidingFitPitch);
		// TODO - Make decisions
		return true;
		
	}
	catch (const StatusCodeException &statusCodeException)
	{
		std::cout << "MyClusterMergingAlgorithm::AreClustersAssociated " << statusCodeException.ToString() << std::endl;
	}
	return false;
}
*/


/*
bool MyClusterMergingAlgorithm::AreClustersAssociated(const Cluster *const pParentCluster, const Cluster *const pDaughterCluster) const
{
	// TODO This is where the crucial cluster-merging decision is to be made - add sophistication here!
	if (LArClusterHelper::GetClosestDistance(pParentCluster, pDaughterCluster) > m_maxClusterSeparation)
		return false;
	return true;
}
*/



bool MyClusterMergingAlgorithm::AreClustersAssociated(const Cluster *const pParentCluster, const Cluster *const pDaughterCluster) const
{
	try
	{
		// Useful constructs for pointing information
		const LArPointingCluster parentPointingCluster(pParentCluster);
		const LArPointingCluster daughterPointingCluster(pDaughterCluster);
		LArPointingCluster::Vertex closestVertexParent, closestVertexDaughter;
		LArPointingClusterHelper::GetClosestVertices(parentPointingCluster, daughterPointingCluster, closestVertexParent, closestVertexDaughter);
		// Impact parameters
		float parentDaughterImpactL(std::numeric_limits<float>::max()), parentDaughterImpactT(std::numeric_limits<float>::max());
		LArPointingClusterHelper::GetImpactParameters(closestVertexParent, closestVertexDaughter, parentDaughterImpactL, parentDaughterImpactT);
		float daughterParentImpactL(std::numeric_limits<float>::max()), daughterParentImpactT(std::numeric_limits<float>::max());
		LArPointingClusterHelper::GetImpactParameters(closestVertexDaughter, closestVertexParent, daughterParentImpactL, daughterParentImpactT);
		    // Visualization and debug
        //std::cout << "With Impact Parameters: " << std::endl;
        //std::cout << "maxImpactL: " << m_maxImpactL << std::endl;
        //std::cout << "maxImpactT: " << m_maxImpactT << std::endl;
		//std::cout << "MyClusterMergingAlgorithm::AreClustersAssociated " << std::endl;
		//std::cout << "parentDaughterImpactL: " << parentDaughterImpactL << ", parentDaughterImpactT " << parentDaughterImpactT << std::endl;
		//std::cout << "daughterParentImpactL: " << daughterParentImpactL << ", daughterParentImpactT " << daughterParentImpactT << std::endl;
		ClusterList parentList, daughterList;
		parentList.push_back(pParentCluster); daughterList.push_back(pDaughterCluster);
		
		/*
		    //COMMENT THIS OUT
		PandoraMonitoringApi::VisualizeClusters(this->GetPandora(), &parentList, "ParentCluster", RED);
		PandoraMonitoringApi::VisualizeClusters(this->GetPandora(), &daughterList, "DaughterCluster", BLUE);
		PandoraMonitoringApi::AddMarkerToVisualization(this->GetPandora(), &(closestVertexParent.GetPosition()), "ParentVertex", ORANGE, 2);
		PandoraMonitoringApi::AddMarkerToVisualization(this->GetPandora(), &(closestVertexDaughter.GetPosition()), "DaughterVertex", GREEN, 2);
		PandoraMonitoringApi::ViewEvent(this->GetPandora());
		*/
					

		// Make decision

		if (((parentDaughterImpactL < m_maxImpactL) && (parentDaughterImpactT < m_maxImpactT)) ||
		((daughterParentImpactL < m_maxImpactL) && (daughterParentImpactT < m_maxImpactT)))
		{
		    std::cout << "-Found two associated clusters-" <<std::endl;
			return true;
		}
	}
	catch (const StatusCodeException &statusCodeException)
	{
		//std::cout << "MyClusterMergingAlgorithm::AreClustersAssociated " << statusCodeException.ToString() << std::endl;
	}
	//std::cout << "-Clusters not associated-" << std::endl;
	return false;
}



void MyClusterMergingAlgorithm::GetSortedLongClusters(const ClusterList *const pClusterList, ClusterVector &sortedLongClusters)
{
	for (const Cluster *const pCluster : *pClusterList)
	{
		if (pCluster->GetNCaloHits() > m_minClusterCaloHits)
			sortedLongClusters.push_back(pCluster);
	}
	std::sort(sortedLongClusters.begin(), sortedLongClusters.end(), LArClusterHelper::SortByNHits);
}



} // namespace workshop_content
