//Find
	_send_bonus_info(ch);
	
///Add
#if defined(BL_OFFLINE_MESSAGE)
	ch->ReadOfflineMessages();
#endif