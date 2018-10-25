#pragma once

namespace ExcelData
{

class Skill
{
public:
	Skill()
	{
		m_Effect.resize(5);

		memset(&m_Target, 0, sizeof(m_Target));

		memset(&m_Scale, 0, sizeof(m_Scale));

		memset(&m_RangeAdd, 0, sizeof(m_RangeAdd));

		memset(&m_Range, 0, sizeof(m_Range));

		memset(&m_Location, 0, sizeof(m_Location));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Increase, 0, sizeof(m_Increase));

		memset(&m_HoldTime, 0, sizeof(m_HoldTime));

		memset(&m_Delay, 0, sizeof(m_Delay));

		memset(&m_Crash, 0, sizeof(m_Crash));

		memset(&m_CoolTime, 0, sizeof(m_CoolTime));

		memset(&m_Condition, 0, sizeof(m_Condition));

		memset(&m_CastingTime, 0, sizeof(m_CastingTime));

		memset(&m_BasicChance, 0, sizeof(m_BasicChance));

	}

	int& TargetReference()
	{
		return m_Target;
	}

	int Target() const
	{
		return m_Target;
	}

	void Target(const int& _Target)
	{
		m_Target = _Target;
	}

	float& ScaleReference()
	{
		return m_Scale;
	}

	float Scale() const
	{
		return m_Scale;
	}

	void Scale(const float& _Scale)
	{
		m_Scale = _Scale;
	}

	float& RangeAddReference()
	{
		return m_RangeAdd;
	}

	float RangeAdd() const
	{
		return m_RangeAdd;
	}

	void RangeAdd(const float& _RangeAdd)
	{
		m_RangeAdd = _RangeAdd;
	}

	int& RangeReference()
	{
		return m_Range;
	}

	int Range() const
	{
		return m_Range;
	}

