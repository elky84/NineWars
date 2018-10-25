#pragma once

namespace ExcelData
{

class Class
{
public:
	Class()
	{
		m_Strong.resize(6);

		memset(&m_Index, 0, sizeof(m_Index));

	}

	int& Strong5Reference()
	{
		return m_Strong[5];
	}

	std::vector<int>& VectorStrong()
	{
		return m_Strong;
	}

	int& Strong4Reference()
	{
		return m_Strong[4];
	}

	int& Strong3Reference()
	{
		return m_Strong[3];
	}

	int& Strong2Reference()
	{
		return m_Strong[2];
	}

	int& Strong1Reference()
	{
		return m_Strong[1];
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

	std::wstring& ImageReference()
	{
		return m_Image;
	}

	std::wstring Image() const
	{
		return m_Image;
	}

	void Image(const std::wstring& _Image)
	{
		m_Image = _Image;
	}

private:
	std::vector<int> m_Strong;
	std::wstring m_Name;
	int m_Index;
	std::wstring m_Image;
};

class ClassData : public light::excel::Data
{
public:
	virtual bool Load()
	{
		Class Instance;
		light::XMLParser parser;
		light::ScopeProfiler profiler(__FUNCTIONW__, 10, L"./XML/Class.XML");
		if( false == parser.read_file(L"./XML/Class.XML"))
		{
			LOG_ERROR(L"%s, Open() Failed. Path(./XML/Class.XML");
			return false;
		}

		if ( false == parser.execute(L"/ClassList"))
		{
			LOG_ERROR(L"%s, execute() Failed. /ClassList");
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(L"%s, execute() Failed. Data");
			return false;
		}

		if ( false == parser.bind_attrib(L"Image", Instance.ImageReference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.ImageReference()");
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

		if ( false == parser.bind_attrib(L"Strong1", Instance.Strong1Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Strong1Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Strong2", Instance.Strong2Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Strong2Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Strong3", Instance.Strong3Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Strong3Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Strong4", Instance.Strong4Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Strong4Reference()");
			return false;
		}

		if ( false == parser.bind_attrib(L"Strong5", Instance.Strong5Reference()))
		{
			LOG_ERROR(L"bind_attrib() Failed. Instance.Strong5Reference()");
			return false;
		}

		while (parser.next())
		{
			m_Map.insert(std::map<int, Class>::value_type(Instance.Index(), Instance));
		}

		return true;
	}

	bool Get(int& key, Class& Instance)
	{
		auto it = m_Map.find(key);
		{
			return false;
		}
		Instance = it->second;
		return true;
	}

	std::map<int, Class>& Map()
	{
		return m_Map;
	}

private:
	std::map<int, Class> m_Map;
};

__declspec(selectany) ClassData ClassDataInstance;

} // ExcelData

