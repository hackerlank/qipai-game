#ifndef ANDROID_USER_ITEM_SINK_HEAD_FILE
#define ANDROID_USER_ITEM_SINK_HEAD_FILE

#pragma once

#include "Stdafx.h"
#include "GameLogic.h"

//////////////////////////////////////////////////////////////////////////

//机器人类
class CAndroidUserItemSink : public IAndroidUserItemSink
{
	//游戏变量
protected:
	WORD							m_wBankerUser;						//庄家位置

	//下注信息
protected:
	LONG							m_lMaxScore;						//最高下注
	LONG							m_lLessScore;						//最少下注

	//辅助变量
protected:
	bool							m_bGameScene;						//场景标志

	//控件变量
protected:
	CGameLogic						m_GameLogic;						//游戏逻辑
	IAndroidUserItem *				m_pIAndroidUserItem;				//用户接口

	//函数定义
public:
	//构造函数
	CAndroidUserItemSink();
	//析构函数
	virtual ~CAndroidUserItemSink();

	//基础接口
public:
	//释放对象
	virtual VOID __cdecl Release() { }
	//是否有效
	virtual bool __cdecl IsValid() { return AfxIsValidAddress(this,sizeof(CAndroidUserItemSink))?true:false; }
	//接口查询
	virtual void * __cdecl QueryInterface(const IID & Guid, DWORD dwQueryVer);

	//控制接口
public:
	//初始接口
	virtual bool __cdecl InitUserItemSink(IUnknownEx * pIUnknownEx);
	//重置接口
	virtual bool __cdecl RepositUserItemSink();

	//游戏事件
public:
	//时间消息
	virtual bool __cdecl OnEventTimer(UINT nTimerID);
	//游戏消息
	virtual bool __cdecl OnEventGameMessage(WORD wSubCmdID, void * pData, WORD wDataSize);
	//游戏消息
	virtual bool __cdecl OnEventFrameMessage(WORD wSubCmdID, void * pData, WORD wDataSize);
	//场景消息
	virtual bool __cdecl OnEventGameScene(BYTE cbGameStatus, bool bLookonOther, void * pData, WORD wDataSize);

	//用户事件
public:
	//用户进入
	virtual void __cdecl OnEventUserEnter(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);
	//用户离开
	virtual void __cdecl OnEventUserLeave(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);
	//用户积分
	virtual void __cdecl OnEventUserScore(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);
	//用户状态
	virtual void __cdecl OnEventUserStatus(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);
	//用户段位
	virtual void __cdecl OnEventUserSegment(IAndroidUserItem * pIAndroidUserItem, bool bLookonUser);

	//消息处理
protected:
	//时间信息
	bool OnSubTimeInfo(const void * pBuffer, WORD wDataSize);
	//下注信息
	bool OnSubScoreInfo(const void * pBuffer, WORD wDataSize);
	//庄家信息
	bool OnSubBankerUser(const void * pBuffer, WORD wDataSize);
	//抢庄信息
	bool OnSubChangeInfo(const void * pBuffer, WORD wDataSize);
	//下注信息
	bool OnSubUserChipin(const void * pBuffer, WORD wDataSize);
	//发送扑克
	bool OnSubSendCard(const void * pBuffer, WORD wDataSize);
	//游戏开始
	bool OnSubGameStart(const void * pBuffer, WORD wDataSize);
	//游戏结束
	bool OnSubGameEnd(const void * pBuffer, WORD wDataSize);
};

//////////////////////////////////////////////////////////////////////////
#endif
