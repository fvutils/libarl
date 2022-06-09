/*
 * ModelActivitySequence.h
 *
 *  Created on: Jun 5, 2022
 *      Author: mballance
 */

#pragma once
#include "arl/IModelActivitySequence.h"

namespace arl {

class ModelActivitySequence : public IModelActivitySequence {
public:
	ModelActivitySequence();

	virtual ~ModelActivitySequence();

	virtual const std::vector<IModelActivityUP> &getActivities() const override {
		return m_activities;
	}

	virtual void addActivity(IModelActivity *a) override {
		m_activities.push_back(IModelActivityUP(a));
	}

	virtual void accept(vsc::IVisitor *v) override;

private:
	std::vector<IModelActivityUP>			m_activities;
};

} /* namespace arl */

