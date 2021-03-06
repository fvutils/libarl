/*
 * IsModelActivitySequence.h
 *
 *  Created on: Jun 17, 2022
 *      Author: mballance
 */

#pragma once
#include "arl/impl/VisitorBase.h"

namespace arl {

class IsModelActivitySequence : public VisitorBase {
public:
	IsModelActivitySequence();

	virtual ~IsModelActivitySequence();

	bool test(IModelActivity *a);

	virtual void visitModelActivityParallel(IModelActivityParallel *a) override { }

	virtual void visitModelActivitySchedule(IModelActivitySchedule *a) override { }

	virtual void visitModelActivitySequence(IModelActivitySequence *a) override {
		m_is = true;
	}

	virtual void visitModelActivityTraverse(IModelActivityTraverse *a) override { }


private:
	bool						m_is;
};

} /* namespace arl */

