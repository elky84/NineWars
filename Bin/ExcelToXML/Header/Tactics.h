#pragma once

namespace ExcelData
{

class Tactics
{
public:
	Tactics()
	{
		m_Multiply.resize(5);

		m_Stat.resize(5);

		memset(&m_Index, 0, sizeof(m_Index));

	}

	int& Stat4Reference()
	{
		return m_Stat[4];
	}

	std::vector<int>& VectorStat()
	{
		return m_Stat;
	}

	int& Stat3Reference()
	{
		return m_Stat[3];
	}

	int& Stat2Reference()
	{
		return m_Stat[2];
	}

	int& Stat1Reference()
	{
		return m_Stat[1];
	}

	int& Stat0Reference()
	{
		return m_Stat[0];
	}

	std::wstring& NameReference()
	{
		return m_Name;
	}

	std::wstring Name() const
	{
		return m_Name;
	}

	void Name(const std::wstring& _Name)
	{
		m_Name = _Name;
	}

	int& Multiply4Reference()
	{
		return m_Multiply[4];
	}

	std::vector<int>& VectorMultiply()
	{
		return m_Multiply;
	}

	int& Multiply3Reference()
	{
		return m_Multiply[3];
	}

	int& Multiply2Reference()
	{
		return m_Multiply[2];
	}

	int& Multiply1Reference()
	{
		return m_Multiply[1];
	}

	int& Multiply0Reference()
	{
		return m_Multiply[0];
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

private:
	std::vector<int> m_Stat;
	std::wstring m_Name;
	std::vector<int> m_Multiply;
	int m_Index;
};

class TacticsData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Tactics Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Tactics.XML");
		if( false == parser.read_file(L"./XML/Tactics.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/Tactics.XML");
			return false;
		}

		if ( false == parser.execute(L"/TacticsList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /TacticsList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Multiply0", Instance.Multiply0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Multiply0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Multiply1", Instance.Multiply1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Multiply1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Multiply2", Instance.Multiply2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Multiply2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Multiply3", Instance.Multiply3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Multiply3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Multiply4", Instance.Multiply4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Multiply4Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Stat0", Instance.Stat0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Stat0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Stat1", Instance.Stat1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Stat1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Stat2", Instance.Stat2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Stat2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Stat3", Instance.Stat3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Stat3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Stat4", Instance.Stat4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Stat4Reference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Tactics>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, Tactics& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Tactics>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Tactics> m_Map;
};

__declspec(selectany) TacticsData TacticsDataInstance;

} // ExcelData

namespace ExcelData
{

class TacticsString
{
public:
	TacticsString()
	{
		m_Point.resize(5);

		m_String.resize(5);

		memset(&m_Index, 0, sizeof(m_Index));

	}

	std::wstring& String4Reference()
	{
		return m_String[4];
	}

	std::vector<std::wstring>& VectorString()
	{
		return m_String;
	}

	std::wstring& String3Reference()
	{
		return m_String[3];
	}

	std::wstring& String2Reference()
	{
		return m_String[2];
	}

	std::wstring& String1Reference()
	{
		return m_String[1];
	}

	std::wstring& String0Reference()
	{
		return m_String[0];
	}

	int& Point4Reference()
	{
		return m_Point[4];
	}

	std::vector<int>& VectorPoint()
	{
		return m_Point;
	}

	int& Point3Reference()
	{
		return m_Point[3];
	}

	int& Point2Reference()
	{
		return m_Point[2];
	}

	int& Point1Reference()
	{
		return m_Point[1];
	}

	int& Point0Reference()
	{
		return m_Point[0];
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

private:
	std::vector<std::wstring> m_String;
	std::vector<int> m_Point;
	int m_Index;
};

class TacticsStringData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		TacticsString Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/TacticsString.XML");
		if( false == parser.read_file(L"./XML/TacticsString.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/TacticsString.XML");
			return false;
		}

		if ( false == parser.execute(L"/TacticsStringList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /TacticsStringList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Point0", Instance.Point0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Point0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Point1", Instance.Point1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Point1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Point2", Instance.Point2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Point2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Point3", Instance.Point3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Point3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Point4", Instance.Point4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Point4Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"String0", Instance.String0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.String0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"String1", Instance.String1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.String1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"String2", Instance.String2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.String2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"String3", Instance.String3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.String3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"String4", Instance.String4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.String4Reference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, TacticsString>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, TacticsString& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, TacticsString>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, TacticsString> m_Map;
};

__declspec(selectany) TacticsStringData TacticsStringDataInstance;

} // ExcelData

