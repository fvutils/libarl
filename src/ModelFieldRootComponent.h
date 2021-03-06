/*
 * ModelFieldRootComponent.h
 *
 *  Created on: May 17, 2022
 *      Author: mballance
 */

#pragma once
#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "arl/IContext.h"
#include "arl/IModelFieldRootComponent.h"
#include "vsc/IModelField.h"
#include "vsc/IModelVal.h"
#include "ComponentMap.h"

namespace arl {

class ModelFieldRootComponent : public IModelFieldRootComponent {
public:
	ModelFieldRootComponent(
			arl::IContext			*ctxt,
			const std::string 		&name,
			vsc::IDataType			*type);

	virtual ~ModelFieldRootComponent();

	void initCompTree();

	virtual const std::string &name() const override {
		return m_name;
	}

	virtual vsc::IDataType *getDataType() const override {
		return m_type;
	}

	virtual vsc::IModelField *getParent() const override {
		return m_parent;
	}

	virtual void setParent(vsc::IModelField *p) override {
		m_parent = p;
	}

	virtual const std::vector<vsc::IModelConstraintUP> &constraints() const override {
		return m_constraints;
	}

	virtual void addConstraint(vsc::IModelConstraint *c) override;

	virtual const std::vector<vsc::IModelFieldUP> &fields() const override {
		return m_fields;
	}

	virtual void addField(vsc::IModelField *field) override;

	virtual vsc::IModelField *getField(int32_t idx) override {
		return m_fields.at(idx).get();
	}

	virtual const vsc::IModelVal *val() const override {
		return m_val.get();
	}

	virtual vsc::IModelVal *val() override {
		return m_val.get();
	}

	virtual vsc::ModelFieldFlag flags() const override {
		return m_flags;
	}

	virtual void clearFlag(vsc::ModelFieldFlag flags) override {
		m_flags = (m_flags & (~flags));
	}

	virtual void setFlag(vsc::ModelFieldFlag flags) override {
		m_flags = (m_flags | flags);
	}

	virtual bool isFlagSet(vsc::ModelFieldFlag flags) const override {
		return ((m_flags & flags) == flags);
	}

	virtual void setFieldData(vsc::IModelFieldData *data) override {
		m_data = vsc::IModelFieldDataUP(data);
	}

	virtual vsc::IModelFieldData *getFieldData() override {
		return m_data.get();
	}

	virtual void accept(vsc::IVisitor *v) override;

private:
	IContext								*m_ctxt;
	std::string								m_name;
	vsc::IDataType							*m_type;
	vsc::IModelField						*m_parent;
	vsc::IModelFieldDataUP					m_data;
	vsc::IModelValUP						m_val;

	std::vector<vsc::IModelFieldUP>								m_fields;
	std::vector<vsc::IModelConstraintUP>						m_constraints;
	vsc::ModelFieldFlag											m_flags;
	ComponentMapUP							m_comp_map;


};

} /* namespace arl */

