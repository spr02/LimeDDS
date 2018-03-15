	/*
	DDSEnablexSO		<= mem(1)(0);
	DDSTxSelxSO			<= mem(1)(1);
	DDSRxSelxSO			<= mem(1)(2);
	
	DDSTaylorEnxSO		<= mem(2)(0);
	DDSTrDithEnxSO		<= mem(2)(1);
	DDSPhDithEnxSO		<= mem(2)(2);
	
	DDSSweepEnxSO		<= mem(2)(4);
	DDSSweepUpDownxSO	<= mem(2)(5);
	
	DDSSweepRatexDO	<= mem(20) & mem(21);
	DDSTopFTWxDO		<= mem(4) & mem(5);
	DDSBotFTWxDO		<= mem(6) & mem(7);
	*/
#define DDS_BASE_ADDR 224

#define DDS_MUX				DDS_BASE_ADDR + 1			//225
#define DDS_TX_SEL			1
#define DDS_RX_SEL			2
	
#define DDS_CONTROL			DDS_BASE_ADDR + 2			//226
#define DDS_TAYLOR_EN		0
#define DDS_TR_DITH_EN		1
#define DDS_PH_DITH_EN		2

#define DDS_SWEEP_EN		4
#define DDS_SWEEP_UP_DOWN	5

#define DDS_TOP_FTW_H		DDS_BASE_ADDR + 4			//228
#define DDS_TOP_FTW_L		DDS_BASE_ADDR + 5			//229
#define DDS_BOT_FTW_H		DDS_BASE_ADDR + 6			//230	
#define DDS_BOT_FTW_L		DDS_BASE_ADDR + 7			//231	
	
#define DDS_SWEEP_RATE_H	DDS_BASE_ADDR + 20			//244
#define DDS_SWEEP_RATE_L	DDS_BASE_ADDR + 21			//245
