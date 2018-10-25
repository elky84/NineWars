#pragma once

namespace ExcelData
{

class DamageType
{
public:
	DamageType()
	{
		memset(&m_Type, 0, sizeof(m_Type));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	int& TypeReference()
	{
		return m_Type;
	}

	int Type() const
	{
		return m_Type;
	}

	void Type(const int& _Type)
	{
		m_Type = _Type;
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
	int m_Type;
	int m_Class;
};

class DamageTypeData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		DamageType Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/DamageType.XML");
		if( false == parser.read_file(L"./XML/DamageType.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/DamageType.XML");
			return false;
		}

		if ( false == parser.execute(L"/DamageTypeList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /DamageTypeList");
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

		if ( false == parser.bind_attrib(L"Type", Instance.TypeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.TypeReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, DamageType>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, DamageType& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, DamageType>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, DamageType> m_Map;
};

__declspec(selectany) DamageTypeData DamageTypeDataInstance;

} // ExcelData

namespace ExcelData
{

class AdDamage
{
public:
	AdDamage()
	{
		memset(&m_Min, 0, sizeof(m_Min));

		memset(&m_Max, 0, sizeof(m_Max));

		memset(&m_Class, 0, sizeof(m_Class));

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
	int m_Min;
	int m_Max;
	int m_Class;
};

class AdDamageData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		AdDamage Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/AdDamage.XML");
		if( false == parser.read_file(L"./XML/AdDamage.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/AdDamage.XML");
			return false;
		}

		if ( false == parser.execute(L"/AdDamageList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /AdDamageList");
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

		while (parser.next())
		{
			m_Map.insert(std::map<int, AdDamage>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, AdDamage& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, AdDamage>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, AdDamage> m_Map;
};

__declspec(selectany) AdDamageData AdDamageDataInstance;

} // ExcelData

namespace ExcelData
{

class ApDamage
{
public:
	ApDamage()
	{
		memset(&m_Min, 0, sizeof(m_Min));

		memset(&m_Max, 0, sizeof(m_Max));

		memset(&m_Class, 0, sizeof(m_Class));

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
	int m_Min;
	int m_Max;
	int m_Class;
};

class ApDamageData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		ApDamage Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/ApDamage.XML");
		if( false == parser.read_file(L"./XML/ApDamage.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/ApDamage.XML");
			return false;
		}

		if ( false == parser.execute(L"/ApDamageList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /ApDamageList");
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

		while (parser.next())
		{
			m_Map.insert(std::map<int, ApDamage>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, ApDamage& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, ApDamage>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, ApDamage> m_Map;
};

__declspec(selectany) ApDamageData ApDamageDataInstance;

} // ExcelData

namespace ExcelData
{

class AdDefense
{
public:
	AdDefense()
	{
		memset(&m_Point, 0, sizeof(m_Point));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	int& PointReference()
	{
		return m_Point;
	}

	int Point() const
	{
		return m_Point;
	}

	void Point(const int& _Point)
	{
		m_Point = _Point;
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
	int m_Point;
	int m_Class;
};

class AdDefenseData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		AdDefense Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/AdDefense.XML");
		if( false == parser.read_file(L"./XML/AdDefense.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/AdDefense.XML");
			return false;
		}

		if ( false == parser.execute(L"/AdDefenseList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /AdDefenseList");
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

		if ( false == parser.bind_attrib(L"Point", Instance.PointReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.PointReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, AdDefense>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, AdDefense& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, AdDefense>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, AdDefense> m_Map;
};

__declspec(selectany) AdDefenseData AdDefenseDataInstance;

} // ExcelData

namespace ExcelData
{

class ApDefense
{
public:
	ApDefense()
	{
		memset(&m_Point, 0, sizeof(m_Point));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	int& PointReference()
	{
		return m_Point;
	}

	int Point() const
	{
		return m_Point;
	}

	void Point(const int& _Point)
	{
		m_Point = _Point;
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
	int m_Point;
	int m_Class;
};

class ApDefenseData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		ApDefense Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/ApDefense.XML");
		if( false == parser.read_file(L"./XML/ApDefense.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/ApDefense.XML");
			return false;
		}

		if ( false == parser.execute(L"/ApDefenseList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /ApDefenseList");
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

		if ( false == parser.bind_attrib(L"Point", Instance.PointReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.PointReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, ApDefense>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, ApDefense& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, ApDefense>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, ApDefense> m_Map;
};

__declspec(selectany) ApDefenseData ApDefenseDataInstance;

} // ExcelData

namespace ExcelData
{

class AdReduce
{
public:
	AdReduce()
	{
		memset(&m_Reduce, 0, sizeof(m_Reduce));

		memset(&m_AdDefense, 0, sizeof(m_AdDefense));

	}

	float& ReduceReference()
	{
		return m_Reduce;
	}

	float Reduce() const
	{
		return m_Reduce;
	}

	void Reduce(const float& _Reduce)
	{
		m_Reduce = _Reduce;
	}

	int& AdDefenseReference()
	{
		return m_AdDefense;
	}

	int AdDefense() const
	{
		return m_AdDefense;
	}

	void AdDefense(const int& _AdDefense)
	{
		m_AdDefense = _AdDefense;
	}

private:
	float m_Reduce;
	int m_AdDefense;
};

class AdReduceData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		AdReduce Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/AdReduce.XML");
		if( false == parser.read_file(L"./XML/AdReduce.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/AdReduce.XML");
			return false;
		}

		if ( false == parser.execute(L"/AdReduceList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /AdReduceList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"AdDefense", Instance.AdDefenseReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.AdDefenseReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Reduce", Instance.ReduceReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ReduceReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, AdReduce>::value_type(Instance.AdDefense(), Instance));
		}

		return true;
	}

	bool Get(int& key, AdReduce& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, AdReduce>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, AdReduce> m_Map;
};

__declspec(selectany) AdReduceData AdReduceDataInstance;

} // ExcelData

namespace ExcelData
{

class ApReduce
{
public:
	ApReduce()
	{
		memset(&m_Reduce, 0, sizeof(m_Reduce));

		memset(&m_ApDefense, 0, sizeof(m_ApDefense));

	}

	float& ReduceReference()
	{
		return m_Reduce;
	}

	float Reduce() const
	{
		return m_Reduce;
	}

	void Reduce(const float& _Reduce)
	{
		m_Reduce = _Reduce;
	}

	int& ApDefenseReference()
	{
		return m_ApDefense;
	}

	int ApDefense() const
	{
		return m_ApDefense;
	}

	void ApDefense(const int& _ApDefense)
	{
		m_ApDefense = _ApDefense;
	}

private:
	float m_Reduce;
	int m_ApDefense;
};

class ApReduceData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		ApReduce Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/ApReduce.XML");
		if( false == parser.read_file(L"./XML/ApReduce.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/ApReduce.XML");
			return false;
		}

		if ( false == parser.execute(L"/ApReduceList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /ApReduceList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"ApDefense", Instance.ApDefenseReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ApDefenseReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Reduce", Instance.ReduceReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ReduceReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, ApReduce>::value_type(Instance.ApDefense(), Instance));
		}

		return true;
	}

	bool Get(int& key, ApReduce& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, ApReduce>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, ApReduce> m_Map;
};

__declspec(selectany) ApReduceData ApReduceDataInstance;

} // ExcelData

namespace ExcelData
{

class Turn
{
public:
	Turn()
	{
		memset(&m_Point, 0, sizeof(m_Point));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	float& PointReference()
	{
		return m_Point;
	}

	float Point() const
	{
		return m_Point;
	}

	void Point(const float& _Point)
	{
		m_Point = _Point;
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
	float m_Point;
	int m_Class;
};

class TurnData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Turn Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Turn.XML");
		if( false == parser.read_file(L"./XML/Turn.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/Turn.XML");
			return false;
		}

		if ( false == parser.execute(L"/TurnList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /TurnList");
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

		if ( false == parser.bind_attrib(L"Point", Instance.PointReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.PointReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Turn>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, Turn& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Turn>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Turn> m_Map;
};

__declspec(selectany) TurnData TurnDataInstance;

} // ExcelData

namespace ExcelData
{

class WeightGauge
{
public:
	WeightGauge()
	{
		memset(&m_Point, 0, sizeof(m_Point));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	float& PointReference()
	{
		return m_Point;
	}

	float Point() const
	{
		return m_Point;
	}

	void Point(const float& _Point)
	{
		m_Point = _Point;
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
	float m_Point;
	int m_Class;
};

class WeightGaugeData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		WeightGauge Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/WeightGauge.XML");
		if( false == parser.read_file(L"./XML/WeightGauge.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/WeightGauge.XML");
			return false;
		}

		if ( false == parser.execute(L"/WeightGaugeList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /WeightGaugeList");
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

		if ( false == parser.bind_attrib(L"Point", Instance.PointReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.PointReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, WeightGauge>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, WeightGauge& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, WeightGauge>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, WeightGauge> m_Map;
};

__declspec(selectany) WeightGaugeData WeightGaugeDataInstance;

} // ExcelData

namespace ExcelData
{

class HP
{
public:
	HP()
	{
		memset(&m_Point, 0, sizeof(m_Point));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	int& PointReference()
	{
		return m_Point;
	}

	int Point() const
	{
		return m_Point;
	}

	void Point(const int& _Point)
	{
		m_Point = _Point;
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
	int m_Point;
	int m_Class;
};

class HPData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		HP Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/HP.XML");
		if( false == parser.read_file(L"./XML/HP.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/HP.XML");
			return false;
		}

		if ( false == parser.execute(L"/HPList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /HPList");
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

		if ( false == parser.bind_attrib(L"Point", Instance.PointReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.PointReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, HP>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, HP& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, HP>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, HP> m_Map;
};

__declspec(selectany) HPData HPDataInstance;

} // ExcelData

namespace ExcelData
{

class MP
{
public:
	MP()
	{
		memset(&m_Point, 0, sizeof(m_Point));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	float& PointReference()
	{
		return m_Point;
	}

	float Point() const
	{
		return m_Point;
	}

	void Point(const float& _Point)
	{
		m_Point = _Point;
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
	float m_Point;
	int m_Class;
};

class MPData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		MP Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/MP.XML");
		if( false == parser.read_file(L"./XML/MP.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/MP.XML");
			return false;
		}

		if ( false == parser.execute(L"/MPList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /MPList");
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

		if ( false == parser.bind_attrib(L"Point", Instance.PointReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.PointReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, MP>::value_type(Instance.Class(), Instance));
		}

		return true;
	}

	bool Get(int& key, MP& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, MP>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, MP> m_Map;
};

__declspec(selectany) MPData MPDataInstance;

} // ExcelData

