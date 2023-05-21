




void	DMA1_voidChannelInit(u8 channelID , u16 trans  , u8 prioritylevel , u8 suorcesize ,u8 distincsize ) ;
void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength) ;


#define     M2M        0 
#define     M2P        1
#define     P2M        2
#define     P2P        3   

#define			LOW_PRIORITY           	0
#define 		MEDIUM_PRIORITY			1
#define 		HIGH_PRIORITY			2
#define 		VERYHIGH_PRIORITY 		3

#define         BYTE                0
#define         TWO_BYTE            1
#define         FOUR_BYTE           2
