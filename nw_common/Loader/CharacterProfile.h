#pragma once

namespace ExcelData
{

class CharacterProfile
{
public:
	CharacterProfile()
	{
		memset(&m_Sex, 0, sizeof(m_Sex));

		memset(&m_Race, 0, sizeof(m_Race));

		memset(&m_Nation, 0, sizeof(m_Nation));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Group, 0, sizeof(m_Group));

		memset(&m_Cost, 0, sizeof(m_Cost));

		memset(&m_Class, 0, sizeof(m_Class));

	}

	std::wstring& StoryReference()
	{
		return m_Story;
	}

	std::wstring Story() const
	{
		return m_Story;
	}

	void Story(const std::wstring& _Story)
	{
		m_Story = _Story;
	}

	int& SexReference()
	{
		return m_Sex;
	}

	int Sex() const
	{
		return m_Sex;
	}

	void Sex(const int& _Sex)
	{
		m_Sex = _Sex;
	}

	int& RaceReference()
	{
		return m_Race;
	}

	int Race() const
	{
		return m_Race;
	}

	void Race(const int& _Race)
	{
		m_Race = _Race;
	}

	std::wstring& NicknameReference()
	{
		return m_Nickname;
	}

	std::wstring Nickname() const
	{
		return m_Nickname;
	}

	void Nickname(const std::wstring& _Nickname)
	{
		m_Nickname = _Nickname;
	}

	int& NationReference()
	{
		return m_Nation;
	}

	int Nation() const
	{
		return m_Nation;
	}

	void Nation(const int& _Nation)
	{
		m_Nation = _Nation;
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

	std::wstring& JobReference()
	{
		return m_Job;
	}

	std::wstring Job() const
	{
		return m_Job;
	}

	void Job(const std::wstring& _Job)
	{
		m_Job = _Job;
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

	int& GroupReference()
	{
		return m_Group;
	}

	int Group() const
	{
		return m_Group;
	}

	void Group(const int& _Group)
	{
		m_Group = _Group;
	}

	int& CostReference()
	{
		return m_Cost;
	}

	int Cost() const
	{
		return m_Cost;
	}

	void Cost(const int& _Cost)
	{
		m_Cost = _Cost;
	}

	std::wstring& CommentReference()
	{
		return m_Comment;
	}

	std::wstring Comment() const
	{
		return m_Comment;
	}

	void Comment(const std::wstring& _Comment)
	{
		m_Comment = _Comment;
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

	std::wstring& AgeReference()
	{
		return m_Age;
	}

	std::wstring Age() const
	{
		return m_Age;
	}

	void Age(const std::wstring& _Age)
	{
		m_Age = _Age;
	}

private:
	std::wstring m_Story;
	int m_Sex;
	int m_Race;
	std::wstring m_Nickname;
	int m_Nation;
	std::wstring m_Name;
	std::wstring m_Job;
	int m_Index;
	int m_Group;
	int m_Cost;
	std::wstring m_Comment;
	int m_Class;
	std::wstring m_Age;
};

class CharacterProfileData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		CharacterProfile Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/CharacterProfile.XML");
		if( false == parser.read_file(L"./XML/CharacterProfile.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/CharacterProfile.XML");
			return false;
		}

		if ( false == parser.execute(L"/CharacterProfileList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /CharacterProfileList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Age", Instance.AgeReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.AgeReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Class", Instance.ClassReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ClassReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Comment", Instance.CommentReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CommentReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Cost", Instance.CostReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.CostReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Group", Instance.GroupReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.GroupReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.IndexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Job", Instance.JobReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.JobReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Nation", Instance.NationReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NationReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Nickname", Instance.NicknameReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.NicknameReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Race", Instance.RaceReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.RaceReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Sex", Instance.SexReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.SexReference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Story", Instance.StoryReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.StoryReference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, CharacterProfile>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, CharacterProfile& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, CharacterProfile>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, CharacterProfile> m_Map;
};

__declspec(selectany) CharacterProfileData CharacterProfileDataInstance;

} // ExcelData

