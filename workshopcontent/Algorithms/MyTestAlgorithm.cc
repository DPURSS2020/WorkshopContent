/**
  * @file WorkshopContent/workshopcontent/Algorithms/MyTestAlgorithm.cpp
  * @brief implementation of the mytest algorithm class
  * $Log: $
 */

#include "Pandora/AlgorithmHeaders.h"
#include "larpandoracontent/LArHelpers/LArClusterHelper.h"
#include "larpandoracontent/LArHelpers/LArMCParticleHelper.h"
#include "workshopcontent/Algorithms/MyTestAlgorithm.h"

using namespace pandora;
using namespace lar_content;

namespace workshop_content{
    MyTestAlgorithm::MyTestAlgorithm() :
	m_myMandatoryString(),
	m_myOptionalBool(false),
	m_myOptionalUnsignedInt(5),
	m_myMandatoryFloatVector(),
	
	m_outputClusterListName(),
	m_nHitsPerCluster(10),
	m_inputCaloHitListName()
    {
    }

StatusCode MyTestAlgorithm::Run(){
	std::cout << "-m_myMandatoryString: " << m_myMandatoryString << std::endl;
	std::cout << "-m_myOptionalBool: " << m_myOptionalBool << std::endl;
	std::cout << "-m_myOptionalUnsignedInt: " << m_myOptionalUnsignedInt << std::endl;
	std::cout << "-m_myMandatoryString: ";
	
	
	
		//CaloHits
		
	const CaloHitList *pCaloHitList(nullptr);
	//Declared as a Null Pointer because it IS a pointer itself but we haven't yet given it a place to point to, but the * inicates that it is a pointer for a CaloHitList object
	PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, PandoraContentApi::GetList(*this, m_inputCaloHitListName, pCaloHitList));
	
	const bool showDetectorGaps(true);
	PandoraMonitoringApi::SetEveDisplayParameters(this->GetPandora(), showDetectorGaps, DETECTOR_VIEW_XZ, -1.f, -1.f, 1.f);
	PandoraMonitoringApi::VisualizeCaloHits(this->GetPandora(), pCaloHitList, "CurrentCaloHits", BLUE);

	
	CaloHitVector sortedCaloHits(pCaloHitList->begin(), pCaloHitList->end());
	std::sort(sortedCaloHits.begin(), sortedCaloHits.end(), LArClusterHelper::SortHitsByPosition);
	
	//for (const auto value: m_myMandatoryFloatVector) { //std::cout << value << " "; 
	//}
	//for (const CaloHit *const pCaloHit : sortedCaloHits) { //std::cout << "Input Hit - Hit Type: " << pCaloHit->GetHitType() << ", " << pCaloHit->GetPositionVector() << std::endl; 
	//}

	const ClusterList *pTemporaryList(nullptr);
	std::string temporaryListName;
	PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, PandoraContentApi::CreateTemporaryListAndSetCurrent(*this, pTemporaryList, temporaryListName));
	
	const Cluster *pCluster(nullptr);
	
	for (const CaloHit *const pCaloHit : sortedCaloHits) 
	{
		if (!PandoraContentApi::IsAvailable(*this, pCaloHit))
			continue;
		
		if (!pCluster || (pCluster->GetNCaloHits() >= m_nHitsPerCluster)){
			PandoraContentApi::Cluster::Parameters parameters;
			parameters.m_caloHitList.push_back(pCaloHit);
			PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, PandoraContentApi::Cluster::Create(*this, parameters, pCluster));
			//std::cout << "New Cluster created " << std::endl;
		}
		else{
			PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, PandoraContentApi::AddToCluster(*this, pCluster, pCaloHit));
			//std::cout << "Hit added to cluster " << std::endl;
		}
	}
	if (!pTemporaryList->empty()){
		PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, PandoraContentApi::SaveList<Cluster>(*this, m_outputClusterListName));
		PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, PandoraContentApi::ReplaceCurrentList<Cluster>(*this, m_outputClusterListName));
	}
	
		//MCParticles
	
	const MCParticleList *pMCParticleList(nullptr);
	PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, PandoraContentApi::GetCurrentList(*this, pMCParticleList));
	PandoraMonitoringApi::VisualizeMCParticles(this->GetPandora(), pMCParticleList, "CurrentMCParticles", RED);


	MCParticleVector sortedMCParticles(pMCParticleList->begin(), pMCParticleList->end());
	std::sort(sortedMCParticles.begin(), sortedMCParticles.end(), LArMCParticleHelper::SortByMomentum);
	
	//for (const MCParticle *const pMCParticle : sortedMCParticles){
		//std::cout << "InputMCParticle - PDG: " << pMCParticle->GetParticleId() << ", nParents " << pMCParticle->GetParentList().size()
				  //<< ", nDaughters " << pMCParticle->GetDaughterList().size() << std::endl;
	//}


	PandoraMonitoringApi::ViewEvent(this->GetPandora());


	std::cout << std::endl;

        return STATUS_CODE_SUCCESS;
    }
    
    

    StatusCode MyTestAlgorithm::ReadSettings(const TiXmlHandle xmlHandle){
    	PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, XmlHelper::ReadValue(xmlHandle, "MyMandatoryString", m_myMandatoryString));
	PANDORA_RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, XmlHelper::ReadValue(xmlHandle, "MyOptionalBool", m_myOptionalBool));
	PANDORA_RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, XmlHelper::ReadValue(xmlHandle, "MyOptionalUnsignedInt", m_myOptionalUnsignedInt));
	PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, XmlHelper::ReadVectorOfValues(xmlHandle, "MyMandatoryFloatVector", m_myMandatoryFloatVector));
	
	PANDORA_RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, XmlHelper::ReadValue(xmlHandle, "OutputClusterListName", m_outputClusterListName));
	PANDORA_RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, XmlHelper::ReadValue(xmlHandle, "NHitsPerCluster", m_nHitsPerCluster));
	
	PANDORA_RETURN_RESULT_IF_AND_IF(STATUS_CODE_SUCCESS, STATUS_CODE_NOT_FOUND, !=, XmlHelper::ReadValue(xmlHandle, "InputCaloHitListName", m_inputCaloHitListName));
	
        return STATUS_CODE_SUCCESS;
    }
}   //namespace workshop_content
