#pragma once

namespace ExcelData
{

class RelationEffect
{
public:
	RelationEffect()
	{
		memset(&m_Min, 0, sizeof(m_Min));

		memset(&m_Max, 0, sizeof(m_Max));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Effect, 0, sizeof(m_Effect));

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

	float& EffectReference()
	{
		return m_Effect;
	}

	float Effect() const
	{
		return m_Effect;
	}

	void Effect(const float& _Effect)
	{
		m_Effect = _Effect;
	}

private:
	int m_Min;
	int m_Max;
	int m_Index;
	float m_Effect;
};

class RelationEffectData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		RelationEffect Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/RelationEffect.XML");
		if( false == parser.read_file(L"./XML/RelationEffect.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/RelationEffect.XML");
			return false;
		}

		if ( false == parser.execute(L"/RelationEffectList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /RelationEffectList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Effect", Instance.EffectReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.EffectReference()");
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

		while (parser.next())
		{
			m_Map.insert(std::map<int, RelationEffect>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, RelationEffect& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, RelationEffect>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, RelationEffect> m_Map;
};

__declspec(selectany) RelationEffectData RelationEffectDataInstance;

} // ExcelData

namespace ExcelData
{

class RaceRelation
{
public:
	RaceRelation()
	{
		m_Race.resize(9);

		m_Relation.resize(9);

		memset(&m_Index, 0, sizeof(m_Index));

	}

	int& Relation8Reference()
	{
		return m_Relation[8];
	}

	std::vector<int>& VectorRelation()
	{
		return m_Relation;
	}

	int& Relation7Reference()
	{
		return m_Relation[7];
	}

	int& Relation6Reference()
	{
		return m_Relation[6];
	}

	int& Relation5Reference()
	{
		return m_Relation[5];
	}

	int& Relation4Reference()
	{
		return m_Relation[4];
	}

	int& Relation3Reference()
	{
		return m_Relation[3];
	}

	int& Relation2Reference()
	{
		return m_Relation[2];
	}

	int& Relation1Reference()
	{
		return m_Relation[1];
	}

	int& Relation0Reference()
	{
		return m_Relation[0];
	}

	int& Race8Reference()
	{
		return m_Race[8];
	}

	std::vector<int>& VectorRace()
	{
		return m_Race;
	}

	int& Race7Reference()
	{
		return m_Race[7];
	}

	int& Race6Reference()
	{
		return m_Race[6];
	}

	int& Race5Reference()
	{
		return m_Race[5];
	}

	int& Race4Reference()
	{
		return m_Race[4];
	}

	int& Race3Reference()
	{
		return m_Race[3];
	}

	int& Race2Reference()
	{
		return m_Race[2];
	}

	int& Race1Reference()
	{
		return m_Race[1];
	}

	int& Race0Reference()
	{
		return m_Race[0];
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

private:
	std::vector<int> m_Relation;
	std::vector<int> m_Race;
	std::wstring m_Name;
	int m_Index;
};

class RaceRelationData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		RaceRelation Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/RaceRelation.XML");
		if( false == parser.read_file(L"./XML/RaceRelation.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/RaceRelation.XML");
			return false;
		}

		if ( false == parser.execute(L"/RaceRelationList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /RaceRelationList");
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

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race0", Instance.Race0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Race0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race1", Instance.Race1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Race1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race2", Instance.Race2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Race2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race3", Instance.Race3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Race3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race4", Instance.Race4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Race4Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race5", Instance.Race5Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Race5Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race6", Instance.Race6Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Race6Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race7", Instance.Race7Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Race7Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race8", Instance.Race8Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Race8Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation0", Instance.Relation0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation1", Instance.Relation1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation2", Instance.Relation2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation3", Instance.Relation3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation4", Instance.Relation4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation4Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation5", Instance.Relation5Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation5Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation6", Instance.Relation6Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation6Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation7", Instance.Relation7Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation7Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation8", Instance.Relation8Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation8Reference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, RaceRelation>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, RaceRelation& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, RaceRelation>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, RaceRelation> m_Map;
};

__declspec(selectany) RaceRelationData RaceRelationDataInstance;

} // ExcelData

namespace ExcelData
{

class GroupRelation
{
public:
	GroupRelation()
	{
		m_Group.resize(5);

		m_Relation.resize(5);

		memset(&m_Index, 0, sizeof(m_Index));

	}

	int& Relation4Reference()
	{
		return m_Relation[4];
	}

	std::vector<int>& VectorRelation()
	{
		return m_Relation;
	}

	int& Relation3Reference()
	{
		return m_Relation[3];
	}

	int& Relation2Reference()
	{
		return m_Relation[2];
	}

	int& Relation1Reference()
	{
		return m_Relation[1];
	}

	int& Relation0Reference()
	{
		return m_Relation[0];
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

	int& Group4Reference()
	{
		return m_Group[4];
	}

	std::vector<int>& VectorGroup()
	{
		return m_Group;
	}

	int& Group3Reference()
	{
		return m_Group[3];
	}

	int& Group2Reference()
	{
		return m_Group[2];
	}

	int& Group1Reference()
	{
		return m_Group[1];
	}

	int& Group0Reference()
	{
		return m_Group[0];
	}

private:
	std::vector<int> m_Relation;
	std::wstring m_Name;
	int m_Index;
	std::vector<int> m_Group;
};

class GroupRelationData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		GroupRelation Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/GroupRelation.XML");
		if( false == parser.read_file(L"./XML/GroupRelation.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/GroupRelation.XML");
			return false;
		}

		if ( false == parser.execute(L"/GroupRelationList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /GroupRelationList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Group0", Instance.Group0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Group0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Group1", Instance.Group1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Group1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Group2", Instance.Group2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Group2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Group3", Instance.Group3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Group3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Group4", Instance.Group4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Group4Reference()");
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

		if ( false == parser.bind_attrib(L"Relation0", Instance.Relation0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation1", Instance.Relation1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation2", Instance.Relation2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation3", Instance.Relation3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation4", Instance.Relation4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation4Reference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, GroupRelation>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, GroupRelation& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, GroupRelation>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, GroupRelation> m_Map;
};

__declspec(selectany) GroupRelationData GroupRelationDataInstance;

} // ExcelData

namespace ExcelData
{

class NationRelation
{
public:
	NationRelation()
	{
		m_Nation.resize(5);

		m_Relation.resize(5);

		memset(&m_Index, 0, sizeof(m_Index));

	}

	int& Relation4Reference()
	{
		return m_Relation[4];
	}

	std::vector<int>& VectorRelation()
	{
		return m_Relation;
	}

	int& Relation3Reference()
	{
		return m_Relation[3];
	}

	int& Relation2Reference()
	{
		return m_Relation[2];
	}

	int& Relation1Reference()
	{
		return m_Relation[1];
	}

	int& Relation0Reference()
	{
		return m_Relation[0];
	}

	int& Nation4Reference()
	{
		return m_Nation[4];
	}

	std::vector<int>& VectorNation()
	{
		return m_Nation;
	}

	int& Nation3Reference()
	{
		return m_Nation[3];
	}

	int& Nation2Reference()
	{
		return m_Nation[2];
	}

	int& Nation1Reference()
	{
		return m_Nation[1];
	}

	int& Nation0Reference()
	{
		return m_Nation[0];
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

private:
	std::vector<int> m_Relation;
	std::vector<int> m_Nation;
	std::wstring m_Name;
	int m_Index;
};

class NationRelationData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		NationRelation Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/NationRelation.XML");
		if( false == parser.read_file(L"./XML/NationRelation.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/NationRelation.XML");
			return false;
		}

		if ( false == parser.execute(L"/NationRelationList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /NationRelationList");
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

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Nation0", Instance.Nation0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Nation0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Nation1", Instance.Nation1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Nation1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Nation2", Instance.Nation2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Nation2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Nation3", Instance.Nation3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Nation3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Nation4", Instance.Nation4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Nation4Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation0", Instance.Relation0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation1", Instance.Relation1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation2", Instance.Relation2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation3", Instance.Relation3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation4", Instance.Relation4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation4Reference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, NationRelation>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, NationRelation& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, NationRelation>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, NationRelation> m_Map;
};

__declspec(selectany) NationRelationData NationRelationDataInstance;

} // ExcelData

namespace ExcelData
{

class CharacterRelation
{
public:
	CharacterRelation()
	{
		m_Character.resize(9);

		m_Relation.resize(9);

		memset(&m_Index, 0, sizeof(m_Index));

	}

	int& Relation8Reference()
	{
		return m_Relation[8];
	}

	std::vector<int>& VectorRelation()
	{
		return m_Relation;
	}

	int& Relation7Reference()
	{
		return m_Relation[7];
	}

	int& Relation6Reference()
	{
		return m_Relation[6];
	}

	int& Relation5Reference()
	{
		return m_Relation[5];
	}

	int& Relation4Reference()
	{
		return m_Relation[4];
	}

	int& Relation3Reference()
	{
		return m_Relation[3];
	}

	int& Relation2Reference()
	{
		return m_Relation[2];
	}

	int& Relation1Reference()
	{
		return m_Relation[1];
	}

	int& Relation0Reference()
	{
		return m_Relation[0];
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

	int& Character8Reference()
	{
		return m_Character[8];
	}

	std::vector<int>& VectorCharacter()
	{
		return m_Character;
	}

	int& Character7Reference()
	{
		return m_Character[7];
	}

	int& Character6Reference()
	{
		return m_Character[6];
	}

	int& Character5Reference()
	{
		return m_Character[5];
	}

	int& Character4Reference()
	{
		return m_Character[4];
	}

	int& Character3Reference()
	{
		return m_Character[3];
	}

	int& Character2Reference()
	{
		return m_Character[2];
	}

	int& Character1Reference()
	{
		return m_Character[1];
	}

	int& Character0Reference()
	{
		return m_Character[0];
	}

private:
	std::vector<int> m_Relation;
	std::wstring m_Name;
	int m_Index;
	std::vector<int> m_Character;
};

class CharacterRelationData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		CharacterRelation Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/CharacterRelation.XML");
		if( false == parser.read_file(L"./XML/CharacterRelation.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/CharacterRelation.XML");
			return false;
		}

		if ( false == parser.execute(L"/CharacterRelationList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /CharacterRelationList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Character0", Instance.Character0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Character0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Character1", Instance.Character1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Character1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Character2", Instance.Character2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Character2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Character3", Instance.Character3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Character3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Character4", Instance.Character4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Character4Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Character5", Instance.Character5Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Character5Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Character6", Instance.Character6Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Character6Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Character7", Instance.Character7Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Character7Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Character8", Instance.Character8Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Character8Reference()");
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

		if ( false == parser.bind_attrib(L"Relation0", Instance.Relation0Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation0Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation1", Instance.Relation1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation2", Instance.Relation2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation3", Instance.Relation3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation4", Instance.Relation4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation4Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation5", Instance.Relation5Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation5Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation6", Instance.Relation6Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation6Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation7", Instance.Relation7Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation7Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Relation8", Instance.Relation8Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Relation8Reference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, CharacterRelation>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, CharacterRelation& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, CharacterRelation>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, CharacterRelation> m_Map;
};

__declspec(selectany) CharacterRelationData CharacterRelationDataInstance;

} // ExcelData

