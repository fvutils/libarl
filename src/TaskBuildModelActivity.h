/*
 * TaskBuildModelActivity.h
 *
 *  Created on: Jun 8, 2022
 *      Author: mballance
 */

#pragma once
#include <vector>
#include "arl/impl/VisitorBase.h"
#include "arl/IModelActivity.h"
#include "arl/IDataTypeActivity.h"
#include "vsc/IModelField.h"

namespace arl {

class TaskBuildModelActivity : public VisitorBase {
public:
	TaskBuildModelActivity();

	virtual ~TaskBuildModelActivity();

	IModelActivity *build(
			vsc::IModelField	*parent_ctxt,
			IDataTypeActivity	*activity);

	virtual void visitDataTypeActivitySchedule(IDataTypeActivitySchedule *t) override;

	virtual void visitDataTypeActivitySequence(IDataTypeActivitySequence *t) override;

	virtual void visitDataTypeActivityTraverse(IDataTypeActivityTraverse *t) override;

private:
	std::vector<vsc::IModelField *>		m_ctxt_s;


};

} /* namespace arl */

