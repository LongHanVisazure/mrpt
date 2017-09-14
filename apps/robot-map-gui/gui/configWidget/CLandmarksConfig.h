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
#include "CBaseConfig.h"

#include <memory>

#include <mrpt/maps/CLandmarksMap.h>

namespace Ui
{
class CLandmarksConfig;
}
class CLandmarksConfig : public CBaseConfig
{
   public:
	CLandmarksConfig();
	virtual ~CLandmarksConfig() = default;

	virtual const QString getName() override;
	virtual void updateConfiguration(
		mrpt::maps::TMetricMapInitializer* options) override;
	virtual TypeOfConfig type() const override;

	void setInsertOpt(
		const mrpt::maps::CLandmarksMap::TInsertionOptions& insertOpt =
			mrpt::maps::CLandmarksMap::TInsertionOptions());
	void setLikelihoodOpt(
		const mrpt::maps::CLandmarksMap::TLikelihoodOptions& likelihoodOpt =
			mrpt::maps::CLandmarksMap::TLikelihoodOptions());

   private:
	std::unique_ptr<Ui::CLandmarksConfig> m_ui;
};
