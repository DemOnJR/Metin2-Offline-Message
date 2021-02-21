//Find
		bool		DragonSoul_RefineWindow_CanRefine();
		
///Add
#if defined(BL_OFFLINE_MESSAGE)
	protected:
		DWORD				dwLastOfflinePMTime;
	public:
		DWORD				GetLastOfflinePMTime() const { return dwLastOfflinePMTime; }
		void				SetLastOfflinePMTime() { dwLastOfflinePMTime = get_dword_time(); }
		void				SendOfflineMessage(const char* To, const char* Message);
		void				ReadOfflineMessages();
#endif