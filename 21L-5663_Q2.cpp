#include <iostream>
#include <string>
using namespace std;

template <class T, typename U>
class DataObject
{
private:
	T Data;
	U Key;
	DataObject* Link;
	
public:
	DataObject()
	{
		Data = NULL;
		Key = NULL;
		Link = NULL;
	}
	
	DataObject(T x,U y)
	{
		Data = x;
		Key = y;
		Link = NULL;
	}
	
	~DataObject()
	{
		if(Link != nullptr)
		{
			Link = nullptr;
		}
	}
	DataObject(const DataObject& dto)
	{
		Data = dto.Data;
		Key = dto.Key;
		Link = dto.Link;

	}

	void setData(T data)
	{
		data = Data;
	}

	void setKey(U key)
	{
		Key = key;
	}

	void setLink(DataObject *dt)
	{
		Link = dt;
	}

	T getData()
	{
		return Data;
	}

	U getKey()
	{
		return Key;
	}

	DataObject* getLink()
	{
		return Link;
	}

	void operator=(const DataObject & DO)
	{
		Data = DO.Data;
		Key = DO.Key;
		Link = DO.Link;
	}

	bool operator==(const DataObject & dta)
	{
		if (Data==dta.Data && Key==dta.Key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()  
{
	DataObject<int, char> Obj1 = DataObject<int, char>(97, 'a');  
	DataObject<int, char> Obj2 = DataObject<int, char>(Obj1);  
	DataObject<int, char> Obj3 = DataObject<int, char>(1, 'x');  
	((Obj1 == Obj2)) ? cout << "Objects are equal" : cout << "Objects are not equal"; 
	Obj2.setLink(&Obj1);  
	Obj2.setData('b');  
	Obj2.setKey(98);  
	cout << endl;  
	cout << "[ " << Obj1.getData() << " : " << Obj1.getKey() << " : " << Obj1.getLink()  << " ]";  
	Obj1.~DataObject();  
	cout << endl;  
	cout << "[ " << Obj2.getData() << " : " << Obj2.getKey() << " : " << Obj2.getLink()  << " ]";  
	cout << endl;  
	cout << "[ " << Obj3.getData() << " : " << Obj3.getKey() << " : " << Obj3.getLink()  << " ]";  
	Obj3 = Obj2;  
	Obj2.~DataObject();  
	cout << endl;  
	cout << "[ " << Obj3.getData() << " : " << Obj3.getKey() << " : " << Obj3.getLink()  << " ]\n";  
	Obj3.~DataObject();  

	system("pause");
	return 0;  
} 
