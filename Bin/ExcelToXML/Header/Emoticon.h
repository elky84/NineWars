#pragma once

namespace ExcelData
{

class SituationEmoticon
{
public:
	SituationEmoticon()
	{
		memset(&m_Name, 0, sizeof(m_Name));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Description, 0, sizeof(m_Description));

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

private:
	std::wstring m_Name;
	int m_Index;
	std::wstring m_Description;
};

class SituationEmoticonData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		SituationEmoticon Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/SituationEmoticon.XML");
		if( false == parser.read_file(L"./XML/SituationEmoticon.XML"))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/SituationEmoticon.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(L"/SituationEmoticonList"))
		{
			LOG_ERROR(_T("%s, execute() Failed. /SituationEmoticonList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Description", Instance.DescriptionReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.DescriptionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.NameReference()"), __FUNCTIONW__);
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, SituationEmoticon>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, SituationEmoticon& Instance)
	{
		std::map<int, SituationEmoticon>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, SituationEmoticon>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, SituationEmoticon> m_Map;
};

__declspec(selectany) SituationEmoticonData SituationEmoticonDataInstance;

} // ExcelData

namespace ExcelData
{

class FeelingEmoticon
{
public:
	FeelingEmoticon()
	{
		memset(&m_isDuplicate, 0, sizeof(m_isDuplicate));

		memset(&m_Speed, 0, sizeof(m_Speed));

		memset(&m_RemainTime, 0, sizeof(m_RemainTime));

		memset(&m_Range, 0, sizeof(m_Range));

		memset(&m_Name, 0, sizeof(m_Name));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_HP_Regenerate, 0, sizeof(m_HP_Regenerate));

		memset(&m_Description, 0, sizeof(m_Description));

		memset(&m_Condition, 0, sizeof(m_Condition));

		memset(&m_AttackSpeed, 0, sizeof(m_AttackSpeed));

		memset(&m_AP_DEPENSE, 0, sizeof(m_AP_DEPENSE));

		memset(&m_AP_DAMAGE, 0, sizeof(m_AP_DAMAGE));

		memset(&m_AD_DEFENSE, 0, sizeof(m_AD_DEFENSE));

		memset(&m_AD_DAMAGE, 0, sizeof(m_AD_DAMAGE));

	}

	std::wstring& isDuplicateReference()
	{
		return m_isDuplicate;
	}

	std::wstring isDuplicate() const
	{
		return m_isDuplicate;
	}

	void isDuplicate(const std::wstring& _isDuplicate)
	{
		m_isDuplicate = _isDuplicate;
	}

	float& SpeedReference()
	{
		return m_Speed;
	}

	float Speed() const
	{
		return m_Speed;
	}

	void Speed(const float& _Speed)
	{
		m_Speed = _Speed;
	}

	int& RemainTimeReference()
	{
		return m_RemainTime;
	}

	int RemainTime() const
	{
		return m_RemainTime;
	}

	void RemainTime(const int& _RemainTime)
	{
		m_RemainTime = _RemainTime;
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

	int& HP_RegenerateReference()
	{
		return m_HP_Regenerate;
	}

	int HP_Regenerate() const
	{
		return m_HP_Regenerate;
	}

	void HP_Regenerate(const int& _HP_Regenerate)
	{
		m_HP_Regenerate = _HP_Regenerate;
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

	std::wstring& ConditionReference()
	{
		return m_Condition;
	}

	std::wstring Condition() const
	{
		return m_Condition;
	}

	void Condition(const std::wstring& _Condition)
	{
		m_Condition = _Condition;
	}

	float& AttackSpeedReference()
	{
		return m_AttackSpeed;
	}

	float AttackSpeed() const
	{
		return m_AttackSpeed;
	}

	void AttackSpeed(const float& _AttackSpeed)
	{
		m_AttackSpeed = _AttackSpeed;
	}

	int& AP_DEPENSEReference()
	{
		return m_AP_DEPENSE;
	}

	int AP_DEPENSE() const
	{
		return m_AP_DEPENSE;
	}

	void AP_DEPENSE(const int& _AP_DEPENSE)
	{
		m_AP_DEPENSE = _AP_DEPENSE;
	}

	int& AP_DAMAGEReference()
	{
		return m_AP_DAMAGE;
	}

	int AP_DAMAGE() const
	{
		return m_AP_DAMAGE;
	}

	void AP_DAMAGE(const int& _AP_DAMAGE)
	{
		m_AP_DAMAGE = _AP_DAMAGE;
	}

	int& AD_DEFENSEReference()
	{
		return m_AD_DEFENSE;
	}

	int AD_DEFENSE() const
	{
		return m_AD_DEFENSE;
	}

	void AD_DEFENSE(const int& _AD_DEFENSE)
	{
		m_AD_DEFENSE = _AD_DEFENSE;
	}

	int& AD_DAMAGEReference()
	{
		return m_AD_DAMAGE;
	}

	int AD_DAMAGE() const
	{
		return m_AD_DAMAGE;
	}

	void AD_DAMAGE(const int& _AD_DAMAGE)
	{
		m_AD_DAMAGE = _AD_DAMAGE;
	}

private:
	std::wstring m_isDuplicate;
	float m_Speed;
	int m_RemainTime;
	int m_Range;
	std::wstring m_Name;
	int m_Index;
	int m_HP_Regenerate;
	std::wstring m_Description;
	std::wstring m_Condition;
	float m_AttackSpeed;
	int m_AP_DEPENSE;
	int m_AP_DAMAGE;
	int m_AD_DEFENSE;
	int m_AD_DAMAGE;
};

class FeelingEmoticonData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		FeelingEmoticon Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/FeelingEmoticon.XML");
		if( false == parser.read_file(L"./XML/FeelingEmoticon.XML"))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/FeelingEmoticon.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(L"/FeelingEmoticonList"))
		{
			LOG_ERROR(_T("%s, execute() Failed. /FeelingEmoticonList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AD_DAMAGE", Instance.AD_DAMAGEReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AD_DAMAGEReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AD_DEFENSE", Instance.AD_DEFENSEReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AD_DEFENSEReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AP_DAMAGE", Instance.AP_DAMAGEReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AP_DAMAGEReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AP_DEPENSE", Instance.AP_DEPENSEReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AP_DEPENSEReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"AttackSpeed", Instance.AttackSpeedReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AttackSpeedReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Condition", Instance.ConditionReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ConditionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Description", Instance.DescriptionReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.DescriptionReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"HP_Regenerate", Instance.HP_RegenerateReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.HP_RegenerateReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.NameReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Range", Instance.RangeReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.RangeReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"RemainTime", Instance.RemainTimeReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.RemainTimeReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Speed", Instance.SpeedReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.SpeedReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"isDuplicate", Instance.isDuplicateReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.isDuplicateReference()"), __FUNCTIONW__);
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, FeelingEmoticon>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, FeelingEmoticon& Instance)
	{
		std::map<int, FeelingEmoticon>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, FeelingEmoticon>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, FeelingEmoticon> m_Map;
};

__declspec(selectany) FeelingEmoticonData FeelingEmoticonDataInstance;

} // ExcelData

