/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+
   */
#pragma once
#include "CNode.h"

#include <string>

#include "mrpt/maps/CSimpleMap.h"

class CObservationsNode;
class CPosesNode;

class CPairNode : public CNode
{
   public:
	CPairNode(
		CNode* parent,
		const mrpt::maps::CSimpleMap::TPosePDFSensFramePair& poseSensFramePair);
	virtual ~CPairNode();

	int childCount() const;

	CNode* child(int id);
	CNode* child(int id) const;
	ObjectType type() const override;
	std::string displayName() const override;

   private:
	CNode* getChild(int id) const;

	std::unique_ptr<CPosesNode> m_pose;
	std::unique_ptr<CObservationsNode> m_observations;
};
