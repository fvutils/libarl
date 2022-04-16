/*
 * DataTypeStruct.h
 *
 *  Created on: Apr 16, 2022
 *      Author: mballance
 */

#pragma once
#include <string>
#include <vector>
#include "vsc/ITypeField.h"
#include "vsc/ITypeConstraint.h"

namespace arl {

class DataTypeStruct {
public:
	DataTypeStruct(const std::string &name);

	virtual ~DataTypeStruct();

	virtual const std::string &name() const {
		return m_name;
	}

	virtual void addField(vsc::ITypeField *f);

	virtual const std::vector<vsc::ITypeFieldUP> &getFields() const;

	virtual vsc::ITypeField *getField(int32_t idx);

	virtual void addConstraint(vsc::ITypeConstraint *c);

	virtual const std::vector<vsc::ITypeConstraintUP> &getConstraints() const;

public:
	std::string								m_name;
	std::vector<vsc::ITypeFieldUP>		 	m_fields;
	std::vector<vsc::ITypeConstraintUP>		m_constraints;


};

} /* namespace arl */

