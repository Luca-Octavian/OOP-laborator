#pragma once
template <typename K, typename V>
class Map
{
	struct Cuplu
	{
		K key;
		V value;
	};
	Cuplu *Harta;
	int size;
	int maxsize;
	void redimensionare()
	{
		this->maxsize = this->maxsize * 2;
		Cuplu *Hartanoua = new Cuplu[this->maxsize];
		for (int i = 0;i < this->size;i++)
		{
			Hartanoua[i] = this->Harta[i];
		}
		delete[] Harta;
		this->Harta = Hartanoua;
	}
	int Gasesteindex(const K& Key)
	{
		for (int i = 0;i < this->size;i++)
		{
			if (this->Harta[i].key == Key)
				return i;
		}
		return -1;
	}
public:
	Map()
	{
		this->size = 0;
		this->maxsize = 5;
		this->Harta = new Cuplu[this->maxsize];
	}
	~Map()
	{
		delete[] Harta;
	}
	V& operator[](const K& Key)
	{
		int Index = this->Gasesteindex(Key);
		if(Index!=-1)
		{
			return this->Harta[Index].value;
		}
		if (this->size >= this->maxsize)
		{
			this->redimensionare();
		}
		Harta[this->size].key = Key;
		Harta[this->size].value = V();
		return this->Harta[this->size++].value;
	}
	void Set(const V& Value, const K& Key)
	{
		int Index = this->Gasesteindex(Key);
		if (Index != -1)
		{
			this->Harta[Index].value = Value;
		}
		else
		{
			if (this->size >= this->maxsize)
			{
				this->redimensionare();
			}
			this->Harta[size].key = Key;
			this->Harta[size].value = Value;
			size++;
		}
	}
	bool Get(const K& Key, V& Value)
	{
		int Index = this->Gasesteindex(Key);
		if (Index != -1)
		{
			Value = this->Harta[Index].value;
			return true;  
		}
		return false;
	}
	int Count()
	{
		return this->size;
	}
	void Clear()
	{
		this->size = 0;
	}
	bool Delete(const K& Key)
	{
		int Index = this->Gasesteindex(Key);
		if (Index == -1)
		{
			return false;
		}
		for (int i = Index; i < this->size-1;i++)
		{
			this->Harta[i] = this->Harta[i + 1];
		}
		this->size--;
		return true;
	}
	bool Includes(Map <K, V>& other)
	{
		for (int i = 0;i < other.size;i++)
		{
			int Index = this->Gasesteindex(other.Harta[i].key);
			if (Index == -1)
			{
				return false;
			}
		}
		return true;
	}
	struct Obiect
	{
		K& key;
		V& value;
		int index;
	};
	class Iterator
	{
	public:
		Cuplu* ptr;
		int index;
		Iterator(Cuplu* p, int i)
		{
			ptr = p;
			index = i;
		}
		bool operator!=(Iterator& other)
		{
			return index!= other.index;
		}
		void operator++()
		{
			ptr++;
			index++;
		}
		Obiect operator*()
		{
			return { ptr->key,ptr->value, index };
		}
		

	};
	Iterator begin()
	{
		return Iterator(Harta, 0);
	}

	Iterator end()
	{
		return Iterator(Harta + size, size);
	}
};

