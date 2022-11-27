#pragma once

/* Vagao das listas */

template<class TIPO>
class Elemento
{
private:
	Elemento<TIPO>* pProx;
	TIPO* item;
public:
	Elemento()
	{
		pProx = nullptr;
		item = nullptr;
	}
	~Elemento()
	{}

	void setProximo(Elemento<TIPO>* p) { this->pProx = p; }
	Elemento<TIPO>* getProximo() { return pProx; }

	void setItem(TIPO* i) { this->item = i; }
	TIPO* getItem() { return item; }
};

