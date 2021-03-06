/*
 * DataTypeActivityScope.h
 *
 *  Created on: Jun 4, 2022
 *      Author: mballance
 */

#pragma once
#include "arl/IDataTypeActivityScope.h"

namespace arl {

class DataTypeActivityScope : public virtual IDataTypeActivityScope {
public:
	DataTypeActivityScope(const std::string &name);

	virtual ~DataTypeActivityScope();

	virtual const std::string &name() const override { return m_name; }

	virtual void addField(vsc::ITypeField *f) override;

	virtual const std::vector<vsc::ITypeFieldUP> &getFields() const override {
		return m_fields;
	}

	virtual vsc::ITypeField *getField(int32_t idx) override {
		return m_fields.at(idx).get();
	}

	virtual void addConstraint(vsc::ITypeConstraint *c) override;

	virtual const std::vector<vsc::ITypeConstraintUP> &getConstraints() const override {
		return m_constraints;
	}

	virtual vsc::IModelStructCreateHook *getCreateHook() const override {
		return m_create_hook.get();
	}

	virtual void setCreateHook(vsc::IModelStructCreateHook *hook) override {
		m_create_hook = vsc::IModelStructCreateHookUP(hook);
	}

	virtual const std::vector<ITypeFieldActivityUP> &getActivities() const override {
		return m_activities;
	}

	virtual void addActivity(ITypeFieldActivity *a) override;

private:
	std::string									m_name;
	std::vector<vsc::ITypeFieldUP>				m_fields;
	std::vector<vsc::ITypeConstraintUP>			m_constraints;
	vsc::IModelStructCreateHookUP				m_create_hook;

	std::vector<ITypeFieldActivityUP>			m_activities;

};

} /* namespace arl */