	void Range(const int& _Range)
	{
		m_Range = _Range;
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

	int& LocationReference()
	{
		return m_Location;
	}

	int Location() const
	{
		return m_Location;
	}

	void Location(const int& _Location)
	{
		m_Location = _Location;
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

	int& IncreaseReference()
	{
		return m_Increase;
	}

	int Increase() const
	{
		return m_Increase;
	}

	void Increase(const int& _Increase)
	{
		m_Increase = _Increase;
	}

	int& HoldTimeReference()
	{
		return m_HoldTime;
	}

	int HoldTime() const
	{
		return m_HoldTime;
	}

	void HoldTime(const int& _HoldTime)
	{
		m_HoldTime = _HoldTime;
	}

	std::wstring& EffectFileReference()
	{
		return m_EffectFile;
	}

	std::wstring EffectFile() const
	{
		return m_EffectFile;
	}

	void EffectFile(const std::wstring& _EffectFile)
	{
		m_EffectFile = _EffectFile;
	}

	int& Effect4Reference()
	{
		return m_Effect[4];
	}

	std::vector<int>& VectorEffect()
	{
		return m_Effect;
	}

	int& Effect3Reference()
	{
		return m_Effect[3];
	}

	int& Effect2Reference()
	{
		return m_Effect[2];
	}

	int& Effect1Reference()
	{
		return m_Effect[1];
	}

	int& Effect0Reference()
	{
		return m_Effect[0];
	}

	std::wstring& DescriptionReference()
	{
		return m_Description;
	}

	std::wstring Description() const
	{
		return m_Description;
	}

	void Description(const std::wstring& _Description)
	{
		m_Description = _Description;
	}

	int& DelayReference()
	{
		return m_Delay;
	}

	int Delay() const
	{
		return m_Delay;
	}

	void Delay(const int& _Delay)
	{
		m_Delay = _Delay;
	}

	int& CrashReference()
	{
		return m_Crash;
	}

	int Crash() const
	{
		return m_Crash;
	}

	void Crash(const int& _Crash)
	{
		m_Crash = _Crash;
	}

	int& CoolTimeReference()
	{
		return m_CoolTime;
	}

	int CoolTime() const
	{
		return m_CoolTime;
	}

	void CoolTime(const int& _CoolTime)
	{
		m_CoolTime = _CoolTime;
	}

	int& ConditionReference()
	{
		return m_Condition;
	}

	int Condition() const
	{
		return m_Condition;
	}

	void Condition(const int& _Condition)
	{
		m_Condition = _Condition;
	}

	int& CastingTimeReference()
	{
		return m_CastingTime;
	}

	int CastingTime() const
	{
		return m_CastingTime;
	}

	void CastingTime(const int& _CastingTime)
	{
		m_CastingTime = _CastingTime;
	}

	int& BasicChanceReference()
	{
		return m_BasicChance;
	}

	int BasicChance() const
	{
		return m_BasicChance;
	}

	void BasicChance(const int& _BasicChance)
	{
		m_BasicChance = _BasicChance;
	}

private:
	int m_Target;
	float m_Scale;
	float m_RangeAdd;
	int m_Range;
	std::wstring m_Name;
	int m_Location;
	int m_Index;
	int m_Increase;
	int m_HoldTime;
	std::wstring m_EffectFile;
	std::vector<int> m_Effect;
	std::wstring m_Description;
	int m_Delay;
	int m_Crash;
	int m_CoolTime;
	int m_Condition;
	int m_CastingTime;
	int m_BasicChance;
};

class SkillData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Skill Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Skill.XML");
		if( false == parser.read_file(L"./XML/Skill.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/Skill.XML");
			return false;
		}

		if ( false == parser.execute(L"/SkillList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /SkillList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"BasicChance", Instance.BasicChanceReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.BasicChanceReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"CastingTime", Instance.CastingTimeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CastingTimeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Condition", Instance.ConditionReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ConditionReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"CoolTime", Instance.CoolTimeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CoolTimeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Crash", Instance.CrashReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CrashReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Delay", Instance.DelayReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.DelayReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Description", Instance.DescriptionReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.DescriptionReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Effect0", Instance.Effect0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Effect0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Effect1", Instance.Effect1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Effect1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Effect2", Instance.Effect2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Effect2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Effect3", Instance.Effect3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Effect3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Effect4", Instance.Effect4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Effect4Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"EffectFile", Instance.EffectFileReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.EffectFileReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"HoldTime", Instance.HoldTimeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.HoldTimeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Increase", Instance.IncreaseReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IncreaseReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Location", Instance.LocationReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.LocationReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Range", Instance.RangeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RangeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"RangeAdd", Instance.RangeAddReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RangeAddReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Scale", Instance.ScaleReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ScaleReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Target", Instance.TargetReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.TargetReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Skill>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, Skill& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Skill>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Skill> m_Map;
};

__declspec(selectany) SkillData SkillDataInstance;

} // ExcelData

namespace ExcelData
{

class SkillEffect
{
public:
	SkillEffect()
	{
		m_EffectValue.resize(3);

		memset(&m_Probability, 0, sizeof(m_Probability));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_EffectType, 0, sizeof(m_EffectType));

	}

	int& ProbabilityReference()
	{
		return m_Probability;
	}

	int Probability() const
	{
		return m_Probability;
	}

	void Probability(const int& _Probability)
	{
		m_Probability = _Probability;
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

	float& EffectValue2Reference()
	{
		return m_EffectValue[2];
	}

	std::vector<float>& VectorEffectValue()
	{
		return m_EffectValue;
	}

	float& EffectValue1Reference()
	{
		return m_EffectValue[1];
	}

	float& EffectValue0Reference()
	{
		return m_EffectValue[0];
	}

	int& EffectTypeReference()
	{
		return m_EffectType;
	}

	int EffectType() const
	{
		return m_EffectType;
	}

	void EffectType(const int& _EffectType)
	{
		m_EffectType = _EffectType;
	}

	std::wstring& EffectFileReference()
	{
		return m_EffectFile;
	}

	std::wstring EffectFile() const
	{
		return m_EffectFile;
	}

	void EffectFile(const std::wstring& _EffectFile)
	{
		m_EffectFile = _EffectFile;
	}

private:
	int m_Probability;
	std::wstring m_Name;
	int m_Index;
	std::vector<float> m_EffectValue;
	int m_EffectType;
	std::wstring m_EffectFile;
};

class SkillEffectData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		SkillEffect Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/SkillEffect.XML");
		if( false == parser.read_file(L"./XML/SkillEffect.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/SkillEffect.XML");
			return false;
		}

		if ( false == parser.execute(L"/SkillEffectList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /SkillEffectList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"EffectFile", Instance.EffectFileReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.EffectFileReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"EffectType", Instance.EffectTypeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.EffectTypeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"EffectValue0", Instance.EffectValue0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.EffectValue0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"EffectValue1", Instance.EffectValue1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.EffectValue1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"EffectValue2", Instance.EffectValue2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.EffectValue2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Probability", Instance.ProbabilityReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ProbabilityReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, SkillEffect>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, SkillEffect& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, SkillEffect>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, SkillEffect> m_Map;
};

__declspec(selectany) SkillEffectData SkillEffectDataInstance;

} // ExcelData

namespace ExcelData
{

class SkillCondition
{
public:
	SkillCondition()
	{
		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_ConditionValue, 0, sizeof(m_ConditionValue));

		memset(&m_ConditionType, 0, sizeof(m_ConditionType));

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

	std::wstring& DescReference()
	{
		return m_Desc;
	}

	std::wstring Desc() const
	{
		return m_Desc;
	}

	void Desc(const std::wstring& _Desc)
	{
		m_Desc = _Desc;
	}

	int& ConditionValueReference()
	{
		return m_ConditionValue;
	}

	int ConditionValue() const
	{
		return m_ConditionValue;
	}

	void ConditionValue(const int& _ConditionValue)
	{
		m_ConditionValue = _ConditionValue;
	}

	int& ConditionTypeReference()
	{
		return m_ConditionType;
	}

	int ConditionType() const
	{
		return m_ConditionType;
	}

	void ConditionType(const int& _ConditionType)
	{
		m_ConditionType = _ConditionType;
	}

private:
	int m_Index;
	std::wstring m_Desc;
	int m_ConditionValue;
	int m_ConditionType;
};

class SkillConditionData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		SkillCondition Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/SkillCondition.XML");
		if( false == parser.read_file(L"./XML/SkillCondition.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/SkillCondition.XML");
			return false;
		}

		if ( false == parser.execute(L"/SkillConditionList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /SkillConditionList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"ConditionType", Instance.ConditionTypeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ConditionTypeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"ConditionValue", Instance.ConditionValueReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ConditionValueReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Desc", Instance.DescReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.DescReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, SkillCondition>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, SkillCondition& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, SkillCondition>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, SkillCondition> m_Map;
};

__declspec(selectany) SkillConditionData SkillConditionDataInstance;

} // ExcelData

