//Find
	HEADER_GD_REQUEST_CHANNELSTATUS	= 140,
	
///Add
#if defined(BL_OFFLINE_MESSAGE)
	HEADER_GD_REQUEST_OFFLINE_MESSAGES = 141,
	HEADER_GD_SEND_OFFLINE_MESSAGE = 142,
#endif

//Find
	HEADER_DG_RESPOND_CHANNELSTATUS		= 181,
	
///Add
#if defined(BL_OFFLINE_MESSAGE)
	HEADER_DG_RESPOND_OFFLINE_MESSAGES = 182,
#endif

//Find
enum ERequestChargeType
{
	...
};

///Add
#if defined(BL_OFFLINE_MESSAGE)
typedef struct
{
	char 	szName[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGDReadOfflineMessage;

typedef struct
{
	char	szFrom[CHARACTER_NAME_MAX_LEN + 1];
	char	szMessage[CHAT_MAX_LEN + 1];
} TPacketDGReadOfflineMessage;

typedef struct
{
	char	szFrom[CHARACTER_NAME_MAX_LEN + 1];
	char	szTo[CHARACTER_NAME_MAX_LEN + 1];
	char	szMessage[CHAT_MAX_LEN + 1];
} TPacketGDSendOfflineMessage;
#endif