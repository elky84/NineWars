#pragma once

#include "EnvironmentManager.h"

#include "Direct2D.h"

class Main : public light::EnvironmentManager
{
public:
	Main(const std::wstring& strProgramName, const std::wstring& strArg);
	~Main();

private:
	virtual bool initialize();

	virtual void on_update();

	virtual void release();

private:
	light::view::Direct2D m_direct_x;

	std::wstring m_strArg;
};
