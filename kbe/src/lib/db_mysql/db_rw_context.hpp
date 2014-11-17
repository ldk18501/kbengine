/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KBE_DB_RW_CONTEXT_HPP
#define KBE_DB_RW_CONTEXT_HPP

#include "cstdkbe/cstdkbe.hpp"
#include "cstdkbe/memorystream.hpp"
#include "helper/debug_helper.hpp"

namespace KBEngine { 


/**
	����һ��ʵ��ĳ�ű������ݣ�����д����ʹ�õ�
	dbid���������������ʵ���dbid���ӱ����ǵ�ǰ��ѯ��dbid

	dbids��������dbids��ֻ��һ��dbid������ʵ���id�����ʵ�����ݴ���������������ӱ����֣���������ݽṹ��������һ���ӱ���ʱ��
		dbids�����������ӱ�����, ÿ��dbid����ʾ����ӱ��϶�Ӧ��ֵ���Ұ�������˳��ͬʱҲ��ʾ�������ж�Ӧλ�õ�ֵ��
		dbids = {
			123 : [xxx, xxx, ...], // 123Ϊ�����ϵ�ĳ��dbid������Ϊ���ӱ����븸��������ĵ�dbids��
			...
		}

	items��������������ֶ���Ϣ�������д�����ֶ���Ҳ�ж�Ӧ��Ҫдֵ��

	optable���ӱ��ṹ

	results��������ʱ��ѯ��������, ���ݵ����ж�Ӧitems�е�strkey����������dbids��������
	readresultIdx����Ϊresults�е�������dbids * items�����Ե���ĳЩ�ݹ����ʱ��������ݻ�������readresultIdx��������λ�á�

	parentTableDBID��������dbid
	parentTableName������������

	tableName����ǰ��������
 */
class DBRW_Context
{
public:
	/**
		�洢����Ҫ�����ı�item�ṹ
	*/
	struct DB_ITEM_DATA
	{
		char sqlval[MAX_BUF];
		const char* sqlkey;
		std::string extraDatas;
	};

	typedef std::vector< std::pair< std::string/*tableName*/, KBEShared_ptr< DBRW_Context > > > DB_RW_CONTEXTS;
	typedef std::vector< KBEShared_ptr<DB_ITEM_DATA>  > DB_ITEM_DATAS;

	DBRW_Context()
	{
	}

	~DBRW_Context()
	{
	}
	
	DB_ITEM_DATAS items;
	std::string tableName;
	std::string parentTableName;
	DBID parentTableDBID;
	DBID dbid;
	DB_RW_CONTEXTS optable;
	bool isEmpty;
	std::map<DBID, std::vector<DBID> > dbids;
	std::vector< std::string >results;
	std::vector< std::string >::size_type readresultIdx;


private:

};

}
#endif // KBE_DB_RW_CONTEXT_HPP
