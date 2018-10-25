#pragma once

namespace ExcelData
{

class MoveDecide
{
public:
	MoveDecide()
	{
		memset(&m_MaintainSpeed, 0, sizeof(m_MaintainSpeed));

		memset(&m_MaintainRange, 0, sizeof(m_MaintainRange));

		memset(&m_ControlSpeed, 0, sizeof(m_ControlSpeed));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	int& MaintainSpeedReference()
	{
		return m_MaintainSpeed;
	}

	int MaintainSpeed() const
	{
		return m_MaintainSpeed;
	}

	void MaintainSpeed(const int& _MaintainSpeed)
	{
		m_MaintainSpeed = _MaintainSpeed;
	}

	float& MaintainRangeReference()
	{
		return m_MaintainRange;
	}

	float MaintainRange() const
	{
		return m_MaintainRange;
	}

	void MaintainRange(const float& _MaintainRange)
	{
		m_MaintainRange = _MaintainRange;
	}

	float& ControlSpeedReference()
	{
		return m_ControlSpeed;
	}

	float ControlSpeed() const
	{
		return m_ControlSpeed;
	}

	void ControlSpeed(const float& _ControlSpeed)
	{
		m_ControlSpeed = _ControlSpeed;
	}

	int& ClassReference()
	{
		return m_Class;
	}

	int Class() const
	{
		return m_Class;
	}

	void Class(const int& _Class)
	{
		m_Class = _Class;
	}

private:
	int m_MaintainSpeed;
	float m_MaintainRange;
	float m_ControlSpeed;
	int m_Class;
};

class MoveDecideData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		MoveDecide Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/MoveDecide.XML");
		if( false == parser.read_file(L"./XML/MoveDecide.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/MoveDecide.XML");
			return false;
		}

		if ( false == parser.execute(L"/MoveDecideList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /MoveDecideList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Class", Instance.ClassReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ClassReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"ControlSpeed", Instance.ControlSpeedReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ControlSpeedReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"MaintainRange", Instance.MaintainRangeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.MaintainRangeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"MaintainSpeed", Instance.MaintainSpeedReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.MaintainSpeedReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, MoveDecide>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, MoveDecide& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, MoveDecide>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, MoveDecide> m_Map;
};

__declspec(selectany) MoveDecideData MoveDecideDataInstance;

} // ExcelData

namespace ExcelData
{

class TargetingDecide
{
public:
	TargetingDecide()
	{
		memset(&m_StrongClass, 0, sizeof(m_StrongClass));

		memset(&m_NearDistance, 0, sizeof(m_NearDistance));

		memset(&m_LessHP, 0, sizeof(m_LessHP));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	float& StrongClassReference()
	{
		return m_StrongClass;
	}

	float StrongClass() const
	{
		return m_StrongClass;
	}

	void StrongClass(const float& _StrongClass)
	{
		m_StrongClass = _StrongClass;
	}

	float& NearDistanceReference()
	{
		return m_NearDistance;
	}

	float NearDistance() const
	{
		return m_NearDistance;
	}

	void NearDistance(const float& _NearDistance)
	{
		m_NearDistance = _NearDistance;
	}

	float& LessHPReference()
	{
		return m_LessHP;
	}

	float LessHP() const
	{
		return m_LessHP;
	}

	void LessHP(const float& _LessHP)
	{
		m_LessHP = _LessHP;
	}

	int& ClassReference()
	{
		return m_Class;
	}

	int Class() const
	{
		return m_Class;
	}

	void Class(const int& _Class)
	{
		m_Class = _Class;
	}

private:
	float m_StrongClass;
	float m_NearDistance;
	float m_LessHP;
	int m_Class;
};

class TargetingDecideData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		TargetingDecide Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/TargetingDecide.XML");
		if( false == parser.read_file(L"./XML/TargetingDecide.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/TargetingDecide.XML");
			return false;
		}

		if ( false == parser.execute(L"/TargetingDecideList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /TargetingDecideList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Class", Instance.ClassReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ClassReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"LessHP", Instance.LessHPReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LessHPReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"NearDistance", Instance.NearDistanceReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NearDistanceReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"StrongClass", Instance.StrongClassReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.StrongClassReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, TargetingDecide>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, TargetingDecide& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, TargetingDecide>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, TargetingDecide> m_Map;
};

__declspec(selectany) TargetingDecideData TargetingDecideDataInstance;

} // ExcelData

namespace ExcelData
{

class MaintainSpeed
{
public:
	MaintainSpeed()
	{
		memset(&m_WarSituation, 0, sizeof(m_WarSituation));

		memset(&m_MoveTendency, 0, sizeof(m_MoveTendency));

		memset(&m_Min, 0, sizeof(m_Min));

		memset(&m_Max, 0, sizeof(m_Max));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_CurrentState, 0, sizeof(m_CurrentState));

	}

