#pragma once

namespace ExcelData
{

class Class
{
public:
	Class()
	{
		m_Strong.resize(6);

		memset(&m_Name, 0, sizeof(m_Name));

		memset(&m_Index, 0, sizeof(m_Index));

		memset(&m_Image, 0, sizeof(m_Image));

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
			LOG_ERROR(_T("%s, Open() Failed. Path(./XML/Class.XML"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.execute(L"/ClassList"))
		{
			LOG_ERROR(_T("%s, execute() Failed. /ClassList"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_elem(L"Data"))
		{
			LOG_ERROR(_T("%s, execute() Failed. Data"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Image", Instance.ImageReference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.ImageReference()"), __FUNCTIONW__);
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

		if ( false == parser.bind_attrib(L"Strong1", Instance.Strong1Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Strong1Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Strong2", Instance.Strong2Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Strong2Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Strong3", Instance.Strong3Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Strong3Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Strong4", Instance.Strong4Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Strong4Reference()"), __FUNCTIONW__);
			return false;
		}

		if ( false == parser.bind_attrib(L"Strong5", Instance.Strong5Reference()))
		{
			LOG_ERROR(_T("%s, bind_attrib() Failed. Instance.Strong5Reference()"), __FUNCTIONW__);
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
		std::map<int, Class>::iterator it = m_Map.find(key);
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

