//*************************************************************************************************************
//
// �O������ [orbit.h]
// Author : IKUTO SEKINE
//
//*************************************************************************************************************
#ifndef _MYSTD_HASH_MAP_H_
#define _MYSTD_HASH_MAP_H_

//-------------------------------------------------------------------------------------------------------------
// �C���N���[�h�t�@�C��
//-------------------------------------------------------------------------------------------------------------
#include "mystd.h"

//-------------------------------------------------------------------------------------------------------------
// ���O��Ԓ�`
//-------------------------------------------------------------------------------------------------------------
_BEGIN_MYSTD

template<class T>
class hash_map
{
public:
	typedef typename T type;
	typedef typename type data_type;
	typedef typename std::string key_type;
public:
	// �����N���X
	class cell
	{
	public:
		cell() {}
		cell(key_type inkey, data_type indata)
		{
			key = inkey;
			data = indata;
		}
		~cell()
		{
		}

		key_type key;	// �L�[
		data_type data;	// �f�[�^
	};

public:
	// �R���X�g���N�^
	hash_map() {}
	hash_map(std::initializer_list<cell> init) :
		hash_map(std::begin(init), std::end(init)) {}

	template<class init>
	hash_map(init first, init last)
	{
		// �o�P�b�g��
		m_nNumBucket = (int)((last - first) * 1.25f);
		// �n�b�V���e�[�u���̍쐬
		MakeHashtable(m_nNumBucket);

		for (auto itr = first; itr != last; ++itr)
		{
			this->entry(*itr);
		}
	}

	// �f�X�g���N�^
	~hash_map()
	{
		DestroyHashtable();
	}

	// �n�b�V���l�̎擾
	int HashValue(key_type key)
	{
		int nHashval = 0;

		for (auto cha : key)
		{
			nHashval += cha;
		}

		// �n�b�V���l���T�C�Y�̗]���Ԃ�
		return nHashval % m_nNumBucket;
	}

	// �o�^
	void entry(cell in)
	{
		int nIdx = HashValue(in.key);

		while (m_pCell[nIdx].key.empty() == false)
		{
			nIdx = (nIdx + 1) % m_nNumBucket;
		}
		m_pCell[nIdx].key = in.key;
		m_pCell[nIdx].data = in.data;
		++m_nNumEntry;
	}

	// �o�^
	void entry(key_type inkey, data_type indata)
	{
		int nIdx = HashValue(inkey);

		while (m_pCell[nIdx].key.empty() == false)
		{
			nIdx = (nIdx + 1) % m_nNumBucket;
		}
		m_pCell[nIdx].key = inkey;
		m_pCell[nIdx].data = indata;

		++m_nNumEntry;
	}

	// ����
	data_type search(key_type key)
	{
		int nIdx = HashValue(key);

		while (m_pCell[nIdx].key.empty() == false)
		{
			if (m_pCell[nIdx].key.compare(key) == 0)
			{
				return m_pCell[nIdx].data;
			}
			nIdx = (nIdx + 1) % m_nNumBucket;
		}

		return (data_type)-1;
	}

private:

	// �n�b�V���e�[�u���̍쐬
	void MakeHashtable(int nNum)
	{
		m_pCell = new cell[nNum];
	}

	// �n�b�V���e�[�u���̔j��
	void DestroyHashtable(void)
	{
		delete[]m_pCell;
		m_pCell = nullptr;
	}

	int m_nNumBucket;	// �e�[�u���̃o�P�b�g��
	int m_nNumEntry;	// �G���g���[��
	cell *m_pCell;		// �f�[�^
};

_END_MYSTD

#endif