	float& WarSituationReference()
	{
		return m_WarSituation;
	}

	float WarSituation() const
	{
		return m_WarSituation;
	}

	void WarSituation(const float& _WarSituation)
	{
		m_WarSituation = _WarSituation;
	}

	float& MoveTendencyReference()
	{
		return m_MoveTendency;
	}

	float MoveTendency() const
	{
		return m_MoveTendency;
	}

	void MoveTendency(const float& _MoveTendency)
	{
		m_MoveTendency = _MoveTendency;
	}

	int& MinReference()
	{
		return m_Min;
	}

	int Min() const
	{
		return m_Min;
	}

	void Min(const int& _Min)
	{
		m_Min = _Min;
	}

	int& MaxReference()
	{
		return m_Max;
	}

	int Max() const
	{
		return m_Max;
	}

	void Max(const int& _Max)
	{
		m_Max = _Max;
	}

	int& IndexReference()
	{
		return m_Index;
	}

	int Index() const
	{
		return m_Index;
	}

	void Index(const int& _Index)
	{
		m_Index = _Index;
	}

	float& CurrentStateReference()
	{
		return m_CurrentState;
	}

	float CurrentState() const
	{
		return m_CurrentState;
	}

	void CurrentState(const float& _CurrentState)
	{
		m_CurrentState = _CurrentState;
	}

private:
	float m_WarSituation;
	float m_MoveTendency;
	int m_Min;
	int m_Max;
	int m_Index;
	float m_CurrentState;
};

class MaintainSpeedData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		MaintainSpeed Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/MaintainSpeed.XML");
		if( false == parser.read_file(L"./XML/MaintainSpeed.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/MaintainSpeed.XML");
			return false;
		}

		if ( false == parser.execute(L"/MaintainSpeedList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /MaintainSpeedList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"CurrentState", Instance.CurrentStateReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CurrentStateReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Max", Instance.MaxReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.MaxReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Min", Instance.MinReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.MinReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"MoveTendency", Instance.MoveTendencyReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.MoveTendencyReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"WarSituation", Instance.WarSituationReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.WarSituationReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, MaintainSpeed>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, MaintainSpeed& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, MaintainSpeed>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, MaintainSpeed> m_Map;
};

__declspec(selectany) MaintainSpeedData MaintainSpeedDataInstance;

} // ExcelData

namespace ExcelData
{

class PowerDecide
{
public:
	PowerDecide()
	{
		memset(&m_MR, 0, sizeof(m_MR));

		memset(&m_Class, 0, sizeof(m_Class));

		memset(&m_AP, 0, sizeof(m_AP));

		memset(&m_AD, 0, sizeof(m_AD));

		memset(&m_AC, 0, sizeof(m_AC));

	}

	int& MRReference()
	{
		return m_MR;
	}

	int MR() const
	{
		return m_MR;
	}

	void MR(const int& _MR)
	{
		m_MR = _MR;
	}

	int& ClassReference()
	{
		return m_Class;
	}

	int Class() const
	{
		return m_Class;
	}

	void Class(const int& _Class)
	{
		m_Class = _Class;
	}

	int& APReference()
	{
		return m_AP;
	}

	int AP() const
	{
		return m_AP;
	}

	void AP(const int& _AP)
	{
		m_AP = _AP;
	}

	int& ADReference()
	{
		return m_AD;
	}

	int AD() const
	{
		return m_AD;
	}

	void AD(const int& _AD)
	{
		m_AD = _AD;
	}

	int& ACReference()
	{
		return m_AC;
	}

	int AC() const
	{
		return m_AC;
	}

	void AC(const int& _AC)
	{
		m_AC = _AC;
	}

private:
	int m_MR;
	int m_Class;
	int m_AP;
	int m_AD;
	int m_AC;
};

class PowerDecideData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		PowerDecide Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/PowerDecide.XML");
		if( false == parser.read_file(L"./XML/PowerDecide.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/PowerDecide.XML");
			return false;
		}

		if ( false == parser.execute(L"/PowerDecideList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /PowerDecideList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"AC", Instance.ACReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ACReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"AD", Instance.ADReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ADReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"AP", Instance.APReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.APReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Class", Instance.ClassReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ClassReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"MR", Instance.MRReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.MRReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, PowerDecide>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, PowerDecide& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, PowerDecide>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, PowerDecide> m_Map;
};

__declspec(selectany) PowerDecideData PowerDecideDataInstance;

} // ExcelData

