/*
 * ModelActivitySchedule.cpp
 *
 *  Created on: Jun 6, 2022
 *      Author: mballance
 */

#include "arl/IVisitor.h"
#include "ModelActivitySchedule.h"

namespace arl {

ModelActivitySchedule::ModelActivitySchedule(
		const std::string		&name,
		IDataTypeActivity		*type) : m_name(name), m_type(type) {
	// TODO Auto-generated constructor stub

}

ModelActivitySchedule::~ModelActivitySchedule() {
	// TODO Auto-generated destructor stub
}

void ModelActivitySchedule::accept(vsc::IVisitor *v) {
	if (dynamic_cast<arl::IVisitor *>(v)) {
		dynamic_cast<arl::IVisitor *>(v)->visitModelActivitySchedule(this);
	}
}

} /* namespace arl */
