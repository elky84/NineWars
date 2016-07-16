#pragma once

namespace ExcelData
{

class ClassAnimation
{
public:
	ClassAnimation()
	{
		memset(&m_Width, 0, sizeof(m_Width));

		memset(&m_Name, 0, sizeof(m_Name));

		memset(&m_Move, 0, sizeof(m_Move));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Idle, 0, sizeof(m_Idle));

		memset(&m_Height, 0, sizeof(m_Height));

		memset(&m_Attack, 0, sizeof(m_Attack));

	}

	int& WidthReference()
	{
		return m_Width;
	}

	int Width() const
	{
		return m_Width;
	}

	void Width(const int& _Width)
	{
		m_Width = _Width;
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

	std::wstring& MoveReference()
	{
		return m_Move;
	}

	std::wstring Move() const
	{
		return m_Move;
	}

	void Move(const std::wstring& _Move)
	{
		m_Move = _Move;
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

	std::wstring& IdleReference()
	{
		return m_Idle;
	}

	std::wstring Idle() const
	{
		return m_Idle;
	}

	void Idle(const std::wstring& _Idle)
	{
		m_Idle = _Idle;
	}

	int& HeightReference()
	{
		return m_Height;
	}

	int Height() const
	{
		return m_Height;
	}

	void Height(const int& _Height)
	{
		m_Height = _Height;
	}

	std::wstring& AttackReference()
	{
		return m_Attack;
	}

	std::wstring Attack() const
	{
		return m_Attack;
	}

	void Attack(const std::wstring& _Attack)
	{
		m_Attack = _Attack;
	}

private:
	int m_Width;
	std::wstring m_Name;
	std::wstring m_Move;
	int m_Index;
	std::wstring m_Idle;
	int m_Height;
	std::wstring m_Attack;
};

class ClassAnimationData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		ClassAnimation Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/ClassAnimation.XML");
		if( false == parser.read_file(L"./XML/ClassAnimation.XML"))
		{
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/ClassAnimation.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(L"/ClassAnimationList"))
		{
			LOG_ERROR(_T("%s, execute() Failed. /ClassAnimationList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Attack", Instance.AttackReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.AttackReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Height", Instance.HeightReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.HeightReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Idle", Instance.IdleReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IdleReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Index", Instance.IndexReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.IndexReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Move", Instance.MoveReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.MoveReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Name", Instance.NameReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.NameReference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Width", Instance.WidthReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.WidthReference()"), __FUNCTIONW__);
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, ClassAnimation>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, ClassAnimation& Instance)
	{
		std::map<int, ClassAnimation>::iterator it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, ClassAnimation>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, ClassAnimation> m_Map;
};

__declspec(selectany) ClassAnimationData ClassAnimationDataInstance;

} // ExcelData

