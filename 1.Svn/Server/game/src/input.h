//Find
	void		ItemAwardInformer(TPacketItemAwardInfromer* data);
	
///Add
#if defined(BL_OFFLINE_MESSAGE)
	void		ReadOfflineMessages(LPDESC desc, const char* pcData);
#endif